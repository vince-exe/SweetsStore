#include "employeewindow.h"
#include "ui_employeewindow.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

#include "database.h"
#include "about_me_dialog.h"

/* UI widgets stylesheet */
const QString infoBtnStyleSheet = "text-align: center; background: '#661035'; border: 3px solid '#bfbfbf'; color: '#ebebeb';";
const QString dateLabelStylesheet = "color: '#ebebeb'; background: '#75103c';  color: '#e8e8e8'; border: 4px solid '#1a1818';";
const QString windowBtnsStylesheet = "background: '#75103c'; color: '#e8e8e8'; border: 4px solid '#1a1818';";

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

    QPalette backgroundPalette;
    backgroundPalette.setColor(QPalette::Window, "#661035");

    this->setAutoFillBackground(true);
    this->setPalette(backgroundPalette);

    /* info label */
    ui->infoLabel->setStyleSheet("color: '#ebebeb';");
    ui->infoLabel->setText("Welcome:   " + QString::fromUtf8(currentEmployee.getFirstName()));
    /* title label */
    ui->titleLabel->setStyleSheet("color: '#ebebeb';");
    /*info button */
    ui->infoButton->setStyleSheet(infoBtnStyleSheet);
    /* set the time label */
    ui->dateLabel->setStyleSheet(dateLabelStylesheet);
    ui->dateLabel->setText("Current Date:  " + QString::fromUtf8(currentDateTime().c_str()));

    /* set the stylesheet to the product buttons */
    ui->addProdBtn->setStyleSheet(windowBtnsStylesheet);
    ui->rmProdBtn->setStyleSheet(windowBtnsStylesheet);
    ui->srcProdBtn->setStyleSheet(windowBtnsStylesheet);
    ui->modProdBtn->setStyleSheet(windowBtnsStylesheet);
    /* set the stylesheet to the customer buttons */
    ui->addCstmrBtn->setStyleSheet(windowBtnsStylesheet);
    ui->rmvCstmrBtn->setStyleSheet(windowBtnsStylesheet);
    ui->srcCstmrBtn->setStyleSheet(windowBtnsStylesheet);
    ui->modCstmrBtn->setStyleSheet(windowBtnsStylesheet);
    /* set the stylesheet to the employee buttons */
    ui->addEmplyBtn->setStyleSheet(windowBtnsStylesheet);
    ui->rmEmplyBtn->setStyleSheet(windowBtnsStylesheet);
    ui->modEmplyBtn->setStyleSheet(windowBtnsStylesheet);
    ui->srchEmplyBtn->setStyleSheet(windowBtnsStylesheet);
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

void EmployeeWindow::on_infoButton_pressed() {
    /* change the background */
    ui->infoButton->setStyleSheet("text-align: center; background: '#8a1546'; border: 3px solid '#bfbfbf'; color: '#ebebeb';");
}


void EmployeeWindow::on_infoButton_released() {
    /* reset the background */
    ui->infoButton->setStyleSheet(infoBtnStyleSheet);
}

/* Add Product Button */
void EmployeeWindow::on_addProdBtn_clicked() {

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

