#ifndef ARDUINO_H
#define ARDUINO_H

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

#include "serialportinfo.h"
#include "serialport.h"


class SerialPort;
class QTimer;

class ArduinoThread : public QThread
{
    Q_OBJECT
public:
    explicit ArduinoThread(QObject *parent = 0);
    void output();
    ~ArduinoThread();
    void run();

signals:
    void sendPotRotation(long potRotation);

public slots:
    void set(double height, int timer); // sets height info and allows data to be collected
    void UpdateArduino();

private:
    QEventLoop eventloop;
    QTime time; // used for determining time elapsed between motor readings to calculate speed
    double msec; // time between motor values
    double timer_interval;
    bool startupdating; // initially false, turned true in set(int). Prevents xTrans, yTrans, and zTrans updates in GLWidget

    long potRotation;
    SerialPort *m_port;
    QTimer *m_timer;

    bool m_rts;
    bool m_dtr;


};

#endif // ARDUINO_H
