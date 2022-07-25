#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <map>
#include <QMessageBox>

#include "mainWindowUtilities.h"
#include "employee.h"
#include "employeewindow.h"
#include "database.h"

/* UI widgets stylesheet */
const QString emailBoxStylesheet = "border: 3px solid '#000000'; text-align: center; border-radius:10px; padding-top: 5px; background: '#661035'; color: '#c9c7c7'";
const QString passBoxStylesheet = "border: 3px solid '#000000'; text-align: center; border-radius:10px; padding-top: 5px; background: '#661035'; color: '#c9c7c7'";
const QString signInBtnStylesheet = "background: '#661035'; color: '#ebebeb'; border: 4px solid '#000000'; border-radius: 10px;";
const QString signUpBtnStylesheet = "background: '#661035'; color: '#ebebeb'; border: 4px solid '#000000'; border-radius: 10px;";

const int MaxEmailBoxLen = 30;
const int MaxPassBoxLen = 16;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setGeometry(50, 50, 1280, 720);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* palette for background */
    QPalette backgroundPalette;
    backgroundPalette.setColor(QPalette::Window, "#661035");

    this->setAutoFillBackground(true);
    this->setPalette(backgroundPalette);

    ui->titleLabel->setText("<font color='#ebebeb'>Sweets Store</font>");
    ui->copyrightLabel->setText("<font color='#dbdbdb'> Copyright © 2022 vince-exe. All rights reserved");

    ui->emailTextBox->setAlignment(Qt::AlignCenter);
    ui->emailTextBox->setAutoFillBackground(true);
    ui->emailTextBox->setPalette(backgroundPalette);
    ui->emailTextBox->setTextColor("#ebebeb");
    ui->emailTextBox->setStyleSheet(emailBoxStylesheet);
    ui->emailTextBox->setPlaceholderText("    youremai@gmail.com");

    ui->passTextBox->setAlignment(Qt::AlignCenter);
    ui->passTextBox->setAutoFillBackground(true);
    ui->passTextBox->setPalette(backgroundPalette);
    ui->passTextBox->setTextColor("#ebebeb");
    ui->passTextBox->setStyleSheet(passBoxStylesheet);
    ui->passTextBox->setPlaceholderText("         *********");
    QFont font;

    qDebug() << "App path : " << qApp->applicationDirPath();

    /* editing the citation label */
    ui->citationLabel->setText("<font color='#ebebeb'>\" Everything is better with a donut in your mouth \"</font>");
    /* editing the signInButton */
    ui->signInButton->setStyleSheet(signInBtnStylesheet);
    /* editing the SignUpButton */
    ui->signUpButton->setStyleSheet(signUpBtnStylesheet);

    /* check if the software failed to load the employees file */
    if(!loadEmployeesFile("files/employees.txt", &employeeDatabase)) {
        /* create a message box */
        QMessageBox messageBox;
        messageBox.critical(0,"Fatal Error","The software failed to load the application files :/");
        messageBox.setFixedSize(550,300);
        exit(-1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* SignInButton clicked */
void MainWindow::on_signInButton_clicked() {
    /* save the email and the password from the text boxes */
    std::string email = ui->emailTextBox->toPlainText().toStdString();
    std::string password = ui->passTextBox->toPlainText().toStdString();

    /* check if the given credentials are valid */
    if(!checkCredentials(email, password)) {
        QMessageBox messageBox;
        messageBox.critical(0,"Login Error", "Invalid email or password");
        messageBox.setFixedSize(550,300);

        /* clear the text boxes */
        ui->emailTextBox->clear();
        ui->passTextBox->clear();
        ui->emailTextBox->setStyleSheet(emailBoxStylesheet);
        ui->passTextBox->setStyleSheet(passBoxStylesheet);
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
        return;
    }
}


void MainWindow::on_signInButton_pressed() {
    /* change the color of the background */
    ui->signInButton->setStyleSheet("background: '#8a1546'; text-align: center; color: '#ebebeb'; border: 4px solid '#000000'; border-radius: 10px;");
}


void MainWindow::on_signInButton_released() {
    /* reset the stylesheet */
    ui->signInButton->setStyleSheet(signInBtnStylesheet);
}


void MainWindow::on_signUpButton_pressed() {
    /* change the background color */
    ui->signUpButton->setStyleSheet("background: '#8a1546'; text-align: center; color: '#ebebeb'; border: 4px solid '#000000'; border-radius: 10px;");
}


void MainWindow::on_signUpButton_released() {
    /* reset the stylesheet */
    ui->signUpButton->setStyleSheet(signUpBtnStylesheet);
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

