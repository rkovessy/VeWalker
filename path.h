#ifndef PATH_H
#define PATH_H

#include "math.h"
#include <QDebug>
#include <QString>

const double PI = (asin(0.5) * 6.0);

enum PathOn { INTO, TURNINTO, CIRCLE, TURNAWAY, AWAY };

struct Point { // information needed for drawing the car at any point
    double x, y, rotation;
    int position;

    void operator =(double);
    bool operator <=(Point);
    bool operator >=(Point);
};

class Path
{
public:
    /* see "walkercarmodel.png" for visual interpretation of path
       responsible for generating points which cars can follow
       into is for going towards the roundabout, away is away from the roundabout
       turn is for when turning into or out of the roundabout, circle is for in the roundabout,
       lanes (ie [2], or second dimension) are 0 for inside and 1 for outside
       road (ie [4], or first dimension) is for which start/end road, 0 for north, 1 for west...
       each path split up into points/degrees, where each change in rotation of car is a change of point/degree
       since split up into degrees, each path has different relative speed, (ie cars turning in or in the circle on different lanes will be in synchrony if starting path at same time but have different speeds)
       each turn/circle is made up of an x and y arm from its origin.
       x is 0.6, or 3/4 of length of car from front bumper to give a realistic angle when turning (ie. front bumper is further from inside edge of curve than the back bumper)
       y can be thought of as radius of circle, it is radius from origin to outside skirt 3/4 length from front bumper
    */
    Path();
    void set(double radius, double lanewidth); // provides information needed for defining paths of different roundabouts

    const static double DISTANCE = 0.04; // distance cars travel each updateCar with a INTO speed of 1.0, or travelling 0.04 units / 0.02 seconds
    const static double TRANSLATION = 0.6; // extension of the car to give it a realistic turning curve

    Point circle[2][1800]; // is a circle with 0,0,0 as origin, does not have a road dimension, not needed
    Point turninto[4][2][225]; // an eighth circle, starting parallel/perpendicular to x/y axes, ending with 45 degree to x/y axes, with origin in line with 45 degree line from 0,0,0
    Point turnaway[4][2][225]; // an eighth circle, starting with 45 degree to x/y axes, ending parallel/perpendicular to x/y axes, with origin in line with 45 degree line from 0,0,0
    Point into[4][2][1500]; // linear, starts car outside of environment box
    Point away[4][2][1500]; // linear, takes car outside of environment box

    double speed[2][100]; // holds reference values for speeds at all lanes and paths

    double distance_tostart; // distance cars travel from first position to actual start

private:
    double coordinate[2]; // coordinate for defining origins
    double radius[4]; // 2 radii for 2 lanes of the circle and turninto/away for path
    double origin[4][2][2]; // 4 origins with 2 lanes with an x and y cooridinate that define the center of circles for turninto and turnaway paths
    double radians; // angle counterclockwise from road 0 (east bound road) used for calculating x and y coordinates.
    double radians2; // angle used for turnaway, going from 45 to zero instead of 0 up

    double laneVector[2]; // distance from origin to center of inside / outside lanes    
};

#endif // PATH_H
