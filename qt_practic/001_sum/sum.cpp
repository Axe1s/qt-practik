#include "sum.h"
#include "ui_sum.h"

sum::sum(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sum)
{
    ui->setupUi(this);
}

sum::~sum()
{
    delete ui;
}

void sum::on_pushButtonPlus_clicked()
{
    summa(true);
}

void sum::on_pushButtonMinus_clicked()
{
    summa(false);
}
void sum::summa (bool bVal)
{
    int a = ui->lineEdit1->text().toInt();
    int b = ui->lineEdit2->text().toInt();
    int c = 0;

    if (bVal == true) { c = a + b; }
    else { c = a - b; }

    QString s = QString::number(c);

    ui->lineEditResult->setText(s);


}
