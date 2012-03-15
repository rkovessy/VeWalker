/********************************************************************************
** Form generated from reading UI file 'popupscreen.ui'
**
** Created: Wed Mar 14 19:53:01 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUPSCREEN_H
#define UI_POPUPSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopUpScreen
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *resume;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PopUpScreen)
    {
        if (PopUpScreen->objectName().isEmpty())
            PopUpScreen->setObjectName(QString::fromUtf8("PopUpScreen"));
        PopUpScreen->resize(200, 100);
        PopUpScreen->setMaximumSize(QSize(200, 100));
        centralwidget = new QWidget(PopUpScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(0, 100));
        centralwidget->setMaximumSize(QSize(200, 100));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 171, 41));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        resume = new QPushButton(centralwidget);
        resume->setObjectName(QString::fromUtf8("resume"));
        resume->setGeometry(QRect(60, 60, 75, 23));
        resume->setDefault(true);
        PopUpScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(PopUpScreen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PopUpScreen->setStatusBar(statusbar);

        retranslateUi(PopUpScreen);

        QMetaObject::connectSlotsByName(PopUpScreen);
    } // setupUi

    void retranslateUi(QMainWindow *PopUpScreen)
    {
        PopUpScreen->setWindowTitle(QApplication::translate("PopUpScreen", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PopUpScreen", "Click continue to initiate experimental trials.", 0, QApplication::UnicodeUTF8));
        resume->setText(QApplication::translate("PopUpScreen", "Continue", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PopUpScreen: public Ui_PopUpScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUPSCREEN_H
