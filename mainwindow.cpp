#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createaccount.h"
#include "inquiryaccount.h"
#include "deposit.h"
#include "withdraw.h"
#include "remittance.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_CreateAcc_clicked()
{
    CreateAccount *createAcc;
    createAcc = new CreateAccount();
    createAcc->show();
}

void MainWindow::on_btn_Inquiry_clicked()
{
    InquiryAccount *inquiryAcc;
    inquiryAcc = new InquiryAccount();
    inquiryAcc->show();
}

void MainWindow::on_btn_Exit_clicked()
{
    this->close();
}

void MainWindow::on_btn_Deposit_clicked()
{
    Deposit *deposit;
    deposit = new Deposit();
    deposit->show();
}

void MainWindow::on_btn_Withdraw_clicked()
{
    Withdraw *withdraw;
    withdraw = new Withdraw();
    withdraw->show();
}

void MainWindow::on_btn_Remittance_clicked()
{
    Remittance *remittance;
    remittance = new Remittance();
    remittance->show();
}

void MainWindow::on_btn_dbconnect_clicked()
{

}
