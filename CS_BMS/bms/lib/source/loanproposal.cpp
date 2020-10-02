#include "loanproposal.h"
#include "ui_loanproposal.h"

#include <QMessageBox>

loanProposal::loanProposal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loanProposal)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    ui->spinBox_dur->setMinimum(6);



}

loanProposal::~loanProposal()

{
    delete ui;
}


void loanProposal::on_pushButton_loan_ys_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);


QString accn, bal;


    MainWindow mw;
    mw.connOpen();
    QSqlQuery qry1;
    qry1.prepare("SELECT * FROM    pendingLoan WHERE   ROWID = (SELECT MAX(ROWID)  FROM pendingLoan)");
    qry1.exec();
    while (qry1.next())
    {
        accn = qry1.value(0).toString();
        bal = qry1.value(1).toString();
    }

    ui->label_accn->setText(accn);
    ui->label_balance->setText(bal);
//------------------------------------calculation----------------------------

 /*if (purpose=="Home Loan")
     (ui->label_intrest->setText("4%"));
 else if(purpose=="Student Loan")
     (ui->label_intrest->setText("3%"));
 else if(purpose=="Business Loan")
     (ui->label_intrest->setText("6%"));
 else if(purpose=="Car Loan")
     (ui->label_intrest->setText("5%"));
  bool ok = true;
 int intr = ((principal.toDouble(&ok, 10))*((duration.toDouble(&ok, 10))/12)*interest.toDouble(&ok, 10))/100;
 amt = intr+principal.toDouble(&ok, 10);*/


//------------------------------------//------------------------------------


}

void loanProposal::on_pushButton_loan_no_clicked()
{
    QString accn;
    MainWindow mw;
    mw.connOpen();
    QSqlQuery qry,qry1;
    qry.prepare("SELECT * FROM    pendingLoan WHERE   ROWID = (SELECT MAX(ROWID)  FROM pendingLoan)");
    qry.exec();
    while (qry.next())
    {
         accn = qry.value(0).toString();

    }

    qDebug()<<accn;
    qry1.prepare("delete from pendingLoan where Account_No = '"+accn+"'");
    qry1.exec();
            //mw.connClose();
    this->close();
}
void loanProposal::on_pushButton_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void loanProposal::on_pushButton_apprval_clicked()
{
    QString accn = ui->label_accn->text();
    QString principal = ui->lineEdit_principal->text();
    QString duration = QString::number(ui->spinBox_dur->value(),10);
    QString purpose = ui->comboBox_purpose->currentText();
     QString interest = ui->label_intrest->text();
    QString amt = ui->label_ttlAmt->text();

    MainWindow mw;
    mw.connOpen();
    QSqlQuery qry;
    qry.prepare("update pendingLoan set Principal='"+principal+"', Duration= '"+duration+"', Purpose= '"+purpose+"', Interest= '"+interest+"', Amount= '"+amt+"' where Account_No='"+accn+"'");
    if(qry.exec())
    {
        QMessageBox::information(this, tr("Sent"), "Loan Request has been sent.\nIt will be approved by a bank Staff.");
        this->close();
    }
else{
        QMessageBox::critical(this,"Error", qry.lastError().text());
    }
}



void loanProposal::on_comboBox_purpose_currentTextChanged(const QString &arg1)
{
    const QString *purpos = &arg1;
    const QString purpose = *purpos;
    if (purpose=="Home Loan")
        (ui->label_intrest->setText("4"));
    else if(purpose=="Student Loan")
        (ui->label_intrest->setText("3"));
    else if(purpose=="Business Loan")
        (ui->label_intrest->setText("6"));
    else if(purpose=="Car Loan")
        (ui->label_intrest->setText("5"));
}

void loanProposal::on_spinBox_dur_editingFinished()
{
    QString principal = ui->lineEdit_principal->text();
    QString duration = QString::number(ui->spinBox_dur->value(),10);
    QString purpose = ui->comboBox_purpose->currentText();

    QString rinterest = ui->label_intrest->text();
qDebug() << principal.toDouble()<< rinterest.toDouble()<< duration.toDouble();
double interest=(principal.toDouble()*rinterest.toDouble()*(duration.toDouble()/12)/100);

    double totalamount=interest+principal.toDouble();

    QString inter;
    inter.sprintf("%f",interest);
   qDebug()<<inter;

   QString ttl;
   ttl.sprintf("%.2f",totalamount);
   //qDebug()<< anc;
   ui->label_ttlAmt->setText(ttl);

    QString amt = ui->label_ttlAmt->text();
}
