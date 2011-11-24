#include "mywindow.h"

MyWindow::MyWindow()
{
    glWidget = new GLWidget();
    settingLayout();
    setWindowTitle(tr("Walker Scene"));
    replay = false;
    glWidget->set_window(window_width, window_height);
    setMouseTracking(true);
}

void MyWindow::settingLayout() {
    glWidget->setGeometry(0,0,window_width,window_height);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(glWidget);
    setLayout(mainLayout);
    this->setGeometry(0,0,window_width,window_height);//1920 by 1080
}

 void MyWindow::set(int pid) {
     QString id = QString::number(pid);;
     if (pid < 10)
         id.prepend("0");QString::number(pid);
     QString filename = "Pedestrian/P" + id + "_Pedestrian.txt";
     glWidget->tc.data.setPedestrian(filename);

     glWidget->tc.set(pid);
     double x = glWidget->tc.draw.get_walkwayDistance() + glWidget->tc.draw.MIDZONE_WIDTH / 2.0;
     double y = -1 * (glWidget->tc.draw.LANE_WIDTH * glWidget->tc.draw.get_numberOfLanes() + glWidget->tc.draw.MIDZONE_WIDTH / 2.0);
     glWidget->setPedestrian(x, y, glWidget->tc.draw.MIDZONE_WIDTH / 2.0);
     glWidget->set_recording();
 }

 void MyWindow::set_replay() {
     replay = true;
 }

 void MyWindow::keyPressEvent(QKeyEvent *e) {
     switch ( e->key() )
     {
        case Qt::Key_Left:
            glWidget->Zrotation(-1);
            break;
        case Qt::Key_Right:
            glWidget->Zrotation(1);
            break;
        case Qt::Key_Up:
            glWidget->Xrotation(1);
            break;
        case Qt::Key_Down:
            glWidget->Xrotation(-1);
            break;

     }
 }

 void MyWindow::keyReleaseEvent(QKeyEvent *e) {
     switch ( e->key() )
     {
        case Qt::Key_Left:
            glWidget->Zrotation(0);
            break;
        case Qt::Key_Right:
            glWidget->Zrotation(0);
            break;
        case Qt::Key_Up:
            glWidget->Xrotation(0);
            break;
        case Qt::Key_Down:
            glWidget->Xrotation(0);
            break;

     }
 }

 //captures the mouse movement to rotate the screen
 void MyWindow::mouseMoveEvent(QMouseEvent *e) {

     //up and down rotation
     if(e->x() > previousXPos) {
         glWidget->Zrotation(1);
     } else if(e->x() < previousXPos) {
         glWidget->Zrotation(-1);
     } else
         glWidget->Zrotation(0);

     //left/right rotation
     if(e->y() > previousYPos) {
         glWidget->Xrotation(1);
     } else if(e->y() < previousYPos) {
         glWidget->Xrotation(-1);
     } else
         glWidget->Xrotation(0);

     previousXPos = e->x();
     previousYPos = e->y();

 }

 void MyWindow::updateScene() {
     glWidget->updateScene();
 }

 void MyWindow::updateMotor(double m, bool s, double z) {
     if (s && glWidget->tc.data.step && glWidget->tc.data.time_arrive == 0.0)
         glWidget->tc.data.steps++;
     glWidget->setTranslation(m, z); // updates GLWidget, connected to sendMotor(...) signal from legoThread
 }

 void MyWindow::updateCompass(double anglediff) {
     glWidget->rotation(anglediff);
 }

void MyWindow::updateCameraValues(int x1, int x2, int y1, int y2){

}
