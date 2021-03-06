#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#include <QMainWindow>

#include "about_me_dialog.h"

namespace Ui {
class EmployeeWindow;
}

class EmployeeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeWindow(QWidget *parent = nullptr);
    ~EmployeeWindow();

private slots:
    void on_infoButton_clicked();

    void on_prodMenuBtn_clicked();

    void on_emplyMenuBtn_clicked();

private:
    Ui::EmployeeWindow *ui;
    AboutMeDialog* aboutMeWindow;
};

#endif // EMPLOYEEWINDOW_H
