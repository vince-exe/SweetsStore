#ifndef VIEW_CART_DIALOG_H
#define VIEW_CART_DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>

#include "product.h"

void printTable(std::vector<std::string>* customerCart, std::map<std::string, Product>* productsDatabase, QStandardItemModel* model, QTableView* table);

void printSearchedCartProd(std::vector<std::string>* customerCart, std::map<std::string, Product>* productsDatabase, QStandardItemModel* searchModel, QTableView* table, std::string search);

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

    void on_srchProductBox_textChanged(const QString &arg1);

    void on_srchButton_clicked();

    void on_resetBtn_clicked();

    void on_rmvProductBtn_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::ViewCartDialog *ui;
};

#endif // VIEW_CART_DIALOG_H
