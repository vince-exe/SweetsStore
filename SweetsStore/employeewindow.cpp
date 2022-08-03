#include "employeewindow.h"
#include "ui_employeewindow.h"

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
#include "view_employees_dialog.h"

/* open the products file */
bool openProductsFile(const char *pathFile) {
    /* try to open the products file ( reading mode ) */
    FILE* file = fopen(pathFile, "r");
    /* check if the fail opened correctly */
    if(!file) { return false; }

    /* restore the cursor of the file at the start */
    fseek(file, 0, SEEK_SET);
    /* read the informations from the product file and store it in the map */
    readProductsInformations(file, &productsDatabase);
    /* close the file */
    fclose(file);

    return true;
}

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
    /* open the products file and store the informations in the proucts map */
    if(!openProductsFile("files/products.txt")) {
        QMessageBox messageBox;
        messageBox.critical(0, "Fatal Error", "The application failed to open the system files");
        messageBox.setFixedSize(550,300);
        return;
    }
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
