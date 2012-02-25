#include <QtGui/QApplication>
#include "startwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Demographics w;
    w.show();

    return a.exec();
}
