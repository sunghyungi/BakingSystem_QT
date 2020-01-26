#include "remittance.h"
#include "ui_remittance.h"

Remittance::Remittance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Remittance)
{
    ui->setupUi(this);
}

Remittance::~Remittance()
{
    delete ui;
}

void Remittance::on_btn_ExitRemittance_clicked()
{
    this->close();
}

void Remittance::on_btn_Withdraw_clicked()
{
    int mynum = ui->le_myAccount->text().toInt();
    int mypass = ui->le_Password->text().toInt();
    int money = ui->le_WithdrawAmount->text().toInt();
    int yournum = ui->le_yourAccount->text().toInt();
    char string[20] = "";
    Account* account = new Account(mynum, mypass, string, string, money);

    account->Remittance(yournum);

    delete account;
    this->close();
}
