#ifndef TRAFFICCONTROL_H
#define TRAFFICCONTROL_H

#include "car.h"
#include "path.h"
#include "draw.h"
#include "data.h"
#include "popupscreen.h"

#include <QObject>
#include <QWidget>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTime>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlDriver>
#include <QMessageBox>

using namespace std;

struct Limits {
    bool hit, elevated, stopped; // puts limits on movement of pedestrian. hit is for when hit by a car, elevated is for adjusting zTrans based on whether or not pedestrian is on a higher ground
                                 // stopped is for if the pedestrian should be stopped, ie for a tree. Haven't implemented the logic yet
    void operator =(bool); // puts all members to same bool
};

class TrafficControl : public QWidget
{
    /* controls car behaviour, and opens pop up window when appropriate
    */
    Q_OBJECT

public:
    explicit TrafficControl(QWidget *parent = 0);
    ~TrafficControl();

    void set(int pid); // called in mywindow, gives required information to path, draw, and cars
    void update(); // called in paintGL() updates the scene by checking/setting status and drawing all cars
    void updatePedestrian(double xTrans, double yTrans, int zRot); // called in paintGL() and updates the pedestrian in trafficControl and sends the limits on pedestrian
    bool get_screen(int index = 0); // returns if either of the abnormal screens is up for index = 0, and for a specific screen for different indexes
    bool get_failed();
    QString get_trials();
    QString get_start();
    int get_display(); // for the countdown lcd in glwidget

    void nexttrial(); // sets up trafficcontrol for next trial, called after pedestrian reaches end
    void resettrial(); // called after failed trial

    Draw draw; // does all drawing
    Data data; // writes info for pedestrian, data, and cars
    Limits limits; // limits for pedestrian

    void database_get_vals();
    void database_connect();

public slots:
    void clicked(); // executed after aknowledgement from user after failed trial or start of real trials.

signals:
    void close_window();// closes window after trial >= trials ( ie no more specified trials)

private:
    void updateCar(int index, bool initial = false); // calls cars[index].update() then determines its point and distanceTravelled in trafficControl
    void checkCar(int index); // checks all possible reasons for a car needing to stop/slow down, returns a new followSpeed as a parameter of cars[index].setStatus(followSpeed)
    int checkPedestrian(); // returns enum roadclassification defined in "data.h", describes whether pedestrian is on sidewalk, road, or refuge
    bool safeZone(); // returns true if pedestrian is in a safe zone, ie grass or walking path not on road
    double magnitude(Point, Point); // returns the magnitude between two points
    double angle(Car a, Point b, bool sightadjusted = true); // returns the angle from Car a normal to Point b. sightadjusted is for changing the normal when Car a is turning
    double differenceRotation(Car a, Car b); // returns the difference in rotation between two cars
    bool pointCollision(Car a, Point p); // returns true if Car a intersects with Point p
    QSqlDatabase db; //Database variables

    void setCarstart(); // cycles through updateCar()'s till first car is at start position, i think 3.22 seconds from pedestrian

    Path path; // stores the paths
    Car cars[6]; // stores the cars
    Point pedestrian; // stores x, y, and rotation of pedestrian

    QFile file; // file for car output
    QTextStream text; // for cars
    QString filename; // filename of cars and sep times
    double time; // time program has been running

    bool whitescreen; // true inbetween trials, when whitescreen is up
    bool failed; // true when failscreen is up
    bool starttrialsscreen; // true before the first trial in a set
    bool startpracticescreen; // true before the first practice trial in a set
    QString starttrials; // one of inputs to popupscreen found in spec file
    QString startpractice; // one of inputs to popupscreen found in spec file
    QString fail; // one of inputs to popupscreen

    int numberOfTrials; // number of trials defined in specs file
    int trial; // trial for referencing array
    double elapsed[2]; // times elapsed since restarting for starting cars and in setCarstart()
    int carCounter; // reference for the next car to enter environment
    double distance_tostart; // distance a car needs to travel before in start position, used in setCarstart()

    QString trials[100]; // for output files
    QString startPos[100]; // whether pedestrian starts on A or B
    QString popUps[100]; // for telling when the popUps will come up
    double speeds[100]; // speeds defined for each trial
    int gaps[100][5]; // seperation times, where array is path, trial, time

    int numberOfCars; // number of cars chosen in form

    PopUpScreen popupscreen; // responsible for notifying user of changes from trial to practice or vice versa and when they fail, requires a response from them
};

#endif // TRAFFICCONTROL_H
