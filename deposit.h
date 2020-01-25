#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>
#include "account.h"

namespace Ui {
class Deposit;
}

class Deposit : public QWidget
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();

private slots:
    void on_btn_ExitDeposit_clicked();

    void on_btn_Deposit_clicked();

private:
    Ui::Deposit *ui;
};

#endif // DEPOSIT_H
