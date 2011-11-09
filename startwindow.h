#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "demographics.h"

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>

namespace Ui {
    class Startwindow;
}

class Startwindow : public QMainWindow
/* first window that pops up, used to determine the participant id and if
   that id is already taken. If you want to overwrite a file, you click once
   and the warning message will pop up, click again on the same id and it
   will overwrite. Once it exits it opens demographics
*/
{
    Q_OBJECT

public:
    explicit Startwindow(QWidget *parent = 0);
    ~Startwindow();

    Demographics demographics;

private:
    Ui::Startwindow *ui;
    int id;
    int oldid; // used to check for overwriting files

private slots:
    void on_pushButton_clicked();
};

#endif // STARTWINDOW_H
