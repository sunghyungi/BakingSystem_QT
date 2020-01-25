#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QWidget>
#include "account.h"

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAccount(QWidget *parent = nullptr);
    ~CreateAccount();

private slots:
    void on_btn_ExitCreate_clicked();

    void on_btn_Create_clicked();

private:
    Ui::CreateAccount *ui;
};

#endif // CREATEACCOUNT_H
