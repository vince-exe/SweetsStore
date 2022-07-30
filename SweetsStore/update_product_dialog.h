#ifndef UPDATE_PRODUCT_DIALOG_H
#define UPDATE_PRODUCT_DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>

void setInputBoxes(QLineEdit* f1, QLineEdit* f2, QLineEdit* f3, QSpinBox* f4, QDateEdit* f5);

namespace Ui {
class UpdateProductDialog;
}

class UpdateProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateProductDialog(QWidget *parent = nullptr);
    ~UpdateProductDialog();

private slots:
    void on_prodNameBox_textChanged(const QString &arg1);

    void on_brandBox_textChanged(const QString &arg1);

    void on_priceBox_textChanged(const QString &arg1);

    void on_saveButton_clicked();

private:
    Ui::UpdateProductDialog *ui;
};

#endif // UPDATE_PRODUCT_DIALOG_H
