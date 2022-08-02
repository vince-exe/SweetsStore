#ifndef VIEW_EMPLOYEES_DIALOG_H
#define VIEW_EMPLOYEES_DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>

#include "employee.h"

/* print the employees table */
void printEmployeesTable(QStandardItemModel* model, std::map<std::string, Employee>* employeeDatabase, QTableView* table);

/* print the searched employee */
void printSearchedEmployee(QStandardItemModel* model, std::map<std::string, Employee>* employeeDatabase, QTableView* table, std::string searchedEmply);

namespace Ui {
class ViewEmployeesDialog;
}

class ViewEmployeesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewEmployeesDialog(QWidget *parent = nullptr);
    ~ViewEmployeesDialog();

private slots:
    void on_srchEmplyBox_textChanged(const QString &arg1);

    void on_infoBtn_clicked();

    void on_addProdBtn_4_clicked();

    void on_saveBtn_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_updtBtn_clicked();

    void on_rmEmplyBtn_clicked();

    void on_resetBtn_clicked();

    void on_srchButton_clicked();

private:
    Ui::ViewEmployeesDialog *ui;
};

#endif // VIEW_EMPLOYEES_DIALOG_H
