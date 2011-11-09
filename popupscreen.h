#ifndef POPUPSCREEN_H
#define POPUPSCREEN_H

#include <QMainWindow>
#include <QString>

namespace Ui {
    class PopUpScreen;
}

class PopUpScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit PopUpScreen(QWidget *parent = 0);
    ~PopUpScreen();

    void set_display(QString);

signals:
    void clicked();

private:
    Ui::PopUpScreen *ui;

private slots:
    void on_resume_clicked();
};

#endif // POPUPSCREEN_H
