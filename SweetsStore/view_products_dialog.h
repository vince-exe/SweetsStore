#ifndef VIEW_PRODUCTS_DIALOG_H
#define VIEW_PRODUCTS_DIALOG_H

#include <QDialog>

namespace Ui {
class ViewProductsDialog;
}

class ViewProductsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewProductsDialog(QWidget *parent = nullptr);
    ~ViewProductsDialog();

private slots:
    void on_addProdBtn_4_clicked();

    void on_addProdBtn_2_clicked();

private:
    Ui::ViewProductsDialog *ui;
};

#endif // VIEW_PRODUCTS_DIALOG_H
