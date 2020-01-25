#include "createaccount.h"
#include "ui_createaccount.h"



CreateAccount::CreateAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateAccount)
{
    ui->setupUi(this);

}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_btn_ExitCreate_clicked()
{
    this->close();
}

void CreateAccount::on_btn_Create_clicked()
{
    int num = ui->le_AccNum->text().toInt();
    int pass = ui->le_Password->text().toInt();
    char* name = new char[20];
    strcpy(name, ui->le_Name->text().toStdString().c_str());
    char* birth= new char[20];
    strcpy(birth, ui->le_Birth->text().toStdString().c_str());
    int money = 0;

    Account* account = new Account(num, pass, name, birth, money);
    account->CreateAcc();
    delete[] name;
    delete[] birth;
    delete account;
    this->close();


}
