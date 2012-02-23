#include "data.h"

Data::Data()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DEMOGRAPHICS

void Data::writeDemographics(int pid, QString age, QString sex, QString dominance)
{
    QString f = "Demographics";
    if (!QDir(f).exists())
        QDir().mkdir(f);

    QString personId = QString::number(pid);
    if (pid < 10)
        personId.prepend("0");
    filename[DEMOGRAPHICS] = QString("Demographics/") + "P"+ personId + QString("_Demographics.txt");
    file[DEMOGRAPHICS].setFileName(filename[DEMOGRAPHICS]);
    text[DEMOGRAPHICS].setDevice(&file[DEMOGRAPHICS]);

    file[DEMOGRAPHICS].open(QIODevice::WriteOnly | QIODevice::Text);

    text[DEMOGRAPHICS].setFieldWidth(20);
    text[DEMOGRAPHICS] << "PID" << "Name" << "Age" << "Gender" << "Ethnicity" << "Faculty" << endl;
    text[DEMOGRAPHICS] << personId << name << age << gender << ethnicity << faculty;

    file[DEMOGRAPHICS].close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SPECS

void Data::read_specs() {
    filename[SPECS] = "Setup/specs.txt";

    file[SPECS].setFileName(filename[SPECS]);
    text[SPECS].setDevice(&file[SPECS]);
    file[SPECS].open(QIODevice::ReadOnly);

    QString null;

    text[SPECS] >> null >> numberOfTrials;
    if (numberOfTrials > 100 || numberOfTrials < 1)
        qDebug() << "read number of trials error" << numberOfTrials;
    for (int count = 0; count <= 8; ++count)
        text[SPECS] >> null;
    for (int count = 0; count < numberOfTrials; ++count) {
        text[SPECS] >> trials[count];
        for (int gap = 0; gap < 5; ++gap)
            text[SPECS] >> gaps[count][gap];
        text[SPECS] >> speeds[count] >> startPos[count] >> popUps[count];

        if (trials[count].size() > 2)
            qDebug() << "read trials error" << trials[count];
        for (int gap = 0; gap < 5; ++gap)
            if ((speeds[count] != 0 && !(gaps[count][gap] == 2 || gaps[count][gap] == 4 || gaps[count][gap] == 6 || gaps[count][gap] == 8 || gaps[count][gap] == 10))
                || (speeds[count] == 0 && gaps[0][gap] != 0))
                qDebug() << "read gap error" << gaps[count][gap];
        if (speeds[count] < 0 || speeds[count] > 100)
            qDebug() << "read speed error" << speeds[count];
        if (!(startPos[count] == "A" || startPos[count] == "B"))
            qDebug() << "read start position error" << startPos[count];
        if (!(popUps[count] == "none" || popUps[count] == "startpractice" || popUps[count] == "starttrials"))
            qDebug() << "read pop ups error" << popUps[count];
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DATA

void Data::writeIntro(QString f) {
    filename[DATA] = f;
    if (!QDir("Data").exists())
        QDir().mkdir("Data");

    file[DATA].setFileName(filename[DATA]);
    text[DATA].setDevice(&file[DATA]);
    file[DATA].open(QIODevice::WriteOnly | QIODevice::Text);
    text[DATA].setFieldWidth(20);
    text[DATA] <<  "trial" << "start" << "time_starttrial" << "time_bumper" << "time_step" << "time_latency" << "time_arrive" << "time_crossing" << "steps" << "gap_chosen" << endl;
}

void Data::updateinfo(int p) {
    if (start == "A") {
        if (position == SIDE && p == ROAD) {
            time_step = time - time_starttrial;
            time_latency = time_step - time_bumper;
            step = true;
        }
        else if (position == ROAD && p == REFUGE) {
            time_arrive = time - time_starttrial;
            time_crossing = time_arrive - time_step;
        }
    }
    else if (start == "B") {
        if (position == REFUGE && p == ROAD) {
            time_step = time - time_starttrial;
            time_latency = time_step - time_bumper;
            step = true;
        }
        else if (position == ROAD && p == SIDE) {
            time_arrive = time - time_starttrial;
            time_crossing = time_arrive - time_step;
        }
    }
    position = p;
}

void Data::writeData(QString trial, bool failed) {
    if (failed)
        trial.prepend("failed_");
    text[DATA] <<  trial << start << time_starttrial << time_bumper << time_step << time_latency << time_arrive << time_crossing << steps << gap_chosen << endl;

    time_bumper = 0.0;
    time_step = 0.0;
    time_latency = 0.0;
    time_crossing = 0.0;
    time_arrive = 0.0;
    gap_chosen = 0;
    steps = 0;

    step = false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PEDESTRIAN

void Data::setPedestrian(QString f) {
    filename[PEDESTRIAN] = f;
    file[PEDESTRIAN].setFileName(filename[PEDESTRIAN]);
    text[PEDESTRIAN].setDevice(&file[PEDESTRIAN]);
    file[PEDESTRIAN].open(QIODevice::WriteOnly | QIODevice::Text);
    text[PEDESTRIAN].setFieldWidth(10);
    text[PEDESTRIAN] << "trial" << "time" << "xTrans" << "yTrans" << "zTrans" << "xRot" << "yRot" << "zRot" << endl;
}

void Data::writePedestrian(QString trial, double xTrans, double yTrans, double zTrans, double xRot, double yRot, double zRot) {
    text[PEDESTRIAN] << trial << time << xTrans << yTrans << zTrans << xRot << yRot << zRot << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CARS

QString Data::setCars(int pid) {
    filename[CARS] = "Cars";
    if (!QDir(filename[CARS]).exists())
        QDir().mkdir(filename[CARS]);
    filename[CARS].append("/P");

    QString id = QString::number(pid);
    if (pid < 10)
        id.prepend("0");
    filename[CARS].append(id + "_Cars.txt");
    file[CARS].setFileName(filename[CARS]);
    text[CARS].setDevice(&file[CARS]);
    file[CARS].open(QIODevice::WriteOnly | QIODevice::Text);
    text[CARS].setFieldWidth(10);

    return id;
}

void Data::writeCars_trial(QString trial, double time, bool trials, bool practice, bool white, bool failed) {
    if (trials)
        text[CARS] << "starttrials_" + trial;
    else if (practice)
        text[CARS] << "startpractice_" + trial;
    else if (white)
        text[CARS] << "white_" + trial;
    else if (failed)
        text[CARS] << "fail_" + trial;
    else
        text[CARS] << trial;
    text[CARS] << time;
}

void Data::writeCars(double a, double b, double c) {
    text[CARS] << a << b << c << " ";
}

void Data::writeCars_endl() {
    text[CARS] << endl;
}
