#include "demographics.h"
#include "ui_demographics.h"

Demographics::Demographics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demographics)
{
    ui->setupUi(this);
    ui->dateupperrange->setDate(QDate::currentDate());
    referenceid=1;

    db = QSqlDatabase::addDatabase("QPSQL", "demoConnect");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("abc123");
    db.setDatabaseName("configDb");
    db.open();
    if (db.lastError().isValid());
        qDebug() << "lastDB error from opening connection " << db.lastError();

    get_last_id();
    write_new_id();
}

//destructor
Demographics::~Demographics()
{
    QSqlDatabase::database("demoConnect").close();
    QSqlDatabase::removeDatabase("demoConnect");
    delete ui;
}


void Demographics::database_connect()
{

}

void Demographics::database_insert_config()
{

    if (db.isOpen())
    {
        QString inStatement = "UPDATE loadconfig set participant_id = :participant_id, sex = :sex, age = :age, hand_dom = :hand_dom, mode = :mode, roundabout = :roundabout, vehicle_traffic = :vehicle_traffic, unsafe_crossing = :unsafe_crossing, traffic_intensity = :traffic_intensity, vehicle_quantity = :vehicle_quantity, trial_quantity = :trial_quantity, participant_height = :participant_height, object_tracking = :object_tracking, trial_date = :trial_date where reference_id = :reference_id;";
        QSqlQuery qry(db);

        qry.prepare(inStatement);

        qry.bindValue(":reference_id", referenceid);

        qry.bindValue(":participant_id", participantid);

        if (male)
            qry.bindValue(":sex", "male");
        else
            qry.bindValue(":sex", "female");

        qry.bindValue(":age", age);

        if (righthanded)
            qry.bindValue(":hand_dom", "right");
        else
            qry.bindValue(":hand_dom", "left");

        if (demo)
            qry.bindValue(":mode", "demo");
        else
            qry.bindValue(":mode", "trial");

        if (singlelane)
            qry.bindValue(":roundabout", 1);
        else
            qry.bindValue(":roundabout", 2);

        if (trafficenable)
            qry.bindValue(":vehicle_traffic", 1);
        else
            qry.bindValue(":vehicle_traffic", 0);

        if (unsafeenable)
            qry.bindValue(":unsafe_crossing", 1);
        else
            qry.bindValue(":unsafe_crossing", 0);

        qry.bindValue(":vehicle_quantity", vehiclequantityslider);
        qry.bindValue(":traffic_intensity", intensityslider);
        qry.bindValue(":trial_quantity", trialquantity);
        qry.bindValue(":participant_height", participantheight);

        if (neongreen)
            qry.bindValue(":object_tracking", "green");
        else if(neonpink)
            qry.bindValue(":object_tracking", "pink");
        else
            qry.bindValue(":object_tracking", "orange");

        qry.bindValue(":trial_date", QDate::currentDate());

        if (qry.exec())
            qDebug() << "Insert successful";
        else
            qDebug() << "Insertion failed";

    }
    else
    {
        if (db.lastError().isValid());
            qDebug() << db.lastError();
            qDebug() << "Demographics failed to open database connection to insert data.";
    }
}

void Demographics::database_select_config()
{
    if (db.open())
    {

        db.close();
    }
    else
    {
        qDebug() << "Demographics failed to open database connection to get data.";
    }
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
    calibrateRotation *calibrateMe = new calibrateRotation();
    calibrateMe->show();
}

