#include "demographics.h"
#include "ui_demographics.h"

Demographics::Demographics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demographics)
{
    ui->setupUi(this);
    ui->dateupperrange->setDate(QDate::currentDate());
}

//destructor
Demographics::~Demographics()
{
    delete ui;
}


//logic to select only a male or female radio button, but not both
void Demographics::on_female_clicked()
{
    if (ui->male->isChecked())
        ui->male->setChecked(false);
    else
        ui->female->setChecked(true);
}

void Demographics::on_male_clicked()
{
    if(ui->female->isChecked())
        ui->female->setChecked(false);
    else
        ui->male->setChecked(true);
}

//logic to select only a right or left dominance, but not both
void Demographics::on_righthanded_clicked()
{
    if (ui->lefthanded->isChecked())
        ui->lefthanded->setChecked(false);
    else
        ui->righthanded->setChecked(true);
}

void Demographics::on_lefthanded_clicked()
{
    if(ui->righthanded->isChecked())
        ui->righthanded->setChecked(false);
    else
        ui->lefthanded->setChecked(true);
}

//logic to select only trial or demo mode radio button, but not both
void Demographics::on_trial_clicked()
{
    if (ui->demo->isChecked())
        ui->demo->setChecked(false);
    else
        ui->trial->setChecked(true);
}

void Demographics::on_demo_clicked()
{
    if(ui->trial->isChecked())
        ui->trial->setChecked(false);
    else
        ui->demo->setChecked(true);
}

//logic to select only unsafe intensity enable or disable, but not both
void Demographics::on_unsafeenable_clicked()
{
    if (ui->unsafedisable->isChecked())
        ui->unsafedisable->setChecked(false);
    else
        ui->unsafeenable->setChecked(true);
}

void Demographics::on_unsafedisable_clicked()
{
    if(ui->unsafeenable->isChecked())
        ui->unsafeenable->setChecked(false);
    else
        ui->unsafedisable->setChecked(true);
}

//logic to select only single or double lane radio button, but not both
void Demographics::on_singlelane_clicked()
{
    if (ui->doublelane->isChecked())
        ui->doublelane->setChecked(false);
    else
        ui->singlelane->setChecked(true);
}

void Demographics::on_doublelane_clicked()
{
    if(ui->singlelane->isChecked())
        ui->singlelane->setChecked(false);
    else
        ui->doublelane->setChecked(true);
}

//logic to select only traffic enabled or disabled radio button, but not both
void Demographics::on_trafficdisable_clicked()
{
    if (ui->trafficenable->isChecked())
        ui->trafficenable->setChecked(false);
    else
        ui->trafficdisable->setChecked(true);
}

void Demographics::on_trafficenable_clicked()
{
    if(ui->trafficdisable->isChecked())
        ui->trafficdisable->setChecked(false);
    else
        ui->trafficenable->setChecked(true);
}

//logic to select only green, pink, or orange color tracking radio button, but not more than one
void Demographics::on_neongreen_clicked()
{
    if(ui->neonorange->isChecked())
        ui->neonorange->setChecked(false);
    else if(ui->neonpink->isChecked())
        ui->neonpink->setChecked(false);
    else
        ui->neongreen->setChecked(true);
}

void Demographics::on_neonorange_clicked()
{
    if(ui->neongreen->isChecked())
        ui->neongreen->setChecked(false);
    else if(ui->neonpink->isChecked())
        ui->neonpink->setChecked(false);
    else
        ui->neonorange->setChecked(true);
}

void Demographics::on_neonpink_clicked()
{
    if(ui->neonorange->isChecked())
        ui->neonorange->setChecked(false);
    else if(ui->neongreen->isChecked())
        ui->neongreen->setChecked(false);
    else
        ui->neonpink->setChecked(true);
}

void Demographics::on_cancel_clicked()
{
    this->hide();
    return;
}

void Demographics::on_datum_clicked()
{
    return;
}

void Demographics::on_download_clicked()
{
    return;
}

void Demographics::on_calibrate_clicked()
{
    return;
}

void Demographics::on_quit_clicked()
{
    id = ui->id->value();
    QString pid = QString::number(id);
    if (id < 10)
        pid.prepend("0");
    QFile file("Data/P" + pid + "_Data.txt");

    QString f = "Data";
    QDir().mkdir(f);

    bool inputError = false;
    //defines variables in relation to objects to allow for passing of variables to rest of program
    FILE * pFile;
    pFile = fopen ("configdata.txt", "w+");

    age =ui->age->value();
    participantheight =ui->participantheight->value();
    trialquantity =ui->trialquantity->value();
    bool male = ui->male->isChecked();
    bool female = ui->female->isChecked();
    bool neongreen= ui->neongreen->isChecked();
    bool neonpink= ui->neonpink->isChecked();
    bool neonorange= ui->neonorange->isChecked();
    bool trafficenable= ui->trafficenable->isChecked();
    bool trafficdisable= ui->trafficdisable->isChecked();
    bool singlelane= ui->singlelane->isChecked();
    bool doublelane= ui->doublelane->isChecked();
    bool demo= ui->demo->isChecked();
    bool trial= ui->trial->isChecked();
    bool left = ui->lefthanded->isChecked();
    bool right= ui->righthanded->isChecked();
    //sets the gender flag so that we can write the data to a file
    if(male)
    {
        sex = "male";
    }
    else if (female)
    {
        sex = "female";
    }

    //sets the dominance flag so that we can write the data to a file
    if(right)
    {
        dominance = "right";
    }
    else if (left)
    {
        dominance = "left";
    }

    //fprintf(pFile, "age: %s\n", age);
   // fprintf(pFile, "gender: %s\n", sex);
    if(trafficenable)
        fprintf(pFile, "traffic: yes\n");
    else
        fprintf(pFile, "traffic: no\n");
    if (singlelane)
        fprintf(pFile, "lanes: 1\n");
    else
        fprintf(pFile, "lanes: 2\n");
    if(demo)
        fprintf(pFile, "demo: true\n");
    else
        fprintf(pFile, "demo: false\n");
    //fprintf(pFile, "dominance: %s\n", dominance);

    fclose(pFile);

//error handling finished, now we write to file by emitting a signal which is picked up in mainwindow.cpp:
    if(inputError)
    {
        return;
    }
    else
    {
        data.writeDemographics(id, age, sex, dominance);
        virtuale.start(id);
        this->hide();
    }



}

void Demographics::setPid(int personalIdentification)
{
    //set the ID of the user to be displayed in the GUI
    ui->id->setValue(personalIdentification);
}

//get functions for sex, age, id, height
QString Demographics::getSex()
{
    return sex;
}
QString Demographics::getAge()
{
    return age;
}
int Demographics::getId()
{
    return id;
}
QString Demographics::getHeight()
{
    return participantheight;
}
QString Demographics::getDominance()
{
    return dominance;
}
