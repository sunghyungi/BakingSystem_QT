#ifndef INQUIRYACCOUNT_H
#define INQUIRYACCOUNT_H

#include <QWidget>
#include "account.h"
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class InquiryAccount;
}

class InquiryAccount : public QWidget
{
    Q_OBJECT

public:
    explicit InquiryAccount(QWidget *parent = nullptr);
    ~InquiryAccount();

private slots:
    void on_btn_ExitInquiry_clicked();

    void on_btn_Inquiry_clicked();

private:
    Ui::InquiryAccount *ui;
};

#endif // INQUIRYACCOUNT_H
