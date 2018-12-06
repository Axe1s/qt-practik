#include "calculater.h"
#include "ui_calculater.h"


calculater::calculater(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calculater)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(enteredNumbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(enteredNumbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(enteredNumbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(enteredNumbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(enteredNumbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(enteredNumbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(enteredNumbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(enteredNumbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(enteredNumbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(enteredNumbers()));
    connect(ui->pushButtonPoint,SIGNAL(clicked()),this,SLOT(enteredNumbers()));

    m_strDisplay = "";
    dValFirst = 0;
    bPlus   = false;
    bMinus  = false;
    bMult   = false;
    bDiv    = false;

}

calculater::~calculater()
{
    delete ui;
}

void calculater::on_pushButtonCE_clicked()
{
    m_stk.clear();
    m_strDisplay = "";
    ui->lcdNumber->display(0);

    dValFirst = 0;

    bPlus   = false;
    bMinus  = false;
    bMult   = false;
    bDiv    = false;
}

void calculater::enteredNumbers()
{
    QString button = ((QPushButton*)sender())->text();

  if (button.contains(QRegExp("[0-9]")))
   {
       m_strDisplay += button;
       ui->lcdNumber->display(m_strDisplay.toDouble());
   } else if ( button == ".")
   {
       if (!m_strDisplay.contains("."))
       {
           m_strDisplay += button;
           ui->lcdNumber->display(m_strDisplay);
       }
    }
}

void calculater::on_pushButtonPlusMinus_clicked()
{
    double dVal = m_strDisplay.toDouble()*(-1);
    ui->lcdNumber->display(dVal);
    m_strDisplay = QString::number(dVal);
}


void calculater::on_pushButtonBS_clicked()
{
    m_strDisplay.chop(1);
    ui->lcdNumber->display(m_strDisplay.toDouble());
}

void calculater::on_pushButtonPlus_clicked()
{
    calculation();

    dValFirst = m_strDisplay.toDouble();
    bPlus = true;
    bMinus  = false;
    bMult   = false;
    bDiv    = false;
    m_strDisplay = "";

}

void calculater::on_pushButtonMinus_clicked()
{
    calculation();

    dValFirst = m_strDisplay.toDouble();
    bPlus   = false;
    bMinus  = true;
    bMult   = false;
    bDiv    = false;
    m_strDisplay = "";
}

void calculater::on_pushButtonMulc_clicked()
{
    calculation();

    dValFirst = m_strDisplay.toDouble();
    bPlus   = false;
    bMinus  = false;
    bMult   = true;
    bDiv    = false;
    m_strDisplay = "";
}

void calculater::on_pushButtonDivide_clicked()
{
    calculation();

    dValFirst = m_strDisplay.toDouble();
    bPlus   = false;
    bMinus  = false;
    bMult   = false;
    bDiv    = true;
    m_strDisplay = "";
}

void calculater::calculation()
{
    double dVal = 0;

    if (bPlus)
    {
        dVal = dValFirst + m_strDisplay.toDouble();
    }
    if (bMinus)
    {
        dVal = dValFirst - m_strDisplay.toDouble();
    }

    if (bMult)
    {
        dVal = dValFirst * m_strDisplay.toDouble();
    }

    if (bDiv)
    {
        dVal = dValFirst / m_strDisplay.toDouble();
    }

    if (bPlus || bMinus || bMult || bDiv)
    {
        ui->lcdNumber->display(dVal);
//        dValFirst = dVal;
        m_strDisplay = QString::number(dVal);
    }

}

void calculater::on_pushButtonEquality_clicked()
{
    calculation();

    bPlus   = false;
    bMinus  = false;
    bMult   = false;
    bDiv    = false;
    dValFirst = 0;
}



