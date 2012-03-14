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
   return a.exec();
}
