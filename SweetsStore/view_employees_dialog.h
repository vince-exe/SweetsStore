#ifndef VIEW_EMPLOYEES_DIALOG_H
#define VIEW_EMPLOYEES_DIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>

#include "employee.h"

/* print the employees table */
void printEmployeesTable(QStandardItemModel* model, std::map<std::string, Employee>* employeeDatabase, QTableView* table);

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

private:
    Ui::ViewEmployeesDialog *ui;
};

#endif // VIEW_EMPLOYEES_DIALOG_H
