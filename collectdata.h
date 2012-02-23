#ifndef COLLECTDATA_H
#define COLLECTDATA_H

#include "math.h"
#include <QWidget>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include "nxt.h"
#include "legoThread.h"
#include "vuzixthread.h"
#include "arduino.h"

#include <QDebug>

#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <winbase.h>
#include "rcx21.h"

class CollectData : public QWidget
{
    /* interfacing class that handles the second thread legoThread for the NXT and contains
       timer that updates glWidget*/
    Q_OBJECT

public:
    explicit CollectData(QWidget *parent = 0);

    QTime time; // used for finding the time elaspsed between calling the nxt to send an appropriate NXT motor speed
    LegoThread legoThread; // collects nxt data
    VuzixThread vuzikThread; //collects data from vuzix headset
    ArduinoThread arduinoThread; //collects data from arduino


signals:
    void updateScene(); // emitted to call paintGL() in glwidget

public slots:
    void update(); // function called from timer that calls updateScene and starts legothread
    void set(double); // sets data for legothread

private:
    QTimer updater; // timeout() signal connected to UpdateRotation() which updates NXT values
    bool started; // initially false, turned true in set(int). Prevents xTrans, yTrans, and zTrans updates in GLWidget
    bool threading; // used for only starting legoThread once
    const static int timer_interval = 20; // number of msecs updateScene() is called
};

#endif // COLLECTDATA_H
