/********************************************************************************
** Form generated from reading UI file 'demographics.ui'
**
** Created: Fri Feb 24 15:25:26 2012
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
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
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
    QWidget *layoutWidget;
    QGridLayout *gridLayout_5;
    QLabel *quiterror;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *triallabel;
    QLabel *modelabel;
    QRadioButton *trial;
    QRadioButton *demo;
    QLabel *roundaboutsize;
    QLabel *trafficlabel;
    QRadioButton *trafficenable;
    QRadioButton *singlelane;
    QRadioButton *doublelane;
    QRadioButton *trafficdisable;
    QLabel *trialquantitylabel;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *trialquantity;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *backgroundlabel;
    QSpacerItem *horizontalSpacer;
    QLabel *participantnumberlabel;
    QLabel *sexlabel;
    QLabel *agelabel;
    QLabel *handdominancelabel;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *id;
    QRadioButton *male;
    QRadioButton *female;
    QRadioButton *lefthanded;
    QRadioButton *righthanded;
    QSpinBox *age;
    QGridLayout *gridLayout_3;
    QLabel *triallabel_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *heightlabel;
    QLabel *trackinglabel;
    QRadioButton *neonpink;
    QRadioButton *neonorange;
    QLabel *rotationalspeed;
    QLabel *displaylabel;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *neongreen;
    QPushButton *Calibrate;
    QPushButton *datum;
    QSpinBox *participantheight;
    QPushButton *quit;

    void setupUi(QDialog *Demographics)
    {
        if (Demographics->objectName().isEmpty())
            Demographics->setObjectName(QString::fromUtf8("Demographics"));
        Demographics->resize(781, 470);
        layoutWidget = new QWidget(Demographics);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 763, 460));
        gridLayout_5 = new QGridLayout(layoutWidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        quiterror = new QLabel(layoutWidget);
        quiterror->setObjectName(QString::fromUtf8("quiterror"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        quiterror->setPalette(palette);
        QFont font;
        font.setPointSize(11);
        quiterror->setFont(font);
        quiterror->setAlignment(Qt::AlignCenter);
        quiterror->setWordWrap(true);

        gridLayout_5->addWidget(quiterror, 3, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 8, 0, 1, 4);

        triallabel = new QLabel(layoutWidget);
        triallabel->setObjectName(QString::fromUtf8("triallabel"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        triallabel->setFont(font1);

        gridLayout_2->addWidget(triallabel, 1, 0, 1, 5);

        modelabel = new QLabel(layoutWidget);
        modelabel->setObjectName(QString::fromUtf8("modelabel"));
        modelabel->setFont(font);

        gridLayout_2->addWidget(modelabel, 3, 0, 1, 1);

        trial = new QRadioButton(layoutWidget);
        trial->setObjectName(QString::fromUtf8("trial"));
        trial->setFont(font);
        trial->setCheckable(true);
        trial->setChecked(true);
        trial->setAutoExclusive(false);

        gridLayout_2->addWidget(trial, 3, 1, 1, 1);

        demo = new QRadioButton(layoutWidget);
        demo->setObjectName(QString::fromUtf8("demo"));
        demo->setFont(font);
        demo->setAutoExclusive(false);

        gridLayout_2->addWidget(demo, 3, 2, 1, 2);

        roundaboutsize = new QLabel(layoutWidget);
        roundaboutsize->setObjectName(QString::fromUtf8("roundaboutsize"));
        roundaboutsize->setFont(font);

        gridLayout_2->addWidget(roundaboutsize, 4, 0, 1, 1);

        trafficlabel = new QLabel(layoutWidget);
        trafficlabel->setObjectName(QString::fromUtf8("trafficlabel"));
        trafficlabel->setFont(font);

        gridLayout_2->addWidget(trafficlabel, 5, 0, 1, 1);

        trafficenable = new QRadioButton(layoutWidget);
        trafficenable->setObjectName(QString::fromUtf8("trafficenable"));
        trafficenable->setFont(font);
        trafficenable->setCheckable(true);
        trafficenable->setChecked(true);
        trafficenable->setAutoExclusive(false);

        gridLayout_2->addWidget(trafficenable, 5, 1, 1, 1);

        singlelane = new QRadioButton(layoutWidget);
        singlelane->setObjectName(QString::fromUtf8("singlelane"));
        singlelane->setFont(font);
        singlelane->setCheckable(true);
        singlelane->setChecked(true);
        singlelane->setAutoExclusive(false);

        gridLayout_2->addWidget(singlelane, 4, 1, 1, 1);

        doublelane = new QRadioButton(layoutWidget);
        doublelane->setObjectName(QString::fromUtf8("doublelane"));
        doublelane->setFont(font);
        doublelane->setAutoExclusive(false);

        gridLayout_2->addWidget(doublelane, 4, 2, 1, 2);

        trafficdisable = new QRadioButton(layoutWidget);
        trafficdisable->setObjectName(QString::fromUtf8("trafficdisable"));
        trafficdisable->setFont(font);
        trafficdisable->setAutoExclusive(false);

        gridLayout_2->addWidget(trafficdisable, 5, 2, 1, 2);

        trialquantitylabel = new QLabel(layoutWidget);
        trialquantitylabel->setObjectName(QString::fromUtf8("trialquantitylabel"));
        trialquantitylabel->setFont(font);

        gridLayout_2->addWidget(trialquantitylabel, 6, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 0, 1, 5);

        trialquantity = new QSpinBox(layoutWidget);
        trialquantity->setObjectName(QString::fromUtf8("trialquantity"));

        gridLayout_2->addWidget(trialquantity, 6, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 0, 1, 2, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        backgroundlabel = new QLabel(layoutWidget);
        backgroundlabel->setObjectName(QString::fromUtf8("backgroundlabel"));
        backgroundlabel->setFont(font1);

        gridLayout->addWidget(backgroundlabel, 0, 0, 1, 6);

        horizontalSpacer = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 6);

        participantnumberlabel = new QLabel(layoutWidget);
        participantnumberlabel->setObjectName(QString::fromUtf8("participantnumberlabel"));
        participantnumberlabel->setFont(font);

        gridLayout->addWidget(participantnumberlabel, 2, 0, 1, 3);

        sexlabel = new QLabel(layoutWidget);
        sexlabel->setObjectName(QString::fromUtf8("sexlabel"));
        sexlabel->setFont(font);

        gridLayout->addWidget(sexlabel, 3, 0, 1, 1);

        agelabel = new QLabel(layoutWidget);
        agelabel->setObjectName(QString::fromUtf8("agelabel"));
        agelabel->setFont(font);

        gridLayout->addWidget(agelabel, 4, 0, 1, 1);

        handdominancelabel = new QLabel(layoutWidget);
        handdominancelabel->setObjectName(QString::fromUtf8("handdominancelabel"));
        handdominancelabel->setFont(font);

        gridLayout->addWidget(handdominancelabel, 5, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 6, 0, 1, 6);

        id = new QSpinBox(layoutWidget);
        id->setObjectName(QString::fromUtf8("id"));
        id->setMaximumSize(QSize(116, 135));

        gridLayout->addWidget(id, 2, 3, 1, 1);

        male = new QRadioButton(layoutWidget);
        male->setObjectName(QString::fromUtf8("male"));
        male->setFont(font);
        male->setCheckable(true);
        male->setChecked(true);
        male->setAutoExclusive(false);

        gridLayout->addWidget(male, 3, 3, 1, 1);

        female = new QRadioButton(layoutWidget);
        female->setObjectName(QString::fromUtf8("female"));
        female->setFont(font);
        female->setAutoExclusive(false);

        gridLayout->addWidget(female, 3, 4, 1, 1);

        lefthanded = new QRadioButton(layoutWidget);
        lefthanded->setObjectName(QString::fromUtf8("lefthanded"));
        lefthanded->setFont(font);

        gridLayout->addWidget(lefthanded, 5, 4, 1, 1);

        righthanded = new QRadioButton(layoutWidget);
        righthanded->setObjectName(QString::fromUtf8("righthanded"));
        righthanded->setFont(font);
        righthanded->setCheckable(true);
        righthanded->setChecked(true);
        righthanded->setAutoExclusive(false);

        gridLayout->addWidget(righthanded, 5, 3, 1, 1);

        age = new QSpinBox(layoutWidget);
        age->setObjectName(QString::fromUtf8("age"));

        gridLayout->addWidget(age, 4, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 2, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        triallabel_2 = new QLabel(layoutWidget);
        triallabel_2->setObjectName(QString::fromUtf8("triallabel_2"));
        triallabel_2->setFont(font1);

        gridLayout_3->addWidget(triallabel_2, 0, 0, 1, 3);

        horizontalSpacer_6 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 0, 1, 5);

        heightlabel = new QLabel(layoutWidget);
        heightlabel->setObjectName(QString::fromUtf8("heightlabel"));
        heightlabel->setFont(font);

        gridLayout_3->addWidget(heightlabel, 2, 0, 1, 2);

        trackinglabel = new QLabel(layoutWidget);
        trackinglabel->setObjectName(QString::fromUtf8("trackinglabel"));
        trackinglabel->setFont(font);

        gridLayout_3->addWidget(trackinglabel, 3, 0, 1, 1);

        neonpink = new QRadioButton(layoutWidget);
        neonpink->setObjectName(QString::fromUtf8("neonpink"));
        neonpink->setFont(font);
        neonpink->setAutoExclusive(false);

        gridLayout_3->addWidget(neonpink, 3, 3, 1, 1);

        neonorange = new QRadioButton(layoutWidget);
        neonorange->setObjectName(QString::fromUtf8("neonorange"));
        neonorange->setFont(font);
        neonorange->setAutoExclusive(false);

        gridLayout_3->addWidget(neonorange, 3, 4, 1, 1);

        rotationalspeed = new QLabel(layoutWidget);
        rotationalspeed->setObjectName(QString::fromUtf8("rotationalspeed"));
        rotationalspeed->setFont(font);

        gridLayout_3->addWidget(rotationalspeed, 4, 0, 1, 1);

        displaylabel = new QLabel(layoutWidget);
        displaylabel->setObjectName(QString::fromUtf8("displaylabel"));
        displaylabel->setFont(font);

        gridLayout_3->addWidget(displaylabel, 5, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 6, 0, 1, 5);

        neongreen = new QRadioButton(layoutWidget);
        neongreen->setObjectName(QString::fromUtf8("neongreen"));
        neongreen->setFont(font);
        neongreen->setCheckable(true);
        neongreen->setChecked(true);
        neongreen->setAutoExclusive(false);

        gridLayout_3->addWidget(neongreen, 3, 2, 1, 1);

        Calibrate = new QPushButton(layoutWidget);
        Calibrate->setObjectName(QString::fromUtf8("Calibrate"));
        Calibrate->setFont(font);
        Calibrate->setCheckable(false);
        Calibrate->setDefault(true);
        Calibrate->setFlat(false);

        gridLayout_3->addWidget(Calibrate, 4, 2, 1, 1);

        datum = new QPushButton(layoutWidget);
        datum->setObjectName(QString::fromUtf8("datum"));
        datum->setFont(font);
        datum->setCheckable(false);
        datum->setDefault(true);
        datum->setFlat(false);

        gridLayout_3->addWidget(datum, 5, 2, 1, 1);

        participantheight = new QSpinBox(layoutWidget);
        participantheight->setObjectName(QString::fromUtf8("participantheight"));

        gridLayout_3->addWidget(participantheight, 2, 2, 1, 2);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        quit = new QPushButton(layoutWidget);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setFont(font);
        quit->setCheckable(false);
        quit->setDefault(true);
        quit->setFlat(false);

        gridLayout_5->addWidget(quit, 2, 0, 1, 1);


        retranslateUi(Demographics);

        QMetaObject::connectSlotsByName(Demographics);
    } // setupUi

    void retranslateUi(QDialog *Demographics)
    {
        Demographics->setWindowTitle(QApplication::translate("Demographics", "Dialog", 0, QApplication::UnicodeUTF8));
        quiterror->setText(QApplication::translate("Demographics", "Please complete all items before selecting Start.", 0, QApplication::UnicodeUTF8));
        triallabel->setText(QApplication::translate("Demographics", "Trial Configuration", 0, QApplication::UnicodeUTF8));
        modelabel->setText(QApplication::translate("Demographics", "Mode:", 0, QApplication::UnicodeUTF8));
        trial->setText(QApplication::translate("Demographics", "Trial", 0, QApplication::UnicodeUTF8));
        demo->setText(QApplication::translate("Demographics", "Demo", 0, QApplication::UnicodeUTF8));
        roundaboutsize->setText(QApplication::translate("Demographics", "Roundabout:", 0, QApplication::UnicodeUTF8));
        trafficlabel->setText(QApplication::translate("Demographics", "Vehicle traffic:", 0, QApplication::UnicodeUTF8));
        trafficenable->setText(QApplication::translate("Demographics", "Enable", 0, QApplication::UnicodeUTF8));
        singlelane->setText(QApplication::translate("Demographics", "Single lane", 0, QApplication::UnicodeUTF8));
        doublelane->setText(QApplication::translate("Demographics", "Double lane", 0, QApplication::UnicodeUTF8));
        trafficdisable->setText(QApplication::translate("Demographics", "Disable", 0, QApplication::UnicodeUTF8));
        trialquantitylabel->setText(QApplication::translate("Demographics", "Number of trials:", 0, QApplication::UnicodeUTF8));
        backgroundlabel->setText(QApplication::translate("Demographics", "Participant Background Information", 0, QApplication::UnicodeUTF8));
        participantnumberlabel->setText(QApplication::translate("Demographics", "Participant number: ", 0, QApplication::UnicodeUTF8));
        sexlabel->setText(QApplication::translate("Demographics", "Sex:", 0, QApplication::UnicodeUTF8));
        agelabel->setText(QApplication::translate("Demographics", "Age:", 0, QApplication::UnicodeUTF8));
        handdominancelabel->setText(QApplication::translate("Demographics", "Hand dominance:", 0, QApplication::UnicodeUTF8));
        male->setText(QApplication::translate("Demographics", "Male", 0, QApplication::UnicodeUTF8));
        female->setText(QApplication::translate("Demographics", "Female", 0, QApplication::UnicodeUTF8));
        lefthanded->setText(QApplication::translate("Demographics", "Left", 0, QApplication::UnicodeUTF8));
        righthanded->setText(QApplication::translate("Demographics", "Right", 0, QApplication::UnicodeUTF8));
        triallabel_2->setText(QApplication::translate("Demographics", "Simulation Calibration", 0, QApplication::UnicodeUTF8));
        heightlabel->setText(QApplication::translate("Demographics", "Participant height (in):", 0, QApplication::UnicodeUTF8));
        trackinglabel->setText(QApplication::translate("Demographics", "Object tracking:", 0, QApplication::UnicodeUTF8));
        neonpink->setText(QApplication::translate("Demographics", "Pink", 0, QApplication::UnicodeUTF8));
        neonorange->setText(QApplication::translate("Demographics", "Orange", 0, QApplication::UnicodeUTF8));
        rotationalspeed->setText(QApplication::translate("Demographics", "Rotational speed:", 0, QApplication::UnicodeUTF8));
        displaylabel->setText(QApplication::translate("Demographics", "Display:", 0, QApplication::UnicodeUTF8));
        neongreen->setText(QApplication::translate("Demographics", "Green", 0, QApplication::UnicodeUTF8));
        Calibrate->setText(QApplication::translate("Demographics", "Calibrate", 0, QApplication::UnicodeUTF8));
        datum->setText(QApplication::translate("Demographics", "Datum", 0, QApplication::UnicodeUTF8));
        quit->setText(QApplication::translate("Demographics", "Start", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Demographics: public Ui_Demographics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMOGRAPHICS_H
