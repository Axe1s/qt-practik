#ifndef SUM_H
#define SUM_H

#include <QMainWindow>

namespace Ui {
class sum;
}

class sum : public QMainWindow
{
    Q_OBJECT

public:
    explicit sum(QWidget *parent = nullptr);
    ~sum();

private slots:
    void on_pushButtonPlus_clicked();

    void on_pushButtonMinus_clicked();

    void summa(bool);

private:
    Ui::sum *ui;
};

#endif // SUM_H
