#include "sqllight.h"
#include "ui_sqllight.h"
#include "bookedit.h"

sqllight::sqllight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sqllight),
    model(this)
{
    ui->setupUi(this);
    //Вывод модели
    ui->tableView->setModel(&model);
    //Попытка скрыть колонку ID
    ui->tableView->setColumnHidden(1,true);
    //Выделение строки
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //Выделение лишь одной строки
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    //Размер таблицы по содержимому
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
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
    bookedit *pAddDate = new bookedit (this);
    pAddDate->exec();
    delete pAddDate;
    model.select();

}
