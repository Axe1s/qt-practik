#include "date.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    date w;
    w.show();

    return a.exec();
}
