#include "mywindow.h"

MyWindow::MyWindow()
{
    glWidget = new GLWidget();
    settingLayout();
    setWindowTitle(tr("Walker Scene"));
    replay = false;
    glWidget->set_window(window_width, window_height);
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

