#include "account.h"
#include "inquiryaccount.h"


Account::Account(int num, int pass, char* name, char* birth, int money)
        :accNum(num), passWord(pass), balance(money)
{
    std::strcpy(cusName, name);
    std::strcpy(cusBirth, birth);

    // SQL Server information
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("user_BankingSystem");
    db.setPassword("rootroot");
    db.setDatabaseName("BankingSystem");

    if(db.open())
    {
        printf("Database open");
    }
    else
    {
        printf("Database not open");
    }
}

Account::Account()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("user_BankingSystem");
    db.setPassword("rootroot");
    db.setDatabaseName("BankingSystem");

    if(db.open())
    {
        printf("Database open");
    }
    else
    {
        printf("Database not open");
    }
}

void Account::CreateAcc()
{
    QSqlQuery qry;
    qry.prepare("insert into Account "
             "values(:accNum, :passWord, :cusName, :cusBirth, :money)");

    qry.bindValue(":accNum", accNum);
    qry.bindValue(":passWord", passWord);
    qry.bindValue(":cusName", cusName);
    qry.bindValue(":cusBirth", cusBirth);
    qry.bindValue(":money", 0);

    if(qry.exec())
    {
        printf("insert success");
    }
    else{
        printf("insert failed");
    }

}

QSqlQuery Account::InquiryAcc()
{
    QSqlQuery qry;
    qry.prepare("select accNum, cusName, cusBirth, balance from Account");

    return qry;

}

void Account::Deposit()
{
    QSqlQuery qry;
    qry.prepare("update Account set balance=balance+:balance"
                    " where accNum=:accNum");

    qry.bindValue(":accNum", accNum);
    qry.bindValue(":balance", balance);


    qry.exec();
}

void Account::Withdraw()
{
    QSqlQuery qry;
    qry.prepare("update Account set balance=balance-:balance"
                    " where accNum=:accNum and passWord=:passWord");

    qry.bindValue(":accNum", accNum);
    qry.bindValue(":balance", balance);
    qry.bindValue(":passWord", passWord);

    QSqlQuery qry2;
    qry2.prepare("Select balance from Account where accNum=:accNum");

    qry2.bindValue(":accNum", accNum);
    qry2.exec();
    qry2.next();

    if(qry2.value(0).toInt()>balance){
        qry.exec();
    }
    else{
        printf("잔액이부족합니다.");
    }


}

void Account::Remittance(int yourNum)
{
    QSqlQuery qry;
    qry.prepare("update Account set balance=balance-:balance"
                    " where accNum=:accNum and passWord=:passWord");

    qry.bindValue(":accNum", accNum);
    qry.bindValue(":balance", balance);
    qry.bindValue(":passWord", passWord);

    QSqlQuery qry2;
    qry2.prepare("Select balance from Account where accNum=:accNum");

    qry2.bindValue(":accNum", accNum);
    qry2.exec();
    qry2.next();

    QSqlQuery qry3;
    qry3.prepare("update Account set balance=balance+:balance where accNum=:accNum");

    qry3.bindValue(":balance", balance);
    qry3.bindValue(":accNum", yourNum);


    if(qry2.value(0).toInt()>balance){
        qry.exec();
        qry3.exec();
    }
    else{
        printf("잔액이부족합니다.");
    }
}

Account::~Account()
{
    db.close();
//    db.removeDatabase( QSqlDatabase::defaultConnection );
}
