#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btn_CreateAcc_clicked();

    void on_btn_Inquiry_clicked();

    void on_btn_Exit_clicked();

    void on_btn_Deposit_clicked();

    void on_btn_Withdraw_clicked();

    void on_btn_Remittance_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
