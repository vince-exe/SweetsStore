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

EmployeeWindow::EmployeeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmployeeWindow) {

    ui->setupUi(this);

    this->setGeometry(100, 50, 590, 640);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

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

