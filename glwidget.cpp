#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    object = 0;
    backgroundColor = Qt::white;
    prevRotation = 0;
    hit = false;

    shoulderRot = 0.0;
    headRot = 0.0;
    time = 0.0;
    started = false;

    this->database_connect();



    //setMouseTracking(true);
}

GLWidget::~GLWidget()
{
    makeCurrent();
    glDeleteLists(object, 1);
}

void GLWidget::setPedestrian(double x, double y, double mid) {

    startingyTrans[0] = y;
    startingyTrans[1] = 0.0;
    startingxTrans[0] = x; //This is about at the cross walk
    startingrotation[0] = 270;

    startPos = tc.get_start();
    if (startPos == "A")
        start = 0;
    else
        start = 1;
    yTrans = startingyTrans[start];
    xTrans = startingxTrans[0];
    setZRotation(startingrotation[start]);

    maxTrans = fabs(y) + mid; // mid is half of walkway path width

    object = makeObject();
}

void GLWidget::set_recording() {
    started = true;
}

void GLWidget::set_window(int x, int y) {
    window_width = x;
    window_height = y;
    lcd.setGeometry(0, 0, x, y);
    lcd.setDigitCount(1);

}

void GLWidget::setXRotation(double angle)
{
    if (angle != xRot) { //&& angle >= 180 && angle <= 360) {
        xRot = angle;
        //updateGL();
    }
    //qDebug("xRot: %d", angle);
}

void GLWidget::setYRotation(double angle)
{
    if (angle != yRot && (angle <= 90.0 || angle >= 5670.0)) {
        yRot = angle;
        //updateGL();
    }
    //qDebug("yRot: %d", angle);
}

void GLWidget::setZRotation(double angle)
{
    if (angle != zRot) {
        zRot = angle;
        if (zRot < 0.0) {
            do {
                zRot += 360.0;
            } while(zRot < 0.0);
        }
        else if (zRot > 360.0) {
            do {
                zRot -= 360.0;
            } while(zRot > 360.0);
        }
    }
}

void GLWidget::setTranslation(double mag, double z) { // connected to senddata(double,double) signal in collectdata which runs update slot in mywindow

    qDebug() << "mag " << mag << " z " << z;
    if (!hit) {
        if (!(tc.get_screen()))
            motorSpeed = mag;
        else
            motorSpeed = 0.0;
        zTrans = z;
    }
}

void GLWidget::setArduinoTranslation(int potRot)
{
    currRotation = potRot;
    //qDebug() << "potRot:    " << potRot;
    if(!hit) {
        if(!(tc.get_screen()))
            motorSpeed = 0.00; //abs(currRotation - prevRotation) * PI / 180.0 * 0.14;
         else
            motorSpeed = 0.0; //0.0;
    }
    //zTrans = height / 30.0 * sin(PI * (rValueNXT + 20) / 40) + height + height / 30;
    prevRotation = currRotation;
    zTrans = 0.5;
}

void GLWidget::rotation(double anglediff)
{
    if (!(tc.get_screen()))
        compassSpeed = anglediff;
    else
        compassSpeed = 0.0;

    qDebug() << "compassSpeed rotation" << compassSpeed;
}

void GLWidget::Zrotation(double anglediff)
{
    if (!(tc.get_screen())) {
        zcompassSpeed = anglediff;
       // qDebug() << "compassSpeed Zrotation  " << compassSpeed;
    }
    else
        zcompassSpeed = 0.0;
}

void GLWidget::Xrotation(double anglediff)
{
    if (!(tc.get_screen()))
        xcompassSpeed = anglediff;
    else
        xcompassSpeed = 0.0;
}

void GLWidget::Yrotation(double anglediff)
{
    if(!tc.get_screen())
        ycompassSpeed = anglediff;
    else
        ycompassSpeed = 0.0;
}

