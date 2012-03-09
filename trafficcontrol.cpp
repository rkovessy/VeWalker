#include "trafficcontrol.h"

void Limits::operator =(bool a) {
    hit = a;
    elevated = a;
    stopped = a;
}

TrafficControl::TrafficControl(QWidget *parent) :
    QWidget(parent)
{
    limits = false;
    whitescreen = false;
    failed = false;
    starttrialsscreen = false;
    startpracticescreen = false;

    trial = -1;
    for (int count = 0; count < 2; ++count)
        elapsed[count] = 0.0;
    carCounter = 0;

    starttrials = "starttrials";
    startpractice = "startpractice";
    fail = "fail";

    db = QSqlDatabase::addDatabase("QPSQL", "trafficConnect");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("abc123");
    db.setDatabaseName("configDb");
    db.open();
    this->database_connect();
    database_get_vals();
    database_get_trafficenable();

    connect(&popupscreen, SIGNAL(clicked()), this, SLOT(clicked()));
}

TrafficControl::~TrafficControl()
{
    QSqlDatabase::database("trafficConnect").close();
    QSqlDatabase::removeDatabase("trafficConnect");
}

void TrafficControl::set(int pid) {
    path.set(draw.centerRadius, draw.LANE_WIDTH);
    for (int count = 0; count < numberOfCars; ++count)
        cars[count].setCar(path.speed);

    time = 0.0;
    data.time = 0.0;
    QString id = data.setCars(pid);
    data.writeIntro("Data/P" + id + "_Data.txt");

    data.read_specs();
    numberOfTrials = data.numberOfTrials;
    for (int count = 0; count < numberOfTrials; ++count) {
        trials[count] = data.trials[count];
        startPos[count] = data.startPos[count];
        speeds[count] = double(data.speeds[count]) / 21.9456; // translating from km/h to 0.04units/0.02s;
        popUps[count] = data.popUps[count];
        for (int gap = 0; gap < 5; ++gap)
            gaps[count][gap] = data.gaps[count][gap];
    }
    nexttrial();
}

void TrafficControl::update() { // pedestrian location updated, car status updated and drawn
    data.writeCars_trial(trials[trial], time, starttrialsscreen, startpracticescreen, whitescreen, failed);

    if (whitescreen || failed || starttrialsscreen || startpracticescreen) {
        for (int count = 0; count < numberOfCars; ++count)
            data.writeCars(0.0, 0.0, 0.0);
        data.writeCars_endl();
        if (whitescreen) {
            elapsed[1] += 0.02;
            if (elapsed[1] >= 5.0) {
                elapsed[1] = 0.0;
                whitescreen = false;
                failed = false;
                setCarstart(); // comment this if you don't want cars, ctrl F 'comment' to find other part
            }
        }
    }
    else {
        for (int count = 0; count < numberOfCars; ++count)
            data.writeCars(cars[count].point.x, cars[count].point.y, cars[count].point.rotation);
        data.writeCars_endl();
        time += 0.02;
        data.time = time;
        if (trial != 0)
            elapsed[0] += 0.02;
        if (trial != 0 && elapsed[0] >= gaps[trial][carCounter]) {
            elapsed[0] = 0.0;
            carCounter++;
            if (carCounter < 6)
                cars[carCounter].newCar(speeds[trial]);
        }
        for (int count = 0; count < numberOfCars; ++count) {
            if (cars[count].get_onTrack()) {
                updateCar(count);
                checkCar(count);
                //cars[count].stopCar(); // comment this if you want cars, ctrl F 'comment' to find other part
                draw.car(cars[count]);
            }
            else
                cars[count].point = 0.0;
        }
        data.updateinfo(checkPedestrian());
    }
}

void TrafficControl::updatePedestrian(double x, double y, int rotation) {
    pedestrian.rotation = rotation;
    if (!limits.hit) {
        pedestrian.x = x;
        pedestrian.y = y;
    }
    if (safeZone())
        limits.elevated = true;
    else
        limits.elevated = false;
}

