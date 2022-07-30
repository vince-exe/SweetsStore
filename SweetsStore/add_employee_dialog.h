#ifndef ADD_EMPLOYEE_DIALOG_H
#define ADD_EMPLOYEE_DIALOG_H

#include <QDialog>

namespace Ui {
class AddEmployeeDialog;
}

class AddEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployeeDialog(QWidget *parent = nullptr);
    ~AddEmployeeDialog();

private slots:
    void on_firstNameBox_textChanged(const QString &arg1);

    void on_lastNameBox_textChanged(const QString &arg1);

    void on_emailBox_textChanged(const QString &arg1);

    void on_passBox_textChanged(const QString &arg1);

    void on_salaryBox_textChanged(const QString &arg1);

private:
    Ui::AddEmployeeDialog *ui;
};

#endif // ADD_EMPLOYEE_DIALOG_H
