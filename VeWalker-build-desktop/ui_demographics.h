/********************************************************************************
** Form generated from reading UI file 'demographics.ui'
**
** Created: Tue Jan 31 02:27:34 2012
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
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Demographics
{
public:
    QComboBox *age;
    QLineEdit *teProgram;
    QLabel *quiterror;
    QRadioButton *caucasian;
    QLabel *lbProgramError;
    QLabel *ethnicityerror;
    QSpinBox *id;
    QLabel *idlabel;
    QPushButton *quit;
    QLabel *namelabel_3;
    QRadioButton *black;
    QLabel *ageerror;
    QRadioButton *male;
    QLabel *ethnicitylabel;
    QRadioButton *middleeastern;
    QRadioButton *other;
    QRadioButton *eastasian;
    QLabel *lbFacultyError;
    QLabel *sexerror;
    QLabel *agelabel;
    QRadioButton *hispanic;
    QRadioButton *female;
    QLabel *iderror;
    QLabel *sexlabel;
    QLineEdit *name;
    QLineEdit *othertext;
    QRadioButton *southasian;
    QComboBox *cbFaculty;
    QLabel *nameerror;
    QLabel *namelabel_2;
    QLabel *namelabel;

    void setupUi(QDialog *Demographics)
    {
        if (Demographics->objectName().isEmpty())
            Demographics->setObjectName(QString::fromUtf8("Demographics"));
        Demographics->resize(872, 295);
        age = new QComboBox(Demographics);
        age->setObjectName(QString::fromUtf8("age"));
        age->setGeometry(QRect(570, 60, 111, 20));
        age->setMinimumSize(QSize(50, 0));
        QFont font;
        font.setPointSize(11);
        age->setFont(font);
        teProgram = new QLineEdit(Demographics);
        teProgram->setObjectName(QString::fromUtf8("teProgram"));
        teProgram->setGeometry(QRect(90, 150, 194, 20));
        teProgram->setMaximumSize(QSize(194, 16777215));
        teProgram->setFont(font);
        quiterror = new QLabel(Demographics);
        quiterror->setObjectName(QString::fromUtf8("quiterror"));
        quiterror->setGeometry(QRect(180, 240, 471, 21));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        quiterror->setPalette(palette);
        quiterror->setFont(font);
        quiterror->setAlignment(Qt::AlignCenter);
        quiterror->setWordWrap(true);
        caucasian = new QRadioButton(Demographics);
        caucasian->setObjectName(QString::fromUtf8("caucasian"));
        caucasian->setGeometry(QRect(700, 120, 121, 21));
        caucasian->setFont(font);
        caucasian->setAutoRepeat(false);
        caucasian->setAutoExclusive(true);
        lbProgramError = new QLabel(Demographics);
        lbProgramError->setObjectName(QString::fromUtf8("lbProgramError"));
        lbProgramError->setGeometry(QRect(300, 150, 61, 20));
        lbProgramError->setMinimumSize(QSize(0, 10));
        lbProgramError->setMaximumSize(QSize(16777215, 20));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush2(QColor(255, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 63, 63, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        lbProgramError->setPalette(palette1);
        lbProgramError->setFont(font);
        ethnicityerror = new QLabel(Demographics);
        ethnicityerror->setObjectName(QString::fromUtf8("ethnicityerror"));
        ethnicityerror->setEnabled(true);
        ethnicityerror->setGeometry(QRect(840, 90, 31, 31));
        ethnicityerror->setMinimumSize(QSize(0, 20));
        ethnicityerror->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        ethnicityerror->setPalette(palette2);
        ethnicityerror->setFont(font);
        id = new QSpinBox(Demographics);
        id->setObjectName(QString::fromUtf8("id"));
        id->setEnabled(false);
        id->setGeometry(QRect(90, 30, 111, 20));
        id->setFont(font);
        id->setReadOnly(true);
        id->setMinimum(1);
        id->setMaximum(99);
        id->setValue(1);
        idlabel = new QLabel(Demographics);
        idlabel->setObjectName(QString::fromUtf8("idlabel"));
        idlabel->setEnabled(false);
        idlabel->setGeometry(QRect(30, 30, 58, 21));
        idlabel->setFont(font);
        quit = new QPushButton(Demographics);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(360, 210, 75, 23));
        quit->setFont(font);
        quit->setCheckable(false);
        quit->setDefault(true);
        quit->setFlat(false);
        namelabel_3 = new QLabel(Demographics);
        namelabel_3->setObjectName(QString::fromUtf8("namelabel_3"));
        namelabel_3->setGeometry(QRect(30, 150, 58, 21));
        namelabel_3->setFont(font);
        black = new QRadioButton(Demographics);
        black->setObjectName(QString::fromUtf8("black"));
        black->setGeometry(QRect(580, 120, 101, 21));
        black->setFont(font);
        ageerror = new QLabel(Demographics);
        ageerror->setObjectName(QString::fromUtf8("ageerror"));
        ageerror->setGeometry(QRect(840, 60, 61, 20));
        ageerror->setMinimumSize(QSize(0, 10));
        ageerror->setMaximumSize(QSize(16777215, 20));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        ageerror->setPalette(palette3);
        ageerror->setFont(font);
        male = new QRadioButton(Demographics);
        male->setObjectName(QString::fromUtf8("male"));
        male->setGeometry(QRect(610, 30, 71, 17));
        male->setFont(font);
        male->setCheckable(true);
        male->setChecked(true);
        male->setAutoExclusive(false);
        ethnicitylabel = new QLabel(Demographics);
        ethnicitylabel->setObjectName(QString::fromUtf8("ethnicitylabel"));
        ethnicitylabel->setEnabled(true);
        ethnicitylabel->setGeometry(QRect(510, 89, 71, 31));
        ethnicitylabel->setMaximumSize(QSize(16777215, 16777215));
        ethnicitylabel->setFont(font);
        ethnicitylabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        middleeastern = new QRadioButton(Demographics);
        middleeastern->setObjectName(QString::fromUtf8("middleeastern"));
        middleeastern->setGeometry(QRect(700, 140, 131, 31));
        middleeastern->setFont(font);
        other = new QRadioButton(Demographics);
        other->setObjectName(QString::fromUtf8("other"));
        other->setGeometry(QRect(580, 170, 101, 21));
        other->setFont(font);
        eastasian = new QRadioButton(Demographics);
        eastasian->setObjectName(QString::fromUtf8("eastasian"));
        eastasian->setGeometry(QRect(580, 90, 101, 31));
        eastasian->setFont(font);
        eastasian->setChecked(true);
        eastasian->setAutoRepeat(false);
        eastasian->setAutoExclusive(true);
        lbFacultyError = new QLabel(Demographics);
        lbFacultyError->setObjectName(QString::fromUtf8("lbFacultyError"));
        lbFacultyError->setGeometry(QRect(300, 110, 61, 20));
        lbFacultyError->setMinimumSize(QSize(0, 10));
        lbFacultyError->setMaximumSize(QSize(16777215, 20));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        lbFacultyError->setPalette(palette4);
        lbFacultyError->setFont(font);
        sexerror = new QLabel(Demographics);
        sexerror->setObjectName(QString::fromUtf8("sexerror"));
        sexerror->setGeometry(QRect(840, 30, 61, 20));
        sexerror->setMinimumSize(QSize(0, 10));
        sexerror->setMaximumSize(QSize(16777215, 20));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        sexerror->setPalette(palette5);
        sexerror->setFont(font);
        agelabel = new QLabel(Demographics);
        agelabel->setObjectName(QString::fromUtf8("agelabel"));
        agelabel->setGeometry(QRect(510, 60, 58, 21));
        agelabel->setFont(font);
        hispanic = new QRadioButton(Demographics);
        hispanic->setObjectName(QString::fromUtf8("hispanic"));
        hispanic->setGeometry(QRect(580, 140, 101, 31));
        hispanic->setFont(font);
        female = new QRadioButton(Demographics);
        female->setObjectName(QString::fromUtf8("female"));
        female->setGeometry(QRect(690, 30, 81, 20));
        female->setFont(font);
        female->setAutoExclusive(false);
        iderror = new QLabel(Demographics);
        iderror->setObjectName(QString::fromUtf8("iderror"));
        iderror->setGeometry(QRect(298, 30, 61, 20));
        iderror->setMinimumSize(QSize(0, 10));
        iderror->setMaximumSize(QSize(16777215, 20));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        iderror->setPalette(palette6);
        iderror->setFont(font);
        sexlabel = new QLabel(Demographics);
        sexlabel->setObjectName(QString::fromUtf8("sexlabel"));
        sexlabel->setGeometry(QRect(510, 30, 58, 21));
        sexlabel->setFont(font);
        name = new QLineEdit(Demographics);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(90, 70, 194, 20));
        name->setMaximumSize(QSize(194, 16777215));
        name->setFont(font);
        othertext = new QLineEdit(Demographics);
        othertext->setObjectName(QString::fromUtf8("othertext"));
        othertext->setGeometry(QRect(700, 170, 151, 21));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(othertext->sizePolicy().hasHeightForWidth());
        othertext->setSizePolicy(sizePolicy);
        othertext->setMaximumSize(QSize(200, 16777215));
        othertext->setFont(font);
        southasian = new QRadioButton(Demographics);
        southasian->setObjectName(QString::fromUtf8("southasian"));
        southasian->setGeometry(QRect(700, 90, 121, 31));
        southasian->setFont(font);
        cbFaculty = new QComboBox(Demographics);
        cbFaculty->setObjectName(QString::fromUtf8("cbFaculty"));
        cbFaculty->setGeometry(QRect(90, 110, 191, 22));
        cbFaculty->setFont(font);
        nameerror = new QLabel(Demographics);
        nameerror->setObjectName(QString::fromUtf8("nameerror"));
        nameerror->setGeometry(QRect(298, 70, 61, 20));
        nameerror->setMinimumSize(QSize(0, 10));
        nameerror->setMaximumSize(QSize(16777215, 20));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        nameerror->setPalette(palette7);
        nameerror->setFont(font);
        namelabel_2 = new QLabel(Demographics);
        namelabel_2->setObjectName(QString::fromUtf8("namelabel_2"));
        namelabel_2->setGeometry(QRect(30, 110, 58, 21));
        namelabel_2->setFont(font);
        namelabel = new QLabel(Demographics);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(30, 70, 58, 21));
        namelabel->setFont(font);
        QWidget::setTabOrder(name, cbFaculty);
        QWidget::setTabOrder(cbFaculty, teProgram);
        QWidget::setTabOrder(teProgram, male);
        QWidget::setTabOrder(male, female);
        QWidget::setTabOrder(female, age);
        QWidget::setTabOrder(age, eastasian);
        QWidget::setTabOrder(eastasian, southasian);
        QWidget::setTabOrder(southasian, black);
        QWidget::setTabOrder(black, caucasian);
        QWidget::setTabOrder(caucasian, hispanic);
        QWidget::setTabOrder(hispanic, middleeastern);
        QWidget::setTabOrder(middleeastern, other);
        QWidget::setTabOrder(other, othertext);
        QWidget::setTabOrder(othertext, quit);
        QWidget::setTabOrder(quit, id);

        retranslateUi(Demographics);

        age->setCurrentIndex(1);
        cbFaculty->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Demographics);
    } // setupUi

    void retranslateUi(QDialog *Demographics)
    {
        Demographics->setWindowTitle(QApplication::translate("Demographics", "Dialog", 0, QApplication::UnicodeUTF8));
        age->clear();
        age->insertItems(0, QStringList()
         << QApplication::translate("Demographics", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "28", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "31", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "33", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "34", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "35", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "36", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "37", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "38", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "39", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "41", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "42", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "43", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "44", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "45", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "46", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "47", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "48", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "49", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "50", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "51", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "52", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "53", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "54", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "55", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "56", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "57", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "58", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "59", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "60", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "61", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "62", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "63", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "64", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "65", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "66", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "67", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "68", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "69", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "70", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "71", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "72", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "73", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "74", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "75", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "76", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "77", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "78", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "79", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "80", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "81", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "82", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "83", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "84", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "85", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "86", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "87", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "88", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "89", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "91", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "92", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "93", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "94", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "95", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "96", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "97", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "98", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "99", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "100+", 0, QApplication::UnicodeUTF8)
        );
        teProgram->setText(QApplication::translate("Demographics", "da", 0, QApplication::UnicodeUTF8));
        quiterror->setText(QApplication::translate("Demographics", "Please complete all items before submitting", 0, QApplication::UnicodeUTF8));
        caucasian->setText(QApplication::translate("Demographics", "Caucasian", 0, QApplication::UnicodeUTF8));
        lbProgramError->setText(QApplication::translate("Demographics", "(*)", 0, QApplication::UnicodeUTF8));
        ethnicityerror->setText(QApplication::translate("Demographics", "(*)", 0, QApplication::UnicodeUTF8));
        idlabel->setText(QApplication::translate("Demographics", "ID:", 0, QApplication::UnicodeUTF8));
        quit->setText(QApplication::translate("Demographics", "Submit", 0, QApplication::UnicodeUTF8));
        namelabel_3->setText(QApplication::translate("Demographics", "Program:", 0, QApplication::UnicodeUTF8));
        black->setText(QApplication::translate("Demographics", "Black", 0, QApplication::UnicodeUTF8));
        ageerror->setText(QApplication::translate("Demographics", "(*)", 0, QApplication::UnicodeUTF8));
        male->setText(QApplication::translate("Demographics", "Male", 0, QApplication::UnicodeUTF8));
        ethnicitylabel->setText(QApplication::translate("Demographics", "Ethnicity:", 0, QApplication::UnicodeUTF8));
        middleeastern->setText(QApplication::translate("Demographics", "Middle-Eastern", 0, QApplication::UnicodeUTF8));
        other->setText(QApplication::translate("Demographics", "Other:", 0, QApplication::UnicodeUTF8));
        eastasian->setText(QApplication::translate("Demographics", "East Asian", 0, QApplication::UnicodeUTF8));
        lbFacultyError->setText(QApplication::translate("Demographics", "(*)", 0, QApplication::UnicodeUTF8));
        sexerror->setText(QApplication::translate("Demographics", "(*)", 0, QApplication::UnicodeUTF8));
        agelabel->setText(QApplication::translate("Demographics", "Age:", 0, QApplication::UnicodeUTF8));
        hispanic->setText(QApplication::translate("Demographics", "Hispanic", 0, QApplication::UnicodeUTF8));
        female->setText(QApplication::translate("Demographics", "Female", 0, QApplication::UnicodeUTF8));
        iderror->setText(QApplication::translate("Demographics", "(*)", 0, QApplication::UnicodeUTF8));
        sexlabel->setText(QApplication::translate("Demographics", "Sex:", 0, QApplication::UnicodeUTF8));
        name->setText(QApplication::translate("Demographics", "da", 0, QApplication::UnicodeUTF8));
        othertext->setText(QString());
        southasian->setText(QApplication::translate("Demographics", "South Asian", 0, QApplication::UnicodeUTF8));
        cbFaculty->clear();
        cbFaculty->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("Demographics", "Applied Health and Sciences", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "Arts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "Engineering", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "Environment", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "Mathematics", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Demographics", "Science", 0, QApplication::UnicodeUTF8)
        );
        nameerror->setText(QApplication::translate("Demographics", "(*)", 0, QApplication::UnicodeUTF8));
        namelabel_2->setText(QApplication::translate("Demographics", "Faculty:", 0, QApplication::UnicodeUTF8));
        namelabel->setText(QApplication::translate("Demographics", "Name:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Demographics: public Ui_Demographics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMOGRAPHICS_H
