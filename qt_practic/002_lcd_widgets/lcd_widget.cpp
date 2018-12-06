#include "lcd_widget.h"
#include "ui_lcd_widget.h"

lcd_widget::lcd_widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lcd_widget)
{
    ui->setupUi(this);
}

lcd_widget::~lcd_widget()
{
    delete ui;
}

void lcd_widget::on_pushButtonPlus_clicked()
{
    action(1);
}


void lcd_widget::on_pushButtonMinus_clicked()
{
    action(2);
}

void lcd_widget::on_pushButtonProduct_clicked()
{
    action(3);
}

void lcd_widget::action(int iVal)
{
    double a = ui->lineEdit_1->text().toDouble();
    double b = ui->lineEdit_2->text().toDouble();

    double c = 0;

    switch (iVal)
    {
    case 1: { c = a + b; break; }
    case 2: { c = a - b; break;}
    case 3: { c = a * b; break;}
    default: break;
    }

    ui->lcdNumber->display(c);

}

void lcd_widget::on_pushButtonCE_clicked()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lcdNumber->display(0);
}

void lcd_widget::on_pushButton_1_clicked()
{

    ui->lcdNumber->display(0.00);
}
