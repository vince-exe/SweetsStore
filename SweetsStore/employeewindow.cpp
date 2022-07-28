#include "employeewindow.h"
#include "ui_employeewindow.h"
#include "add_product_dialog.h"

#include <QMessageBox>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

#include "utilities.h"
#include "product.h"
/* forms */
#include "about_me_dialog.h"
#include "view_products_dialog.h"

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

    /* try to open the products file ( reading mode ) */
    FILE* file = fopen("files/products.txt", "r");
    /* check if the fail opened correctly */
    if(!file) {
        QMessageBox messageBox;
        messageBox.critical(0, "Fatal Error", "The application failed to open the system files");
        messageBox.setFixedSize(550,300);

        exit(-1);
    }
    /* restore the cursor of the file at the start */
    fseek(file, 0, SEEK_SET);
    /* read the informations from the product file and store it in the map */
    readProductsInformations(file, &productsDatabase);
    /* close the file */
    fclose(file);
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

/* View Products Button */
void EmployeeWindow::on_srcProdBtn_clicked() {
    ViewProductsDialog viewProductsWindow;
    viewProductsWindow.setModal(true);
    viewProductsWindow.exec();
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

/* View Employees Button */
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

/* View Customers Button */
void EmployeeWindow::on_srcCstmrBtn_clicked() {

}

/* Modify Customer Button */
void EmployeeWindow::on_modCstmrBtn_clicked() {

}

/* save all the informations */
void EmployeeWindow::on_addProdBtn_2_clicked() {
    /* check if there aren't new changes to save */
    if(!newChanges) {
        QMessageBox messageBox;
        messageBox.warning(0, "No Changes", "There aren't new changes to save");
        messageBox.setFixedSize(550, 300);
        return;
    }

    /* open the file in reading mode to check if exist */
    FILE* file = fopen("files/products.txt", "r");

    if(!file) {
        QMessageBox messageBox;
        messageBox.critical(0, "Fatal Error", "The application failed to save the changes");
        messageBox.setFixedSize(550,300);

        exit(-1);
    }
    fclose(file);

    /* open it in write mode */
    file = fopen("files/products.txt", "w");
    /* store the informations in the file */
    storeProductInformations(file, &productsDatabase);
    /* close the product file */
    fclose(file);

    QMessageBox messageBox;
    messageBox.setText(tr("The application has successfully save the changes"));

    QAbstractButton* exitButton = messageBox.addButton(tr("Exit"), QMessageBox::YesRole);
    QAbstractButton* continueButton = messageBox.addButton(tr("Continue"), QMessageBox::NoRole);

    messageBox.exec();

    if(messageBox.clickedButton() == exitButton) { exit(0); }

    if(messageBox.clickedButton() == continueButton) {
        newChanges = false;
        return;
    }
}
