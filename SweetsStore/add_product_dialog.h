#ifndef ADD_PRODUCT_DIALOG_H
#define ADD_PRODUCT_DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDateEdit>

#include <iostream>
#include <string>

namespace Ui {
class AddProductDialog;
}

class AddProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProductDialog(QWidget *parent = nullptr);
    ~AddProductDialog();

private slots:
    void on_prodNameBox_textChanged(const QString &arg1);

    void on_brandBox_textChanged(const QString &arg1);

    void on_priceBox_textChanged(const QString &arg1);

    void on_saveButton_clicked();

private:
    Ui::AddProductDialog *ui;
};

#endif // ADD_PRODUCT_DIALOG_H
