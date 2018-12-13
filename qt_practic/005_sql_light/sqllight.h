#ifndef SQLLIGHT_H
#define SQLLIGHT_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>

namespace Ui {
class sqllight;
}

class sqllight : public QMainWindow
{
    Q_OBJECT

public:
    explicit sqllight(QWidget *parent = nullptr);
    ~sqllight();

private slots:
    void editData();
    void on_pushButtonAdd_clicked();

private:
    Ui::sqllight *ui;
    QSqlTableModel model;
};

#endif // SQLLIGHT_H
