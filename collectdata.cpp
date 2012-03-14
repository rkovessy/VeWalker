#include "collectdata.h"

CollectData::CollectData(QWidget *parent) :
    QWidget(parent)
{
   //qDebug() << "collectData Constructor called";
   threading = false;
   started = false;

   updater.start(20); // connected to update()
   connect(&updater, SIGNAL(timeout()), this, SLOT(update()));
}

void CollectData::update() {
    if (started) {
        if (!threading) {
            legoThread.start();
            vuzikThread.start();
           // arduinoThread.start();
            threading = true;
        }
        emit updateScene();
    }
}

void CollectData::set(double a) {
    legoThread.set(a,timer_interval);
    vuzikThread.set(a, timer_interval);
    //arduinoThread.set(a, timer_interval);
    started = true;
}
