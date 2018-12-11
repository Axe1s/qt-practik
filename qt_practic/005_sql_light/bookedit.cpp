#include "bookedit.h"
#include "ui_bookedit.h"

bookedit::bookedit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookedit)
{
    ui->setupUi(this);
}

bookedit::~bookedit()
{
    delete ui;
}
