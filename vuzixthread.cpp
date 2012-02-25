#include "vuzixthread.h"

VuzixThread::VuzixThread(QObject *parent) :
    QThread(parent)
{

    if (IWROpenTracker() == ERROR_SUCCESS) {
        qDebug() << "Connected to headset" << endl;
        if (IWRSetFilterState)
            IWRSetFilterState(TRUE);
    }

    IWRZeroSet();

    HTyaw = 0;
    HTpitch = 0;
    HTroll = 0;
}

void VuzixThread::run()
{
    qDebug("vuzikThread is running!");
    bool flag = false;
   do {
        msec = double(time.elapsed());
        if (msec >= 40) {
            UpdateHTracking();
            time.restart();
         }
    } while (!flag);
    exec();
}

void VuzixThread::set(double a, int t) {
    printf("Timer interval: %i\n",t);
    timer_interval = double(40);
    startupdating = true; // yTrans and zTrans can now be changed
    time.start();
}

void VuzixThread::UpdateHTracking()
{

    DWORD trk_res=IWRGetTracking(&HTyaw,&HTpitch, &HTroll);

    //printf("yaw [%li] pitch [%li] roll [%li] \n", HTyaw, HTpitch, HTroll);
    emit sendHTrackerValues(HTyaw, HTpitch, HTroll);


}
