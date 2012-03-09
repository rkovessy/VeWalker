#include "ve.h"

VE::VE()
{
    //qDebug() << "constructor was called";
}

void VE::start(int pid) {
    collectdata.connect(&collectdata.legoThread, SIGNAL(sendCameraValues(int,int,int,int)), &mywindow, SLOT(updateCameraValues(int,int,int,int)));
    collectdata.connect(&collectdata, SIGNAL(updateScene()), &mywindow, SLOT(updateScene()));
    //collectdata.connect(&collectdata.legoThread, SIGNAL(sendMotor(double,bool,double)), &mywindow, SLOT(updateMotor(double,bool,double))); // doubles are motor speed and zTrans
    //collectdata.connect(&collectdata.legoThread, SIGNAL(sendCompass(double)), &mywindow, SLOT(updateCompass(double)));
    collectdata.connect(&collectdata.vuzikThread, SIGNAL(sendHTrackerValues(long,long,long)), &mywindow, SLOT(updateHTrackerValues(long,long,long)));
    //collectdata.setMouseTracking(true);
    mywindow.connect(&mywindow.glWidget->tc, SIGNAL(close_window()), qApp, SLOT(quit()));

    srand(clock.currentTime().msec());
    collectdata.set(height);
    mywindow.show();
    mywindow.set(pid);
    //cvNamedWindow("Raw Video");
    //cvNamedWindow("Processed Video");
}
