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
