#include "sum.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sum w;
    w.show();

    return a.exec();
}
