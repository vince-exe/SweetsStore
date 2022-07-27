#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <map>
#include <QMessageBox>

#include "employee.h"
#include "employeewindow.h"
#include "utilities.h"

const int MaxEmailBoxLen = 30;
const int MaxPassBoxLen = 16;

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

bool checkEmail(std::string email) {
    const std::string check = "@gmail.com";

    if(!email.length() or email.length() <= check.length()) { return false; }

    size_t start = email.find("@");
    if(start == email.npos) { return false; }

    if(email.compare(start, check.length(), check) != 0) { return false; };

    return true;
}

bool checkPassowrd(std::string password) {
    if(!password.length() or password.length() < 8) { return false; }

    return true;
}

bool checkCredentials(std::string email, std::string password) {
    if(!checkEmail(email) or !checkPassowrd(password)) { return false; }

    return true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setGeometry(50, 50, 1280, 720);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* Email Box */
    ui->emailTextBox->setAlignment(Qt::AlignCenter);
    /* Pass Box */
    ui->passTextBox->setAlignment(Qt::AlignCenter);

    /* open the employee file in reading mode */
    FILE* file = fopen("files/employees.txt", "r");

    /* check if the software failed to load the employees file */
    if(!file) {
        /* create a message box */
        QMessageBox messageBox;
        messageBox.critical(0,"Fatal Error","The software failed to load the application files :/");
        messageBox.setFixedSize(550,300);
        exit(-1);
    }

    /* store the informations in the map */
    readEmployeesInformations(file, &employeeDatabase);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* SignInButton clicked */
void MainWindow::on_signInButton_clicked() {
    /* save the email and the password from the text boxes */
    std::string email = lowerStr(ui->emailTextBox->toPlainText().toStdString());
    std::string password = ui->passTextBox->toPlainText().toStdString();

    /* clear the text boxes */
    ui->emailTextBox->clear();
    ui->passTextBox->clear();
    /* Email Box */
    ui->emailTextBox->setAlignment(Qt::AlignCenter);
    /* Pass Box */
    ui->passTextBox->setAlignment(Qt::AlignCenter);

    /* check if the given credentials are valid */
    if(!checkCredentials(email, password)) {
        QMessageBox messageBox;
        messageBox.critical(0,"Login Error", "Invalid email or password");
        messageBox.setFixedSize(550,300);
        return;
    }

    /* Successfully logged in as employee*/
    if(checkSignInEmployee(email, password, &employeeDatabase)) {
        /* open the employee window */
        this->employeeWindow = new EmployeeWindow(this);

        this->hide();
        this->employeeWindow->show();
    }

    /* failed to login */
    else {
        QMessageBox messageBox;
        messageBox.critical(0,"Login Error","Email or password wrong");
        messageBox.setFixedSize(550,300);

        /* clear the text boxes */
        ui->emailTextBox->clear();
        ui->passTextBox->clear();
        /* Email Box */
        ui->emailTextBox->setAlignment(Qt::AlignCenter);
        /* Pass Box */
        ui->passTextBox->setAlignment(Qt::AlignCenter);
        return;
    }
}

void MainWindow::on_emailTextBox_textChanged() {
    /* limit the amount of characters in the email text box */
    if(ui->emailTextBox->toPlainText().length() > MaxEmailBoxLen) {
        ui->emailTextBox->textCursor().deletePreviousChar();
       }
}

void MainWindow::on_passTextBox_textChanged() {
    /* limit the amount of characters in the pass text box */
    if(ui->passTextBox->toPlainText().length() > MaxPassBoxLen) {
        ui->passTextBox->textCursor().deletePreviousChar();
    }
}

