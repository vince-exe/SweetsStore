#ifndef VIEW_CART_DIALOG_H
#define VIEW_CART_DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>

#include "product.h"

void printTable(std::vector<std::string>* customerCart, std::map<std::string, Product>* productsDatabase, QStandardItemModel* model, QTableView* table);

namespace Ui {
class ViewCartDialog;
}

class ViewCartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCartDialog(QWidget *parent = nullptr);
    ~ViewCartDialog();

private slots:
    void on_infoBtn_clicked();

private:
    Ui::ViewCartDialog *ui;
};

#endif // VIEW_CART_DIALOG_H
