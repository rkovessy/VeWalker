#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QSqlDatabase>
#include <QStringList>
#include <QtSql>
#include <QSqlDriver>
#include <QMessageBox>
#include <QObject>
#include "poisson.h"

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
    void get_numberOfTrials();
    void connect_to_database();
    void get_mode();
    void get_trafficIntensity();
    void generate_interarrival_time();
    void get_numberOfCars();
    void get_trafficEnable();
    void get_unsafeCrossing();
    void get_referenceId();
    void get_participantId();

    void get_traffic_speed();
    int trafficSpeed;
    int numberOfCars;
    int referenceId;
    int participantId;
    double trafficIntensity;
    const static double unsafeCrossingInterarrival = 2.5;
    bool demoMode;
    bool unsafeCrossingEnable;
    double time; // time program has been running
    void read_specs(); // reads from spec file
    int numberOfTrials; // number of trials including practice trials
    QString trials[100]; // for output files
    QString startPos[200]; // whether pedestrian starts on A or B
    QString popUps[200]; // when and which popups appear
    double speeds[200]; // speeds defined for each trial
    double gaps[200][100]; // seperation times, where array is path, trial, time
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
    void updateinfo(int position); // updates position of pedestrian, where some of the data is recorded, ex time1_step
    void writeData(QString, bool failed = false); // writes data after trial ended or failed

private:
    QSqlDatabase db;
};

#endif // DATA_H
