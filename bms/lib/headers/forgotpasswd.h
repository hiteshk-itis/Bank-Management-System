#ifndef FORGOTPASSWD_H
#define FORGOTPASSWD_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Forgotpasswd;
}

class Forgotpasswd : public QDialog
{
    Q_OBJECT

public:
    explicit Forgotpasswd(QWidget *parent = nullptr);
    ~Forgotpasswd();

private slots:
    void on_pushButton_chk_clicked();

    void on_pushButton_chk_1_clicked();

    void on_pushButton_change_clicked();

    void on_lineEdit_pwd_2_editingFinished();

private:
    Ui::Forgotpasswd *ui;

};

#endif // FORGOTPASSWD_H
