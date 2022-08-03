#include "employeewindow.h"
#include "ui_employeewindow.h"

#include <QMessageBox>

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

/* forms */
#include "about_me_dialog.h"
#include "view_products_dialog.h"
#include "view_employees_dialog.h"

EmployeeWindow::EmployeeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmployeeWindow) {

    ui->setupUi(this);

    this->setGeometry(100, 50, 590, 640);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
}

EmployeeWindow::~EmployeeWindow() {
    delete ui;
}

/* About Me button clicked */
void EmployeeWindow::on_infoButton_clicked() {
    AboutMeDialog newDialog;
    newDialog.setModal(true);
    newDialog.exec();
}

/* Open the products Menu */
void EmployeeWindow::on_prodMenuBtn_clicked() {
    ViewProductsDialog viewProductsWindow;
    viewProductsWindow.setModal(true);
    viewProductsWindow.exec();
}

/* open the employee menu */
void EmployeeWindow::on_emplyMenuBtn_clicked() {
    ViewEmployeesDialog viewEmployeeWindow;
    viewEmployeeWindow.setModal(true);
    viewEmployeeWindow.exec();
}
