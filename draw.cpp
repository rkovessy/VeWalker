#include "draw.h"
#include <string>
using namespace std;

Draw::Draw()
{
    quad = gluNewQuadric();
    move = 0.0;
    loadTextures();

    db = QSqlDatabase::addDatabase("QPSQL", "drawConn");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("abc123");
    db.setDatabaseName("configDb");
    db.open();

    //get_centerheight();

    if (db.lastError().isValid());
        qDebug() << "lastDB error from opening connection " << db.lastError();

    if (db.isOpen())
    {
        QString readStatement = ("SELECT roundabout FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                numberOfLanes = qry.value(0).toInt();
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }
    }
    else
    {
        qDebug() << "Draw failed to open database connection to pull data.";
    }
    get_database_mode(); // If demo mode is selected use the more impressive two-lane roundabout, and default denter median height
    setStatic_Environment();
}
Draw::~Draw()
{
   // QSqlDatabase::database("drawConn").close();
 //   QSqlDatabase::removeDatabase("drawConn");

}

void Draw::setStatic_Environment()
{
    cornerRadius = ((centerRadius + LANE_WIDTH * numberOfLanes) * sin(PI / 4.0) - LANE_WIDTH * numberOfLanes) / (1 - sin(PI / 4.0));
    cornerCoordinate = LANE_WIDTH * numberOfLanes + cornerRadius;
    midzoneLength[0] = centerRadius + LANE_WIDTH * numberOfLanes;
    midzoneLength[1] = centerRadius * 2;
    midzoneLength[2] = 0.5;
    midzoneVector[0] = midzoneLength[0];
    midzoneVector[1] = midzoneLength[0] + midzoneLength[1];
    midzoneVector[2] = midzoneLength[0] + midzoneLength[1] + midzoneLength[2];

    walkwayDistance = midzoneLength[0] + midzoneLength[1] / 2.0;
    if (walkwayDistance < cornerCoordinate)
        walkwayDistance = cornerCoordinate;

    CAR_LENGTH = CAR_LENGTH_DESIGN * CAR_SCALING;
    CAR_WIDTH = CAR_WIDTH_DESIGN * CAR_SCALING;
}

void Draw::environment() {
        setTexture(ASPHALT);
        for(double i=0.0; i<=100.0; i+=2.5)
        {
            for(double j=0.0; j<=100.0; j+=2.5)
                rectangle(0, 0, 1, -50.0+i, -50.0+j, 0.0, 'x', 2.5, 'y', 2.5);
        }

        setTexture(CLOUD2);
        gluQuadricOrientation(quad, GLU_INSIDE);
        glNormal3d(0, 0, 1);
        gluQuadricDrawStyle(quad, GLU_FILL);
        gluQuadricTexture(quad, GL_TRUE);
        gluSphere(quad, 75.0, 360, 360); // draws the center half sphere

        gluQuadricOrientation(quad, GLU_OUTSIDE);
        //glScaled(1, 1, centerRadius / centerHeight); // back to normal

        //These were the previously used rectangles for the sky.  Changed to sphere model above.
        /*rectangle(0, -1, 0, -50.0, 50.0, 0.0, 'x', 100.0, 'z', 50.0);
        rectangle(1, 0, 0, -50.0, -50.0, 0.0, 'y', 100.0, 'z', 50.0);
        rectangle(0, 1, 0, 50.0, -50.0, 0.0, 'x', -100.0, 'z', 50.0);
        rectangle(-1, 0, 0, 50.0, 50.0, 0.0, 'y', -100.0, 'z', 50.0);

        setTexture(SKYBLUE);
        rectangle(0, 0, -1, 50.0, 50.0, 50.0, 'y', -100.0, 'x', -100.0);*/

        for (int xcount = -1; xcount < 2; xcount += 2)
            for (int ycount = -1; ycount < 2; ycount += 2)
                for (int count = 0; count < 10; ++count)
                    tree((rand() % 11 - 5.0) / 10.0 + 1.0, treeCoordinate(xcount), treeCoordinate(ycount));

        building();



        center();
        corners();
}

