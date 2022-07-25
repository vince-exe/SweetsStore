#include "employeewindow.h"
#include "ui_employeewindow.h"
#include "add_product_dialog.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

#include "database.h"
#include "about_me_dialog.h"

/* function to get the current time */
const std::string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    return buf;
}

EmployeeWindow::EmployeeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmployeeWindow) {

    ui->setupUi(this);

    this->setGeometry(100, 50, 1300, 730);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* info label */
    ui->infoLabel->setText("Welcome:   " + QString::fromUtf8(currentEmployee.getFirstName()));
    /* set the time label */
    ui->dateLabel->setText("Current Date:  " + QString::fromUtf8(currentDateTime().c_str()));
}

EmployeeWindow::~EmployeeWindow()
{
    delete ui;
}

/* About Me button clicked */
void EmployeeWindow::on_infoButton_clicked() {
    AboutMeDialog newDialog;
    newDialog.setModal(true);
    newDialog.exec();
}

/* Add Product Button */
void EmployeeWindow::on_addProdBtn_clicked() {
    AddProductDialog addProdWindow;

    addProdWindow.setModal(true);
    addProdWindow.exec();
}

/* Remove Product Button */
void EmployeeWindow::on_rmProdBtn_clicked() {

}

/* Search Product Button */
void EmployeeWindow::on_srcProdBtn_clicked() {

}

/* Modify Product Button */
void EmployeeWindow::on_modProdBtn_clicked() {

}

/* Add Employee Button */
void EmployeeWindow::on_addEmplyBtn_clicked() {

}

/* Remove Employee Button */
void EmployeeWindow::on_rmEmplyBtn_clicked() {

}

/* Search Employee Button */
void EmployeeWindow::on_srchEmplyBtn_clicked() {
}

/* Modify Employee Button */
void EmployeeWindow::on_modEmplyBtn_clicked() {

}

/* Add Customer Button */
void EmployeeWindow::on_addCstmrBtn_clicked() {

}

/* Remove Customer Button */
void EmployeeWindow::on_rmvCstmrBtn_clicked() {
}

/* Search Customer Button */
void EmployeeWindow::on_srcCstmrBtn_clicked() {

}

/* Modify Customer Button */
void EmployeeWindow::on_modCstmrBtn_clicked() {

}

