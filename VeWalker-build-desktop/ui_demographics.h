/********************************************************************************
** Form generated from reading UI file 'demographics.ui'
**
** Created: Fri Mar 9 13:03:00 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMOGRAPHICS_H
#define UI_DEMOGRAPHICS_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Demographics
{
public:
    QGroupBox *groupBox_1;
    QRadioButton *trafficdisable;
    QRadioButton *trafficenable;
    QLabel *roundaboutsize;
    QLabel *modelabel;
    QRadioButton *trial;
    QRadioButton *demo;
    QRadioButton *singlelane;
    QRadioButton *doublelane;
    QLabel *trafficlabel;
    QLabel *trialquantitylabel;
    QSpinBox *trialquantity;
    QSlider *intensityslider;
    QSlider *vehiclequantityslider;
    QLabel *vehiclequantitylabel;
    QLabel *trafficintensitylabel;
    QRadioButton *unsafedisable;
    QRadioButton *unsafeenable;
    QLabel *unsafeintensitylabel;
    QLabel *minlabel1;
    QLabel *minlabel2;
    QLabel *maxlabel1;
    QLabel *maxlabel2;
    QGroupBox *groupBox_2;
    QRadioButton *neonpink;
    QPushButton *calibrate;
    QLabel *heightlabel;
    QSpinBox *participantheight;
    QLabel *trackinglabel;
    QRadioButton *neongreen;
    QRadioButton *neonorange;
    QLabel *rotationalspeed;
    QLabel *displaylabel;
    QPushButton *datum;
    QLabel *trackinglabel_2;
    QRadioButton *headControl;
    QRadioButton *shoulderControl;
    QGroupBox *groupBox_3;
    QLabel *agelabel;
    QSpinBox *age;
    QLabel *participantnumberlabel;
    QSpinBox *id;
    QLabel *sexlabel;
    QRadioButton *male;
    QRadioButton *female;
    QLabel *handdominancelabel;
    QRadioButton *righthanded;
    QRadioButton *lefthanded;
    QGroupBox *groupBox_4;
    QPushButton *download;
    QLabel *heightlabel_2;
    QDateEdit *datelowerrange;
    QLabel *heightlabel_3;
    QDateEdit *dateupperrange;
    QPushButton *quit;
    QPushButton *cancel;

    void setupUi(QDialog *Demographics)
    {
        if (Demographics->objectName().isEmpty())
            Demographics->setObjectName(QString::fromUtf8("Demographics"));
        Demographics->setEnabled(true);
        Demographics->resize(713, 476);
        groupBox_1 = new QGroupBox(Demographics);
        groupBox_1->setObjectName(QString::fromUtf8("groupBox_1"));
        groupBox_1->setGeometry(QRect(9, 9, 371, 241));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        groupBox_1->setFont(font);
        trafficdisable = new QRadioButton(groupBox_1);
        trafficdisable->setObjectName(QString::fromUtf8("trafficdisable"));
        trafficdisable->setGeometry(QRect(223, 80, 68, 22));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        trafficdisable->setFont(font1);
        trafficdisable->setAutoExclusive(false);
        trafficenable = new QRadioButton(groupBox_1);
        trafficenable->setObjectName(QString::fromUtf8("trafficenable"));
        trafficenable->setGeometry(QRect(127, 80, 65, 22));
        trafficenable->setFont(font1);
        trafficenable->setCheckable(true);
        trafficenable->setChecked(true);
        trafficenable->setAutoExclusive(false);
        roundaboutsize = new QLabel(groupBox_1);
        roundaboutsize->setObjectName(QString::fromUtf8("roundaboutsize"));
        roundaboutsize->setGeometry(QRect(13, 52, 83, 18));
        roundaboutsize->setFont(font1);
        modelabel = new QLabel(groupBox_1);
        modelabel->setObjectName(QString::fromUtf8("modelabel"));
        modelabel->setGeometry(QRect(13, 24, 41, 18));
        modelabel->setFont(font1);
        trial = new QRadioButton(groupBox_1);
        trial->setObjectName(QString::fromUtf8("trial"));
        trial->setGeometry(QRect(127, 24, 48, 22));
        trial->setFont(font1);
        trial->setCheckable(true);
        trial->setChecked(true);
        trial->setAutoExclusive(false);
        demo = new QRadioButton(groupBox_1);
        demo->setObjectName(QString::fromUtf8("demo"));
        demo->setGeometry(QRect(223, 24, 62, 22));
        demo->setFont(font1);
        demo->setAutoExclusive(false);
        singlelane = new QRadioButton(groupBox_1);
        singlelane->setObjectName(QString::fromUtf8("singlelane"));
        singlelane->setGeometry(QRect(127, 52, 90, 22));
        singlelane->setFont(font1);
        singlelane->setCheckable(true);
        singlelane->setChecked(true);
        singlelane->setAutoExclusive(false);
        doublelane = new QRadioButton(groupBox_1);
        doublelane->setObjectName(QString::fromUtf8("doublelane"));
        doublelane->setGeometry(QRect(223, 52, 98, 22));
        doublelane->setFont(font1);
        doublelane->setAutoExclusive(false);
        trafficlabel = new QLabel(groupBox_1);
        trafficlabel->setObjectName(QString::fromUtf8("trafficlabel"));
        trafficlabel->setGeometry(QRect(13, 80, 90, 18));
        trafficlabel->setFont(font1);
        trialquantitylabel = new QLabel(groupBox_1);
        trialquantitylabel->setObjectName(QString::fromUtf8("trialquantitylabel"));
        trialquantitylabel->setGeometry(QRect(14, 201, 109, 18));
        trialquantitylabel->setFont(font1);
        trialquantity = new QSpinBox(groupBox_1);
        trialquantity->setObjectName(QString::fromUtf8("trialquantity"));
        trialquantity->setGeometry(QRect(150, 201, 39, 24));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        trialquantity->setFont(font2);
        trialquantity->setValue(60);
        intensityslider = new QSlider(groupBox_1);
        intensityslider->setObjectName(QString::fromUtf8("intensityslider"));
        intensityslider->setEnabled(true);
        intensityslider->setGeometry(QRect(172, 141, 151, 24));
        intensityslider->setMaximum(10);
        intensityslider->setOrientation(Qt::Horizontal);
        intensityslider->setTickPosition(QSlider::TicksBelow);
        vehiclequantityslider = new QSlider(groupBox_1);
        vehiclequantityslider->setObjectName(QString::fromUtf8("vehiclequantityslider"));
        vehiclequantityslider->setGeometry(QRect(172, 171, 151, 24));
        vehiclequantityslider->setMaximum(10);
        vehiclequantityslider->setOrientation(Qt::Horizontal);
        vehiclequantityslider->setTickPosition(QSlider::TicksBelow);
        vehiclequantitylabel = new QLabel(groupBox_1);
        vehiclequantitylabel->setObjectName(QString::fromUtf8("vehiclequantitylabel"));
        vehiclequantitylabel->setGeometry(QRect(14, 171, 130, 18));
        vehiclequantitylabel->setFont(font1);
        trafficintensitylabel = new QLabel(groupBox_1);
        trafficintensitylabel->setObjectName(QString::fromUtf8("trafficintensitylabel"));
        trafficintensitylabel->setEnabled(true);
        trafficintensitylabel->setGeometry(QRect(14, 141, 101, 18));
        trafficintensitylabel->setFont(font1);
        trafficintensitylabel->setTextFormat(Qt::AutoText);
        unsafedisable = new QRadioButton(groupBox_1);
        unsafedisable->setObjectName(QString::fromUtf8("unsafedisable"));
        unsafedisable->setGeometry(QRect(223, 108, 68, 22));
        unsafedisable->setFont(font1);
        unsafedisable->setChecked(true);
        unsafedisable->setAutoExclusive(false);
        unsafeenable = new QRadioButton(groupBox_1);
        unsafeenable->setObjectName(QString::fromUtf8("unsafeenable"));
        unsafeenable->setGeometry(QRect(127, 108, 65, 22));
        unsafeenable->setFont(font1);
        unsafeenable->setCheckable(true);
        unsafeenable->setChecked(false);
        unsafeenable->setAutoExclusive(false);
        unsafeintensitylabel = new QLabel(groupBox_1);
        unsafeintensitylabel->setObjectName(QString::fromUtf8("unsafeintensitylabel"));
        unsafeintensitylabel->setGeometry(QRect(13, 108, 108, 18));
        unsafeintensitylabel->setFont(font1);
        minlabel1 = new QLabel(groupBox_1);
        minlabel1->setObjectName(QString::fromUtf8("minlabel1"));
        minlabel1->setGeometry(QRect(150, 141, 16, 16));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(false);
        font3.setWeight(50);
        minlabel1->setFont(font3);
        minlabel2 = new QLabel(groupBox_1);
        minlabel2->setObjectName(QString::fromUtf8("minlabel2"));
        minlabel2->setGeometry(QRect(150, 171, 16, 16));
        minlabel2->setFont(font3);
        maxlabel1 = new QLabel(groupBox_1);
        maxlabel1->setObjectName(QString::fromUtf8("maxlabel1"));
        maxlabel1->setGeometry(QRect(333, 141, 20, 16));
        maxlabel1->setFont(font3);
        maxlabel2 = new QLabel(groupBox_1);
        maxlabel2->setObjectName(QString::fromUtf8("maxlabel2"));
        maxlabel2->setGeometry(QRect(333, 171, 20, 16));
        maxlabel2->setFont(font3);
        groupBox_2 = new QGroupBox(Demographics);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 250, 371, 181));
        groupBox_2->setFont(font);
        neonpink = new QRadioButton(groupBox_2);
        neonpink->setObjectName(QString::fromUtf8("neonpink"));
        neonpink->setGeometry(QRect(317, 84, 48, 22));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(neonpink->sizePolicy().hasHeightForWidth());
        neonpink->setSizePolicy(sizePolicy);
        neonpink->setFont(font1);
        neonpink->setAutoExclusive(false);
        calibrate = new QPushButton(groupBox_2);
        calibrate->setObjectName(QString::fromUtf8("calibrate"));
        calibrate->setGeometry(QRect(159, 112, 75, 26));
        calibrate->setFont(font1);
        calibrate->setCheckable(false);
        calibrate->setDefault(true);
        calibrate->setFlat(false);
        heightlabel = new QLabel(groupBox_2);
        heightlabel->setObjectName(QString::fromUtf8("heightlabel"));
        heightlabel->setGeometry(QRect(11, 26, 142, 18));
        heightlabel->setFont(font1);
        participantheight = new QSpinBox(groupBox_2);
        participantheight->setObjectName(QString::fromUtf8("participantheight"));
        participantheight->setGeometry(QRect(159, 26, 39, 24));
        participantheight->setFont(font1);
        participantheight->setValue(70);
        trackinglabel = new QLabel(groupBox_2);
        trackinglabel->setObjectName(QString::fromUtf8("trackinglabel"));
        trackinglabel->setGeometry(QRect(11, 84, 103, 18));
        trackinglabel->setFont(font1);
        neongreen = new QRadioButton(groupBox_2);
        neongreen->setObjectName(QString::fromUtf8("neongreen"));
        neongreen->setGeometry(QRect(159, 84, 62, 22));
        sizePolicy.setHeightForWidth(neongreen->sizePolicy().hasHeightForWidth());
        neongreen->setSizePolicy(sizePolicy);
        neongreen->setFont(font1);
        neongreen->setCheckable(true);
        neongreen->setChecked(true);
        neongreen->setAutoExclusive(false);
        neonorange = new QRadioButton(groupBox_2);
        neonorange->setObjectName(QString::fromUtf8("neonorange"));
        neonorange->setGeometry(QRect(240, 84, 71, 22));
        sizePolicy.setHeightForWidth(neonorange->sizePolicy().hasHeightForWidth());
        neonorange->setSizePolicy(sizePolicy);
        neonorange->setFont(font1);
        neonorange->setAutoExclusive(false);
        rotationalspeed = new QLabel(groupBox_2);
        rotationalspeed->setObjectName(QString::fromUtf8("rotationalspeed"));
        rotationalspeed->setGeometry(QRect(11, 112, 112, 18));
        rotationalspeed->setFont(font1);
        displaylabel = new QLabel(groupBox_2);
        displaylabel->setObjectName(QString::fromUtf8("displaylabel"));
        displaylabel->setGeometry(QRect(11, 144, 50, 18));
        displaylabel->setFont(font1);
        datum = new QPushButton(groupBox_2);
        datum->setObjectName(QString::fromUtf8("datum"));
        datum->setGeometry(QRect(159, 144, 75, 26));
        datum->setFont(font1);
        datum->setCheckable(false);
        datum->setDefault(true);
        datum->setFlat(false);
        trackinglabel_2 = new QLabel(groupBox_2);
        trackinglabel_2->setObjectName(QString::fromUtf8("trackinglabel_2"));
        trackinglabel_2->setGeometry(QRect(11, 56, 116, 18));
        trackinglabel_2->setFont(font1);
        headControl = new QRadioButton(groupBox_2);
        headControl->setObjectName(QString::fromUtf8("headControl"));
        headControl->setGeometry(QRect(159, 56, 57, 22));
        sizePolicy.setHeightForWidth(headControl->sizePolicy().hasHeightForWidth());
        headControl->setSizePolicy(sizePolicy);
        headControl->setFont(font1);
        headControl->setCheckable(true);
        headControl->setChecked(true);
        headControl->setAutoExclusive(false);
        shoulderControl = new QRadioButton(groupBox_2);
        shoulderControl->setObjectName(QString::fromUtf8("shoulderControl"));
        shoulderControl->setGeometry(QRect(240, 56, 78, 22));
        sizePolicy.setHeightForWidth(shoulderControl->sizePolicy().hasHeightForWidth());
        shoulderControl->setSizePolicy(sizePolicy);
        shoulderControl->setFont(font1);
        shoulderControl->setAutoExclusive(false);
        groupBox_3 = new QGroupBox(Demographics);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(410, 10, 291, 141));
        groupBox_3->setFont(font);
        agelabel = new QLabel(groupBox_3);
        agelabel->setObjectName(QString::fromUtf8("agelabel"));
        agelabel->setGeometry(QRect(13, 85, 30, 18));
        agelabel->setFont(font1);
        age = new QSpinBox(groupBox_3);
        age->setObjectName(QString::fromUtf8("age"));
        age->setGeometry(QRect(150, 85, 39, 24));
        age->setFont(font2);
        age->setMinimum(1);
        participantnumberlabel = new QLabel(groupBox_3);
        participantnumberlabel->setObjectName(QString::fromUtf8("participantnumberlabel"));
        participantnumberlabel->setGeometry(QRect(13, 27, 131, 18));
        participantnumberlabel->setFont(font1);
        id = new QSpinBox(groupBox_3);
        id->setObjectName(QString::fromUtf8("id"));
        id->setEnabled(true);
        id->setGeometry(QRect(150, 27, 39, 24));
        id->setMaximumSize(QSize(116, 135));
        id->setFont(font2);
        id->setValue(1);
        sexlabel = new QLabel(groupBox_3);
        sexlabel->setObjectName(QString::fromUtf8("sexlabel"));
        sexlabel->setGeometry(QRect(13, 57, 29, 18));
        sexlabel->setFont(font1);
        male = new QRadioButton(groupBox_3);
        male->setObjectName(QString::fromUtf8("male"));
        male->setGeometry(QRect(150, 57, 53, 22));
        male->setFont(font1);
        male->setCheckable(true);
        male->setChecked(true);
        male->setAutoExclusive(false);
        female = new QRadioButton(groupBox_3);
        female->setObjectName(QString::fromUtf8("female"));
        female->setGeometry(QRect(211, 57, 70, 22));
        female->setFont(font1);
        female->setAutoExclusive(false);
        handdominancelabel = new QLabel(groupBox_3);
        handdominancelabel->setObjectName(QString::fromUtf8("handdominancelabel"));
        handdominancelabel->setGeometry(QRect(13, 115, 114, 18));
        handdominancelabel->setFont(font1);
        righthanded = new QRadioButton(groupBox_3);
        righthanded->setObjectName(QString::fromUtf8("righthanded"));
        righthanded->setGeometry(QRect(150, 115, 55, 22));
        righthanded->setFont(font1);
        righthanded->setCheckable(true);
        righthanded->setChecked(true);
        righthanded->setAutoExclusive(false);
        lefthanded = new QRadioButton(groupBox_3);
        lefthanded->setObjectName(QString::fromUtf8("lefthanded"));
        lefthanded->setGeometry(QRect(211, 115, 48, 22));
        lefthanded->setFont(font1);
        groupBox_4 = new QGroupBox(Demographics);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(410, 150, 291, 121));
        groupBox_4->setFont(font);
        download = new QPushButton(groupBox_4);
        download->setObjectName(QString::fromUtf8("download"));
        download->setGeometry(QRect(11, 79, 75, 26));
        download->setFont(font1);
        download->setCheckable(false);
        download->setDefault(true);
        download->setFlat(false);
        heightlabel_2 = new QLabel(groupBox_4);
        heightlabel_2->setObjectName(QString::fromUtf8("heightlabel_2"));
        heightlabel_2->setGeometry(QRect(11, 25, 221, 18));
        heightlabel_2->setFont(font1);
        datelowerrange = new QDateEdit(groupBox_4);
        datelowerrange->setObjectName(QString::fromUtf8("datelowerrange"));
        datelowerrange->setGeometry(QRect(11, 49, 112, 24));
        datelowerrange->setFont(font2);
        datelowerrange->setDate(QDate(2012, 1, 1));
        datelowerrange->setCalendarPopup(true);
        heightlabel_3 = new QLabel(groupBox_4);
        heightlabel_3->setObjectName(QString::fromUtf8("heightlabel_3"));
        heightlabel_3->setGeometry(QRect(136, 49, 16, 18));
        heightlabel_3->setFont(font1);
        dateupperrange = new QDateEdit(groupBox_4);
        dateupperrange->setObjectName(QString::fromUtf8("dateupperrange"));
        dateupperrange->setGeometry(QRect(155, 49, 112, 24));
        dateupperrange->setFont(font2);
        dateupperrange->setDate(QDate(2012, 1, 1));
        dateupperrange->setCalendarPopup(true);
        quit = new QPushButton(Demographics);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(280, 440, 75, 26));
        sizePolicy.setHeightForWidth(quit->sizePolicy().hasHeightForWidth());
        quit->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(11);
        quit->setFont(font4);
        quit->setCheckable(false);
        quit->setDefault(true);
        quit->setFlat(false);
        cancel = new QPushButton(Demographics);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(361, 440, 75, 26));
        sizePolicy.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy);
        cancel->setFont(font4);
        quit->raise();
        cancel->raise();
        groupBox_4->raise();
        groupBox_3->raise();
        groupBox_2->raise();
        groupBox_1->raise();

        retranslateUi(Demographics);

        QMetaObject::connectSlotsByName(Demographics);
    } // setupUi

    void retranslateUi(QDialog *Demographics)
    {
        Demographics->setWindowTitle(QApplication::translate("Demographics", "VeWalker Configuration", 0, QApplication::UnicodeUTF8));
        groupBox_1->setTitle(QApplication::translate("Demographics", "Trial Configuration", 0, QApplication::UnicodeUTF8));
        trafficdisable->setText(QApplication::translate("Demographics", "Disable", 0, QApplication::UnicodeUTF8));
        trafficenable->setText(QApplication::translate("Demographics", "Enable", 0, QApplication::UnicodeUTF8));
        roundaboutsize->setText(QApplication::translate("Demographics", "Roundabout:", 0, QApplication::UnicodeUTF8));
        modelabel->setText(QApplication::translate("Demographics", "Mode:", 0, QApplication::UnicodeUTF8));
        trial->setText(QApplication::translate("Demographics", "Trial", 0, QApplication::UnicodeUTF8));
        demo->setText(QApplication::translate("Demographics", "Demo", 0, QApplication::UnicodeUTF8));
        singlelane->setText(QApplication::translate("Demographics", "Single lane", 0, QApplication::UnicodeUTF8));
        doublelane->setText(QApplication::translate("Demographics", "Double lane", 0, QApplication::UnicodeUTF8));
        trafficlabel->setText(QApplication::translate("Demographics", "Vehicle traffic:", 0, QApplication::UnicodeUTF8));
        trialquantitylabel->setText(QApplication::translate("Demographics", "Number of trials:", 0, QApplication::UnicodeUTF8));
        vehiclequantitylabel->setText(QApplication::translate("Demographics", "Number of vehicles:", 0, QApplication::UnicodeUTF8));
        trafficintensitylabel->setText(QApplication::translate("Demographics", "Traffic intensty:", 0, QApplication::UnicodeUTF8));
        unsafedisable->setText(QApplication::translate("Demographics", "Disable", 0, QApplication::UnicodeUTF8));
        unsafeenable->setText(QApplication::translate("Demographics", "Enable", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        unsafeintensitylabel->setToolTip(QApplication::translate("Demographics", "Inter-vehicle distance prevents safe crossing.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        unsafeintensitylabel->setText(QApplication::translate("Demographics", "Unsafe crossing:", 0, QApplication::UnicodeUTF8));
        minlabel1->setText(QApplication::translate("Demographics", "Min", 0, QApplication::UnicodeUTF8));
        minlabel2->setText(QApplication::translate("Demographics", "0", 0, QApplication::UnicodeUTF8));
        maxlabel1->setText(QApplication::translate("Demographics", "Max", 0, QApplication::UnicodeUTF8));
        maxlabel2->setText(QApplication::translate("Demographics", "10", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Demographics", "Simulation Calibration", 0, QApplication::UnicodeUTF8));
        neonpink->setText(QApplication::translate("Demographics", "Pink", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        calibrate->setToolTip(QApplication::translate("Demographics", "Calibrate rotational speed based on lean extents.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        calibrate->setText(QApplication::translate("Demographics", "Calibrate", 0, QApplication::UnicodeUTF8));
        heightlabel->setText(QApplication::translate("Demographics", "Participant height (in):", 0, QApplication::UnicodeUTF8));
        trackinglabel->setText(QApplication::translate("Demographics", "Object tracking:", 0, QApplication::UnicodeUTF8));
        neongreen->setText(QApplication::translate("Demographics", "Green", 0, QApplication::UnicodeUTF8));
        neonorange->setText(QApplication::translate("Demographics", "Orange", 0, QApplication::UnicodeUTF8));
        rotationalspeed->setText(QApplication::translate("Demographics", "Rotational speed:", 0, QApplication::UnicodeUTF8));
        displaylabel->setText(QApplication::translate("Demographics", "Display:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        datum->setToolTip(QApplication::translate("Demographics", "Calibrate zero position of head.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        datum->setText(QApplication::translate("Demographics", "Datum", 0, QApplication::UnicodeUTF8));
        trackinglabel_2->setText(QApplication::translate("Demographics", "Rotational control:", 0, QApplication::UnicodeUTF8));
        headControl->setText(QApplication::translate("Demographics", "Head", 0, QApplication::UnicodeUTF8));
        shoulderControl->setText(QApplication::translate("Demographics", "Shoulder", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Demographics", "Participant Background Information", 0, QApplication::UnicodeUTF8));
        agelabel->setText(QApplication::translate("Demographics", "Age:", 0, QApplication::UnicodeUTF8));
        participantnumberlabel->setText(QApplication::translate("Demographics", "Participant number: ", 0, QApplication::UnicodeUTF8));
        sexlabel->setText(QApplication::translate("Demographics", "Sex:", 0, QApplication::UnicodeUTF8));
        male->setText(QApplication::translate("Demographics", "Male", 0, QApplication::UnicodeUTF8));
        female->setText(QApplication::translate("Demographics", "Female", 0, QApplication::UnicodeUTF8));
        handdominancelabel->setText(QApplication::translate("Demographics", "Hand dominance:", 0, QApplication::UnicodeUTF8));
        righthanded->setText(QApplication::translate("Demographics", "Right", 0, QApplication::UnicodeUTF8));
        lefthanded->setText(QApplication::translate("Demographics", "Left", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Demographics", "Trial History", 0, QApplication::UnicodeUTF8));
        download->setText(QApplication::translate("Demographics", "Download", 0, QApplication::UnicodeUTF8));
        heightlabel_2->setText(QApplication::translate("Demographics", "Specify date range(dd/mm/yyyy):", 0, QApplication::UnicodeUTF8));
        heightlabel_3->setText(QApplication::translate("Demographics", "to", 0, QApplication::UnicodeUTF8));
        quit->setText(QApplication::translate("Demographics", "Start", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("Demographics", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Demographics: public Ui_Demographics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMOGRAPHICS_H
