#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QWidget>
#include "account.h"

namespace Ui {
class Withdraw;
}

class Withdraw : public QWidget
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = nullptr);
    ~Withdraw();

private slots:
    void on_btn_ExitWithdraw_clicked();

    void on_btn_Withdraw_clicked();

private:
    Ui::Withdraw *ui;
};

#endif // WITHDRAW_H
