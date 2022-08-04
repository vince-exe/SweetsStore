#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <map>

#include <QPixmap>
#include <QMessageBox>

#include "employee.h"
#include "employeewindow.h"

#include "utilities.h"
#include "employee_utilities.h"
#include "main_window_utilities.h"

/* forms */
#include "sign_up_dialog.h"

bool checkSignInEmployee(std::string email, std::string password, std::map<std::string, Employee>* employeeDatabase) {
    /* get the key */
    auto key = employeeDatabase->find(email);
    /* if the key doesn't exist */
    if(key == employeeDatabase->end()) { return false; }

    /* check if the password is correct */
    if(key->second.getPassword() == password) {
        /* fill the current employee variable */
        currentEmployee = key->second;

        return true;
    }

    return false;
}

bool checkSignInCustomer(std::string email, std::string password, std::map<std::string, Customer>* customerDatabase) {
    /* get the key */
    auto key = customerDatabase->find(email);
    /* if the key doesn't exist */
    if(key == customerDatabase->end()) { return false; }

    /* check if the password is correct */
    if(key->second.getPassword() == password) {
        /* fill the current employee variable */
        currentCustomer = key->second;
        return true;
    }

    return false;
}

bool openStoreEmployeeFile(const char *pathFile) {
    /* try to open the employees file ( reading mode ) */
    FILE* file = fopen(pathFile, "r");
    /* check if the fail opened correctly */
    if(!file) { return false;  }

    /* restore the cursor of the file at the start */
    fseek(file, 0, SEEK_SET);
    /* read the informations from the product file and store it in the map */
    readEmployeesInformations(file, &employeeDatabase);
    /* close the file */
    fclose(file);

    return true;
}

bool openStoreProductsFile(const char *pathFile) {
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
bool openStoreCustomerFile(const char* pathFile) {
    FILE* f = fopen(pathFile, "r");
    if(!f) { return false; }

    fseek(f, 0, SEEK_SET);
    readCustomersInformations(f, &customersDatabase);
    fclose(f);

    return true;
}

bool openStoreOrderFile(const char *pathFile) {
    FILE* f = fopen(pathFile, "r");
    if(!f) { return false; }

    fseek(f, 0, SEEK_SET);
    readOrdersInformations(f, &ordersDatabase);
    fclose(f);

    return true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setGeometry(50, 50, 519, 514);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* Email Box */
    ui->emailBox->setAlignment(Qt::AlignCenter);
    /* Pass Box */
    ui->passBox->setAlignment(Qt::AlignCenter);
    /* align the citation label to the center */
    ui->citationLabel->setAlignment(Qt::AlignCenter);
    /* align the title label to the center */
    ui->titleLabel->setAlignment(Qt::AlignCenter);

    /* try to open all the system files */
    if(!openStoreEmployeeFile("files/employees.txt") || !openStoreCustomerFile("files/customers.txt") || !openStoreProductsFile("files/products.txt") || !openStoreOrderFile("files/orders.txt")) {
        QMessageBox messageBox;
        messageBox.critical(0, "Fatal Error", "The application failed to open the system files");
        messageBox.setFixedSize(550,300);
        exit(-1);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

/* SignInButton clicked */
void MainWindow::on_signInButton_clicked() {
    /* save the email and the password from the text boxes */
    std::string email = lowerStr(ui->emailBox->text().toStdString());
    std::string password = ui->passBox->text().toStdString();

    /* clear the text boxes */
    ui->emailBox->clear();
    ui->passBox->clear();

    /* check if the given credentials are valid */
    if(!checkCredentials(email, password)) {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Credentials", "Email must be '@gmail.com', password must be at least 8 characters long.");
        messageBox.setFixedSize(550,300);
        return;
    }

    /* Successfully logged in as employee*/
    if(checkSignInEmployee(email, password, &employeeDatabase)) {
        loggedInAsCustomer = false;
        /* open the employee window */
        this->employeeWindow = new EmployeeWindow(this);
        this->hide();
        this->employeeWindow->show();
    }

    /* check if he is a customer */
    else if(checkSignInCustomer(email, password, &customersDatabase)) {
        loggedInAsCustomer = true;
        /* open the customer window */
        this->customerWindow = new CustomerMenuDialog(this);
        this->hide();
        this->customerWindow->show();
    }

    /* failed to login */
    else {
        QMessageBox messageBox;
        messageBox.critical(0,"Login Error","Email or password wrong");
        messageBox.setFixedSize(550,300);

        ui->emailBox->clear();
        ui->passBox->clear();
        return;
    }
}

/* Sign Up button clicked */
void MainWindow::on_signUpButton_clicked() {
    SignUpDialog signUpWindow;
    signUpWindow.setModal(true);
    signUpWindow.show();
    signUpWindow.exec();
}

/* make sure that the lenght of the email is lower then the max email len */
void MainWindow::on_emailBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxEmailLen) { ui->emailBox->backspace(); }
}

/* make sure that the lenght of the password is lower then the max pass len */
void MainWindow::on_passBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxPassLen) { ui->passBox->backspace(); }
}
