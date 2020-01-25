#include "deposit.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);
}

Deposit::~Deposit()
{
    delete ui;
}


void Deposit::on_btn_ExitDeposit_clicked()
{
    this->close();
}

void Deposit::on_btn_Deposit_clicked()
{
    int num = ui->le_myAccount->text().toInt();
    int money = ui->le_DepositAmount->text().toInt();
    char string[20] = "";
    Account* account = new Account(num, 0, string, string, money);

    account->Deposit();
    delete account;
    this->close();
}
