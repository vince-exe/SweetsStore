#ifndef BUY_PRODUCT_DIALOG_H
#define BUY_PRODUCT_DIALOG_H

#include <QDialog>

namespace Ui {
class BuyProductDialog;
}

class BuyProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BuyProductDialog(QWidget *parent = nullptr);
    ~BuyProductDialog();

private slots:
    void on_saveBtn_clicked();

    void on_qntyBox_valueChanged(int arg1);

private:
    Ui::BuyProductDialog *ui;
};

#endif // BUY_PRODUCT_DIALOG_H
