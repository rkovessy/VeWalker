/********************************************************************************
** Form generated from reading UI file 'errorpage.ui'
**
** Created: Tue Jul 19 15:48:16 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORPAGE_H
#define UI_ERRORPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ErrorPage
{
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *errorText;

    void setupUi(QDialog *ErrorPage)
    {
        if (ErrorPage->objectName().isEmpty())
            ErrorPage->setObjectName(QString::fromUtf8("ErrorPage"));
        ErrorPage->resize(400, 300);
        buttonBox = new QDialogButtonBox(ErrorPage);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        errorText = new QPlainTextEdit(ErrorPage);
        errorText->setObjectName(QString::fromUtf8("errorText"));
        errorText->setGeometry(QRect(50, 30, 301, 191));

        retranslateUi(ErrorPage);
        QObject::connect(buttonBox, SIGNAL(accepted()), ErrorPage, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ErrorPage, SLOT(reject()));

        QMetaObject::connectSlotsByName(ErrorPage);
    } // setupUi

    void retranslateUi(QDialog *ErrorPage)
    {
        ErrorPage->setWindowTitle(QApplication::translate("ErrorPage", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ErrorPage: public Ui_ErrorPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORPAGE_H
