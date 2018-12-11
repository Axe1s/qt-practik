#ifndef BOOKEDIT_H
#define BOOKEDIT_H

#include <QWidget>
#include <QSql>

namespace Ui {
class bookedit;
}

class bookedit : public QWidget
{
    Q_OBJECT

public:
    explicit bookedit(QWidget *parent = nullptr);
    ~bookedit();

private:
    Ui::bookedit *ui;
};

#endif // BOOKEDIT_H
