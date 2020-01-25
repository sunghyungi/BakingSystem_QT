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
