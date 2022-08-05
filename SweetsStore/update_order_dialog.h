#ifndef UPDATE_ORDER_DIALOG_H
#define UPDATE_ORDER_DIALOG_H

#include <QDialog>

namespace Ui {
class UpdateOrderDialog;
}

class UpdateOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateOrderDialog(QWidget *parent = nullptr);
    ~UpdateOrderDialog();

private slots:
    void on_updateBtn_clicked();

    void on_qntyBox_valueChanged(int arg1);

private:
    Ui::UpdateOrderDialog *ui;
};

#endif // UPDATE_ORDER_DIALOG_H
