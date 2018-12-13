#include "bookedit.h"
#include "ui_bookedit.h"
#include <QtSql>
#include <QDebug>

bookedit::bookedit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookedit)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());//Установка даты по умолчанию

    QSqlQuery query;

}

bookedit::~bookedit()
{
    delete ui;
}

void bookedit::on_pushButtonOk_clicked()
{
    dataEdit(1);
}

void bookedit::dataEdit(int iVal)
{
    if (iVal == 1)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO book (lname, fname, date, phone, adress) "
                      "VALUES (:lname, :fname, :date, :phone, :adress)");
        query.bindValue( ":lname",   ui->lineEditLName ->text() );
        query.bindValue( ":fname",   ui->lineEditFName->text() );
        query.bindValue( ":date",    ui->dateEdit->date().DateFormat );
        query.bindValue( ":phone",   ui->lineEditPhone->text().toInt() );
        query.bindValue( ":adress",  ui->lineEditAdress->text() );
        query.exec();

        if ( query.lastError().type() != QSqlError::NoError )
        {
            qCritical() << query.lastError().text();
        }
    }
    if (iVal ==2)
    {

    }

    bookedit::accept();
}
