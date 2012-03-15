#ifndef DRAW_H
#define DRAW_H

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
#include <QDir>
#include <qgl.h>
#include <QtGui/QApplication>
#include <QtCore/QCoreApplication>
#include <QSqlDatabase>
#include <QStringList>
#include <QtSql>
#include <QSqlDriver>
#include <QMessageBox>
#include <QObject>

#include "path.h"
#include "car.h"

enum filename { STREET, GRASSGREEN, WALKWAYGREY, WALKWAYWHITE, LINEYELLOW, LINEWHITE, SKY, SKYBLUE, TREEBROWN, TREEGREEN, WINDOW, TIRE, LICENSE, TIREGREY, BLACK, GREY, WHITE, BLUE, RED, YELLOW, GREEN, FR, FRT, FL, FLT, BR, BRT, BRS, BRST, BL, BLT, BLS, BLST, TEXTUREGRASS01, TEXTUREGRASS02, TEXTUREGRASS03, ASPHALT, SIDEWALK, ASPHALT2, CLOUD, CLOUD2, CLOUD3, BUILDING1, BUILDING2, BUILDING3, BUILDING4, BUILDING5, BUILDING6, TIREEDGE, TIRETREAD };
                // enum for switching between textures, the order of the lights textures is important
                // F = front, B = back, R = right, L = left, S = stopping, T = turning
class Draw
{
    /*see "walkercarmodel.png" for visual interpretation of environment
      responsible for all openGL drawing
    */
public:
    Draw();
    ~Draw();
    void setDimensions(double height); // sets parameters of the environment

    void environment(); // draws the enviornment, ie the grass, road, sidewalk, trees, the refuges, the center
    void car(Car car); // draws a car at Point with bottom middle of front bumper as point //VehicleRoadSwitch
    void carEast(Car car); //Same as above function, but draws a car intended to move east in opposing flow to cars drawn in prior function

    void setStatic_Environment();
    void set_move(double);
    int get_numberOfLanes();
    double get_centerRadius();
    double get_centerHeight();
    double get_cornerRadius();
    double get_cornerCoordinate();
    double get_midzoneLength(int);
    double get_midzoneVector(int);
    double get_walkwayDistance();

    const static double CAR_LENGTH_DESIGN = 0.8; // length of each car before scaling
    const static double CAR_WIDTH_DESIGN = 0.5; // width of each car before scaling
    double CAR_LENGTH; // length of each car after scaling
    double CAR_WIDTH; // width of each car after scaling
    const static double CAR_SCALING = 1.1; // 1.0 draws the car with DESIGN dimensions, >1 draws car larger and <1 but >0 draws smaller car
    const static double MIDZONE_WIDTH = 0.5; // width of the center refuge and all walkways
    const static double BORDER_X = 0.04; // x/y distance between the road and grass, filled with pavement
    const static double BORDER_Z = 0.02; // height difference between road and grass/walkway
    const static double LINE_WIDTH = 0.05; // width of painted lane lines
    const static double LANE_WIDTH = 1.7;  // distance from edge of sidwalk to center of the white lane line or from the center of the white line to the center of the yellow line

    int numberOfLanes; // number of lanes
    static const double centerRadius = 1.5; // radius from (0,0,0) to the outside of the grey border of the center of the roundabout
    static const double centerHeight = 1.0/3.0; // height of the object in the center
    void get_centerheight();
    void building(); //Function to draw in buildings to environment


private:
    void loadTextures(); // calls loadTexture(...) for all textures
    void loadTexture(QString filename, int index); // loads the texture at filename and stores it at texture[index]
    void setTexture(int index); // binds the index texture (index is an enum filename)

    void rectangle(double normalx, double normaly, double normalz, double x, double y, double z, char direction1, double length1, char direction2, double length2); // draws a rectangle parallel or perpindicular to x, y, and z axes
    void quadPoints(double normalx, double normaly, double normalz, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4 = 0.0, double y4 = 0.0, double z4 = 0.0); // draws a quad using points
    void quadVectors(double normalx, double normaly, double normalz, double x, double y, double z, double x1, double y1, double z1, double x2, double y2, double z2, double x3 = 0.0, double y3 = 0.0, double z3 = 0.0); // draws a quad using vectors
    void triangle(char horizontal, char vertical, double x, double y, double z, char direction1, double length1, char direction2, double length2); // draws a triangle parrallel to x, y, and z axes
    void trianglePoints(char horizontal, char vertical, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3); // draws a triangle using points
    void triangleVectors(char horizontal, char vertical, double x, double y, double z, double x1, double y1, double z1, double x2, double y2, double z2); // draws a triangle using vectors

    QSqlDatabase db;

    void center(); // draws the center of the roundabout and the circular lane line if needed
    void centersphere(); // draws the half sphere at center()
    void corners(); // draws the corner grass/sidewalk, the center refuge, the yellow line and white lane line if needed of all the corners
    void tree(double scale, double x, double y, double z = 0.02); // draws a tree with the height and width being the orginal * scale, drawn at x, y, z
    double treeCoordinate(int a); // returns a tree coordinate on the grass that is positive if int a is positive and negative if int a is negative

    double move; // for spinning of tires
    double cornerRadius; // radius of the quarter circle till the street defined by the corner of the corner grass closest to the center
    double cornerCoordinate; // define the x and y coordinate of the quater circle between each of the roads (same one as above line)
    double midzoneLength[3]; // lengths between specific points of the center refuge (midzoneLength[0] = midzoneVector[0])
    double midzoneVector[3]; // lengths from the origin to the specific points of the center refuge
    double walkwayDistance; // distance from origin to the closest edge to the center of the painted walkway on the road

    GLuint texture[49]; // holds all the textures
    GLUquadricObj *quad; // needed for cylinders/circles/spheres
    QImage b[50]; // needed for loadTexture(...), textures are loaded via QImage
    QImage t[50]; // needed for loadTexture(...), textures are loaded via QImage

    bool demoMode; //Determines if demo mode is chosen
    void get_database_mode(); //Determines if demo mode was written to database for current run
};

#endif // DRAW_H
