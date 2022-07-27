#ifndef ADD_PRODUCT_DIALOG_H
#define ADD_PRODUCT_DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDateEdit>

#include <iostream>
#include <string>

/* check if the input boxes are empties */
bool checkEmptiesBox(QLineEdit *firstInput, QLineEdit *secondInput, QLineEdit *thirdInput, QSpinBox *spinBox);

/* check if the given date is valid */
bool checkDate(QDateEdit* dateEdit);

/* clear the widgets */
void clearInputFields(QLineEdit* f1, QLineEdit* f2, QLineEdit* f3, QSpinBox* f4, QDateEdit* f5);

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
