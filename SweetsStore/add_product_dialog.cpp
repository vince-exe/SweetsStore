#include "add_product_dialog.h"
#include "ui_add_product_dialog.h"

#include <QMessageBox>

#include <iostream>
#include <string>

#include "utilities.h"
#include "product.h"

const int prodNameLen = 30;
const int brandLen = 20;
const int PriceLen = 4;

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
    /* create the product object */
    Product product;

    /* set the name */
    product.setName(lowerStr(ui->prodNameBox->text().toStdString()));
    /* set the expire date */
    product.setExpiry(lowerStr(ui->dateWidget->text().toStdString()));
    /* set the brand */
    product.setBrand(lowerStr(ui->brandBox->text().toStdString()));
    try {
        /* set the price */
        product.setPrice(std::stof(ui->priceBox->text().toStdString()));
    }
    catch(std::invalid_argument) {
        QMessageBox messageBox;
        messageBox.critical(0, "Price Error", "The price has to be a number");
        messageBox.setFixedSize(550,300);
        /* clear the input fields */
        clearInputFields(ui->prodNameBox, ui->brandBox, ui->priceBox, ui->qntyBox, ui->dateWidget);
        return;
    }

    /* set the quantity */
    product.setQuantity(std::stoi(ui->qntyBox->text().toStdString()));

    /* check if the product already exist */
    auto it = productsDatabase.find(product.getName());

    /* doesn't exist */
    if(it == productsDatabase.end()) {
        /* insert the product inside the map */
        productsDatabase.insert(std::pair<std::string, Product>(product.getName(), product));
        newChanges = true;

        QMessageBox messageBox;
        messageBox.information(0, "Success", "Successfully added the product");
        messageBox.setFixedSize(550,300);
    }
    /* exist */
    else {
        QMessageBox messageBox;
        QString warningMessage = "There is already a product named [ " + QString::fromStdString(product.getName().c_str()) + " ]";
        messageBox.warning(0, "Fail", warningMessage);
        messageBox.setFixedSize(550,300);
    }

    /* clear the inputs */
    clearInputFields(ui->prodNameBox, ui->priceBox, ui->brandBox, ui->qntyBox, ui->dateWidget);
}
