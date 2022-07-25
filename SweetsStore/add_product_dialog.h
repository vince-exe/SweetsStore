#ifndef ADD_PRODUCT_DIALOG_H
#define ADD_PRODUCT_DIALOG_H

#include <QDialog>

namespace Ui {
class AddProductDialog;
}

class AddProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProductDialog(QWidget *parent = nullptr);
    ~AddProductDialog();

private:
    Ui::AddProductDialog *ui;
};

#endif // ADD_PRODUCT_DIALOG_H
