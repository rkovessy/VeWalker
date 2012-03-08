#include <QtGui/QApplication>
#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QStringList>
#include <QtSql>
#include <QSqlDriver>
#include <QMessageBox>
#include <QObject>

#include "demographics.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Demographics w;
   w.show();

/*
    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("DB - ERROR!"),
                              db.lastError().text());
    }

        QSqlQuery qry;

        if (qry.exec("INSERT INTO loadconfig (sex, age) VALUES ('male', '23')"))
            qDebug() << "Insert success";
        else
            qDebug() << "Insert fail";

        if (qry.exec("SELECT * FROM loadconfig"))
        {
            while(qry.next()){
                QString sex = qry.value(0).toString();
                qDebug() << sex;
            }
        }
        else {
            qDebug() << "DbError";
            QMessageBox::critical(0, QObject::tr("DB - ERROR!"),
                                  db.lastError().text());
        }

        qDebug() << "size " << qry.size();

    qDebug() << "addDatabase() " << (db.isValid() ? "VALID" : "ERROR");

    db.close();*/
    return a.exec();
}
