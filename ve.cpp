#include "ve.h"

VE::VE()
{
    collectdata.connect(&collectdata, SIGNAL(updateScene()), &mywindow, SLOT(updateScene()));
    //collectdata.connect(&collectdata.legoThread, SIGNAL(sendCameraValues(int,int,int,int)), &mywindow, SLOT(updateCameraValues(int,int,int,int)));
    collectdata.connect(&collectdata.vuzikThread, SIGNAL(sendHTrackerValues(long,long,long)), &mywindow, SLOT(updateHTrackerValues(long,long,long)));
    collectdata.connect(&collectdata.arduinoThread, SIGNAL(sendPotRotation(long)), &mywindow, SLOT(updatePotRotation(long)));
//    collectdata.setMouseTracking(true);
    mywindow.connect(&mywindow.glWidget->tc, SIGNAL(close_window()), qApp, SLOT(quit()));
//    mywindow.setMouseTracking(true);
}

void VE::start(int pid) {
    srand(clock.currentTime().msec());
    collectdata.set(height);
    mywindow.show();
    mywindow.set(pid);
    //cvNamedWindow("Dilated");
    //cvNamedWindow("Thresholded");
    //cvNamedWindow("Blurred");
    cvNamedWindow("Raw Video");
    cvNamedWindow("Processed Video");
}
