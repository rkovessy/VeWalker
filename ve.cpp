#include "ve.h"

VE::VE()
{
    collectdata.connect(&collectdata, SIGNAL(updateScene()), &mywindow, SLOT(updateScene()));
    collectdata.connect(&collectdata.legoThread, SIGNAL(sendMotor(double,bool,double)), &mywindow, SLOT(updateMotor(double,bool,double))); // doubles are motor speed and zTrans
    collectdata.connect(&collectdata.legoThread, SIGNAL(sendCompass(double)), &mywindow, SLOT(updateCompass(double)));
    collectdata.setMouseTracking(true);
    mywindow.connect(&mywindow.glWidget->tc, SIGNAL(close_window()), qApp, SLOT(quit()));
    mywindow.setMouseTracking(true);
}

void VE::start(int pid) {
    srand(clock.currentTime().msec());
    collectdata.set(height);
    mywindow.show();
    mywindow.set(pid);
}
