#ifndef DEMOGRAPHICS_H
#define DEMOGRAPHICS_H

#include "ui_demographics.h"
#include "data.h"
#include "ve.h"
#include "vuzixthread.h"
#include "calibrateRotation.h"
#include "iweardrv.h"
#include <QDialog>
#include <QDebug>
#include <QString>
#include <QtGui/QApplication>
#include <QtCore/QCoreApplication>
#include <QSqlDatabase>
#include <QStringList>
#include <QtSql>
#include <QSqlDriver>
#include <QMessageBox>
#include <QObject>


namespace Ui {
    class Demographics;
}

class Demographics : public QDialog
{
    /* responsible for getting info from user then writing it using data class
       and then starting ve class
    */
    Q_OBJECT

public:
    explicit Demographics(QWidget *parent = 0);
    ~Demographics();
    void setPid(int personalIdentification);
    void database_connect();
    void database_insert_config();
    void database_select_config();
    void get_last_id();
    void write_new_id();

    //get functions
    QString getSex();
    int getAge();
    int getId();
    QString getDominance();
    int getHeight();
    VE virtuale;

    int participantid;
    int referenceid;
    int vehiclequantityslider;
    int intensityslider;
    int age;
    bool male;
    bool female;
    bool neongreen;
    bool neonpink;
    bool neonorange;
    bool trafficenable;
    bool trafficdisable;
    bool singlelane;
    bool unsafeenable;
    bool unsafedisable;
    bool doublelane;
    bool demo;
    bool trial;
    bool lefthanded;
    bool righthanded;
    QString sex;
    QString dominance;
    int participantheight;
    int trialquantity;
    QString lowerDateRange;
    QString upperDateRange;
    bool headControl;
    bool shoulderControl;
    bool calibrateAccessedFlag;

    //Data data; // writes files for demographics
     // top class for all VE code
    //calibrateRotation *calibrateMe; //class for opening calibration menu


private:
    Ui::Demographics *ui;
    //const static int timer_interval = 20; // number of msecs updateScene() is called
    //Database variables
    QSqlDatabase db;


private slots:
    void on_quit_clicked();
    void on_cancel_clicked();
    void on_datum_clicked();
    void on_download_clicked();
    void on_calibrate_clicked();
    void on_male_clicked();
    void on_female_clicked();
    void on_neongreen_clicked();
    void on_neonpink_clicked();
    void on_neonorange_clicked();
    void on_trafficenable_clicked();
    void on_trafficdisable_clicked();
    void on_singlelane_clicked();
    void on_doublelane_clicked();
    void on_demo_clicked();
    void on_trial_clicked();
    void on_righthanded_clicked();
    void on_lefthanded_clicked();
    void on_unsafeenable_clicked();
    void on_unsafedisable_clicked();
    void on_shoulderControl_clicked();
    void on_headControl_clicked();

private:
    calibrateRotation calibration; //Needed to open the calibrateRotation window

};

#endif // DEMOGRAPHICS_H
