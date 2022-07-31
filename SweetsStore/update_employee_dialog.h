#ifndef UPDATE_EMPLOYEE_DIALOG_H
#define UPDATE_EMPLOYEE_DIALOG_H

#include <QDialog>

namespace Ui {
class UpdateEmployeeDialog;
}

class UpdateEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateEmployeeDialog(QWidget *parent = nullptr);
    ~UpdateEmployeeDialog();

private:
    Ui::UpdateEmployeeDialog *ui;
};

#endif // UPDATE_EMPLOYEE_DIALOG_H
