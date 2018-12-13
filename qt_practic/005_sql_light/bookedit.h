#ifndef BOOKEDIT_H
#define BOOKEDIT_H

#include <QDebug>
#include <QSql>
#include <QDialog>

namespace Ui {
class bookedit;
}

class bookedit : public QDialog
{
    Q_OBJECT

public:
    explicit bookedit(QWidget *parent = nullptr);
    ~bookedit();

private slots:
    void dataEdit(int);
    void on_pushButtonOk_clicked();

private:
    Ui::bookedit *ui;
};

#endif // BOOKEDIT_H
