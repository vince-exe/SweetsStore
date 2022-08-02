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

private:
    Ui::CustomerMenuDialog *ui;
};

#endif // CUSTOMER_MENU_DIALOG_H
