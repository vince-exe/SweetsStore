#ifndef UPDATE_EMPLOYEE_DIALOG_H
#define UPDATE_EMPLOYEE_DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>

void resetInformations(QLineEdit* l1, QLineEdit* l2, QLineEdit* l3, QLineEdit* l4, QLineEdit* l5, QSpinBox* s1, QCheckBox* c1, QCheckBox* c2);

namespace Ui {
class UpdateEmployeeDialog;
}

class UpdateEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateEmployeeDialog(QWidget *parent = nullptr);
    ~UpdateEmployeeDialog();

private slots:
    void on_maleBox_clicked();

    void on_femaleBox_clicked();

    void on_lastNameBox_textChanged(const QString &arg1);

    void on_firstNameBox_textChanged(const QString &arg1);

    void on_passBox_textChanged(const QString &arg1);

    void on_emailBox_textChanged(const QString &arg1);

    void on_salaryBox_textChanged(const QString &arg1);

    void on_saveBtn_clicked();

private:
    Ui::UpdateEmployeeDialog *ui;
};

#endif // UPDATE_EMPLOYEE_DIALOG_H
