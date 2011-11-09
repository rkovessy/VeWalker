#include "popupscreen.h"
#include "ui_popupscreen.h"

PopUpScreen::PopUpScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PopUpScreen)
{
    ui->setupUi(this);
}

PopUpScreen::~PopUpScreen()
{
    delete ui;
}

void PopUpScreen::set_display(QString a) {
    if (a == "starttrials")
        ui->label->setText("Trials are about to begin. Are you ready to continue?");
    else if (a == "startpractice")
        ui->label->setText("Practice trials are about to begin. Are you ready to continue?");
    else if (a == "fail")
        ui->label->setText("You crossed the street unsuccessfully. Are you ready to continue?");
    else
        ui->label->setText("programming error");

    this->show();
}

void PopUpScreen::on_resume_clicked()
{
    emit clicked();
    this->hide();
}
