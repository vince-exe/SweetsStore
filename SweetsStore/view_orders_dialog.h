#ifndef VIEW_ORDERS_DIALOG_H
#define VIEW_ORDERS_DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>

#include "order.h"

void printTable(std::map<int, Order>* ordersDatabase, QStandardItemModel* model, QTableView* table);

namespace Ui {
class ViewOrdersDialog;
}

class ViewOrdersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewOrdersDialog(QWidget *parent = nullptr);
    ~ViewOrdersDialog();

private:
    Ui::ViewOrdersDialog *ui;
};

#endif // VIEW_ORDERS_DIALOG_H
