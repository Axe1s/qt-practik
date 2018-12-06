#include "date.h"
#include "ui_date.h"

date::date(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::date)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());//уставнока текущей даты
}

date::~date()
{
    delete ui;
}



void date::on_pushButtonDate_clicked()
{
//    char *a = ui->dateEdit->date();
//    ui->textEdit->setText(a);
}