void Demographics::on_quit_clicked()
{
    participantid = ui->id->value();
    bool inputError = false;
    age = ui->age->value();
    participantheight =ui->participantheight->value();
    trialquantity =ui->trialquantity->value();
    male = ui->male->isChecked();
    female = ui->female->isChecked();
    neongreen= ui->neongreen->isChecked();
    neonpink= ui->neonpink->isChecked();
    neonorange= ui->neonorange->isChecked();
    trafficenable= ui->trafficenable->isChecked();
    trafficdisable= ui->trafficdisable->isChecked();
    singlelane= ui->singlelane->isChecked();
    doublelane= ui->doublelane->isChecked();
    demo= ui->demo->isChecked();
    trial= ui->trial->isChecked();
    lefthanded = ui->lefthanded->isChecked();
    righthanded = ui->righthanded->isChecked();
    unsafeenable = ui->unsafeenable->isChecked();
    unsafedisable = ui->unsafedisable->isChecked();
    vehiclequantityslider = ui->vehiclequantityslider ->value();
    intensityslider = ui ->intensityslider->value();
    trialquantity = ui->trialquantity->value();

//        QString pid = QString::number(id);
//        if (id < 10)
//            pid.prepend("0");
//        QFile file("Data/P" + pid + "_Data.txt");

//        QString f = "Data";
//        QDir().mkdir(f);

//        //defines variables in relation to objects to allow for passing of variables to rest of program
//        FILE * pFile;
//        pFile = fopen ("configdata.txt", "w+");
//    if(trafficenable)
//        fprintf(pFile, "traffic: yes\n");
//    else
//        fprintf(pFile, "traffic: no\n");
//    if (singlelane)
//        fprintf(pFile, "lanes: 1\n");
//    else
//        fprintf(pFile, "lanes: 2\n");
//    if(demo)
//        fprintf(pFile, "demo: true\n");
//    else
//        fprintf(pFile, "demo: false\n");
//    if(neongreen)
//        fprintf(pFile, "color: neon_green\n");
//    else if(neonpink)
//        fprintf(pFile, "color: neon_pink\n");
//    else
//        fprintf(pFile, "color: neon_orange\n");
//    if(unsafeenable)
//        fprintf(pFile, "unsafe: true\n");
//    else
//        fprintf(pFile, "unsafe: false\n");
//    fprintf(pFile, "trials: %d\n", ui->trialquantity->value());
//    fprintf(pFile, "height: %d\n", ui->participantheight->value());
//    fprintf(pFile, "vehicle_quantity: %d\n", vehiclequantityslider);
//    fprintf(pFile, "intensity: %d\n", ui->intensityslider->value());
//    fclose(pFile);

    this->database_connect();
    this->database_insert_config();

//error handling finished, now we write to file by emitting a signal which is picked up in mainwindow.cpp:
    if(inputError)
    {
        return;
    }
    else
    {
        //data.writeDemographics(id, age, sex, dominance);

        virtuale.start(participantid);
        this->hide();
    }
}

//get functions for sex, age, id, height
QString Demographics::getSex()
{
    return sex;
}
int Demographics::getAge()
{
    return age;
}
int Demographics::getId()
{
    return participantid;
}
int Demographics::getHeight()
{
    return participantheight;
}
QString Demographics::getDominance()
{
    return dominance;
}

void Demographics::get_last_id()
{
    printf("GetlastID called \n");
    if (db.isOpen())
    {
        QString readStatement = ("SELECT reference_id FROM loadconfig order by reference_id desc limit 1");
        QSqlQuery qry(db);

        if (qry.exec(readStatement))
        {
            while(qry.next()){
                referenceid = qry.value(0).toInt();
                qDebug() << "Last Reference ID:" << referenceid;
            }
            referenceid++;
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),db.lastError().text());
        }

    }
    else
    {
        qDebug() << "Demographics failed to open database connection to pull data.";
    }
}

void Demographics::write_new_id()
{
    printf("Writecurrentid called \n");
    if (db.isOpen())
    {
        QString inStatement = "INSERT INTO loadconfig (reference_id) VALUES (:reference_id)";
        QSqlQuery qry(db);

        qry.prepare(inStatement);

        qry.bindValue(":reference_id", referenceid);

        if (qry.exec())
            qDebug() << "Insert successful";
        else
            qDebug() << "Insertion failed";
    }
        else
        {
            if (db.lastError().isValid());
                qDebug() << db.lastError();
                qDebug() << "Demographics failed to open database connection to insert data.";
        }
}
