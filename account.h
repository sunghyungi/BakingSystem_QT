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
    Account();
    void CreateAcc();
    QSqlQuery InquiryAcc();
    void Deposit();
    void Withdraw();
    void Remittance(int yourNum);
    ~Account();
};

#endif // ACCOUNT_H
