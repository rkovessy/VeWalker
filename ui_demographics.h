/********************************************************************************
** Form generated from reading UI file 'demographics.ui'
**
** Created: Sat Feb 25 17:34:03 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMOGRAPHICS_H
#define UI_DEMOGRAPHICS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Demographics
{
public:
    QGroupBox *groupBox;
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
    QGroupBox *groupBox_2;
    QRadioButton *neonpink;
    QPushButton *Calibrate;
    QLabel *heightlabel;
    QSpinBox *participantheight;
    QLabel *trackinglabel;
    QRadioButton *neongreen;
    QRadioButton *neonorange;
    QLabel *rotationalspeed;
    QLabel *displaylabel;
    QPushButton *datum;
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
    QPushButton *donwload;
    QLabel *heightlabel_2;
    QDateEdit *datelowerrange;
    QLabel *heightlabel_3;
    QDateEdit *dateupperrange;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *quit;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_12;

    void setupUi(QDialog *Demographics)
    {
        if (Demographics->objectName().isEmpty())
            Demographics->setObjectName(QString::fromUtf8("Demographics"));
        Demographics->resize(713, 348);
        groupBox = new QGroupBox(Demographics);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 9, 371, 141));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        trafficdisable = new QRadioButton(groupBox);
        trafficdisable->setObjectName(QString::fromUtf8("trafficdisable"));
        trafficdisable->setGeometry(QRect(228, 77, 68, 22));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        trafficdisable->setFont(font1);
        trafficdisable->setAutoExclusive(false);
        trafficenable = new QRadioButton(groupBox);
        trafficenable->setObjectName(QString::fromUtf8("trafficenable"));
        trafficenable->setGeometry(QRect(132, 77, 65, 22));
        trafficenable->setFont(font1);
        trafficenable->setCheckable(true);
        trafficenable->setChecked(true);
        trafficenable->setAutoExclusive(false);
        roundaboutsize = new QLabel(groupBox);
        roundaboutsize->setObjectName(QString::fromUtf8("roundaboutsize"));
        roundaboutsize->setGeometry(QRect(17, 49, 83, 18));
        roundaboutsize->setFont(font1);
        modelabel = new QLabel(groupBox);
        modelabel->setObjectName(QString::fromUtf8("modelabel"));
        modelabel->setGeometry(QRect(17, 21, 41, 18));
        modelabel->setFont(font1);
        trial = new QRadioButton(groupBox);
        trial->setObjectName(QString::fromUtf8("trial"));
        trial->setGeometry(QRect(132, 21, 48, 22));
        trial->setFont(font1);
        trial->setCheckable(true);
        trial->setChecked(true);
        trial->setAutoExclusive(false);
        demo = new QRadioButton(groupBox);
        demo->setObjectName(QString::fromUtf8("demo"));
        demo->setGeometry(QRect(228, 21, 62, 22));
        demo->setFont(font1);
        demo->setAutoExclusive(false);
        singlelane = new QRadioButton(groupBox);
        singlelane->setObjectName(QString::fromUtf8("singlelane"));
        singlelane->setGeometry(QRect(132, 49, 90, 22));
        singlelane->setFont(font1);
        singlelane->setCheckable(true);
        singlelane->setChecked(true);
        singlelane->setAutoExclusive(false);
        doublelane = new QRadioButton(groupBox);
        doublelane->setObjectName(QString::fromUtf8("doublelane"));
        doublelane->setGeometry(QRect(228, 49, 98, 22));
        doublelane->setFont(font1);
        doublelane->setAutoExclusive(false);
        trafficlabel = new QLabel(groupBox);
        trafficlabel->setObjectName(QString::fromUtf8("trafficlabel"));
        trafficlabel->setGeometry(QRect(17, 77, 90, 18));
        trafficlabel->setFont(font1);
        trialquantitylabel = new QLabel(groupBox);
        trialquantitylabel->setObjectName(QString::fromUtf8("trialquantitylabel"));
        trialquantitylabel->setGeometry(QRect(17, 105, 109, 18));
        trialquantitylabel->setFont(font1);
        trialquantity = new QSpinBox(groupBox);
        trialquantity->setObjectName(QString::fromUtf8("trialquantity"));
        trialquantity->setGeometry(QRect(132, 105, 39, 24));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        trialquantity->setFont(font2);
        groupBox_2 = new QGroupBox(Demographics);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 150, 371, 151));
        groupBox_2->setFont(font);
        neonpink = new QRadioButton(groupBox_2);
        neonpink->setObjectName(QString::fromUtf8("neonpink"));
        neonpink->setGeometry(QRect(317, 55, 48, 22));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(neonpink->sizePolicy().hasHeightForWidth());
        neonpink->setSizePolicy(sizePolicy);
        neonpink->setFont(font1);
        neonpink->setAutoExclusive(false);
        Calibrate = new QPushButton(groupBox_2);
        Calibrate->setObjectName(QString::fromUtf8("Calibrate"));
        Calibrate->setGeometry(QRect(159, 83, 75, 26));
        Calibrate->setFont(font1);
        Calibrate->setCheckable(false);
        Calibrate->setDefault(true);
        Calibrate->setFlat(false);
        heightlabel = new QLabel(groupBox_2);
        heightlabel->setObjectName(QString::fromUtf8("heightlabel"));
        heightlabel->setGeometry(QRect(11, 25, 142, 18));
        heightlabel->setFont(font1);
        participantheight = new QSpinBox(groupBox_2);
        participantheight->setObjectName(QString::fromUtf8("participantheight"));
        participantheight->setGeometry(QRect(159, 25, 39, 24));
        participantheight->setFont(font1);
        trackinglabel = new QLabel(groupBox_2);
        trackinglabel->setObjectName(QString::fromUtf8("trackinglabel"));
        trackinglabel->setGeometry(QRect(11, 55, 103, 18));
        trackinglabel->setFont(font1);
        neongreen = new QRadioButton(groupBox_2);
        neongreen->setObjectName(QString::fromUtf8("neongreen"));
        neongreen->setGeometry(QRect(159, 55, 62, 22));
        sizePolicy.setHeightForWidth(neongreen->sizePolicy().hasHeightForWidth());
        neongreen->setSizePolicy(sizePolicy);
        neongreen->setFont(font1);
        neongreen->setCheckable(true);
        neongreen->setChecked(true);
        neongreen->setAutoExclusive(false);
        neonorange = new QRadioButton(groupBox_2);
        neonorange->setObjectName(QString::fromUtf8("neonorange"));
        neonorange->setGeometry(QRect(240, 55, 71, 22));
        sizePolicy.setHeightForWidth(neonorange->sizePolicy().hasHeightForWidth());
        neonorange->setSizePolicy(sizePolicy);
        neonorange->setFont(font1);
        neonorange->setAutoExclusive(false);
        rotationalspeed = new QLabel(groupBox_2);
        rotationalspeed->setObjectName(QString::fromUtf8("rotationalspeed"));
        rotationalspeed->setGeometry(QRect(11, 83, 112, 18));
        rotationalspeed->setFont(font1);
        displaylabel = new QLabel(groupBox_2);
        displaylabel->setObjectName(QString::fromUtf8("displaylabel"));
        displaylabel->setGeometry(QRect(11, 115, 50, 18));
        displaylabel->setFont(font1);
        datum = new QPushButton(groupBox_2);
        datum->setObjectName(QString::fromUtf8("datum"));
        datum->setGeometry(QRect(159, 115, 75, 26));
        datum->setFont(font1);
        datum->setCheckable(false);
        datum->setDefault(true);
        datum->setFlat(false);
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
        participantnumberlabel = new QLabel(groupBox_3);
        participantnumberlabel->setObjectName(QString::fromUtf8("participantnumberlabel"));
        participantnumberlabel->setGeometry(QRect(13, 27, 131, 18));
        participantnumberlabel->setFont(font1);
        id = new QSpinBox(groupBox_3);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(150, 27, 39, 24));
        id->setMaximumSize(QSize(116, 135));
        id->setFont(font2);
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
        donwload = new QPushButton(groupBox_4);
        donwload->setObjectName(QString::fromUtf8("donwload"));
        donwload->setGeometry(QRect(11, 79, 75, 26));
        donwload->setFont(font1);
        donwload->setCheckable(false);
        donwload->setDefault(true);
        donwload->setFlat(false);
        heightlabel_2 = new QLabel(groupBox_4);
        heightlabel_2->setObjectName(QString::fromUtf8("heightlabel_2"));
        heightlabel_2->setGeometry(QRect(11, 25, 119, 18));
        heightlabel_2->setFont(font1);
        datelowerrange = new QDateEdit(groupBox_4);
        datelowerrange->setObjectName(QString::fromUtf8("datelowerrange"));
        datelowerrange->setGeometry(QRect(11, 49, 112, 24));
        datelowerrange->setFont(font2);
        heightlabel_3 = new QLabel(groupBox_4);
        heightlabel_3->setObjectName(QString::fromUtf8("heightlabel_3"));
        heightlabel_3->setGeometry(QRect(136, 49, 16, 18));
        heightlabel_3->setFont(font1);
        dateupperrange = new QDateEdit(groupBox_4);
        dateupperrange->setObjectName(QString::fromUtf8("dateupperrange"));
        dateupperrange->setGeometry(QRect(155, 49, 112, 24));
        dateupperrange->setFont(font2);
        layoutWidget = new QWidget(Demographics);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 310, 691, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        quit = new QPushButton(layoutWidget);
        quit->setObjectName(QString::fromUtf8("quit"));
        sizePolicy.setHeightForWidth(quit->sizePolicy().hasHeightForWidth());
        quit->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(11);
        quit->setFont(font3);
        quit->setCheckable(false);
        quit->setDefault(true);
        quit->setFlat(false);

        horizontalLayout->addWidget(quit);

        cancel = new QPushButton(layoutWidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        sizePolicy.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy);
        cancel->setFont(font3);

        horizontalLayout->addWidget(cancel);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

        groupBox_4->raise();
        groupBox_3->raise();
        groupBox_2->raise();
        groupBox->raise();
        layoutWidget->raise();

        retranslateUi(Demographics);

        QMetaObject::connectSlotsByName(Demographics);
    } // setupUi

    void retranslateUi(QDialog *Demographics)
    {
        Demographics->setWindowTitle(QApplication::translate("Demographics", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Demographics", "Trial Configuration", 0, QApplication::UnicodeUTF8));
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
        groupBox_2->setTitle(QApplication::translate("Demographics", "Simulation Calibration", 0, QApplication::UnicodeUTF8));
        neonpink->setText(QApplication::translate("Demographics", "Pink", 0, QApplication::UnicodeUTF8));
        Calibrate->setText(QApplication::translate("Demographics", "Calibrate", 0, QApplication::UnicodeUTF8));
        heightlabel->setText(QApplication::translate("Demographics", "Participant height (in):", 0, QApplication::UnicodeUTF8));
        trackinglabel->setText(QApplication::translate("Demographics", "Object tracking:", 0, QApplication::UnicodeUTF8));
        neongreen->setText(QApplication::translate("Demographics", "Green", 0, QApplication::UnicodeUTF8));
        neonorange->setText(QApplication::translate("Demographics", "Orange", 0, QApplication::UnicodeUTF8));
        rotationalspeed->setText(QApplication::translate("Demographics", "Rotational speed:", 0, QApplication::UnicodeUTF8));
        displaylabel->setText(QApplication::translate("Demographics", "Display:", 0, QApplication::UnicodeUTF8));
        datum->setText(QApplication::translate("Demographics", "Datum", 0, QApplication::UnicodeUTF8));
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
        donwload->setText(QApplication::translate("Demographics", "Download", 0, QApplication::UnicodeUTF8));
        heightlabel_2->setText(QApplication::translate("Demographics", "Select date range:", 0, QApplication::UnicodeUTF8));
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
