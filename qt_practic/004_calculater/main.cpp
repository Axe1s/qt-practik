#include "calculater.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calculater w;
    w.show();

    return a.exec();
}
