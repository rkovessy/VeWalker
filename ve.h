#ifndef VE_H
#define VE_H

#include <QMainWindow>
#include <QTime>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QString>
#include "mywindow.h"
#include "collectdata.h"

class VE : public QWidget
{
    /* main class for VE environment, contains the two main halves of the program, collectdata,
       which is responsible for the NXT and mywindow which contains everything else.
       If you want to get rid of demographics class it would be easy to set this after startwindow
       instead of demographics
    */
    Q_OBJECT
public:
    VE();
    void start(int pid); // sets up collectdata and sets up/shows mywindow

    QTime clock; // used for setting up randomness with srand(). Only randomness is location of trees, and colour/dimensions of cars

    MyWindow mywindow;
    CollectData collectdata;

    const static double height = 6.0; // 6.0 for 6'
};

#endif // VE_H
