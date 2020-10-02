#ifndef CREATECLIENT_H
#define CREATECLIENT_H

#include <QDialog>

#include <mainwindow.h>

namespace Ui {
class CreateClient;
}

class CreateClient : public QDialog
{
    Q_OBJECT

public:
    explicit CreateClient(QWidget *parent = nullptr);
    ~CreateClient();

private slots:
    void on_pushButton_prDetails_clicked();

    void on_pushButton_bnAcc_n_clicked();

    void on_pushButton_bnAcc_b_clicked();

    void on_pushButton_sec_create_clicked();

    void on_pushButton_sec_b_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::CreateClient *ui;
    MainWindow mw;
};

#endif // CREATECLIENT_H
