#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "employeewindow.h"

#include "employee.h"

/* load the employees file */
bool loadEmployeesFile(const char *filePath, std::map<std::string, Employee>* employeeDatabase);

/* check the credentials for the SignIn */
bool checkSignInEmployee(std::string email, std::string password, std::map<std::string, Employee>* employeeDatabase);

/* check the password */
bool checkPassowrd(std::string password);

/* check the credentials */
bool checkCredentials(std::string email, std::string password);

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

    void on_emailTextBox_textChanged();

    void on_passTextBox_textChanged();

private:
    Ui::MainWindow *ui;
    EmployeeWindow* employeeWindow;
};

#endif // MAINWINDOW_H
