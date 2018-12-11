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
    connect(ui->pushButtonPlus,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButtonMinus,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButtonMulc,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButtonDivide,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButtonProcents,SIGNAL(clicked()),this,SLOT(math()));

    m_strDisplay = "";
    dValFirst = 0;
    bPlus   = false;
    bMinus  = false;
    bMult   = false;
    bDiv    = false;
    bProc   = false;

}

calculater::~calculater()
{
    delete ui;
}

void calculater::on_pushButtonCE_clicked()
{

    m_strDisplay = "";
    ui->lcdNumber->display(0);

    dValFirst = 0;

    bPlus   = false;
    bMinus  = false;
    bMult   = false;
    bDiv    = false;
    bProc   = false;
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


void calculater::math()
{
    calculation();

    bPlus   = false;
    bMinus  = false;
    bMult   = false;
    bDiv    = false;
    bProc   = false;

    dValFirst = m_strDisplay.toDouble();

    QString button = ((QPushButton*)sender())->text();
    if (button.contains("+"))
    {
        bPlus   = true;
    }
    if (button.contains("-"))
    {
        bMinus   = true;
    }
    if (button.contains("*"))
    {
        bMult   = true;
    }
    if (button == "/")
    {
        bDiv   = true;
    }
    if (button == "%")
    {
        bProc   = true;
    }
    m_strDisplay = "";
}

void calculater::on_pushButtonEquality_clicked()
{
    calculation();

    bPlus   = false;
    bMinus  = false;
    bMult   = false;
    bDiv    = false;
    bProc   = false;
    dValFirst = 0;
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

    if (bProc)
    {
        dVal = dValFirst * (m_strDisplay.toDouble())* 0.01;
    }

    if (bPlus || bMinus || bMult || bDiv || bProc)
    {
        ui->lcdNumber->display(dVal);
        m_strDisplay = QString::number(dVal);
    }

}