bool TrafficControl::get_screen(int index) {
    if (index == 0)
        return (whitescreen || failed || starttrialsscreen || startpracticescreen);
    else if (index == 1)
        return starttrialsscreen;
    else if (index == 2)
        return startpracticescreen;
    else if (index == 3)
        return whitescreen;
    else if (index == 4)
        return failed;
    else {
        qDebug() << "tc.get_screen() error";
        return false;
    }
}

bool TrafficControl::get_failed() {
    return failed;
}

QString TrafficControl::get_trials() {
    return trials[trial];
}

QString TrafficControl::get_start() {
    return startPos[trial];
}

int TrafficControl::get_display() {
    return 5 - int(elapsed[1]);
}

void TrafficControl::nexttrial() {
    if (trial >= numberOfTrials - 1) {
        data.writeData(trials[trial]);
        emit close_window();
    }
    else if (trial >= 0) {
        data.writeData(trials[trial], failed);
        for (int count = 0; count < 2; ++count)
            elapsed[count] = 0.0;
        carCounter = 0;
        for (int count = 0; count < numberOfCars; ++count)
            cars[count].stopCar();
    }
    trial++;
    if (!failed)
        qDebug() << trials[trial];
    else
        qDebug() << trials[trial - 1];

    whitescreen = true;
    if (popUps[trial] == starttrials && !failed) {
        popupscreen.set_display(starttrials);
        whitescreen = false;
        failed = false;
        starttrialsscreen = true;
        startpracticescreen = false;
    }
    else if (popUps[trial] == startpractice && !failed) {
        popupscreen.set_display(startpractice);
        whitescreen = false;
        failed = false;
        starttrialsscreen = false;
        startpracticescreen = true;
    }

    data.start = startPos[trial];
    if (startPos[trial] == "A")
        data.position = SIDE;
    else if (startPos[trial] == "B")
        data.position = REFUGE;
}

void TrafficControl::resettrial() {
    failed = true;
    nexttrial();
    trial--;
    data.start = startPos[trial];
    if (startPos[trial] == "A")
        data.position = SIDE;
    else if (startPos[trial] == "B")
        data.position = REFUGE;
    limits.hit = false;
    whitescreen = false;
    popupscreen.set_display(fail);
}

void TrafficControl::updateCar(int index, bool initial) { // updates car.point based upon its occupied members. done here so as to not have a path object in every instance of Car
    cars[index].update(initial);
    Point old;
    old = cars[index].point;

    if (cars[index].occupied.pathOn == INTO)
        cars[index].point = path.into[cars[index].occupied.road][cars[index].occupied.lane][cars[index].occupied.position];
    else if (cars[index].occupied.pathOn == TURNINTO)
        cars[index].point = path.turninto[cars[index].occupied.road][cars[index].occupied.lane][cars[index].occupied.position];
    else if (cars[index].occupied.pathOn == CIRCLE)
        cars[index].point = path.circle[cars[index].occupied.lane][cars[index].occupied.position];
    else if (cars[index].occupied.pathOn == TURNAWAY)
        cars[index].point = path.turnaway[cars[index].occupied.road][cars[index].occupied.lane][cars[index].occupied.position];
    else if (cars[index].occupied.pathOn == AWAY)
        cars[index].point = path.away[cars[index].occupied.road][cars[index].occupied.lane][cars[index].occupied.position];

    cars[index].set_distanceTravelled(magnitude(old, cars[index].point), true);

}

void TrafficControl::checkCar(int index) { // checks if car needs to slow down because of pedestrians or other cars and returns a followspeed[INTO]
    if (!safeZone() && pointCollision(cars[index], pedestrian)) {
        //qDebug() << "pedestrian hit";
        limits.hit = true;
    }

    if (((startPos[trial] == "A" && pedestrian.y < draw.LANE_WIDTH / -2.0) || (startPos[trial] == "B" && pedestrian.y > draw.LANE_WIDTH / -2.0))
        && !cars[index].passedp && cars[index].point.x > draw.get_walkwayDistance() + draw.MIDZONE_WIDTH / 2.0) {
        data.gap_chosen = gaps[trial][index + 1];
        data.time_bumper = time - data.time_starttrial;
        cars[index].passedp = true;
    }

    if (cars[5].passedp) {
        qDebug() << "fail";
        limits.hit = true;
    }
}

