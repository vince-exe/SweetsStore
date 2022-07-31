#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <map>

#include <QPixmap>
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

bool checkPassowrd(std::string password) {
    if(!password.length() or password.length() < 8) { return false; }

    return true;
}

bool checkCredentials(std::string email, std::string password) {
    if(!checkEmail(email, "@gmail.com") or !checkPassowrd(password)) { return false; }

    return true;
}

bool openEmployeeFile(const char *pathFile) {
    /* try to open the employees file ( reading mode ) */
    FILE* file = fopen(pathFile, "r");
    /* check if the fail opened correctly */
    if(!file) {
        QMessageBox messageBox;
        messageBox.critical(0, "Fatal Error", "The application failed to open the system files");
        messageBox.setFixedSize(550,300);

        return false;
    }
    /* restore the cursor of the file at the start */
    fseek(file, 0, SEEK_SET);
    /* read the informations from the product file and store it in the map */
    readEmployeesInformations(file, &employeeDatabase);
    /* close the file */
    fclose(file);

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
    /* declare the pixmap pointers */
    QPixmap* pixmap = new QPixmap("images/donut.png");
    QPixmap* p2 = new QPixmap("images/donut2.png");
    QPixmap* p3 = new QPixmap("images/donut3.png");
    QPixmap* p4 = new QPixmap("images/donut4.png");
    /* set the label1 image */
    ui->imageLabel->setPixmap(*pixmap);
    ui->imageLabel->setScaledContents(true);
    ui->imageLabel->show();
    /* set the label2 image */
    ui->imageLabel_2->setPixmap(*p2);
    ui->imageLabel_2->setScaledContents(true);
    ui->imageLabel_2->show();
    /* set the label3 image */
    ui->imageLabel_3->setPixmap(*p3);
    ui->imageLabel_3->setScaledContents(true);
    ui->imageLabel_3->show();
    /* set the label4 image */
    ui->imageLabel_4->setPixmap(*p4);
    ui->imageLabel_4->setScaledContents(true);
    ui->imageLabel_4->show();

    if(!openEmployeeFile("files/employees.txt")) { exit(-1); }
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