void Draw::car(Car car) {
    /* draws a car with point being the middle of the frontbumber on the ground
       and point.rotation is the direction the car is facing from east counterclockwise in degrees
       code was written for a car facing south
       stop and turn are for the front and back lights
    */
    double rotation = -car.get_distanceTravelled() / (0.08 * CAR_SCALING);
    int colour = car.get_colour();
    double dimension_0 = car.get_dimensions(0);
    double dimension_1 = car.get_dimensions(1);
    double dimension_2 = car.get_dimensions(2);
    double dimension_3 = car.get_dimensions(3);
    double length = dimension_0 + 0.25;


    glPushMatrix();
    glScaled(CAR_SCALING, CAR_SCALING, CAR_SCALING);
    glTranslated(car.point.x, car.point.y, 0.0);
    glRotated(90 + car.point.rotation , 0, 0, 1);

    setTexture(BLACK + colour);

    rectangle(0, -1, 0, -0.25, 0, 0.07, 'x', CAR_WIDTH_DESIGN, 'z', 0.18); // front bumper
    rectangle(0, 1, 0, 0.25, CAR_LENGTH_DESIGN, 0.07, 'x', -1 * CAR_WIDTH_DESIGN, 'z', 0.18); // back bumper
    quadVectors(0, -0.15 / sqrt(0.0325), 0.1 / sqrt(0.0325), -0.25, dimension_0, 0.25, CAR_WIDTH_DESIGN, 0.0, 0.0, 0.0, 0.1, 0.15); // front window border
    quadVectors(0, 0.15 / sqrt(0.025), 0.05 / sqrt(0.025), 0.25, dimension_3, 0.25, -1 * CAR_WIDTH_DESIGN, 0.0, 0.0, 0.0, -0.05, 0.15); // back window border
    quadPoints(1, 0, 0, 0.25, dimension_0, 0.25, 0.25, dimension_3, 0.25, 0.25, dimension_2, 0.4, 0.25, dimension_1, 0.4); // left side window border
    quadPoints(-1, 0, 0, -0.25, dimension_3, 0.25, -0.25, dimension_0, 0.25, -0.25, dimension_1, 0.4, -0.25, dimension_2, 0.4); // right side window border
    for (int count = 0; count < 1.5 && length <= dimension_2 - 0.04; ++count, length += 0.2) {
        rectangle(1, 0, 0, 0.252, length - 0.01, 0.25, 'y', 0.02, 'z', 0.15); // left side window seperator
        rectangle(-1, 0, 0, -0.252, length + 0.01, 0.25, 'y', -0.02, 'z', 0.15); // right side window seperator
    }
    rectangle(1, 0, 0, 0.25, 0.0, 0.07, 'y', CAR_LENGTH_DESIGN, 'z', 0.18); // left side skirt
    rectangle(-1, 0, 0, -0.25, CAR_LENGTH_DESIGN, 0.07, 'y', -1 * CAR_LENGTH_DESIGN, 'z', 0.18); // right side skirt
    rectangle(0, 0, 1, -0.25, 0.0, 0.25, 'x', CAR_WIDTH_DESIGN, 'y', dimension_0); // hood
    rectangle(0, 0, 1, -0.25, dimension_1, 0.4, 'x', CAR_WIDTH_DESIGN, 'y', dimension_2 - dimension_1); // top of car
    rectangle(0, 0, 1, -0.25, dimension_3, 0.25, 'x', CAR_WIDTH_DESIGN, 'y', CAR_LENGTH_DESIGN - dimension_3); // top of trunk

    setTexture(TIREGREY);
    rectangle(0, 0, -1, -0.25, 0.0, 0.07, 'y', CAR_LENGTH_DESIGN, 'x', CAR_WIDTH_DESIGN);
    rectangle(0, -1, 0, -0.25, 0, 0.07, 'z', 0.18, 'x', CAR_WIDTH_DESIGN); // front bumper
    rectangle(0, 1, 0, 0.25, CAR_LENGTH_DESIGN, 0.07, 'z', 0.18, 'x', -1 * CAR_WIDTH_DESIGN); // back bumper
    rectangle(1, 0, 0, 0.25, 0.0, 0.07, 'z', 0.18, 'y', CAR_LENGTH_DESIGN); // left side skirt
    rectangle(-1, 0, 0, -0.25, CAR_LENGTH_DESIGN, 0.07, 'z', 0.18, 'y', -1 * CAR_LENGTH_DESIGN); // right side skirt
    rectangle(0, 0, 1, -0.25, 0.0, 0.25, 'y', CAR_LENGTH_DESIGN, 'x', CAR_WIDTH_DESIGN); // hood extension

    setTexture(FR + car.status.right);
    rectangle(0, -1, 0, -0.23, -0.001, 0.18, 'x', 0.1, 'z', 0.05);

    setTexture(FL + car.status.left);
    rectangle(0, -1, 0, 0.13, -0.001, 0.18, 'x', 0.1, 'z', 0.05);

    setTexture(BL + car.status.stopped + car.status.left);
    rectangle(0, 1, 0, 0.23, CAR_LENGTH_DESIGN + 0.001, 0.18, 'x', -0.1, 'z', 0.05);

    setTexture(BR + car.status.stopped + car.status.right);
    rectangle(0, 1, 0, -0.13, CAR_LENGTH_DESIGN + 0.001, 0.18, 'x', -0.1, 'z', 0.05);

    setTexture(LICENSE);
    rectangle(0, -1, 0, -0.05, -0.001, 0.09, 'x', 0.1, 'z', 0.05); // front
    rectangle(0, 1, 0, 0.05, CAR_LENGTH + 0.001, 0.09, 'x', -0.1, 'z', 0.05); // back

    setTexture(WINDOW);
    quadPoints(0, -0.12 / sqrt(0.0208), 0.08  / sqrt(0.0208), -0.23, dimension_0 + 0.013, 0.27, 0.23, dimension_0 + 0.013, 0.27, 0.23, dimension_1 - 0.007, 0.39); // front
    quadPoints(0, 0.12 / sqrt(0.016), 0.04 / sqrt(0.016), 0.23, dimension_3 - 0.006, 0.27, -0.23, dimension_3 - 0.006, 0.27, -0.23, dimension_2 + 0.004, 0.39); // back
    quadPoints(1, 0, 0, 0.251, dimension_0 + 0.02, 0.25, 0.251, dimension_3 - 0.02, 0.25, 0.251, dimension_2 - 0.02, 0.39, 0.251, dimension_1 + 0.02, 0.39); // left
    quadPoints(-1, 0, 0, -0.251, dimension_3 - 0.02, 0.25, -0.251, dimension_0 + 0.02, 0.25, -0.251, dimension_1 + 0.02, 0.39, -0.251, dimension_2 - 0.02, 0.39); // right

    // black side of tire facing out
    setTexture(TIREGREY);
    glPushMatrix();
    glTranslatef(0.251, 0.2, 0.08);
    glRotatef(90, 0, 1, 0);
    glNormal3d(0, 0, 1);
    gluDisk(quad, 0.056, 0.08, 36, 1); // front left
    glTranslatef(0.0, 0.4, 0.0);
    gluDisk(quad, 0.056, 0.08, 36, 1); // back left
    glTranslatef(0.0, 0.0, -1 * CAR_WIDTH_DESIGN - 0.002);
    glRotatef(180, 0, 1, 0);
    glNormal3d(0, 0, 1);
    gluDisk(quad, 0.056, 0.08, 36, 1); // back right
    glTranslatef(0.0, -0.4, 0.0);
    gluDisk(quad, 0.056, 0.08, 36, 1); // front right
    glPopMatrix();

    // tread of tires
    setTexture(TIRETREAD);
    glPushMatrix();
    glTranslatef(0.171, 0.2, 0.08);
    glRotatef(90, 0, 1, 0);
    glNormal3d(-1, 0, 0);
    gluCylinder(quad, 0.08, 0.08, 0.08, 36, 1); // front left
    glTranslatef(0.0, 0.4, 0.0);
    gluCylinder(quad, 0.08, 0.08, 0.08, 36, 1); // back left
    glTranslatef(0.0, 0.0, -0.422);
    gluCylinder(quad, 0.08, 0.08, 0.08, 36, 1); // back right
    glTranslatef(0.0, -0.4, 0.0);
    gluCylinder(quad, 0.08, 0.08, 0.08, 36, 1); // front right;
    glPopMatrix();

    // inside tire
    setTexture(TIREGREY);
    glPushMatrix();
    glTranslatef(0.171, 0.2, 0.08);
    glRotatef(-90, 0, 1, 0);
    glNormal3d(0, 0, 1);
    gluDisk(quad, 0.0, 0.08, 36, 1); // front left
    glTranslatef(0.0, 0.4, 0.0);
    gluDisk(quad, 0.0, 0.08, 36, 1); // back left
    glTranslatef(0.0, 0.0, 0.342);
    glRotatef(180, 0, 1, 0);
    glNormal3d(0, 0, 1);
    gluDisk(quad, 0.0, 0.08, 36, 1); // back right
    glTranslatef(0.0, -0.4, 0.0);
    gluDisk(quad, 0.0, 0.08, 36, 1); // front right
    glPopMatrix();

    double sine = sin(rotation) * 0.078;
    double cose = cos(rotation) * 0.078;

    // rims
    setTexture(TIRE);
    quadPoints(1, 0, 0, 0.251, 0.2 + sine, 0.08 - cose, 0.251, 0.2 + cose, 0.08 + sine, 0.251, 0.2 - sine, 0.08 + cose); // front left
    quadPoints(1, 0, 0, 0.251, 0.6 + sine, 0.08 - cose, 0.251, 0.6 + cose, 0.08 + sine, 0.251, 0.6 - sine, 0.08 + cose); // back left
    quadPoints(-1, 0, 0, -0.251, 0.6 - sine, 0.08 + cose, -0.251, 0.6 + cose, 0.08 + sine, -0.251, 0.6 + sine, 0.08 - cose); // back right
    quadPoints(-1, 0, 0, -0.251, 0.2 - sine, 0.08 + cose, -0.251, 0.2 + cose, 0.08 + sine, -0.251, 0.2 + sine, 0.08 - cose); // front right

    glPopMatrix();
}

