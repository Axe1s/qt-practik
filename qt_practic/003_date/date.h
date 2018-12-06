#ifndef DATE_H
#define DATE_H

#include <QMainWindow>

namespace Ui {
class date;
}

class date : public QMainWindow
{
    Q_OBJECT

public:
    explicit date(QWidget *parent = nullptr);
    ~date();


private slots:
    void on_pushButtonDate_clicked();

private:
    Ui::date *ui;
};

#endif // DATE_H
