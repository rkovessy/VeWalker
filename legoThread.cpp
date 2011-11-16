#include "legoThread.h"

//Connection *connection = new Bluetooth();
//Brick *nxt = new Brick(connection);
//Motor *motor = new Motor(OUT_A, connection);
//Tilt *tilt = new Tilt (IN_1, connection, 0x02);
//Compass *compass = new Compass (IN_1, connection, 40, 0x02);
//Xyz_position *result = new Xyz_position();

LegoThread::LegoThread() {
    PI = (asin(0.5) * 6.0);
    counter = 0;
    magnitude = 0.0;
    lastrValueNXT = 0.0;
//    connection->connect(port); // '3' is the port the NXT is connected to via bluetooth. Different for every laptop
    qDebug() << "Connected to NXT" << endl;
}

void LegoThread::run()
{
    qDebug("LegoThread is running!");
    /*bool flag = false;
    do {
        time.restart();
        //UpdateRoll();
        UpdateRotation();
        msec = double(time.elapsed());
        if (msec == 0.0) {
            qDebug() << "msec == 0, divided by 0";
            emit sendMotor(magnitude * timer_interval, false, zTrans); // sends data to GLWidget and updates graphics
        }
        else
            emit sendMotor(magnitude * timer_interval / msec, stepped, zTrans); // sends data to GLWidget and updates graphics
        //counter++;
    } while (!flag);

    exec();*/
}

void LegoThread::set(double a, int t) {
    timer_interval = double(t);
    double tmp = a / 2.0 + 2.0; // converts to feet from index of heights, ie 2' = 0, 2'6" = 1...
    height = tmp / 10.0; // converts to pixels
//    variance = motor->get_rotation(); // person must be standing still at start to get variance correct
    lastrValueNXT = 0;
    //firstroll = double(compass->read());
    emit sendMotor(0.0, false, height); // sends data to GLWidget and updates graphics
    startupdating = true; // yTrans and zTrans can now be changed
    time.start();
}

void LegoThread::UpdateRotation()
{
 //   rValueNXT = motor->get_rotation() - variance; // gets motors current position
    if (startupdating) {
        magnitude = abs(rValueNXT - lastrValueNXT) * PI / 180.0 * 0.3; // pi/180 to convert to rad, .3 = radius of walker, d = rtheta
        zTrans = height / 30.0 * sin(PI * (rValueNXT + 20) / 40) + height + height / 30;
    }
    if (rValueNXT > lastrValueNXT && left) {
        stepped = true;
        left = false;
    }
    else if (rValueNXT < lastrValueNXT && !left) {
        stepped = true;
        left = true;
    }
    else
        stepped = false;
    lastrValueNXT = rValueNXT; // present rValueNXT becomes the last one for the next UpdateRotation()
}

void LegoThread::UpdateRoll()// the left to right motion of the head
{
    if (counter % 2 == 0)
        //roll = double(compass->read());

        anglediff = roll - firstroll;
        if (fabs(anglediff) <= 180)
            anglediff = anglediff;
        else if (roll > firstroll)
            anglediff = roll - 360.0 - firstroll;
        else
            anglediff = 360.0 - firstroll + roll;

        anglediff /= 100;
    if (fabs(anglediff) < 0.15)
        anglediff = 0.0;
    emit sendCompass(anglediff);
}
/*
void LegoThread::UpdateTilt()
{
    if (counter % 20 == 0) {
    tilt->read(*result);
    tiltx = result->x;
    tilty = result->y;
    tiltz = result->z;
    qDebug()<< "x =" << tiltx << "y=" << tilty << "z=" << tiltz;
}
}*/
