/********************************************************************************
** Form generated from reading UI file 'failscreen.ui'
**
** Created: Tue Jul 26 16:10:55 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAILSCREEN_H
#define UI_FAILSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FailScreen
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *resume;
    QLabel *label_2;

    void setupUi(QMainWindow *FailScreen)
    {
        if (FailScreen->objectName().isEmpty())
            FailScreen->setObjectName(QString::fromUtf8("FailScreen"));
        FailScreen->resize(150, 100);
        FailScreen->setMaximumSize(QSize(150, 100));
        centralwidget = new QWidget(FailScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(150, 100));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 151, 21));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        resume = new QPushButton(centralwidget);
        resume->setObjectName(QString::fromUtf8("resume"));
        resume->setGeometry(QRect(40, 60, 75, 23));
        resume->setAutoExclusive(false);
        resume->setAutoDefault(false);
        resume->setDefault(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 30, 151, 21));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);
        FailScreen->setCentralWidget(centralwidget);

        retranslateUi(FailScreen);

        QMetaObject::connectSlotsByName(FailScreen);
    } // setupUi

    void retranslateUi(QMainWindow *FailScreen)
    {
        FailScreen->setWindowTitle(QApplication::translate("FailScreen", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FailScreen", "Trial unsuccessful.", 0, QApplication::UnicodeUTF8));
        resume->setText(QApplication::translate("FailScreen", "Continue", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FailScreen", "Are you ready to continue?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FailScreen: public Ui_FailScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAILSCREEN_H
