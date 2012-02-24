#include "firstwindow.h"
#include "ui_firstwindow.h"

firstwindow::firstwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firstwindow)
{
    ui->setupUi(this);
}

firstwindow::~firstwindow()
{
    delete ui;
}
