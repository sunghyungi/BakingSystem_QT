#ifndef REMITTANCE_H
#define REMITTANCE_H

#include <QWidget>

namespace Ui {
class Remittance;
}

class Remittance : public QWidget
{
    Q_OBJECT

public:
    explicit Remittance(QWidget *parent = nullptr);
    ~Remittance();

private slots:
    void on_btn_ExitRemittance_clicked();

private:
    Ui::Remittance *ui;
};

#endif // REMITTANCE_H
