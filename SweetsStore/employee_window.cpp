#include "employee_window.h"
#include "ui_employee_window.h"

employee_window::employee_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::employee_window)
{
    ui->setupUi(this);
}

employee_window::~employee_window()
{
    delete ui;
}
