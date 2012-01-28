#ifndef VUZIXTHREAD_H
#define VUZIXTHREAD_H

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

class VuzixThread : public QThread
{
    Q_OBJECT
public:
    explicit VuzixThread(QObject *parent = 0);
    void run();

signals:
    void sendHTrackerValues(long HTyaw, long HTpitch, long HTroll);

public slots:
    void set(double height, int timer); // sets height info and allows data to be collected
    void UpdateHTracking();

private:
    QEventLoop eventloop;
    QTime time; // used for determining time elapsed between motor readings to calculate speed
    double msec; // time between motor values
    double timer_interval;
    bool startupdating; // initially false, turned true in set(int). Prevents xTrans, yTrans, and zTrans updates in GLWidget

    double HTyaw2;
    double HTpitch2;
    double HTroll2;

    long HTyaw;
    long HTpitch;
    long HTroll;

};

#endif // VUZIXTHREAD_H
