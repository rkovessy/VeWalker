#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLayout>
#include <QEvent>
#include <QSlider>
#include <QMouseEvent>
#include <QtGui>

#include <QDebug>
#include "glwidget.h"
#include <QWidgetAction>
#include "iweardrv.h"

class GLWidget;

class MyWindow : public QWidget
{
    /* class that handles glWidget. Most connect() calls intended for glWidget come through
       this class because of the type of class glWidget is I think. Also its here where the
       window size is defined
    */
     Q_OBJECT

public:
     MyWindow();
     GLWidget *glWidget;

protected:
     void keyPressEvent( QKeyEvent *e );
     void keyReleaseEvent( QKeyEvent *e );
     void mouseMoveEvent( QMouseEvent *e );

public slots:
     void updateMotor(double magnitude, bool stepped, double zTrans); // connected to sendMotor(...) signal from legothread, updates GLWidget
     void updateCameraValues(int x1, int x2, int y1, int y2);
     void updateHTrackerValues(long HTyaw, long HTpitch, long HTroll);
     void set(int pid); // sets up some recording stuff and the initial pedestrian location
     void set_replay();
     void updateCompass(double); // updates compass speed and sends to glWidget rotation(double)
     void updateScene(); // calls glwidget.paintGL indirectly

private:
    void settingLayout(); // sets up physical dimensions of window
    bool replay;

    static const int window_width = 1280; // pixel width of screen
    static const int window_height = 720; // pixel height of screen
    int previousXPos;
    int previousYPos;
 };

 #endif
