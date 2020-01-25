#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <cstring>
#include <iostream>
#include "mainwindow.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

using namespace std;


class Account
{
private:
    int accNum;
    int passWord;
    char cusName[20];
    char cusBirth[20];
    int balance;

public:
    QSqlDatabase db;
    Account(int num, int pass, char* name, char* birth, int money);
    void CreateAcc();
    void InquiryAcc();
    void Deposit();
    void Withdraw();

};

#endif // ACCOUNT_H
