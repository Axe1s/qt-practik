#ifndef LCD_WIDGET_H
#define LCD_WIDGET_H

#include <QMainWindow>

namespace Ui {
class lcd_widget;
}

class lcd_widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit lcd_widget(QWidget *parent = nullptr);
    ~lcd_widget();

private slots:
    void on_pushButtonPlus_clicked();

    void action(int);

    void on_pushButtonMinus_clicked();

    void on_pushButtonProduct_clicked();

    void on_pushButtonCE_clicked();

    void on_pushButton_1_clicked();

private:
    Ui::lcd_widget *ui;
};

#endif // LCD_WIDGET_H
