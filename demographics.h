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

    //get functions
    QString getSex();
    QString getAge();
    int getId();
    QString getDominance();
    QString getHeight();

    int id;
    int vehiclequantityslider;
    int intensityslider;
    QString age;
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
    QString participantheight;
    QString trialquantity;
    QString lowerDateRange;
    QString upperDateRange;

    Data data; // writes files for demographics
    VE virtuale; // top class for all VE code


private:
    Ui::Demographics *ui;

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

};

#endif // DEMOGRAPHICS_H
