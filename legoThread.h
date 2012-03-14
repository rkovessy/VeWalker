#ifndef LEGOTHREAD_H
#define LEGOTHREAD_H

#include <stdio.h>
#include "cv.h"
#include "highgui.h"
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
#include "iweardrv.h"
#include "serialportinfo.h"
#include "serialport.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlDriver>
#include <QMessageBox>

class LegoThread : public QThread
{
    /* provides secondary thread for NXT updates. Sends updates as speeds or first order values
       instead of positions or zero order values. Done this way so that updates can occur every time
       the glWidget is updated instead of everytime the NXT is updated*/
    Q_OBJECT

public:
    LegoThread();
    ~LegoThread();
    void run();
    IplImage* GetThresholdedImage(IplImage* img);
    IplImage* GetBlurredImage(IplImage* img);
    IplImage* GetResizedImage(IplImage* img);
    IplImage* GetDilatedImage(IplImage* img);
    IplImage* GetCroppedImage(IplImage* img);
    void database_connect();
    void database_get_vals();
    CvCapture* capture;
    int id;
    double PI;

signals:
    void sendCameraValues(int posX1, int posX2, int posY1, int posY2);
    void sendPotRotation(long potRotation);

public slots:
    void set(double height, int timer); // sets height info and allows data to be collected
    void UpdateCamera();
    void UpdatePotRotation();
    //void UpdateTilt();//updates the tilt form accelerometer


private:
    QSqlDatabase db; //Database variables
    QEventLoop eventloop;
    QTime time; // used for determining time elapsed between motor readings to calculate speed
    double msec; // time between motor values
    double timer_interval;
    QString colorSelected;

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

    double angleRads; //Angle of bank in rads
    double angleDegrees; //Angle of bank in degrees
    double oppositeSide; //Y distance between points;
    double adjacentSide; //X distance between points;

    bool left; // true when left foot on ground, false when right is
    bool stepped; // true when bool left has changed

    const static int port = 3; // port for the bluetooth connection with the NXT

    double moment101;
    double moment011;
    double moment102;
    double moment012;
    double area1;
    double area2;
    int posX1;
    int posY1;
    int posX2;
    int posY2;
    CvPoint moment_center1;
    CvPoint moment_center2;
    CvScalar min_color1;
    CvScalar max_color1;
    CvScalar min_color2;
    CvScalar max_color2;

    double HTyaw2;
    double HTpitch2;
    double HTroll2;

    long HTyaw;
    long HTpitch;
    long HTroll;

    long potRotation;
};

#endif
