#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QFrame>
#include <QSqlRecord>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QScrollArea>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static int x;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_2_clicked();

    void on_profiel2_pushButton_3_clicked();

    void on_profile2_logout_clicked();

    void on_pushButton_4_clicked();



     void on_singup_clicked();

     void on_profilebutton_p2_clicked();

     void on_backbutton_p2_clicked();

     void on_searchbutton_p2_clicked();


     void onnameclicked();

     void on_confirm_button_p5_clicked();

     void on_singelbook_p4_clicked();

     void on_doublebook_p4_clicked();


     void on_back_button_p4_clicked();

     void on_doublebook_p4_2_clicked();

     void on_back_Button_p3_clicked();

     void on_back_Button_p3_2_clicked();

     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString login_email,login_password,signup_name,signup_email,signup_contact,signup_password;
    QString divisiontext,roomtext;
    QString c_name,c_email,c_mobile,c_cardname,c_cardtype,c_cardnumber,c_room;
    QString btxt,bemail,badress,bmobile,bname,bs_price="   ",bd_price="   ",b_pic;
    QString price1,price2,price3;
    QString pname="   ",pemail="   ",pmobile="   ";
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
