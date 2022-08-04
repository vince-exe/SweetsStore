#ifndef VIEW_PRODUCTS_DIALOG_H
#define VIEW_PRODUCTS_DIALOG_H

#include <QDialog>
#include <QStandardItem>
#include <QTableView>

#include "product.h"

/* print the table */
void printTable(QStandardItemModel* model, std::map<std::string, Product>* productsMap, QTableView* table);

/* print the searched product in the table */
void printsearchedProduct(std::map<std::string, Product>* productsMap, QStandardItemModel* searchModel, QTableView* table, std::string searchedProduct);

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

    void on_addProdBtn_5_clicked();

    void on_infoBtn_clicked();

    void on_rmProdBtn_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_prodNameBox_textChanged(const QString &arg1);

    void on_srchButton_clicked();

    void on_resetBtn_clicked();

private:
    Ui::ViewProductsDialog *ui;
};

#endif // VIEW_PRODUCTS_DIALOG_H
