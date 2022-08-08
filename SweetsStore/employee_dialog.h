#ifndef EMPLOYEE_DIALOG_H
#define EMPLOYEE_DIALOG_H

#include <QDialog>

namespace Ui {
class EmployeeDialog;
}

class EmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeDialog(QWidget *parent = nullptr);
    ~EmployeeDialog();

private slots:
    void on_prodMenuBtn_clicked();

    void on_emplyMenuBtn_clicked();

    void on_customersBtn_clicked();

    void on_infoButton_clicked();

private:
    Ui::EmployeeDialog *ui;
};

#endif // EMPLOYEE_DIALOG_H