int TrafficControl::checkPedestrian() {
    if (fabs(pedestrian.y) < draw.MIDZONE_WIDTH / 2.0)
        return REFUGE;
    else if (fabs(pedestrian.y) < draw.LANE_WIDTH)
        return ROAD;
    else
        return SIDE;
}

bool TrafficControl::safeZone() { // determines whether pedestrian is in a safe zone, ie sidewalk, grass, or middle refuge
    Point p;
    p.x = draw.get_cornerCoordinate();
    p.y = p.x;
    Point origin;
    origin.x = 0.0;
    origin.y = 0.0;

    Point fabsPedestrian;
    fabsPedestrian.x = fabs(pedestrian.x);
    fabsPedestrian.y = fabs(pedestrian.y);

    if ((fabsPedestrian.x >= p.x && fabsPedestrian.y >= p.y - draw.get_cornerRadius()) || // corner rectangle
        (fabsPedestrian.y >= p.y && fabsPedestrian.x >= p.x - draw.get_cornerRadius()) || // corner rectangle
        magnitude(p, fabsPedestrian) <= draw.get_cornerRadius() || // corner circle
        (fabsPedestrian.x >= draw.get_midzoneLength(0) && fabsPedestrian.x < draw.get_midzoneLength(0) + draw.get_midzoneLength(1) && fabsPedestrian.y <= draw.MIDZONE_WIDTH / 2.0) || // 0 or 2 midzone ellipse
        (fabsPedestrian.y >= draw.get_midzoneLength(0) && fabsPedestrian.y < draw.get_midzoneLength(0) + draw.get_midzoneLength(1) && fabsPedestrian.x <= draw.MIDZONE_WIDTH / 2.0) || // 1 or 3 midzone ellipse
        magnitude(origin, pedestrian) <= draw.get_centerRadius()) // middle circle
        return true; 
    else
        return false;

}

double TrafficControl::magnitude(Point a, Point b) {
    return fabs(sqrt(pow(b.x - a.x, 2.0) + pow(b.y - a.y, 2.0)));
}

double TrafficControl::angle(Car a, Point b, bool sightadjusted) { // returns angle from Car a normal to the vector from Car a to Point b
    double vector;                                                 // sightadjusted is for changing the car's view when turning

    if (b.x - a.point.x == 0)
        vector = 90;
    else
        vector = atan((b.y - a.point.y) / (b.x - a.point.x)) * 180.0 / PI;

    if ((vector == 0 && b.x - a.point.x < 0) ||
        (vector > 0.0 && b.y - a.point.y < 0.0) ||
        (vector < 0.0 && b.y - a.point.y > 0.0)) // vector is changed into positive value
        vector += 180.0;
    else if (vector < 0.0 && b.y - a.point.y < 0.0)
        vector += 360.0;

    double carsight = a.point.rotation;
    if (carsight < 0.0)
        carsight += 360.0;

    if (sightadjusted && (a.occupied.pathOn == TURNINTO || a.occupied.pathOn == TURNAWAY))
        carsight -= 45.0;
    else if (sightadjusted && (a.occupied.pathOn == CIRCLE))
        carsight += 45.0;

    double diff = carsight - vector;
    if (fabs(diff) <= 180.0)
        return diff;
    else if (carsight > vector)
        return carsight - 360.0 - vector;
    else
        return 360.0 - vector + carsight; // return is between -180(counterclockwise) and 180(clockwise) from car normal
}