void GLWidget::updateScene() {
    get_tracker_settings();

    if (tc.get_screen())
        updateGL();

    else if (started) {
        setArduinoTranslation(arduinoThread.output());
        //qDebug() << "zRotation: " << compassSpeed;
        setXRotation(xcompassSpeed);
        setYRotation(ycompassSpeed);
        if (QString::compare("shoulder", directionalControlMethod, Qt::CaseInsensitive)==0)
        {
            shoulderRot += (angularAccelActual*0.0015);//0.0075 was tuned value for laptop/slow system time
            headRot += (zcompassSpeed*2.25);
            setZRotation(zRot+(zcompassSpeed*2.20)+(angularAccelActual*0.0015));//0.0075 was tuned value for laptop/slow system time
        }
        else
        {
            headRot += (zcompassSpeed*2.25);
            setZRotation(zRot+(zcompassSpeed*2.20));
        }


        double y;
        double x;

        //qDebug() << "motoSpeed" << motorSpeed;
        //qDebug() << "calc " << (zRot+(zcompassSpeed*2.25)+(angularAccelActual*0.0075));
        //motorSpeed = .1; //Remove when working with actual motor

        if (QString::compare("shoulder", directionalControlMethod, Qt::CaseInsensitive)==0)
        {
            y = (yTrans + (motorSpeed*cos(shoulderRot*PI/180)));
            x = (xTrans + (motorSpeed*sin(shoulderRot*PI/180)));
        }
        else{
            y = (yTrans + (motorSpeed*cos((zRot-(zcompassSpeed*2.25))*PI/180)));
            x = (xTrans + (motorSpeed*sin((zRot-(zcompassSpeed*2.25))*PI/180)));
        }

        //qDebug() << "xy [" << x << "," << y << "]";
        //qDebug() << "motorSpeed " << motorSpeed << " angle: " << angularAccelActual << "xy [" << x << "," << y << "]";
        //if (fabs(y) <= maxTrans && fabs(x) >= maxTrans) {
            yTrans = y;
            xTrans = x;
        //}

            //printf("xRot [%f] yRot [%f] zRot[%f}\n", xRot, yRot, zRot);
        //tc.data.writePedestrian(tc.get_trials(), xTrans, yTrans, zTrans, xRot, yRot, zRot);

       if ((startPos == "A" && yTrans >= startingyTrans[1] && fabs(xTrans-startingxTrans[0]) <= 1) || (startPos == "B" && yTrans <= startingyTrans[0])) {
            tc.nexttrial();
            startPos = tc.get_start();
            if (startPos == "A")
                start = 0;
            else
                start = 1;
            yTrans = startingyTrans[start];
            xTrans = startingxTrans[start];
           // setZRotation(startingrotation[start]);
        }
        updateGL();
    }
}

//! [6]
void GLWidget::initializeGL()
{
    setXRotation(270.0); //270 results in normal view, 290 gives 20 degrees below horizontal
    setYRotation(0.0);
    setZRotation(0.0);

    qglClearColor(backgroundColor);
    glShadeModel(GL_SMOOTH);	//or GL_SMOOTH
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glEnable(GL_TEXTURE_2D);

    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    GLfloat LightAmbient[]= { 3.0f, 3.0f, 3.0f, 1.0f }; //ambient light values
    GLfloat LightDiffuse[]= { 5.0f, 5.0f, 5.0f, 1.0f }; //diffuse light values
    GLfloat LightDirection[]= { 0.0f, -0.5f, 1.0f, 0.0f };

    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient); //setup ambient
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse); //setup diffuse
    glLightfv(GL_LIGHT1, GL_POSITION, LightDirection); //direct the light
    glEnable(GL_LIGHT1);

    glEnable(GL_LIGHTING);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    tc.updatePedestrian(xTrans, yTrans, zRot);

    if (tc.limits.hit && !tc.get_failed()) {
        QSound::play("wilhelm.wav");
        yTrans = startingyTrans[start];
        xTrans = startingxTrans[0];
        setZRotation(startingrotation[start]);
        tc.resettrial();
    }

    if (tc.get_screen()) {
        tc.update();
        if (tc.get_screen(3)) { // 3 is for whitescreen
            lcd.display(tc.get_display());
            lcd.show();
        }
    }
    else {
        lcd.hide();
        glRotated(xRot, 1.0, 0.0, 0.0);
        glRotated(yRot, 0.0, 1.0, 0.0);
        glRotated(zRot, 0.0, 0.0, 1.0); // heading is direction your walking, zRot is direction your looking.
        //zRot is relative to heading so if your looking towards center of roundabout and walking, you will continue to look there until you actively change zRot

        if (tc.limits.elevated) // if on a sidwalk or not on road
            elevated = 0.02;
        else
            elevated = 0.0;

        if (!tc.limits.stopped) {
            glTranslated(-xTrans, -yTrans, -zTrans - elevated); // must move environment backward to move yourself forward, hence negative signs
            glCallList(object);
        }

        tc.update(); // updates traffic control and all of its cars
       // qDebug() << "else";
    }
}

