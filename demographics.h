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
    QString getGender();
    QString getAge();
    int getId();
    QString getName();
    QString getEthnicity();
    QString getFaculty();

    QString name;
    int id;
    QString age;
    bool male;
    bool female;
    QString gender;
    QString ethnicity;
    QString faculty;
    QString program;

    Data data; // writes files for demographics
    VE virtuale; // top class for all VE code


private:
    Ui::Demographics *ui;
    void setErrorStars(bool flags);

private slots:
    void on_quit_clicked();
    void on_male_clicked();
    void on_female_clicked();
};

#endif // DEMOGRAPHICS_H
