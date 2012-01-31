 #ifndef GLWIDGET_H
 #define GLWIDGET_H

 #include <QtGui>
 #include <QtOpenGL>
 #include <windows.h>
 #include <GL\gl.h>
 #include <GL\glu.h>
 #include <stdio.h>
 #include <math.h>
 #include <QDebug>
 #include <QGLWidget>
 #include <QString>
 #include <QImage>
 #include <qgl.h>
 #include <QFile>
 #include <QTextStream>
 #include <QLCDNumber>

 #include "draw.h"
 #include "path.h"
 #include "trafficcontrol.h"
#include "arduino.h"

 class GLWidget : public QGLWidget
 {
     /* contains traffic control and main hub for opengl updating and set up code
     */
     Q_OBJECT

 public:
     GLWidget(QWidget *parent = 0);
     ~GLWidget();
     TrafficControl tc; // manages cars
     ArduinoThread arduinoThread; //collects data from arduino data logger

     void setPedestrian(double x, double y, double mid); // sets pedestrian x and y
     void set_recording();
     void set_window(int x, int y); // sets window_height/width

 public slots:
     void setXRotation(double angle);
     void setYRotation(double angle);
     void setZRotation(double angle);
     void setTranslation(double magnitude, double zTrans); // updates the motor speed and zTrans
     void rotation (double); // updates the compass speed
     void Zrotation (double);
     void Xrotation (double);
     void Yrotation (double);
     void updateScene(); // calls paintGL() and records/calls data for recording/replay

 protected:
     void initializeGL();
     void paintGL();
     void resizeGL(int width, int height);

 private:
     GLuint makeObject();

     GLuint object; // holds code for static environment
     double xRot, yRot, zRot; // rotations of pedestrian for x, y, and z
     double compassSpeed; // speed that zRot is changing every updateScene()
     double zcompassSpeed;
     double xcompassSpeed; // speed that xRot is changing every updateScene()
     double ycompassSpeed; // speed that yRot is changing every updateScene()
     double xTrans; // position left / right
     double yTrans; // position into the screen / forward
     double startingyTrans[2], startingxTrans[2], startingrotation[2]; // info for starting location of each starting point for each trial
     QString startPos; // A or B
     int start; // 0 for A, 1 for B, used for referencing arrays
     double maxTrans; // farthest away from center of road pedestrian can go
     double motorSpeed; // speed that pedestrian is going forward every updateScene()
     double zTrans; // position up from ground
     double elevated; // elevates zTrans when pedestrian is on sidewalk
     QPoint lastPos;
     QColor backgroundColor;

     bool hit; // whether or not pedestrian is hit

     bool started; // recording/replay has begun
     double time; // time program has run for
     bool birdview; // whether or not viewpoint is birdview. changes paintGL()

     int window_width; // determined from mywindow
     int window_height; // determined from mywindow

     QLCDNumber lcd; // displays the 5,4,3,2,1 inbetween trials
 };

 #endif
