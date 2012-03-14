#ifndef CAR_H
#define CAR_H

#include "path.h"
#include <QSqlDatabase>
#include <QStringList>
#include <QtSql>
#include <QSqlDriver>
#include <QMessageBox>
#include <QObject>
#include "poisson.h"

enum Signals { NONE, SIGNALLING, STOPPED }; // numbers are added to get to the number that corresponds to the right texture

struct Status {
    int left, right, stopped; // hold enum Signals values. left and right are for left and right SIGNALLING
    void operator =(int); // sets all members to int, used for resetting
};

struct Occupied { // used to tell trafficControl where the car is so it can draw it based on that info
    int pathOn; // INTO, TURNINTO, CIRCLE, TURNAWAY, OR AWAY
    int road; // 0, 1, 2, or 3
    int lane; // 0, or 1 for inside and outside
    int position; // position specific to pathOn
    int id; // id of the car
};

class Car
{
public:
    Car();
    ~Car();

    void setCar(const double speed[2][100], int vehicleQuantity); // gives car info needed for current and future implementations //VehicleQauntitySwitching
    void newCar(double speed); // called when a new car is needed, random variables are set
    void stopCar(); // called when trial is ended
    void update(bool initial = false); // moves car forward by current tmpSpeed, initial is true when we don't want to move the car but figure out its occupied position

    bool get_onTrack();
    int get_end();
    int get_start();
    int get_position();
    int get_colour();
    void set_colour(int a);
    void set_distanceTravelled(double, bool addition = false);
    double get_distanceTravelled();
    double get_dimensions(int);
    void set_dimensions(int index, double);
    void set_id(int id); // sets occupied.id
    void database_get_numberOfCars();
    void database_get_trafficenable();
    void connect_to_database();

    Status status; // status holds info for its lights
    Occupied occupied; // holds info to determine its global info
    Point point; // holds x, y, and rotation, used for drawing the car

    bool passedp; // true only after the car has passed in front of the pedestrian

private:
    void translateSpeed(int index); // translates speed[index] for all other paths
    double referenceSpeed[2][100]; // reference speed translations used for translating tmp, follow and (normal)Speed
    double speed[100]; // holds translations for different paths of current speed, only one lane reference is needed
    const static int start = 2; // start road of current car
    const static int end = 0; // end road of current car
    int position; // position non-specific to the cars current position, is global for determining occupied, int since needed for referencing arrays
    double dposition; // position is set to int(dposition), is the double of position, needed since speed is double
    int keyPosition[100]; // positions where car changes paths, different depending on difference between start and end roads //VehicleQauntitySwitching
    int colour; // colours are 0 to 7
    bool signalling; // true if car is in zone where car should be signalling
    int signalCounter; // counter for determining when actual light should be on for signalling
    bool committed; // true if car has entered the inside lane, updated in trafficControl
    double distanceTravelled; // magnitude of travel for determining rotation of rims
    static const int numberOfLanes = 1; // number of lanes, used for determining what lane car should be in
    double dimensions[4]; // dimensions of car for randomness
    QSqlDatabase db;
    int numberOfCars; //VehicleQauntitySwitching

    bool onTrack; // whether the car is in the environment or not at the current time
};

#endif // CAR_H
