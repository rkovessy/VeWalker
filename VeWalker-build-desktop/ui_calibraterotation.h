/********************************************************************************
** Form generated from reading UI file 'calibraterotation.ui'
**
** Created: Wed Mar 14 00:31:10 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATEROTATION_H
#define UI_CALIBRATEROTATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calibrateRotation
{
public:
    QGroupBox *groupBox;
    QPushButton *leftExtentCapture;
    QLabel *label;
    QGroupBox *groupBox_2;
    QPushButton *rightExtentCapture;
    QLabel *label_2;
    QLabel *captureError;
    QGroupBox *groupBox_3;
    QLabel *trackinglabel;
    QRadioButton *neonGreen;
    QRadioButton *neonPink;
    QRadioButton *neonOrange;
    QGroupBox *groupBox_4;
    QPushButton *centerCapture;
    QLabel *label_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *completeButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *calibrateRotation)
    {
        if (calibrateRotation->objectName().isEmpty())
            calibrateRotation->setObjectName(QString::fromUtf8("calibrateRotation"));
        calibrateRotation->resize(582, 324);
        groupBox = new QGroupBox(calibrateRotation);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 90, 181, 151));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        leftExtentCapture = new QPushButton(groupBox);
        leftExtentCapture->setObjectName(QString::fromUtf8("leftExtentCapture"));
        leftExtentCapture->setGeometry(QRect(47, 121, 75, 23));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        leftExtentCapture->setFont(font1);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 151, 71));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label->setWordWrap(true);
        groupBox_2 = new QGroupBox(calibrateRotation);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(390, 90, 181, 151));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        groupBox_2->setFont(font3);
        rightExtentCapture = new QPushButton(groupBox_2);
        rightExtentCapture->setObjectName(QString::fromUtf8("rightExtentCapture"));
        rightExtentCapture->setGeometry(QRect(47, 121, 75, 23));
        rightExtentCapture->setFont(font1);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 151, 71));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_2->setWordWrap(true);
        captureError = new QLabel(calibrateRotation);
        captureError->setObjectName(QString::fromUtf8("captureError"));
        captureError->setEnabled(true);
        captureError->setGeometry(QRect(75, 280, 431, 41));
        QFont font4;
        font4.setBold(true);
        font4.setWeight(75);
        captureError->setFont(font4);
        captureError->setTextFormat(Qt::RichText);
        captureError->setAlignment(Qt::AlignCenter);
        captureError->setWordWrap(true);
        groupBox_3 = new QGroupBox(calibrateRotation);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 371, 80));
        groupBox_3->setFont(font);
        trackinglabel = new QLabel(groupBox_3);
        trackinglabel->setObjectName(QString::fromUtf8("trackinglabel"));
        trackinglabel->setGeometry(QRect(12, 31, 103, 18));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(false);
        font5.setWeight(50);
        trackinglabel->setFont(font5);
        neonGreen = new QRadioButton(groupBox_3);
        neonGreen->setObjectName(QString::fromUtf8("neonGreen"));
        neonGreen->setGeometry(QRect(121, 31, 62, 22));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(neonGreen->sizePolicy().hasHeightForWidth());
        neonGreen->setSizePolicy(sizePolicy);
        neonGreen->setFont(font5);
        neonGreen->setCheckable(true);
        neonGreen->setChecked(true);
        neonGreen->setAutoExclusive(false);
        neonPink = new QRadioButton(groupBox_3);
        neonPink->setObjectName(QString::fromUtf8("neonPink"));
        neonPink->setGeometry(QRect(266, 31, 48, 22));
        sizePolicy.setHeightForWidth(neonPink->sizePolicy().hasHeightForWidth());
        neonPink->setSizePolicy(sizePolicy);
        neonPink->setFont(font5);
        neonPink->setAutoExclusive(false);
        neonOrange = new QRadioButton(groupBox_3);
        neonOrange->setObjectName(QString::fromUtf8("neonOrange"));
        neonOrange->setGeometry(QRect(189, 31, 71, 22));
        sizePolicy.setHeightForWidth(neonOrange->sizePolicy().hasHeightForWidth());
        neonOrange->setSizePolicy(sizePolicy);
        neonOrange->setFont(font5);
        neonOrange->setAutoExclusive(false);
        groupBox_4 = new QGroupBox(calibrateRotation);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(200, 90, 181, 151));
        groupBox_4->setFont(font);
        centerCapture = new QPushButton(groupBox_4);
        centerCapture->setObjectName(QString::fromUtf8("centerCapture"));
        centerCapture->setGeometry(QRect(47, 121, 75, 23));
        centerCapture->setFont(font1);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 151, 71));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_3->setWordWrap(true);
        widget = new QWidget(calibrateRotation);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 250, 541, 25));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        completeButton = new QPushButton(widget);
        completeButton->setObjectName(QString::fromUtf8("completeButton"));

        gridLayout->addWidget(completeButton, 0, 1, 1, 1);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout->addWidget(cancelButton, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        retranslateUi(calibrateRotation);

        QMetaObject::connectSlotsByName(calibrateRotation);
    } // setupUi

    void retranslateUi(QWidget *calibrateRotation)
    {
        calibrateRotation->setWindowTitle(QApplication::translate("calibrateRotation", "Rotational Calibration", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("calibrateRotation", "Left Extent", 0, QApplication::UnicodeUTF8));
        leftExtentCapture->setText(QApplication::translate("calibrateRotation", "Capture", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("calibrateRotation", "Ask the paticipant to lean to their maximum extent on their left side. Once the partipant is stable, click 'Capture'.", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("calibrateRotation", "Right Extent", 0, QApplication::UnicodeUTF8));
        rightExtentCapture->setText(QApplication::translate("calibrateRotation", "Capture", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("calibrateRotation", "Ask the paticipant to lean to their maximum extent on their right side. Once the partipant is stable, click 'Capture'.", 0, QApplication::UnicodeUTF8));
        captureError->setText(QApplication::translate("calibrateRotation", "Error: Image could not be captrured. Please check your camera, tracking color, and subject-camera orientation.", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("calibrateRotation", "Configuration", 0, QApplication::UnicodeUTF8));
        trackinglabel->setText(QApplication::translate("calibrateRotation", "Object tracking:", 0, QApplication::UnicodeUTF8));
        neonGreen->setText(QApplication::translate("calibrateRotation", "Green", 0, QApplication::UnicodeUTF8));
        neonPink->setText(QApplication::translate("calibrateRotation", "Pink", 0, QApplication::UnicodeUTF8));
        neonOrange->setText(QApplication::translate("calibrateRotation", "Orange", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("calibrateRotation", "Center Position", 0, QApplication::UnicodeUTF8));
        centerCapture->setText(QApplication::translate("calibrateRotation", "Capture", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("calibrateRotation", "Ask the paticipant to lean to stand straight while facing the camera. Once the partipant is stable, click 'Capture'.", 0, QApplication::UnicodeUTF8));
        completeButton->setText(QApplication::translate("calibrateRotation", "Complete", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("calibrateRotation", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class calibrateRotation: public Ui_calibrateRotation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATEROTATION_H