bool TrafficControl::pointCollision(Car a, Point p) { // determines whether Point p has collided with Car a
    double ang = fabs(angle(a, p, false));
    double mag = magnitude(a.point, p);
    for (double theta = 0.0, count = 0.0; count < 73.0; ++count, theta += PI / 180.0) { // atan(CAR_LENGTH/(CAR_WIDTH/2)) = 72 degrees
        if (mag <= fabs(draw.CAR_WIDTH / 2.0 / cos(theta)) && ang >= 90 + count) {
            return true;
        }
    }
    for (double theta = 72 * PI / 180.0, count = 72.0; count < 90.0; ++count, theta += PI / 180.0) {
        if (mag <= fabs(draw.CAR_LENGTH / sin(theta)) && ang >= 90 + 72 && ang <= 90 + count) {
            return true;
        }
    }
    if (mag <= draw.CAR_LENGTH && ang >= 179)
        return true;

    Point vector[4]; // defines vectors from the reference point of the car to each of its corners
    Point corners[4];

    vector[0].x = -sin(a.point.rotation * PI / 180.0) * draw.CAR_WIDTH / 2.0;
    vector[0].y = cos(a.point.rotation * PI / 180.0) * draw.CAR_WIDTH / 2.0;
    vector[1].x = -vector[0].x;
    vector[1].y = -vector[0].y;
    vector[2].x = vector[0].x - draw.CAR_LENGTH * cos(a.point.rotation * PI / 180.0);
    vector[2].y = vector[0].y + draw.CAR_LENGTH * sin(a.point.rotation * PI / 180.0);
    vector[3].x = vector[1].x - draw.CAR_LENGTH * cos(a.point.rotation * PI / 180.0);
    vector[3].y = vector[1].y + draw.CAR_LENGTH * sin(a.point.rotation * PI / 180.0);

    for (int count = 0; count < 4; ++count) {
        corners[count].x = a.point.x + vector[count].x;
        corners[count].y = a.point.y + vector[count].y;
    }

    for (int count = 0; count < 2; ++count) {
        if (magnitude(corners[count], p) < 0.5 || magnitude(corners[count + 2], p) < 0.2)
            return true;
    }

    return false;
}

void TrafficControl::setCarstart() {
    this->database_connect();
    database_get_vals();
    database_get_trafficenable();

    if (speeds[trial] != 0) {
        double t = path.distance_tostart / (speeds[trial] * path.DISTANCE / 0.02);
        cars[0].newCar(speeds[trial]);

        while (elapsed[1] <= t) {
            if (elapsed[0] >= gaps[trial][carCounter]) {
                elapsed[0] = 0.0;
                carCounter++;
                cars[carCounter].newCar(speeds[trial]);
            }
            for (int count = 0; count < numberOfCars; ++count) {
                if (cars[count].get_onTrack()) {
                    updateCar(count);
                    checkCar(count);
                }
                else
                    cars[count].point = 0.0;
            }
            elapsed[1] += 0.02;
            elapsed[0] += 0.02;
        }
        elapsed[1] = 0.0;
        for (int count = 0; count < numberOfCars; ++count)
            if (cars[count].get_onTrack())
                draw.car(cars[count]);
    }
    data.time_starttrial = time;
}

void TrafficControl::clicked() {
    failed = false;
    starttrialsscreen = false;
    startpracticescreen = false;
    whitescreen = true;
}

void TrafficControl::database_connect()
{
}

void TrafficControl::database_get_vals()
{
    if (db.isOpen())
    {
        QString readStatement = ("SELECT vehicle_quantity FROM loadconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                numberOfCars = qry.value(0).toInt();
                qDebug() << "Number of Cars:" << numberOfCars;
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }
    }
    else
    {
        qDebug() << "TrafficControl failed to open database connection to pull data.";
    }
}

void TrafficControl::database_get_trafficenable()
{
    int trafficEnable;
    if (db.isOpen())
    {
        QString readStatement = ("SELECT vehicle_traffic FROM loadconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                trafficEnable = qry.value(0).toInt();
                //qDebug() << "Number of Cars:" << numberOfCars;
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }
    }
    else
    {
        qDebug() << "TrafficControl failed to open database connection to pull data.";
    }
    if (trafficEnable == 0){
        numberOfCars = 0;
    }
}

void TrafficControl::database_get_traffic_intensity()
{
    int trafficEnable;
    if (db.isOpen())
    {
        QString readStatement = ("SELECT traffic_intensity FROM loadconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                trafficIntensity = qry.value(0).toInt();
                //qDebug() << "Number of Cars:" << numberOfCars;
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }
    }
    else
    {
        qDebug() << "TrafficControl failed to open database connection to pull data.";
    }
}
