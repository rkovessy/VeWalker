#include "startwindow.h"
#include "ui_startwindow.h"

Startwindow::Startwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Startwindow)
{
    ui->setupUi(this);
    ui->error->setVisible(false);
    oldid = -1;
}

Startwindow::~Startwindow()
{
    delete ui;
}

void Startwindow::on_pushButton_clicked()
{
    id = 1;
    QString pid = QString::number(id);
    if (id < 10)
        pid.prepend("0");
    QFile file("Data/P" + pid + "_Data.txt");

    QString f = "Data";
    if (!QDir(f).exists())
        QDir().mkdir(f);

    if (file.exists() && id != oldid) {
        ui->error->setVisible(true);
        oldid = id;
    }
    else {
        demographics.setPid(id);
        demographics.show();
        this->hide();
    }
}
