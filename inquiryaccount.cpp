#include "inquiryaccount.h"
#include "ui_inquiryaccount.h"

// tableWidget 수정 불가능.

InquiryAccount::InquiryAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InquiryAccount)
{
    ui->setupUi(this);
    ui->tableWidget->setHorizontalHeaderLabels({"계좌번호", "잔액", "이름", "생년월일"}); // 열 이름 설정
    ui->tableWidget->resizeColumnToContents(ui->tableWidget->columnCount());    // 열 너비 설정
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);   // 마지막 열 너비 설정
}

InquiryAccount::~InquiryAccount()
{
    delete ui;
}

void InquiryAccount::on_btn_ExitInquiry_clicked()
{
    this->close();
}

void InquiryAccount::on_btn_Inquiry_clicked()
{
    Account* account = new Account();

    QSqlQuery qry = account->InquiryAcc();

    qry.exec();
    ui->tableWidget->setRowCount(0);
    while(qry.next()){
        int currentRow = ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(currentRow+1);
        ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(qry.value(0).toString()));
        ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(qry.value(1).toString()));
        ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(qry.value(2).toString()));
        ui->tableWidget->setItem(currentRow, 3, new QTableWidgetItem(qry.value(3).toString()));
    }

    delete account;
}
