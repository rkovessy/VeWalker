#ifndef DEMOGRAPHICS_H
#define DEMOGRAPHICS_H

#include "data.h"
#include "ve.h"
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

    QString name;
    int id;
    QString age;
    bool male;
    bool female;
    bool neongreen;
    bool neonpink;
    bool neonorange;
    bool trafficenable;
    bool trafficdisable;
    bool singlelane;
    bool doublelane;
    bool demo;
    bool trial;
    bool left;
    bool right;
    QString sex;
    QString dominance;
    QString height;

    Data data; // writes files for demographics
    VE virtuale; // top class for all VE code


private:
    Ui::Demographics *ui;
    void setErrorStars(bool flags);

private slots:
    void on_quit_clicked();
    void on_male_clicked();
    void on_female_clicked();
    void on_green_clicked();
    void on_pink_clicked();
    void on_orange_clicked();
    void on_trafficenable_clicked();
    void on_traffic_disable_clicked();
    void on_singlelane_clicked();
    void on_doublelane_clicked();
    void on_demo_clicked();
    void on_trial_clicked();
    void on_right_clicked();
    void on_left_clicked();

};

#endif // DEMOGRAPHICS_H