void Draw::set_move(double a) {
    move = a;
}

int Draw::get_numberOfLanes() {
    return numberOfLanes;
}

double Draw::get_centerRadius() {
    return centerRadius;
}

double Draw::get_centerHeight() {
    return centerHeight;
}

double Draw::get_cornerRadius() {
    return cornerRadius;
}

double Draw::get_cornerCoordinate() {
    return cornerCoordinate;
}

double Draw::get_midzoneLength(int a) {
    return midzoneLength[a];
}

double Draw::get_midzoneVector(int a) {
    return midzoneVector[a];
}

double Draw::get_walkwayDistance() {
    return walkwayDistance;
}

void Draw::loadTextures() {
    glEnable(GL_TEXTURE_2D);
    QString folder = "images/";
    if (!QDir(folder).exists())
        qDebug() << "image folder not found";

    glGenTextures( 47, &texture[0] );

    loadTexture(folder + "street.bmp", STREET);
    loadTexture(folder + "grassgreen.bmp", GRASSGREEN);
    loadTexture(folder + "walkwaygrey.bmp", WALKWAYGREY);
    loadTexture(folder + "lineyellow.bmp", LINEYELLOW);
    loadTexture(folder + "linewhite.bmp", LINEWHITE);
    loadTexture(folder + "sky.bmp", SKY);
    loadTexture(folder + "skyblue.bmp", SKYBLUE);
    loadTexture(folder + "treebrown.bmp", TREEBROWN);
    loadTexture(folder + "treegreen.bmp", TREEGREEN);
    loadTexture(folder + "window.bmp", WINDOW);
    loadTexture(folder + "tire.bmp", TIRE);
    loadTexture(folder + "license.bmp", LICENSE);
    loadTexture(folder + "tiregrey.bmp", TIREGREY);
    loadTexture(folder + "black.bmp", BLACK);
    loadTexture(folder + "grey.bmp", GREY);
    loadTexture(folder + "white.bmp", WHITE);
    loadTexture(folder + "blue.bmp", BLUE);
    loadTexture(folder + "red.bmp", RED);
    loadTexture(folder + "yellow.bmp", YELLOW);
    loadTexture(folder + "green.bmp", GREEN);
    loadTexture(folder + "frontright.bmp", FR);
    loadTexture(folder + "frontrightturn.bmp", FRT);
    loadTexture(folder + "frontleft.bmp", FL);
    loadTexture(folder + "frontleftturn.bmp", FLT);
    loadTexture(folder + "backright.bmp", BR);
    loadTexture(folder + "backrightturn.bmp", BRT);
    loadTexture(folder + "backrightstop.bmp", BRS);
    loadTexture(folder + "backrightstopturn.bmp", BRST);
    loadTexture(folder + "backleft.bmp", BL);
    loadTexture(folder + "backleftturn.bmp", BLT);
    loadTexture(folder + "backleftstop.bmp", BLS);
    loadTexture(folder + "backleftstopturn.bmp", BLST);
    loadTexture(folder + "TextureGrass01.bmp", TEXTUREGRASS01);
    loadTexture(folder + "TextureGrass02.bmp", TEXTUREGRASS02);
    loadTexture(folder + "TextureGrass03.bmp", TEXTUREGRASS03);
    loadTexture(folder + "road-asphalt.bmp", ASPHALT);
    loadTexture(folder + "sidewalk.bmp", SIDEWALK);
    loadTexture(folder + "road-asphalt02.bmp", ASPHALT2);
    loadTexture(folder + "cloud.bmp", CLOUD);
    loadTexture(folder + "cloud02.bmp", CLOUD2);
    loadTexture(folder + "cloud03.bmp", CLOUD3);
    loadTexture(folder + "building1.bmp", BUILDING1);
    loadTexture(folder + "building2.bmp", BUILDING2);
    loadTexture(folder + "building3.bmp", BUILDING3);
    loadTexture(folder + "building4.bmp", BUILDING4);
    loadTexture(folder + "building5.bmp", BUILDING5);
    loadTexture(folder + "building6.bmp", BUILDING6);
    loadTexture(folder + "tireedge.bmp", TIREEDGE);
    loadTexture(folder + "tiretread.bmp", TIRETREAD);
}

void Draw::loadTexture(QString filename, int index) { // loads texture via QImage
    b[index].load( filename );
    t[index] = QGLWidget::convertToGLFormat( b[index] );
}

void Draw::setTexture(int index) {
    glBindTexture( GL_TEXTURE_2D, texture[index]);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexImage2D( GL_TEXTURE_2D, 0, 3, t[index].width(), t[index].height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t[index].bits() );
}

