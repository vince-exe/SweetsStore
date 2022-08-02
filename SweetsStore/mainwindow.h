#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "employeewindow.h"
#include "customer_menu_dialog.h"

#include "employee.h"
#include "customer.h"

/* check the credentials for the SignIn ( employee ) */
bool checkSignInEmployee(std::string email, std::string password, std::map<std::string, Employee>* employeeDatabase);

/* check the credentials for the SignIn ( customer ) */
bool checkSignInCustomer(std::string email, std::string password, std::map<std::string, Customer>* customerDatabase);

/* open the employees file and store the information inside the employee database */
bool openStoreEmployeeFile(const char *pathFile);

/* open the customers file and store the information inside the customers database */
bool openStoreCustomerFile(const char* pathFile);

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_signInButton_clicked();

    void on_signUpButton_clicked();

    void on_emailBox_textChanged(const QString &arg1);

    void on_passBox_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    EmployeeWindow* employeeWindow;
    CustomerMenuDialog* customerWindow;
};

#endif // MAINWINDOW_H
