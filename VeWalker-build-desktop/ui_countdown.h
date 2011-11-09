/********************************************************************************
** Form generated from reading UI file 'countdown.ui'
**
** Created: Tue Jul 26 21:09:26 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTDOWN_H
#define UI_COUNTDOWN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Countdown
{
public:
    QWidget *centralwidget;
    QLCDNumber *lcdNumber;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Countdown)
    {
        if (Countdown->objectName().isEmpty())
            Countdown->setObjectName(QString::fromUtf8("Countdown"));
        Countdown->resize(800, 600);
        centralwidget = new QWidget(Countdown);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(330, 180, 141, 171));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy);
        lcdNumber->setNumDigits(1);
        lcdNumber->setProperty("value", QVariant(5));
        Countdown->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Countdown);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Countdown->setStatusBar(statusbar);

        retranslateUi(Countdown);

        QMetaObject::connectSlotsByName(Countdown);
    } // setupUi

    void retranslateUi(QMainWindow *Countdown)
    {
        Countdown->setWindowTitle(QApplication::translate("Countdown", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Countdown: public Ui_Countdown {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTDOWN_H