void Draw::rectangle(double normalx, double normaly, double normalz, double x, double y, double z, char direction1, double midzoneLength1, char direction2, double midzoneLength2) {
    /* (x,y,z) is bottom left corner
       directions are either 'x', 'y', or 'z' axes
       direction1 is vector from bottom left corner to bottom right corner
       midzoneLength1 is magnitude of direction1
       direction2 is vector from bottom right corner to top right corner
       midzoneLength2 is magnitude of direction2
    */
    glBegin(GL_QUADS);

    glNormal3d(normalx, normaly, normalz);
    glTexCoord2d(0,0); glVertex3d(x, y, z);

    if (direction1 == 'x') {
        glTexCoord2d(1,0); glVertex3d(x + midzoneLength1, y, z);
        if (direction2 == 'y') {
            glTexCoord2d(1,1); glVertex3d(x + midzoneLength1, y + midzoneLength2, z);
            glTexCoord2d(0,1); glVertex3d(x, y + midzoneLength2, z);
        }
        else if (direction2 == 'z') {
            glTexCoord2d(1,1); glVertex3d(x + midzoneLength1, y, z + midzoneLength2);
            glTexCoord2d(0,1); glVertex3d(x, y, z + midzoneLength2);
        }
    }
    else if (direction1 == 'y') {
        glTexCoord2d(1,0); glVertex3d(x, y + midzoneLength1, z);
        if (direction2 == 'x') {
            glTexCoord2d(1,1); glVertex3d(x + midzoneLength2, y + midzoneLength1, z);
            glTexCoord2d(0,1); glVertex3d(x + midzoneLength2, y, z);
        }
        else if (direction2 == 'z') {
            glTexCoord2d(1,1); glVertex3d(x, y + midzoneLength1, z + midzoneLength2);
            glTexCoord2d(0,1); glVertex3d(x, y, z + midzoneLength2);
        }
        }
    else if (direction1 == 'z') {
        glTexCoord2d(1,0); glVertex3d(x, y, z + midzoneLength1);
        if (direction2 == 'x') {
            glTexCoord2d(1,1); glVertex3d(x + midzoneLength2, y, z + midzoneLength1);
            glTexCoord2d(0,1); glVertex3d(x + midzoneLength2, y, z);
        }
        else if (direction2 == 'y') {
            glTexCoord2d(1,1); glVertex3d(x, y + midzoneLength2, z + midzoneLength1);
            glTexCoord2d(0,1); glVertex3d(x, y + midzoneLength2, z);
        }
    }
    glEnd();
}

void Draw::quadPoints(double normalx, double normaly, double normalz, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, double y4, double z4) {
    /* draws a quad with (xn,yn,zn) defining a point
       n = 1 is bottom left corner
       n = 2 is bottom right corner
       n = 3 is top right corner
       n = 4 is top left corner
       if top left corner is not given a parallelogram is drawn
    */
    if (x4 == 0.0 && y4 == 0.0 && z4 == 0.0) {
        x4 = x1 + x3 - x2;
        y4 = y1 + y3 - y2;
        z4 = z1 + z3 - z2;
    }
    glBegin(GL_QUADS);
    glNormal3d(normalx, normaly, normalz);
    glTexCoord2d(0,0);glVertex3d(x1, y1, z1);
    glTexCoord2d(1,0);glVertex3d(x2, y2, z2);
    glTexCoord2d(1,1);glVertex3d(x3, y3, z3);
    glTexCoord2d(0,1);glVertex3d(x4, y4, z4);
    glEnd();
}

void Draw::quadVectors(double normalx, double normaly, double normalz, double x, double y, double z, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {
    /* draws a quad with (x,y,z) as the bottom left corner
       (xn,yn,zn) defines a vector from one point to another
       n = 1 is bottom left to bottom right corner
       n = 2 is bottom right to top right corner
       n = 3 is top right to top left corner
       if n = 3 is not given a parallelogram is drawn
    */
    if (x3 == 0.0 && y3 == 0.0 && z3 == 0.0) {
        x3 = -x1;
        y3 = -y1;
        z3 = -z1;
    }
    glBegin(GL_QUADS);
    glNormal3d(normalx, normaly, normalz);
    glTexCoord2d(0,0); glVertex3d(x, y, z);
    glTexCoord2d(1,0); glVertex3d(x + x1, y + y1, z + z1);
    glTexCoord2d(1,1); glVertex3d(x + x1 + x2, y + y1 + y2, z + z1 + z2);
    glTexCoord2d(0,1); glVertex3d(x + x1 + x2 + x3, y + y1 + y2 + y3, z + z1 + z2 + z3);
    glEnd();
}

void Draw::triangle(char horizontal, char vertical, double x, double y, double z, char direction1, double midzoneLength1, char direction2, double midzoneLength2) {
    /* draws a triangle where horizontal and vertical define which corner of the rectangle image is kept
       define using number system or 'r', 'l', 't', 'b' for right, left, top, and bottom corner of textured image
       direction1 is vector to horizontal corner, direction 2 is vector to vertical corner
       midzoneLength1 and midzoneLength2 are corresponding magnitudes
    */

    glBegin(GL_TRIANGLES);
    glNormal3f(0,0,1);

    if (horizontal == 'l' || horizontal == '0') {


        if (vertical == 'b' || vertical == '0') {
            if (direction2 == 'x') {
                glTexCoord2d(0,1);glVertex3d(x + midzoneLength2, y, z);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction1 == 'y') {
                    glTexCoord2d(1,0);glVertex3d(x, y + midzoneLength1, z);
                }
                else if (direction1 == 'z')
                    glTexCoord2d(1,0);glVertex3d(x, y, z + midzoneLength1);
            }
            else if (direction2 == 'y') {
                glTexCoord2d(0,1);glVertex3d(x, y + midzoneLength2, z);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction1 == 'x') {
                    glTexCoord2d(1,0);glVertex3d(x + midzoneLength1, y, z);
                }
                else if (direction1 == 'z')
                    glTexCoord2d(1,0);glVertex3d(x, y, z + midzoneLength1);
            }
            else if (direction2 == 'z') {
                glTexCoord2d(0,1);glVertex3d(x, y, z + midzoneLength2);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction1 == 'x') {
                    glTexCoord2d(1,0);glVertex3d(x + midzoneLength1, y, z);
                }
                else if (direction1 == 'y')
                    glTexCoord2d(1,0);glVertex3d(x, y + midzoneLength1, z);
            }
        }

        else if (vertical == 't' || vertical == '1') {
            if (direction1 == 'x') {
                glTexCoord2d(0,1);glVertex3d(x + midzoneLength1, y, z);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction2 == 'y') {
                    glTexCoord2d(1,0);glVertex3d(x, y + midzoneLength2, z);
                }
                else if (direction2 == 'z')
                    glTexCoord2d(1,0);glVertex3d(x, y, z + midzoneLength2);
            }
            else if (direction1 == 'y') {
                glTexCoord2d(0,1);glVertex3d(x, y + midzoneLength1, z);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction2 == 'x') {
                    glTexCoord2d(1,0);glVertex3d(x + midzoneLength2, y, z);
                }
                else if (direction2 == 'z')
                    glTexCoord2d(1,0);glVertex3d(x, y, z + midzoneLength2);
            }
            else if (direction1 == 'z') {
                glTexCoord2d(0,1);glVertex3d(x, y, z + midzoneLength1);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction2 == 'x') {
                    glTexCoord2d(1,0);glVertex3d(x + midzoneLength2, y, z);
                }
                else if (direction2 == 'y')
                    glTexCoord2d(1,0);glVertex3d(x, y + midzoneLength2, z);
            }
        }
    }


    else if (horizontal == 'r' || horizontal == '1') {


        if (vertical == 'b' || vertical == '0') {
            if (direction1 == 'x') {
                glTexCoord2d(0,1);glVertex3d(x + midzoneLength1, y, z);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction2 == 'y') {
                    glTexCoord2d(1,0);glVertex3d(x, y + midzoneLength2, z);
                }
                else if (direction2 == 'z')
                    glTexCoord2d(1,0);glVertex3d(x, y, z + midzoneLength2);
            }
            else if (direction1 == 'y') {
                glTexCoord2d(0,1);glVertex3d(x, y + midzoneLength1, z);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction2 == 'x') {
                    glTexCoord2d(1,0);glVertex3d(x + midzoneLength2, y, z);
                }
                else if (direction2 == 'z')
                    glTexCoord2d(1,0);glVertex3d(x, y, z + midzoneLength2);
            }
            else if (direction1 == 'z') {
                glTexCoord2d(0,1);glVertex3d(x, y, z + midzoneLength1);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction2 == 'x') {
                    glTexCoord2d(1,0);glVertex3d(x + midzoneLength2, y, z);
                }
                else if (direction2 == 'y')
                    glTexCoord2d(1,0);glVertex3d(x, y + midzoneLength2, z);
            }
        }


        else if (vertical == 't' || vertical == '1') {
            if (direction2 == 'x') {
                glTexCoord2d(0,1);glVertex3d(x + midzoneLength2, y, z);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction1 == 'y') {
                    glTexCoord2d(1,0);glVertex3d(x, y + midzoneLength1, z);
                }
                else if (direction1 == 'z')
                    glTexCoord2d(1,0);glVertex3d(x, y, z + midzoneLength1);
            }
            else if (direction2 == 'y') {
                glTexCoord2d(0,1);glVertex3d(x, y + midzoneLength2, z);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction1 == 'x') {
                    glTexCoord2d(1,0);glVertex3d(x + midzoneLength1, y, z);
                }
                else if (direction1 == 'z')
                    glTexCoord2d(1,0);glVertex3d(x, y, z + midzoneLength1);
            }
            else if (direction2 == 'z') {
                glTexCoord2d(0,1);glVertex3d(x, y, z + midzoneLength2);
                glTexCoord2d(0,0);glVertex3d(x, y, z);
                if (direction1 == 'x') {
                    glTexCoord2d(1,0);glVertex3d(x + midzoneLength1, y, z);
                }
                else if (direction1 == 'y')
                    glTexCoord2d(1,0);glVertex3d(x, y + midzoneLength1, z);
            }
        }
    }

    glEnd();
}

