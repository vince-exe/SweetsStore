#ifndef ADD_MONEY_DIALOG_H
#define ADD_MONEY_DIALOG_H

#include <QDialog>

namespace Ui {
class AddMoneyDialog;
}

class AddMoneyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMoneyDialog(QWidget *parent = nullptr);
    ~AddMoneyDialog();

private slots:
    void on_moneyBox_textChanged(const QString &arg1);

    void on_saveBtn_clicked();

private:
    Ui::AddMoneyDialog *ui;
};

#endif // ADD_MONEY_DIALOG_H
