#include "forgotpasswd.h"
#include "ui_forgotpasswd.h"

#include <QMessageBox>
Forgotpasswd::Forgotpasswd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forgotpasswd)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

}

Forgotpasswd::~Forgotpasswd()
{
    delete ui;
}

void Forgotpasswd::on_pushButton_chk_clicked()
{
     MainWindow mwi;
    QString em = ui->lineEdit_email->text();
    mwi.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from Clients where Email_ID='"+em+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->stackedWidget->setCurrentIndex(1);
            ui->label_sq->setText(qry.value(14).toString());
            mwi.connClose();
        }

    }
    else
        QMessageBox::warning(this, tr("Error"), "Email ID not found.");




}

void Forgotpasswd::on_pushButton_chk_1_clicked()
{
    MainWindow mwi;
    QString em = (ui->lineEdit_email->text());
   QString ans = (ui->lineEdit_ans->text()).toUpper();
   mwi.connOpen();
   QSqlQuery qry;
   qry.prepare("select * from Clients where Answer='"+ans+"' and Email_ID='"+em+"'");

   if(qry.exec())
   {
       while(qry.next())
       {
           ui->stackedWidget->setCurrentIndex(2);
            ui->label_4->setVisible(false);
           mwi.connClose();
       }

   }
   else
       QMessageBox::warning(this, tr("Error"), "Wrong Answer!!");
}

void Forgotpasswd::on_pushButton_change_clicked()
{
    QString pswd = ui->lineEdit_pwd->text();
    QString re_pswd = ui->lineEdit_pwd_2->text();

   QString em = ui->lineEdit_email->text();
   QString ans = (ui->lineEdit_ans->text()).toUpper();
MainWindow mwi;
mwi.connOpen();
    if(pswd==re_pswd)
    {
        QSqlQuery qry;
        qry.prepare("update Clients set Password='"+pswd+"' where Answer='"+ans+"' and Email_ID='"+em+"' ");
        if(qry.exec())
        {
            QMessageBox::information(this, "Status", "Password Changed\nIt will take effect after restarting the application.");
            mwi.connClose();
            this->hide();

            qApp->quit();
            QProcess::startDetached(qApp->arguments()[0], qApp->arguments());


        }

    }


}

void Forgotpasswd::on_lineEdit_pwd_2_editingFinished()
{
    QString pswd = ui->lineEdit_pwd->text();
    QString re_pswd = ui->lineEdit_pwd_2->text();

    if(pswd==re_pswd)
    {
        ui->label_4->setVisible(false);
    }
    else{
        ui->label_4->setVisible(true);
        ui->label_4->setText("Password Not Matched..");
    }
}
