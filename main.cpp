#include <QCoreApplication>
#include <QTimer>
#include "MainObject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainObject mObj;

    QObject::connect(&mObj,&MainObject::finished, &a, &QCoreApplication::quit);

    QTimer::singleShot(500, &mObj, SLOT(run()));

    return a.exec();
}
