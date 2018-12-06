#ifndef CALCULATER_H
#define CALCULATER_H

#include <QMainWindow>
#include <QStack>

namespace Ui {
class calculater;
}

class calculater : public QMainWindow
{
    Q_OBJECT

public:
    explicit calculater(QWidget *parent = nullptr);
    ~calculater();

private:
    Ui::calculater *ui;
    QStack<QString> m_stk;
    QString         m_strDisplay;
    double dValFirst, dValSecond;
    bool bPlus, bMinus, bMult, bDiv, bProc;


private slots:
    void enteredNumbers();
    void calculation();
    void math();
    void on_pushButtonPlusMinus_clicked();
    void on_pushButtonCE_clicked();
    void on_pushButtonBS_clicked();
    void on_pushButtonEquality_clicked();
};



#endif // CALCULATER_H
