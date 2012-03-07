#ifndef CALIBRATEROTATION_H
#define CALIBRATEROTATION_H

#include <QWidget>
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

#include "collectdata.h"
#include "nxt.h"
#include "legoThread.h"
#include "vuzixthread.h"
#include "arduino.h"
#include "ui_calibraterotation.h"

namespace Ui {
class calibrateRotation;
}

class calibrateRotation : public QWidget
{
    Q_OBJECT

public slots:
    void calibrate(int leftRightIndex);

private slots:
    void on_rightExtentCapture_clicked();
    void on_leftExtentCapture_clicked();
    void on_completeButton_clicked();
    void on_cancelButton_clicked();
    void on_neonPink_clicked();
    void on_neonGreen_clicked();
    void on_neonOrange_clicked();

public:
    explicit calibrateRotation(QWidget *parent = 0);
    ~calibrateRotation();
    IplImage* GetThresholdedImage(IplImage* img);
    IplImage* GetBlurredImage(IplImage* img);
    IplImage* GetResizedImage(IplImage* img);
    IplImage* GetDilatedImage(IplImage* img);
    CvCapture* capture;

//signals:
//    void clicked();

private:
    Ui::calibrateRotation *ui;
    double angleRads; //Angle of bank in rads
    double angleDegrees; //Angle of bank in degrees
    double oppositeSide; //Y distance between points;
    double adjacentSide; //X distance between points;

    double moment101;
    double moment011;
    double moment102;
    double moment012;
    double area1;
    double area2;
    double alphaLeftActual;
    double alphaRightActual;
    int posX1;
    int posY1;
    int posX2;
    int posY2;
    bool neonGreen;
    bool neonOrange;
    bool neonPink;
    CvPoint moment_center1;
    CvPoint moment_center2;
    CvScalar min_color1;
    CvScalar max_color1;
};

#endif // CALIBRATEROTATION_H
