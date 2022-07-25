#include "add_product_dialog.h"
#include "ui_add_product_dialog.h"

#include <QMessageBox>

#include <iostream>
#include <fstream>
#include <string>

const int prodNameLen = 30;
const int brandLen = 20;
const int PriceLen = 4;

const char* prodFilePath = "files/products.txt";

/* function to add a product */
bool addProduct(const char* filePath, std::string& tmpBuffer) {
    /* open the file in reading mode (to check if exist )*/
    std::fstream checkFile(filePath, std::fstream::in);
    /* check if the file exist */
    if(!checkFile) { return false; }

    checkFile.close();

    std::fstream file(filePath, std::fstream::app);
    if(!file) { return false; }

    /* write in the file */
    file << tmpBuffer;
    /* close the file */
    file.close();

    return true;
}

std::string lowerStr(std::string& string) {
    std::for_each(string.begin(), string.end(), [](char & c) {
        c = ::tolower(c);
    });

    return string;
}


bool checkEmptiesBox(QLineEdit *firstInput, QLineEdit *secondInput, QLineEdit *thirdInput, QSpinBox *spinBox) {
    if(!firstInput->text().length() or !secondInput->text().length() or !thirdInput->text().length()) {
        return false;
    }

    if(spinBox->text().toStdString() == "0") { return false; }

    return true;
}

bool checkDate(QDateEdit *dateEdit) {
    int dayEdit, monthEdit, yearEdit;
    /* save the informations in the variables */
    dateEdit->date().getDate(&yearEdit, &monthEdit, &dayEdit);

    int currDay, currMonth, currYear;
    QDate::currentDate().getDate(&currYear, &currMonth, &currDay);

    /* simple case (year) */
    if(yearEdit < currYear) { return false; }

    if(yearEdit == currYear) {
        if(monthEdit < currMonth ) { return false; }

        else if(monthEdit > currMonth) { return true; }

        if(dayEdit <= currDay) { return false; }
    }

    return true;
}

void clearInputFields(QLineEdit *f1, QLineEdit *f2, QLineEdit *f3, QSpinBox *f4, QDateEdit *f5) {
    /* clear the widgets */
    f1->clear();
    f2->clear();
    f3->clear();
    f4->clear();

    f5->setDate(QDate::currentDate());
}

AddProductDialog::AddProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProductDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 580, 615);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* set the current date */
    ui->dateWidget->setDate(QDate::currentDate());
}

AddProductDialog::~AddProductDialog() {
    delete ui;
}

void AddProductDialog::on_prodNameBox_textChanged(const QString &arg1) {
    /* check if the user is passing the limit of characters */
    if(arg1.toStdString().length() > prodNameLen) { ui->prodNameBox->backspace(); }
}

void AddProductDialog::on_brandBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > brandLen) { ui->brandBox->backspace(); }
}

void AddProductDialog::on_priceBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > PriceLen) { ui->priceBox->backspace(); }
}

/* save the product */
void AddProductDialog::on_saveButton_clicked() {
    /* check if the input fields are empty */
    if(!checkEmptiesBox(ui->prodNameBox, ui->brandBox, ui->priceBox, ui->qntyBox)) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Input box can't be empty");
        messageBox.setFixedSize(550,300);
        return;
    }
    /* check if the expire date is valid */
    if(!checkDate(ui->dateWidget)) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Enter a valid expire date");
        messageBox.setFixedSize(550,300);
        return;
    }
    /* create the temp buffer to store informations */
    std::string tmpBuffer;

    /* append the informations */
    tmpBuffer.append(ui->prodNameBox->text().toStdString() + "\n");
    tmpBuffer.append(ui->dateWidget->text().toStdString() + "\n");
    tmpBuffer.append(ui->brandBox->text().toStdString() + "\n");
    tmpBuffer.append(ui->priceBox->text().toStdString() + "\n");
    tmpBuffer.append(ui->qntyBox->text().toStdString() + "\n");

    /* failed to add the product */
    if(!addProduct(prodFilePath, tmpBuffer)) {
        QMessageBox messageBox;
        messageBox.critical(0,"Product Error", "The application failed to add the new product");
        messageBox.setFixedSize(550,300);

        /* clear the widgets content */
        clearInputFields(ui->prodNameBox, ui->brandBox, ui->priceBox, ui->qntyBox, ui->dateWidget);
        return;
    }
    /* successfully added the product */
    else {
        QMessageBox messageBox;
        messageBox.information(0, "Product Added", "Product added successfully");
        messageBox.setFixedSize(550, 300);

        /* clear the widgets content */
        clearInputFields(ui->prodNameBox, ui->brandBox, ui->priceBox, ui->qntyBox, ui->dateWidget);
        return;
    }
}
