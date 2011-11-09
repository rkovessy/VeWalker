/********************************************************************************
** Form generated from reading UI file 'starttrials.ui'
**
** Created: Tue Jul 26 16:10:55 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTTRIALS_H
#define UI_STARTTRIALS_H

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

class Ui_StartTrials
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *resume;

    void setupUi(QMainWindow *StartTrials)
    {
        if (StartTrials->objectName().isEmpty())
            StartTrials->setObjectName(QString::fromUtf8("StartTrials"));
        StartTrials->resize(250, 100);
        StartTrials->setMaximumSize(QSize(250, 100));
        centralwidget = new QWidget(StartTrials);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(250, 100));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 251, 21));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 30, 251, 21));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);
        resume = new QPushButton(centralwidget);
        resume->setObjectName(QString::fromUtf8("resume"));
        resume->setGeometry(QRect(90, 60, 75, 23));
        resume->setDefault(true);
        StartTrials->setCentralWidget(centralwidget);

        retranslateUi(StartTrials);

        QMetaObject::connectSlotsByName(StartTrials);
    } // setupUi

    void retranslateUi(QMainWindow *StartTrials)
    {
        StartTrials->setWindowTitle(QApplication::translate("StartTrials", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StartTrials", "Practice Trials are complete.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StartTrials", "Are you ready to start the experimental trials?", 0, QApplication::UnicodeUTF8));
        resume->setText(QApplication::translate("StartTrials", "Continue", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StartTrials: public Ui_StartTrials {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTTRIALS_H
