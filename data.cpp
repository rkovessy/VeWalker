#include "data.h"

Data::Data()
{
}

//Configuration settings - basically setting up the trials
void Data::read_specs()
{
    connect_to_database();
    get_numberOfTrials();
    //numberOfTrials=60;
    get_mode();
//    get_numberOfCars(); //VehicleQauntitySwitching
//    get_trafficEnable();
    numberOfCars = 5;
    get_trafficIntensity();
    get_unsafeCrossing();
    generate_interarrival_time();
    get_participantId();
    get_referenceId();

    //Generate arrays with trial parameters based on selections for trial mode
    if (demoMode==false)
    {
        for (int count = 0; count < numberOfTrials; ++count)
        {
            speeds[count] = 50;
            startPos[count] = "A";
            popUps[count] = "none";
        }
    }
    //Generate arrays of random parameters within bounds if demo mode was selected
    else
    {
        for (int count = 0; count < numberOfTrials; ++count)
        {
            //numberOfCars = rand() % 20 + 1; //Have between 1 and 20 vehicles per trial
            speeds[count] = rand() % 50 + 20;//Have vehicles move at random speed between 20 and 70
            startPos[count] = "A"; //Always start at A
            popUps[count] = "none"; //No popups between trials
        }
    }

}

void Data::updateinfo(int p) {
    if (start == "A") {
        if (position == SIDE && p == ROAD) {
            time_step = time - time_starttrial;
            time_latency = time_step - time_bumper;
            step = true;
        }
        else if (position == ROAD && p == REFUGE) {
            time_arrive = time - time_starttrial;
            time_crossing = time_arrive - time_step;
        }
    }
    else if (start == "B") {
        if (position == REFUGE && p == ROAD) {
            time_step = time - time_starttrial;
            time_latency = time_step - time_bumper;
            step = true;
        }
        else if (position == ROAD && p == SIDE) {
            time_arrive = time - time_starttrial;
            time_crossing = time_arrive - time_step;
        }
    }
    position = p;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DATA

void Data::writeIntro(QString f) {
//    filename[DATA] = f;
//    if (!QDir("Data").exists())
//        QDir().mkdir("Data");

//    file[DATA].setFileName(filename[DATA]);
//    text[DATA].setDevice(&file[DATA]);
//    file[DATA].open(QIODevice::WriteOnly | QIODevice::Text);
//    text[DATA].setFieldWidth(20);
//    text[DATA] <<  "trial" << "start" << "time_starttrial" << "time_bumper" << "time_step" << "time_latency" << "time_arrive" << "time_crossing" << "steps" << "gap_chosen" << endl;
}

void Data::writeData(QString trial, bool failed) {


    if (db.isOpen())
    {
        QString inStatementPerformance = "INSERT INTO performancedata (reference_id, participant_id, trial, start, time_starttrial, time_bumper, time_step, time_latency, time_crossing, time_arrive, gap_chosen, steps) VALUES (:reference_id, :participant_id, :trial, :start, :time_starttrial, :time_bumper, :time_step, :time_latency, :time_crossing, :time_arrive, :gap_chosen, :steps);";

        QSqlQuery qryPerformance(db);

        qryPerformance.prepare(inStatementPerformance);

        qryPerformance.bindValue(":reference_id", referenceId);

        qryPerformance.bindValue(":participant_id", participantId);

        qryPerformance.bindValue(":trial", trial);

        qryPerformance.bindValue(":start", start);

        qryPerformance.bindValue(":time_starttrial", time_starttrial);

        qryPerformance.bindValue(":time_bumper", time_bumper);

        qryPerformance.bindValue(":time_step", time_step);

        qryPerformance.bindValue(":time_latency", time_latency);

        qryPerformance.bindValue(":time_crossing", time_crossing);

        qryPerformance.bindValue(":time_arrive", time_arrive);

        qryPerformance.bindValue(":gap_chosen", gap_chosen);

        qryPerformance.bindValue(":steps", steps);

        qryPerformance.exec();
    }
    else
    {
        if (db.lastError().isValid());
        qDebug() << db.lastError();
        qDebug() << "Data failed to open database connection to insert data.";
    }

        time_bumper = 0.0;
        time_step = 0.0;
        time_latency = 0.0;
        time_crossing = 0.0;
        time_arrive = 0.0;
        gap_chosen = 0;
        steps = 0;
        step = false;

//    if (failed)
//        trial.prepend("failed_");
//    text[DATA] <<  trial << start << time_starttrial << time_bumper << time_step << time_latency << time_arrive << time_crossing << steps << gap_chosen << endl;

//    time_bumper = 0.0;
//    time_step = 0.0;
//    time_latency = 0.0;
//    time_crossing = 0.0;
//    time_arrive = 0.0;
//    gap_chosen = 0;
//    steps = 0;

//    step = false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PEDESTRIAN

//void Data::setPedestrian(QString f) {
//    filename[PEDESTRIAN] = f;
//    file[PEDESTRIAN].setFileName(filename[PEDESTRIAN]);
//    text[PEDESTRIAN].setDevice(&file[PEDESTRIAN]);
//    file[PEDESTRIAN].open(QIODevice::WriteOnly | QIODevice::Text);
//    text[PEDESTRIAN].setFieldWidth(10);
//    text[PEDESTRIAN] << "trial" << "time" << "xTrans" << "yTrans" << "zTrans" << "xRot" << "yRot" << "zRot" << endl;
//}

//void Data::writePedestrian(QString trial, double xTrans, double yTrans, double zTrans, double xRot, double yRot, double zRot) {
//    text[PEDESTRIAN] << trial << time << xTrans << yTrans << zTrans << xRot << yRot << zRot << endl;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CARS

QString Data::setCars(int pid)
{
//    filename[CARS] = "Cars";
//    if (!QDir(filename[CARS]).exists())
//        QDir().mkdir(filename[CARS]);
//    filename[CARS].append("/P");

//    QString id = QString::number(pid);
//    if (pid < 10)
//        id.prepend("0");
//    filename[CARS].append(id + "_Cars.txt");
//    file[CARS].setFileName(filename[CARS]);
//    text[CARS].setDevice(&file[CARS]);
//    file[CARS].open(QIODevice::WriteOnly | QIODevice::Text);
//    text[CARS].setFieldWidth(10);

    return "0";
}

void Data::writeCars_trial(QString trial, double time, bool trials, bool practice, bool white, bool failed)
{
//    if (trials)
//        text[CARS] << "starttrials_" + trial;
//    else if (practice)
//        text[CARS] << "startpractice_" + trial;
//    else if (white)
//        text[CARS] << "white_" + trial;
//    else if (failed)
//        text[CARS] << "fail_" + trial;
//    else
//        text[CARS] << trial;
//    text[CARS] << time;
}

void Data::writeCars(double a, double b, double c)
{
//    text[CARS] << a << b << c << " ";
}

void Data::writeCars_endl()
{
//    text[CARS] << endl;
}

void Data::get_numberOfTrials()
{
    if (db.isOpen())
    {
        QString readStatement = ("SELECT trial_quantity FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                numberOfTrials = qry.value(0).toInt();
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }

    }
    else
    {
        qDebug() << "Data failed to open database connection to pull data.";
    }
}

void Data::get_mode()
{
    QString modeConfigured;
    if (db.isOpen())
    {
        QString readStatement = ("SELECT mode FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                modeConfigured = qry.value(0).toString();
            }
        if (QString::compare("demo", modeConfigured, Qt::CaseInsensitive)==0)
            demoMode = true;
        else
            demoMode = false;
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }

    }
    else
    {
        qDebug() << "Data failed to open database connection to pull data.";
    }
}

void Data::get_trafficIntensity()
{
    if (db.isOpen())
    {
        QString readStatement = ("SELECT traffic_intensity FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                trafficIntensity = qry.value(0).toDouble();
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }

    }
    else
    {
        qDebug() << "Data failed to open database connection to pull data.";
    }
}

void Data::connect_to_database()
{
    db = QSqlDatabase::addDatabase("QPSQL", "dataConnect");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("abc123");
    db.setDatabaseName("configDb");
    db.open();
}


//Generate the interarrival times based on a poisson process
void Data::generate_interarrival_time()
{
    //If demo mode is selected generate random interarrival times for each trial based on poisson distributions
    if (demoMode == true)
    {
        int demoTrafficIntensity; //Initialize new intensity for random values to be generated
        poisson generateArrivalTimes; //Create poisson class
        //Generate different interarrival times for each trial based on random interarrival time between 1 and 20
        for (int count = 0; count < numberOfTrials; ++count)
        {
            demoTrafficIntensity = rand() % 20 + 1;
            for (int i=0;i<numberOfCars;i++){
                do{
                    //generate gap times to 5 significant digits, but don't allow overlap of vehicles (ie. arrival time>.5)
                    gaps[count][i] = generateArrivalTimes.createintervals(demoTrafficIntensity);
                    gaps[count][i] += generateArrivalTimes.createintervals(demoTrafficIntensity)/10;
                    gaps[count][i] += generateArrivalTimes.createintervals(demoTrafficIntensity)/100;
                    gaps[count][i] += generateArrivalTimes.createintervals(demoTrafficIntensity)/1000;
                    gaps[count][i] += generateArrivalTimes.createintervals(demoTrafficIntensity)/10000;
                }while(gaps[count][i] <= .5);
            }
        }
    }

    //If there is no unsafe crossing enabled and demo mode is not enabled generate based on a poisson distribution with
    //interarrival time selected
    else if (unsafeCrossingEnable == false && demoMode == false)
    {
        poisson generateArrivalTimes; //Create poisson class
        //Generate different interarrival times for every car in every trial and stroe in array
        for (int count = 0; count < numberOfTrials; ++count)
        {
            for (int i=0;i<numberOfCars;i++){
                do{
                    //generate gap times to 5 significant digits, but don't allow overlap of vehicles (ie. arrival time>.5)
                    gaps[count][i] = generateArrivalTimes.createintervals(trafficIntensity);
                    gaps[count][i] += generateArrivalTimes.createintervals(trafficIntensity)/10;
                    gaps[count][i] += generateArrivalTimes.createintervals(trafficIntensity)/100;
                    gaps[count][i] += generateArrivalTimes.createintervals(trafficIntensity)/1000;
                    gaps[count][i] += generateArrivalTimes.createintervals(trafficIntensity)/10000;
                }while(gaps[count][i] <= .5);
            }
        }
    }
    //If unsafe crossing selected, generate array of constant unsafe interarrival time for all cars and all trials
    else
    {
        for (int count = 0; count < numberOfTrials; ++count)
        {
            for (int i=0;i<numberOfCars;i++){
                    gaps[count][i] = unsafeCrossingInterarrival;
            }
        }

    }
}


//Database call to determien if traffic is disabled
void Data::get_trafficEnable()
{
    int trafficEnable;
    if (db.isOpen())
    {
        QString readStatement = ("SELECT vehicle_traffic FROM trialconfig order by reference_id desc limit 1");
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
        qDebug() << "Data failed to open database connection to pull data.";
    }
    if (trafficEnable == 0){
        numberOfCars = 0;
    }
}


//Database call to get number of cars selected
void Data::get_numberOfCars()
{
    if (db.isOpen())
    {
        QString readStatement = ("SELECT vehicle_quantity FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                numberOfCars = qry.value(0).toInt();
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
        qDebug() << "Data failed to open database connection to pull data.";
    }
}


//Database call to determien if unsafe crossing was selected
void Data::get_unsafeCrossing()
{
    int unsafeCrossingInt;
    if (db.isOpen())
    {
        QString readStatement = ("SELECT unsafe_crossing FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                unsafeCrossingInt = qry.value(0).toInt();
            }
            if (unsafeCrossingInt == 1)
                unsafeCrossingEnable = true;
            else
                unsafeCrossingEnable = false;
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }

    }
    else
    {
        qDebug() << "Data failed to open database connection to pull data.";
    }
}

//Database call for getting unique reference ID for current run of application
void Data::get_referenceId()
{
    if (db.isOpen())
    {
        QString readStatement = ("SELECT reference_id FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                referenceId = qry.value(0).toInt();
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }
    }
    else
    {
        qDebug() << "Data failed to open database connection to pull data.";
    }
}

//Database call for accessing participant id number
void Data::get_participantId()
{
    if (db.isOpen())
    {
        QString readStatement = ("SELECT participant_id FROM participantdata order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                participantId = qry.value(0).toInt();
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }
    }
    else
    {
        qDebug() << "Data failed to open database connection to pull data.";
    }
}
