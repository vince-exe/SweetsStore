#ifndef ADD_EMPLOYEE_DIALOG_H
#define ADD_EMPLOYEE_DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>

/* check if the boxes are empties */
bool checkEmptyBoxes2(QLineEdit* f1, QLineEdit* f2, QLineEdit* f3, QLineEdit* f4, QLineEdit* f5, QSpinBox* s1);

/* clear the given boxes */
void clearBoxesEmployee(QLineEdit* f1, QLineEdit* f2, QLineEdit* f3, QLineEdit* f4, QLineEdit* f5, QSpinBox* s1, QCheckBox* c1, QCheckBox* c2);

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

    void on_saveBtn_clicked();

    void on_femaleBox_clicked();

    void on_maleBox_clicked();

private:
    Ui::AddEmployeeDialog *ui;
};

#endif // ADD_EMPLOYEE_DIALOG_H
