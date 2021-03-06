#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>

enum directory {DEMOGRAPHICS, SPECS, DATA, PEDESTRIAN, CARS};
enum roadclassification {SIDE, ROAD, REFUGE};

class Data
{
    /* responsible for all reading and writing of text files
       broken down into 5 parts, as described in enum directory
       demographics is written when demographics is closed
       specs is for reading the spec file and transfering data to trafficcontrol
       data is written at the end of each trial, some logic for determining some parameters are done here
       pedestrian is written every time the screen is updated (20 msec now)
       cars is written every time the screen is updated as well
    */
public:
    Data();

    QString filename[5];
    QFile file[5];
    QTextStream text[5];

    double time; // time program has been running

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //DEMOGRAPHICS

    void writeDemographics(int pid, QString name, QString age, QString gender, QString ethnicity, QString faculty);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SPECS

    void read_specs(); // reads from spec file
    int numberOfTrials; // number of trials including practice trials
    QString trials[100]; // for output files
    QString startPos[100]; // whether pedestrian starts on A or B
    QString popUps[100]; // when and which popups appear
    double speeds[100]; // speeds defined for each trial
    int gaps[100][5]; // seperation times, where array is path, trial, time

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //DATA

    QString start; // A or B
    double time_starttrial; // global time the trial has started
    double time_bumper; // trial time that the last bumper crossed pedestrian before the pedestrian crosses the road
    double time_step; // trial time the pedestrian goes onto the road
    double time_latency; // time_step - time_bumper
    double time_arrive; // trial time pedestrian gets off the road
    double time_crossing; // time_arrive - time_step
    int steps; // number of times foot was planted on road
    int gap_chosen; // time gap between cars the pedestrian accepted

    int position; // holds enum roadclassification for where the pedestrian is
    bool step; // true if step has been taken onto road

    void writeIntro(QString f); // writes header for data file
    void updateinfo(int position); // updates position of pedestrian, where some of the data is recorded, ex time1_step
    void writeData(QString, bool failed = false); // writes data after trial ended or failed

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //PEDESTRIAN

    void setPedestrian(QString filename); // sets filename for pedestrian file
    void writePedestrian(QString trial, double xTrans, double yTrans, double zTrans,
                         double xRot, double yRot, double zRot); // writes pedestrian file

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //CARS

    QString setCars(int id);
    void writeCars_trial(QString trial, double time, bool trials, bool practice, bool white, bool failed);
    void writeCars(double, double, double);
    void writeCars_endl();
};

#endif // DATA_H
