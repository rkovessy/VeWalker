#ifndef CALIBRATECAM_H
#define CALIBRATECAM_H

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


class calibratecam : public QThread
{
    Q_OBJECT

public:
    calibratecam();

signals:

public slots:

private:

};

#endif
