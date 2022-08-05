#ifndef VIEW_ORDERS_DIALOG_H
#define VIEW_ORDERS_DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>

#include "order.h"

void printTable(std::map<int, Order>* ordersDatabase, QStandardItemModel* model, QTableView* table);

void printSearchedOrder(std::map<int, Order>* ordersDatabase, QStandardItemModel* searchModel, QTableView* table, std::string search);

namespace Ui {
class ViewOrdersDialog;
}

class ViewOrdersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewOrdersDialog(QWidget *parent = nullptr);
    ~ViewOrdersDialog();

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_updtOrderBtn_clicked();

    void on_infoBtn_clicked();

    void on_srchButton_clicked();

    void on_resetBtn_clicked();

    void on_srchOrderBox_textChanged(const QString &arg1);

    void on_rmvOrderBtn_clicked();

private:
    Ui::ViewOrdersDialog *ui;
};

#endif // VIEW_ORDERS_DIALOG_H
