#include "calibration.h"
#include "ui_calibration.h"

calibration::calibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::calibration)
{
    ui->setupUi(this);
}

calibration::~calibration()
{
    delete ui;
}
