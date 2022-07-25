#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "employeewindow.h"

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

    void on_signInButton_pressed();

    void on_signInButton_released();

    void on_signUpButton_pressed();

    void on_signUpButton_released();

    void on_emailTextBox_textChanged();

    void on_passTextBox_textChanged();

private:
    Ui::MainWindow *ui;
    EmployeeWindow* employeeWindow;
};

#endif // MAINWINDOW_H
