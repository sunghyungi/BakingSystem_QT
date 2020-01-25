#include "withdraw.h"
#include "ui_withdraw.h"

Withdraw::Withdraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Withdraw)
{
    ui->setupUi(this);
}

Withdraw::~Withdraw()
{
    delete ui;
}

void Withdraw::on_btn_ExitWithdraw_clicked()
{
    this->close();
}

void Withdraw::on_btn_Withdraw_clicked()
{
    int num = ui->le_AccountNumber->text().toInt();
    int money = ui->le_WithdrawAmount->text().toInt();
    int pass = ui->le_AccountPassword->text().toInt();
    char string[20] = "";
    Account* account = new Account(num, pass, string, string, money);

    account->Withdraw();
    delete account;
    this->close();
}
