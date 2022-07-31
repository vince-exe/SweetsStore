#include "add_product_dialog.h"
#include "ui_add_product_dialog.h"

#include <QMessageBox>

#include <iostream>
#include <string>

#include "utilities.h"
#include "product.h"
#include "product_utilities.h"

AddProductDialog::AddProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProductDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 580, 615);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* set the current date */
    ui->dateWidget->setDate(QDate::currentDate());
    ui->dateWidget->setAlignment(Qt::AlignCenter);
    /* modify the input boxes */
    ui->prodNameBox->setAlignment(Qt::AlignCenter);
    ui->brandBox->setAlignment(Qt::AlignCenter);
    ui->priceBox->setAlignment(Qt::AlignCenter);
}

AddProductDialog::~AddProductDialog() {
    delete ui;
}

/* check if the user is passing the limit of characters for the prod name */
void AddProductDialog::on_prodNameBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > prodNameLen) { ui->prodNameBox->backspace(); }
}

/* check if the user is passing the limit of characters for the brand name */
void AddProductDialog::on_brandBox_textChanged(const QString &arg1) {
 if(arg1.toStdString().length() > brandLen) { ui->brandBox->backspace(); }
}

/* check if the user is passing the limit of characters for the price */
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

    /* if already exist */
    if(productsDatabase.find(product.getName()) != productsDatabase.end()) {
        QMessageBox messageBox;
        QString warningMessage = "There is already a product named [ " + QString::fromStdString(product.getName().c_str()) + " ]";
        messageBox.warning(0, "Fail", warningMessage);
        messageBox.setFixedSize(550,300);

        clearInputFields(ui->prodNameBox, ui->brandBox, ui->priceBox, ui->qntyBox, ui->dateWidget);
        return;
    }

    /* check if he wants to save the chages or exit without saving */
    QMessageBox confirmBox;
    confirmBox.setText(tr("The application will proceed with saving the product, are you sure you want to continue?"));
    confirmBox.addButton(tr("Yes"), QMessageBox::YesRole);
    QAbstractButton* noBtn = confirmBox.addButton(tr("No"), QMessageBox::YesRole);
    /* show the message box */
    confirmBox.exec();
    /* if the user doesn't want to save the product, close */
    if(confirmBox.clickedButton() == noBtn) { this->close(); return; }

    /* insert the product inside the map */
    productsDatabase.insert(std::pair<std::string, Product>(product.getName(), product));
    /* set the new changes variable to true */
    newChanges = true;

    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully added the product");
    messageBox.setFixedSize(550,300);

    /* clear the inputs */
    clearInputFields(ui->prodNameBox, ui->priceBox, ui->brandBox, ui->qntyBox, ui->dateWidget);
}
