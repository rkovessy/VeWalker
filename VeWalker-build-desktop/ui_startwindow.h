/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created: Mon Jan 30 16:44:13 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Startwindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QSpinBox *participant;
    QPushButton *pushButton;
    QLabel *error;

    void setupUi(QMainWindow *Startwindow)
    {
        if (Startwindow->objectName().isEmpty())
            Startwindow->setObjectName(QString::fromUtf8("Startwindow"));
        Startwindow->resize(150, 98);
        Startwindow->setMaximumSize(QSize(150, 100));
        centralWidget = new QWidget(Startwindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(150, 100));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 61, 21));
        participant = new QSpinBox(centralWidget);
        participant->setObjectName(QString::fromUtf8("participant"));
        participant->setGeometry(QRect(90, 10, 42, 22));
        participant->setMinimum(1);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 50, 75, 23));
        pushButton->setDefault(true);
        error = new QLabel(centralWidget);
        error->setObjectName(QString::fromUtf8("error"));
        error->setGeometry(QRect(10, 80, 131, 16));
        Startwindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(pushButton, participant);

        retranslateUi(Startwindow);

        QMetaObject::connectSlotsByName(Startwindow);
    } // setupUi

    void retranslateUi(QMainWindow *Startwindow)
    {
        Startwindow->setWindowTitle(QApplication::translate("Startwindow", "Startwindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Startwindow", "Participant:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Startwindow", "Start", 0, QApplication::UnicodeUTF8));
        error->setText(QApplication::translate("Startwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#ff0000;\">Overwrite participant data?</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Startwindow: public Ui_Startwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
