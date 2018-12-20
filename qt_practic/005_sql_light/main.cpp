#include "sqllight.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{



    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE"); //Создание подключения базы данных
    dbase.setDatabaseName ("base/base.db"); //Путь к базе данных


    if (!dbase.open())  //Проверка соединения с базой данных
    {
        qDebug() << "No connect";
    }
    else
    {
        qDebug() << "Connected";
    }

    QApplication a(argc, argv);
    sqllight w;
    w.show();

    return a.exec();

    dbase.close();
}
