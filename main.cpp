#include "principal.h"

#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal w;
    w.show();

    return a.exec();
}
