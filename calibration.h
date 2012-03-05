#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <QWidget>

namespace Ui {
class calibration;
}

class calibration : public QWidget
{
    Q_OBJECT
    
public:
    explicit calibration(QWidget *parent = 0);
    ~calibration();
    
private:
    Ui::calibration *ui;
};

#endif // CALIBRATION_H