void GLWidget::resizeGL(int width, int height)
{
   /* int side = qMin(width, height);
//    glViewport((width - side) / 2, (height - side) / 2, side, side);

    qDebug("Value of side: %d", side);
    //glViewport(0,0, side, side);

    width=1;
    height=1;
*/
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(50.0, double(window_width) / double(window_height), 0.1, 140.0);
    glViewport(0, 0, window_width, window_height);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

GLuint GLWidget::makeObject()
{
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);

    tc.draw.environment(); // draws all static parts of environment

    glEndList();
    return list;

}

//Determine value of angularAccelActual
void GLWidget::determineAngularAccel(double alphaActual)
{
    get_calibration_settings();
    //If it has not been calibrated, just use a default weighting to turn
    if (alphaRightMax == 0 && alphaLeftMax ==0)
    {
        if(alphaActual > alphaRightMin){
            angularAccelActual = angularAccelMaximum;
        }
        else if (alphaActual < alphaLeftMin)
            angularAccelActual = -1*angularAccelMaximum;
        else
            angularAccelActual = 0;
    }

    //Actual turning algorithm if the camera has been calibrated
    else
    {
        //Adjust values based on center value captured during calibration
        alphaActual -= alphaZeroPosition;
        if (alphaActual > alphaRightMin)
        {
            angularAccelActual = (abs(alphaRightMax)-abs(alphaActual))/(abs(alphaRightMax)-abs(alphaRightMin));
        }
        else if (alphaActual < alphaLeftMin)
        {
            angularAccelActual = -1*(abs(alphaLeftMax)-abs(alphaActual))/(abs(alphaLeftMax)-abs(alphaLeftMin));
        }
        else
            angularAccelActual = 0;
    }
}

void GLWidget::database_connect()
{
    db = QSqlDatabase::addDatabase("QPSQL", "glWidgetConnect");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("abc123");
    db.setDatabaseName("configDb");
    db.open();
}

void GLWidget::get_tracker_settings()
{
    if (db.isOpen())
    {
        QString readStatement = ("SELECT directional_control FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                directionalControlMethod = qry.value(0).toString();
                //qDebug() << "Control selected from DB:" << directionalControlMethod;
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }

    }
    else
    {
        qDebug() << "GLWidget failed to open database connection to pull data.";
    }
}

void GLWidget::get_calibration_settings()
{
    if (db.isOpen())
    {
        QString readStatement = ("SELECT left_calibration FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                alphaLeftMax = qry.value(0).toDouble();
                //qDebug() << "Control selected from DB:" << directionalControlMethod;
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }

    }
    else
    {
        qDebug() << "GLWidget failed to open database connection to pull data.";
    }
    if (db.isOpen())
    {
        QString readStatement = ("SELECT right_calibration FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                alphaRightMax = qry.value(0).toDouble();
                //qDebug() << "Control selected from DB:" << directionalControlMethod;
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }

    }
    else
    {
        qDebug() << "GLWidget failed to open database connection to pull data.";
    }
    if (db.isOpen())
    {
        QString readStatement = ("SELECT center_calibration FROM trialconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                alphaZeroPosition = qry.value(0).toDouble();
                //qDebug() << "Control selected from DB:" << directionalControlMethod;
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }

    }
    else
    {
        qDebug() << "GLWidget failed to open database connection to pull data.";
    }
}
