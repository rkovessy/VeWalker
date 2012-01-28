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
        time.restart();
        UpdateHTracking();

    } while (!flag);
    exec();
}

void VuzixThread::set(double a, int t) {
    timer_interval = double(t);
    startupdating = true; // yTrans and zTrans can now be changed
    time.start();
}

void VuzixThread::UpdateHTracking()
{

    DWORD trk_res=IWRGetTracking(&HTyaw,&HTpitch, &HTroll);

    emit sendHTrackerValues(HTyaw, HTpitch, HTroll);


}
