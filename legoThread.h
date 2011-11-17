#ifndef LEGOTHREAD_H
#define LEGOTHREAD_H

#include <QObject>
#include <QThread>
#include <QEventLoop>

#include "math.h"
#include <QWidget>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include "nxt.h"

#include <QDebug>

#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <winbase.h>
#include "rcx21.h"

class LegoThread : public QThread
{
    /* provides secondary thread for NXT updates. Sends updates as speeds or first order values
       instead of positions or zero order values. Done this way so that updates can occur every time
       the glWidget is updated instead of everytime the NXT is updated*/
    Q_OBJECT

public:
    LegoThread();
    void run();
    int id;

    double PI;

signals:
    void sendMotor(double magnitude, bool stepped, double zTrans); //sends motor data to glwidget setTranslation(double, double) through mywindow
    void sendCompass(double angle); // sends compass data to glwidget rotation(double)

public slots:
    void set(double height, int timer); // sets height info and allows data to be collected
    void UpdateRotation(); //calculates yTrans speed and zTrans and sends data via sendMotor(...)
    void UpdateRoll(); //updates Roll from compass
    //void UpdateTilt();//updates the tilt form accelerometer


private:
    QEventLoop eventloop;
    QTime time; // used for determining time elapsed between motor readings to calculate speed
    double msec; // time between motor values
    double timer_interval;

    int rValueNXT;//new motor value
    int lastrValueNXT; // last motor value
    double magnitude; // speed at which motor is rotating
    double height; // converted max height of person
    double variance; // subtracted from NXT value to get zero when angle is zero
    bool startupdating; // initially false, turned true in set(int). Prevents xTrans, yTrans, and zTrans updates in GLWidget


    double roll, firstroll; // roll values of compass
    int tiltx, tilty, tiltz; // tilt values of accelerometer
    int counter; // used for determining when to updateRoll()
    double anglediff; // speed of compass rotation

    double zTrans; // z coordinate of pedestrian

    bool left; // true when left foot on ground, false when right is
    bool stepped; // true when bool left has changed

    const static int port = 6; // port for the bluetooth connection with the NXT
};

#endif
