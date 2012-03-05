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
    //enable all settings for trials
    ui->age->setEnabled(true);
    ui->agelabel->setEnabled(true);
    ui->doublelane->setEnabled(true);
    ui->female->setEnabled(true);
    ui->handdominancelabel->setEnabled(true);
    ui->id->setEnabled(true);
    ui->trafficlabel->setEnabled(true);
    ui->trafficdisable->setEnabled(true);
    ui->trafficenable->setEnabled(true);
    ui->singlelane->setEnabled(true);
    ui->sexlabel->setEnabled(true);
    ui->righthanded->setEnabled(true);
    ui->roundaboutsize->setEnabled(true);
    ui->lefthanded->setEnabled(true);
    ui->male->setEnabled(true);
    ui->participantnumberlabel->setEnabled(true);
    ui->unsafeenable->setEnabled(true);
    ui->intensityslider->setEnabled(true);
    ui->vehiclequantityslider->setEnabled(true);
    ui->unsafedisable->setEnabled(true);
    ui->vehiclequantitylabel->setEnabled(true);
    ui->trafficintensitylabel->setEnabled(true);
    ui->unsafeintensitylabel->setEnabled(true);
    ui->minlabel1->setEnabled(true);
    ui->maxlabel1->setEnabled(true);
    ui->minlabel2->setEnabled(true);
    ui->maxlabel2->setEnabled(true);

    if (ui->demo->isChecked())
        ui->demo->setChecked(false);
    else
        ui->trial->setChecked(true);
}

void Demographics::on_demo_clicked()
{
    //disable some settings for demo purposes and use default values instead
    ui->age->setEnabled(false);
    ui->agelabel->setEnabled(false);
    ui->doublelane->setEnabled(false);
    ui->female->setEnabled(false);
    ui->handdominancelabel->setEnabled(false);
    ui->id->setEnabled(false);
    ui->trafficlabel->setEnabled(false);
    ui->trafficdisable->setEnabled(false);
    ui->trafficenable->setEnabled(false);
    ui->singlelane->setEnabled(false);
    ui->sexlabel->setEnabled(false);
    ui->righthanded->setEnabled(false);
    ui->roundaboutsize->setEnabled(false);
    ui->lefthanded->setEnabled(false);
    ui->male->setEnabled(false);
    ui->participantnumberlabel->setEnabled(false);
    ui->unsafeenable->setEnabled(false);
    ui->intensityslider->setEnabled(false);
    ui->vehiclequantityslider->setEnabled(false);
    ui->unsafedisable->setEnabled(false);
    ui->vehiclequantitylabel->setEnabled(false);
    ui->trafficintensitylabel->setEnabled(false);
    ui->unsafeintensitylabel->setEnabled(false);
    ui->minlabel1->setEnabled(false);
    ui->maxlabel1->setEnabled(false);
    ui->minlabel2->setEnabled(false);
    ui->maxlabel2->setEnabled(false);

    if(ui->trial->isChecked())
        ui->trial->setChecked(false);
    else
        ui->demo->setChecked(true);
}

//logic to select only unsafe intensity enable or disable, but not both
void Demographics::on_unsafeenable_clicked()
{
    //diable quantity and intensity and use unsafe traffic pattern
    ui->intensityslider->setEnabled(false);
    ui->trafficintensitylabel->setEnabled(false);
    ui->vehiclequantityslider->setEnabled(false);
    ui->vehiclequantitylabel->setEnabled(false);
    ui->minlabel1->setEnabled(false);
    ui->maxlabel1->setEnabled(false);
    ui->minlabel2->setEnabled(false);
    ui->maxlabel2->setEnabled(false);

    if (ui->unsafedisable->isChecked())
        ui->unsafedisable->setChecked(false);
    else
        ui->unsafeenable->setChecked(true);
}

void Demographics::on_unsafedisable_clicked()
{
    //enable use of traffic instenity and quantity
    ui->intensityslider->setEnabled(true);
    ui->trafficintensitylabel->setEnabled(true);
    ui->vehiclequantityslider->setEnabled(true);
    ui->vehiclequantitylabel->setEnabled(true);
    ui->minlabel1->setEnabled(true);
    ui->maxlabel1->setEnabled(true);
    ui->minlabel2->setEnabled(true);
    ui->maxlabel2->setEnabled(true);

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
    IWRZeroSet();
    return;
}

void Demographics::on_download_clicked()
{
    return;
}

void Demographics::on_calibrate_clicked()
{
    calibrateRotation calibration;
    calibration.calibrate();
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
    bool unsafeenable = ui->unsafeenable->isChecked();
    bool unsafedisable = ui->unsafedisable->isChecked();

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
    if(neongreen)
        fprintf(pFile, "color: neon_green\n");
    else if(neonpink)
        fprintf(pFile, "color: neon_pink\n");
    else
        fprintf(pFile, "color: neon_orange\n");
    if(unsafeenable)
        fprintf(pFile, "unsafe: true\n");
    else
        fprintf(pFile, "unsafe: false\n");
    fprintf(pFile, "trials: %d\n", ui->trialquantity->value());
    fprintf(pFile, "height: %d\n", ui->participantheight->value());


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
