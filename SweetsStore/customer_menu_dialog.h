#ifndef CUSTOMER_MENU_DIALOG_H
#define CUSTOMER_MENU_DIALOG_H

#include <QDialog>

namespace Ui {
class CustomerMenuDialog;
}

class CustomerMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerMenuDialog(QWidget *parent = nullptr);
    ~CustomerMenuDialog();

private slots:
    void on_abtMeBtn_clicked();

    void on_addMoneyBtn_clicked();

    void on_buyNowBtn_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_viewOrdersBtn_clicked();

    void on_infoBtn_clicked();

    void on_srchProdBox_textChanged(const QString &arg1);

    void on_srchButton_clicked();

    void on_resetBtn_clicked();

private:
    Ui::CustomerMenuDialog *ui;
};

#endif // CUSTOMER_MENU_DIALOG_H