void Draw::trianglePoints(char horizontal, char vertical, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {
    /* horizontal and vertical define the uncut corner,
       define using number system or 'r', 'l', 't', 'b' for right, left, top, and bottom corner of textured image
       (x1,y1,z1) defines the uncut corner
       (x2,y2,z2) defines the corner shifted horizontally from the uncut corner
       (x3,y3,z3) defines the corner shifted vertically from the uncut corner
    */
    glBegin(GL_TRIANGLES);
    glNormal3f(0,0,1);
    if (horizontal == 'l' || horizontal == '0') {
        if (vertical == 'b' || vertical == '0') {
            glTexCoord2d(0,1);glVertex3d(x3, y3, z3);
            glTexCoord2d(0,0);glVertex3d(x1, y1, z1);
            glTexCoord2d(1,0);glVertex3d(x2, y2, z2);
        }
        else if (vertical == 't' || vertical == '1') {
            glTexCoord2d(1,1);glVertex3d(x2, y2, z2);
            glTexCoord2d(0,1);glVertex3d(x1, y1, z1);
            glTexCoord2d(0,0);glVertex3d(x3, y3, z3);
        }
    }
    else if (horizontal == 'r' || horizontal == '1') {
        if (vertical == 'b' || vertical == '0') {
            glTexCoord2d(0,0);glVertex3d(x2, y2, z2);
            glTexCoord2d(1,0);glVertex3d(x1, y1, z1);
            glTexCoord2d(1,1);glVertex3d(x3, y3, z3);
        }
        else if (vertical == 't' || vertical == '1') {
            glTexCoord2d(1,0);glVertex3d(x3, y3, z3);
            glTexCoord2d(1,1);glVertex3d(x1, y1, z1);
            glTexCoord2d(0,1);glVertex3d(x2, y2, z2);
        }
    }
    glEnd();
}

void Draw::triangleVectors(char horizontal, char vertical, double x, double y, double z, double x1, double y1, double z1, double x2, double y2, double z2) {
    /* horizontal and vertical define the uncut corner,
       define using number system or 'r', 'l', 't', 'b' for right, left, top, and bottom corner of textured image
       (x1,y1,z1) defines the vector to get from uncut corner to the corner shifted horizontally
       (x2,y2,z2) defines the vector to get from uncut corner to the corner shifted vertically
    */
    glBegin(GL_TRIANGLES);
    glNormal3f(0,0,1);
    if (horizontal == 'l' || horizontal == '0') {
        if (vertical == 'b' || vertical == '0') {
            glTexCoord2d(0,1);glVertex3d(x + x2, y + y2, z + z2);
            glTexCoord2d(0,0);glVertex3d(x, y, z);
            glTexCoord2d(1,0);glVertex3d(x + x1, y + y1, z + z1);
        }
        else if (vertical == 't' || vertical == '1') {
            glTexCoord2d(1,1);glVertex3d(x + x1, y + y1, z + z1);
            glTexCoord2d(0,1);glVertex3d(x, y, z);
            glTexCoord2d(0,0);glVertex3d(x + x2, y + y2, z + z2);
        }
    }
    else if (horizontal == 'r' || horizontal == '1') {
        if (vertical == 'b' || vertical == '0') {
            glTexCoord2d(0,0);glVertex3d(x + x1, y + y1, z + z1);
            glTexCoord2d(1,0);glVertex3d(x, y, z);
            glTexCoord2d(1,1);glVertex3d(x + x2, y + y2, z + z2);
        }
        else if (vertical == 't' || vertical == '1') {
            glTexCoord2d(1,0);glVertex3d(x + x2, y + y2, z + z2);
            glTexCoord2d(1,1);glVertex3d(x, y, z);
            glTexCoord2d(0,1);glVertex3d(x + x1, y + y1, z + z1);
        }
    }
    glEnd();
}

void Draw::center() {
    centersphere();

    glPushMatrix();
    setTexture(SIDEWALK);
    glNormal3d(0, 1, 0);
    gluCylinder(quad, centerRadius, centerRadius, BORDER_Z, 36, 1); // center vertical
    glTranslated(0, 0, BORDER_Z);
    glNormal3d(0, 0, 1);
    gluDisk(quad, centerRadius - 0.04, centerRadius, 36, 1); // center horizontal border
    setTexture(TEXTUREGRASS02);
    gluDisk(quad, 0, centerRadius - 0.04, 36, 1); // center grass
    glPopMatrix();

    if (numberOfLanes == 2) {
        glPushMatrix();
        glTranslated(0, 0, 0.001);
        glNormal3d(0, 0, 1);
        setTexture(LINEWHITE);
        gluDisk(quad, centerRadius + LANE_WIDTH - LINE_WIDTH / 2.0, centerRadius + LANE_WIDTH + LINE_WIDTH / 2.0, 36, 1); // lane line
        glPopMatrix();
    }
}

void Draw::centersphere() {
    setTexture(LINEWHITE);
    glNormal3d(0, 0, 1);
    glScaled(1, 1, centerHeight / centerRadius); // needed since a sphere height is dependent on its radius
    gluSphere(quad, centerRadius - 0.2, 36, 36); // draws the center half sphere
    glScaled(1, 1, centerRadius / centerHeight); // back to normal
}

void Draw::corners() {
    glPushMatrix();
    for (int count = 0; count < 4; ++count) {
        setTexture(LINEYELLOW);
        for (double k = midzoneVector[2] + 0.1; k < 50.0; k += 0.2)
            rectangle(0, 0, 1, LINE_WIDTH / -2.0, k, 0.001, 'x', LINE_WIDTH, 'y', 0.1); // yellow paint road divider

        setTexture(LINEWHITE);
        if (numberOfLanes == 2) {
            rectangle(0, 0, 1, LANE_WIDTH - LINE_WIDTH / 2.0, walkwayDistance + 1.0, 0.001, 'x', LINE_WIDTH, 'y', 50.0); // white paint lane divider
            rectangle(0, 0, 1, -1 * LANE_WIDTH - LINE_WIDTH / 2.0, walkwayDistance + 1.0, 0.001, 'x', LINE_WIDTH, 'y', 50.0); // white paint lane divider
        }

        glPushMatrix();
        glTranslated(cornerCoordinate - cornerRadius, walkwayDistance, 0.001);
        for (double side = 0.0, translation = 0.0; side < 1.5; ++side, translation += -1 * LANE_WIDTH * numberOfLanes - MIDZONE_WIDTH / 2.0) {
            glTranslated(translation, 0.0, 0.0);
            for (double vertical = 0.0; vertical < MIDZONE_WIDTH; vertical += 0.45)
                rectangle(0, 0, 1, 0.0, vertical, 0.0, 'y', LINE_WIDTH, 'x', -1 * LANE_WIDTH * numberOfLanes + MIDZONE_WIDTH / 2.0); // walkway long lines
            double seperation = (LANE_WIDTH * numberOfLanes - MIDZONE_WIDTH / 2.0) / (numberOfLanes * 5);
            for (double bar = seperation; bar < LANE_WIDTH * numberOfLanes - MIDZONE_WIDTH / 2.0; bar += seperation)
                rectangle(0, 0, 1, -bar - LINE_WIDTH, LINE_WIDTH, 0.0, 'x', 0.1, 'y', 0.4);  // walkway short lines
        }
        glPopMatrix();

        setTexture(SIDEWALK);

        for(int i=0; i<midzoneLength[1];i++)
            rectangle(0, 0, 1, -0.25, midzoneLength[0]+i, BORDER_Z, 'x', MIDZONE_WIDTH, 'y', 1.0); // refuge rectangle top

        trianglePoints('0', '0', MIDZONE_WIDTH / -2.0, midzoneVector[1], BORDER_Z, MIDZONE_WIDTH / 2.0, midzoneVector[1], BORDER_Z, 0.0, midzoneVector[1] + midzoneLength[2], BORDER_Z); // refuge triangle top
        rectangle(0, -1, 0, -0.25, midzoneLength[0], 0, 'x', MIDZONE_WIDTH, 'z', BORDER_Z); // refuge vertical
        rectangle(1, 0, 0, 0.25, midzoneLength[0], 0, 'y', midzoneLength[1], 'z', BORDER_Z); // refuge vertical
        rectangle(-1, 0, 0, -0.25, midzoneLength[0], 0, 'z', BORDER_Z, 'y', midzoneLength[1]); // refuge vertical
        quadPoints(midzoneLength[2], 0.25, 0, 0.25, midzoneVector[1], 0.0, 0.0, midzoneVector[2], 0.0, 0.0, midzoneVector[2], BORDER_Z); // refuge vertical
        quadPoints(-midzoneLength[2], 0.25, 0, -0.25, midzoneVector[1], 0.0, -0.25, midzoneVector[1], BORDER_Z, 0.0, midzoneVector[2], BORDER_Z); // refuge vertical

        glPushMatrix();
        glTranslated(cornerCoordinate, cornerCoordinate, 0.0);
        glNormal3d(0, 1, 0);
        gluCylinder(quad, cornerRadius, cornerRadius, BORDER_Z + 0.002, 36, 1); // corner walkway vertical
        rectangle(-1, 0, 0, -cornerRadius, 0, 0, 'z', BORDER_Z + 0.003, 'y', 50.0); // walkway vertical
        rectangle(0, -1, 0, 0, -cornerRadius, 0, 'x', 50.0, 'z', BORDER_Z + 0.003); // walkway vertical

        glTranslated(0, 0, BORDER_Z);
        gluDisk(quad, cornerRadius - 0.05, cornerRadius, 36, 1); // corner border
        rectangle(0, 0, 1, -cornerRadius, 0.0, 0.002, 'x', BORDER_X, 'y', 25.0); // border
        rectangle(0, 0, 1, 0.0, -cornerRadius, 0.002, 'x', 25.0, 'y', BORDER_X); // border
        for (int i =0; i<=50; i++)
        {
            rectangle(0, 0, 1, -cornerCoordinate + walkwayDistance+i, -cornerRadius, 0.003, 'x', 1.0, 'y', MIDZONE_WIDTH); // roadside sidewalk
            rectangle(0, 0, 1, -cornerRadius, -cornerCoordinate + walkwayDistance+i, 0.003, 'x', MIDZONE_WIDTH, 'y', 1.0); // roadside sidewalk
        }
        quadPoints(0, 0, 1, -cornerRadius, -cornerCoordinate + walkwayDistance, 0.003,
                   -cornerCoordinate + walkwayDistance, -cornerRadius, 0.003,
                   -cornerCoordinate + walkwayDistance + sin(PI / 4.0), -cornerRadius, 0.003,
                   -cornerRadius, -cornerCoordinate + walkwayDistance + sin(PI / 4.0), 0.003); // diagonal walkway

        setTexture(TEXTUREGRASS02);
        glTranslated(0, 0, 0.001);
        gluQuadricDrawStyle(quad, GLU_FILL);
        gluQuadricTexture(quad, GL_TRUE);
        gluDisk(quad, 0.0, cornerRadius - BORDER_X, 50, 1); // corner grass
        for (int i=0; i<50; i++) {
            for (int j=0; j<50; j++)
                rectangle(0, 0, 1, i-cornerRadius+BORDER_X, j, 0.001, 'x', 1.0, 'y', 1.0); // grass

            rectangle(0, 0, 1, i, BORDER_X - cornerRadius, 0.001, 'x', 1.0, 'y', cornerRadius); // grass
        }

        //setTexture(GRASSGREEN);
        //gluDisk(quad, 0.0, cornerRadius - BORDER_X, 36, 1); // corner grass
        //rectangle(0, 0, 1, BORDER_X - cornerRadius, 0, 0.0, 'x', 50.0, 'y', 50.0); // grass
        //rectangle(0, 0, 1, 0, BORDER_X - cornerRadius, 0.0, 'x', 50.0, 'y', cornerRadius); // grass
        glPopMatrix();
        glRotated(90, 0, 0, 1);
    }
    glPopMatrix();
}


void Draw::building()
{
    glPushMatrix();
    glTranslated(2, 2, 0);
    glScaled(2, 2, 5);

    //Draw buildings for North East corner going east
    for (int buildingCount = 0; buildingCount <5; buildingCount++)
    {
        int stories = rand()%4+2;
        int textureNum = rand()%6+42;
        for (int count = 0; count<stories; count++) //where upper limit is number of stories
        {
            setTexture(textureNum);
            rectangle(1, 0, 0, 2 + (buildingCount*2.5), 2.5, 0.0 + count*0.4, 'y', 2, 'z', 0.4); // left side
            rectangle(-1, 0, 0, 2+ (buildingCount*2.5), 4.5, 0.0 + count*0.4, 'y', -1 * 2, 'z', 0.4); // right side
            rectangle(0, -1, 0, 2 + (buildingCount*2.5), 2.5, 0.0 + count*0.4, 'x', 2, 'z', 0.4); // front
            rectangle(0, 1, 0, 4 + (buildingCount*2.5), 4.5, 0.0 + count*0.4, 'x', -1 * 2, 'z', 0.4); // back
        }
    }

    //Draw buildings for North East corner going north
    for (int buildingCount = 0; buildingCount <5; buildingCount++)
    {
        int stories = rand()%4+2;
        int textureNum = rand()%6+42;
        for (int count = 0; count<stories; count++) //where upper limit is number of stories
        {
            setTexture(textureNum);
            rectangle(1, 0, 0, 1.5, 5 + (buildingCount*2.5), 0.0 + count*0.4, 'y', 2, 'z', 0.4); // left side
            rectangle(-1, 0, 0, 1.5, 7+ (buildingCount*2.5), 0.0 + count*0.4, 'y', -1 * 2, 'z', 0.4); // right side
            rectangle(0, -1, 0, 1.5, 5+ (buildingCount*2.5), 0.0 + count*0.4, 'x', 2, 'z', 0.4); // front
            rectangle(0, 1, 0, 3.5, 7+ (buildingCount*2.5), 0.0 + count*0.4, 'x', -1 * 2, 'z', 0.4); // back
        }
    }

    //Draw buildings for North West corner going west
    for (int buildingCount = 0; buildingCount <5; buildingCount++)
    {
        int stories = rand()%4+2;
        int textureNum = rand()%6+42;
        for (int count = 0; count<stories; count++) //where upper limit is number of stories
        {
            setTexture(textureNum);
            rectangle(1, 0, 0, -5.5 - (buildingCount*2.5), 1.5, 0.0 + count*0.4, 'y', 2, 'z', 0.4);
            rectangle(1, 0, 0, -7.5 - (buildingCount*2.5), 1.5, 0.0 + count*0.4, 'y', 2, 'z', 0.4);
            rectangle(1, 0, 0, -7.5 - (buildingCount*2.5), 3.5, 0.0 + count*0.4, 'x', 2, 'z', 0.4);
            rectangle(1, 0, 0, -7.5 - (buildingCount*2.5), 1.5, 0.0 + count*0.4, 'x', 2, 'z', 0.4);
        }
    }

    //Draw buildings for North West corner going north
    for (int buildingCount = 0; buildingCount <5; buildingCount++)
    {
        int stories = rand()%4+2;
        int textureNum = rand()%6+42;
        for (int count = 0; count<stories; count++) //where upper limit is number of stories
        {
            setTexture(textureNum);
            rectangle(1, 0, 0, -5.0, 4 + (buildingCount*2.5), 0.0 + count*0.4, 'y', 2, 'z', 0.4);
            rectangle(1, 0, 0, -7.0, 4 + (buildingCount*2.5), 0.0 + count*0.4, 'y', 2, 'z', 0.4);
            rectangle(1, 0, 0, -7.0, 6 + (buildingCount*2.5), 0.0 + count*0.4, 'x', 2, 'z', 0.4);
            rectangle(1, 0, 0, -7.0, 4 + (buildingCount*2.5), 0.0 + count*0.4, 'x', 2, 'z', 0.4);
        }
    }

    //Draw buildings for South West corner going West
    for (int buildingCount = 0; buildingCount <5; buildingCount++)
    {
        int stories = rand()%4+2;
        int textureNum = rand()%6+42;
        for (int count = 0; count<stories; count++) //where upper limit is number of stories
        {
            setTexture(textureNum);
            rectangle(1, 0, 0, -8.5 - (buildingCount*2.5), -5.5, 0.0 + count*0.4, 'y', 2, 'z', 0.4);
            rectangle(1, 0, 0, -6.5- (buildingCount*2.5), -5.5, 0.0 + count*0.4, 'y', 2, 'z', 0.4);
            rectangle(0, -1, 0, -6.5 - (buildingCount*2.5), -5.5, 0.0 + count*0.4, 'x', -2, 'z', 0.4);
            rectangle(0, -1, 0, -6.5 - (buildingCount*2.5), -3.5, 0.0 + count*0.4, 'x', -2, 'z', 0.4);
        }
    }

    //Draw buildings for South West corner going South
    for (int buildingCount = 0; buildingCount <5; buildingCount++)
    {
        int stories = rand()%4+2;
        int textureNum = rand()%6+42;
        for (int count = 0; count<stories; count++) //where upper limit is number of stories
        {
            setTexture(textureNum);
            rectangle(1, 0, 0, -8, -8  - (buildingCount*2.5), 0.0 + count*0.4, 'y', 2, 'z', 0.4);
            rectangle(1, 0, 0, -6, -8  - (buildingCount*2.5), 0.0 + count*0.4, 'y', 2, 'z', 0.4);
            rectangle(0, -1, 0, -6, -8  - (buildingCount*2.5), 0.0 + count*0.4, 'x', -2, 'z', 0.4);
            rectangle(0, -1, 0, -6, -6  - (buildingCount*2.5), 0.0 + count*0.4, 'x', -2, 'z', 0.4);
        }
    }

    //Draw buildings for South East corner going east
    for (int buildingCount = 0; buildingCount <5; buildingCount++)
    {
        int stories = rand()%4+2;
        int textureNum = rand()%6+42;
        for (int count = 0; count<stories; count++) //where upper limit is number of stories
        {
            setTexture(textureNum);
            rectangle(-1, 0, 0, 2+ (buildingCount*2.5), -3.5, 0.0 + count*0.4, 'y', -1 * 2, 'z', 0.4);
            rectangle(-1, 0, 0, 4+ (buildingCount*2.5), -3.5, 0.0 + count*0.4, 'y', -1 * 2, 'z', 0.4);
            rectangle(0, -1, 0, 2 + (buildingCount*2.5), -3.5, 0.0 + count*0.4, 'x', 2, 'z', 0.4);
            rectangle(0, 1, 0, 4 + (buildingCount*2.5), -3.5, 0.0 + count*0.4, 'x', -1 * 2, 'z', 0.4);
        }
    }

    //Draw buildings for South East corner going south
    for (int buildingCount = 0; buildingCount <5; buildingCount++)
    {
        int stories = rand()%4+2;
        int textureNum = rand()%6+42;
        for (int count = 0; count<stories; count++) //where upper limit is number of stories
        {
            setTexture(textureNum);
            rectangle(-1, 0, 0, 1.5, -6 - (buildingCount*2.5), 0.0 + count*0.4, 'y', -1 * 2, 'z', 0.4);
            rectangle(-1, 0, 0, 3.5, -6 - (buildingCount*2.5), 0.0 + count*0.4, 'y', -1 * 2, 'z', 0.4);
            rectangle(0, -1, 0, 1.5, -6 - (buildingCount*2.5), 0.0 + count*0.4, 'x', 2, 'z', 0.4);
            rectangle(0, 1, 0, 3.5, -6 - (buildingCount*2.5), 0.0 + count*0.4, 'x', -1 * 2, 'z', 0.4);
        }
    }

    glPopMatrix();
}

void Draw::tree(double scale, double x, double y, double z) {
    glPushMatrix();
    glTranslated(x, y, z);
    glScaled(scale, scale, scale);

    setTexture(TREEBROWN);
    gluCylinder(quad, 0.05, 0.05, 0.15, 25, 25);

    setTexture(TREEGREEN);
    for (double count = 0; count <= 1.0; count += 0.05) {
        for (int count2 = 0; count2 < 180; count2 += 10) {
            glPushMatrix();
            glRotated(rand() % 11 - 5, 0, 0, 1);

            double y = count / ((rand()% 11) / 20.0 + 1.75);

            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2d(0,0); glVertex3d(-count/ 10.0, 0.0, 1.15 - count);
            glNormal3d(0, 1 / -sqrt(2.0), 1 / sqrt(2.0));
            glTexCoord2d(1,0); glVertex3d(0.0, -y, 1.05 - count);
            glNormal3d(0, 0, 1);
            glTexCoord2d(1,1); glVertex3d(count / 10.0, 0.0, 1.15 - count);
            glNormal3d(0, 1 / sqrt(2.0), 1 / sqrt(2.0));
            glTexCoord2d(0,1); glVertex3d(0.0, y, 1.05 - count);
            glEnd();

            glBegin(GL_QUADS);
            glNormal3d(0, 0, 1);
            glTexCoord2d(0,0); glVertex3d(-count/ 10.0, 0.0, 1.15 - count);
            glNormal3d(0, 1 / sqrt(2.0), -1 / sqrt(2.0));
            glTexCoord2d(1,0); glVertex3d(0.0, y, 1.05 - count);
            glNormal3d(0, 0, 1);
            glTexCoord2d(1,1); glVertex3d(count / 10.0, 0.0, 1.15 - count);
            glNormal3d(0, -1 / sqrt(2.0), -1 / sqrt(2.0));
            glTexCoord2d(0,1); glVertex3d(0.0, -y, 1.05 - count);
            glEnd();

            glPopMatrix();
            glRotated(10, 0, 0, 1);
        }
    }
    glPopMatrix();
}

double Draw::treeCoordinate(int a) {
    if (a < 0)
        a = -1;
    else
        a = 1;
    double coord = (walkwayDistance + MIDZONE_WIDTH - LANE_WIDTH * numberOfLanes) / 2.0 + LANE_WIDTH * numberOfLanes;
    int coordinate = int(coord) + 1;
    return a * (coordinate + rand() % (50 - coordinate));
}

//Determine if demo mode is selected based off call to database
void::Draw::get_database_mode()
{
    QString modeConfigured;
    if (db.isOpen())
    {
        QString readStatement = ("SELECT mode FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next())
            {
                modeConfigured = qry.value(0).toString();
            }

            if (QString::compare("demo", modeConfigured, Qt::CaseInsensitive)==0)
            {
                demoMode = true;
            }

            else
            {
                demoMode = false;
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }
        if (demoMode == true)
        {
            numberOfLanes = 2;
            //centerHeight = 1.0/3.0;
            //printf("center height: %f \n", centerHeight);
        }


    }
    else
    {
        qDebug() << "Draw failed to open database connection to pull data.";
    }
}

//Determine if demo mode is selected based off call to database
void::Draw::get_centerheight()
{
    if (db.isOpen())
    {
        QString readStatement = ("SELECT median_height FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next())
            {
                //centerHeight = qry.value(0).toDouble();
                //centerHeight +=0.01;
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR here!"),db.lastError().text());
        }
    }
    else
    {
        qDebug() << "Draw failed to open database connection to pull data.";
    }
}
