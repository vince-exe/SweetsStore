#include "employee_dialog.h"
#include "ui_employee_dialog.h"

/* forms */
#include "about_me_dialog.h"
#include "view_products_dialog.h"
#include "view_employees_dialog.h"
#include "view_customer_dialog.h"

EmployeeDialog::EmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 50, 590, 640);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
}

EmployeeDialog::~EmployeeDialog() {
    delete ui;
}

/* button to open the product menu */
void EmployeeDialog::on_prodMenuBtn_clicked() {
    ViewProductsDialog viewProductsWindow;
    viewProductsWindow.setModal(true);
    viewProductsWindow.exec();
}

/* button to open the employee menu */
void EmployeeDialog::on_emplyMenuBtn_clicked() {
    ViewEmployeesDialog viewEmployeeWindow;
    viewEmployeeWindow.setModal(true);
    viewEmployeeWindow.exec();
}

/* button to open the customer menu */
void EmployeeDialog::on_customersBtn_clicked() {
    ViewCustomerDialog viewCustomerWindow;
    viewCustomerWindow.setModal(true);
    viewCustomerWindow.exec();
}

/* button to open the info menu */
void EmployeeDialog::on_infoButton_clicked() {
    AboutMeDialog newDialog;
    newDialog.setModal(true);
    newDialog.exec();
}

