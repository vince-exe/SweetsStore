#ifndef EMPLOYEE_WINDOW_H
#define EMPLOYEE_WINDOW_H

#include <QMainWindow>

namespace Ui {
class EmployeeWindow;
}

class EmployeeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeWindow(QWidget *parent = nullptr);
    ~EmployeeWindow();

private:
    Ui::EmployeeWindow *ui;
};

#endif // EMPLOYEE_WINDOW_H
