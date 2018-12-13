#include "sqllight.h"
#include "ui_sqllight.h"
#include "bookedit.h"

sqllight::sqllight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sqllight),
    model(this)
{
    ui->setupUi(this);
    ui->tableView->setModel(&model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    model.setTable("book");
    model.select();

    if ( model.lastError().type() != QSqlError::NoError )//Вывод ошибок в консоль
        qCritical() << model.lastError().text();
}


sqllight::~sqllight()
{
    delete ui;
}

void sqllight::on_pushButtonAdd_clicked()
{
    editData();
}

void sqllight::editData()
{
    bookedit * pAddDate = new bookedit (this);
    pAddDate->exec();
    delete pAddDate;
    model.select();

}
