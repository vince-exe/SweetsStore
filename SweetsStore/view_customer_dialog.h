#ifndef VIEW_CUSTOMER_DIALOG_H
#define VIEW_CUSTOMER_DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>

#include "customer.h"

/* print the customers table */
void printCustomersTable(QStandardItemModel* model, std::map<std::string, Customer>* customerDatabase, QTableView* table);

/* print the searched customers */
void printSearchedCustomer(QStandardItemModel* model, std::map<std::string, Customer>* customerDatabase, QTableView* table, std::string searchedCustomer);

namespace Ui {
class ViewCustomerDialog;
}

class ViewCustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewCustomerDialog(QWidget *parent = nullptr);
    ~ViewCustomerDialog();

private slots:
    void on_infoBtn_clicked();

    void on_addCustomerBtn_clicked();

    void on_updtCustomerBtn_clicked();

    void on_rmCustomerBtn_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_saveBtn_clicked();

    void on_srchButton_clicked();

    void on_resetBtn_clicked();

    void on_srchCustomerBox_textChanged(const QString &arg1);

private:
    Ui::ViewCustomerDialog *ui;
};

#endif // VIEW_CUSTOMER_DIALOG_H
