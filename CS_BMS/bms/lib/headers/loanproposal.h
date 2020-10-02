#ifndef LOANPROPOSAL_H
#define LOANPROPOSAL_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class loanProposal;
}

class loanProposal : public QDialog
{
    Q_OBJECT

public:
    explicit loanProposal(QWidget *parent = nullptr);
    ~loanProposal();

private slots:


    void on_pushButton_loan_ys_clicked();

    void on_pushButton_loan_no_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_apprval_clicked();






void on_spinBox_dur_editingFinished();
void on_comboBox_purpose_currentTextChanged(const QString &arg1);



private:
    Ui::loanProposal *ui;
};

#endif // LOANPROPOSAL_H
