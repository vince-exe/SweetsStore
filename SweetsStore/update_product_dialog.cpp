#include "update_product_dialog.h"
#include "ui_update_product_dialog.h"

#include <QMessageBox>
#include <QDateEdit>
#include <QLineEdit>

#include "utilities.h"

/* global variables */
const int prodNameLen = 20;
const int brandLen = 20;
const int PriceLen = 4;

UpdateProductDialog::UpdateProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateProductDialog)
{
    ui->setupUi(this);
    /* set the window */
    this->setGeometry(100, 100, 580, 615);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    /* set the current date */
    ui->dateWidget->setDate(QDate::currentDate());
    ui->dateWidget->setAlignment(Qt::AlignCenter);
    /* modify the input boxes */
    ui->prodNameBox->setAlignment(Qt::AlignCenter);
    ui->brandBox->setAlignment(Qt::AlignCenter);
    ui->priceBox->setAlignment(Qt::AlignCenter);
    /* fill the boxes with the informations of the selected product */
    setInputBoxes(ui->prodNameBox, ui->brandBox, ui->priceBox, ui->qntyBox, ui->dateWidget);
}

UpdateProductDialog::~UpdateProductDialog() {
    delete ui;
}

void UpdateProductDialog::on_prodNameBox_textChanged(const QString &arg1) {
    /* check if the user is passing the limit of characters */
    if(arg1.toStdString().length() > prodNameLen) { ui->prodNameBox->backspace(); }
}

void UpdateProductDialog::on_brandBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > brandLen) { ui->brandBox->backspace(); }
}

void UpdateProductDialog::on_priceBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > PriceLen) { ui->priceBox->backspace(); }
}

/* save the changes in the products database ( doesn't store it in the products file ) */
void UpdateProductDialog::on_saveButton_clicked() {
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
    /* create the product */
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

    /* check if he already exist */
    if(productsDatabase.find(product.getName()) != productsDatabase.end()) {
        QMessageBox messageBox;
        QString warningMessage = "There is already a product named [ " + QString::fromStdString(product.getName().c_str()) + " ]";
        messageBox.warning(0, "Warning", warningMessage);
        messageBox.setFixedSize(550,300);

        /* clear the input fields */
        clearInputFields(ui->prodNameBox, ui->brandBox, ui->priceBox, ui->qntyBox, ui->dateWidget);
        return;
    }
    /* check if he wants to save the chages or exit without saving */
    QMessageBox confirmBox;
    confirmBox.setText(tr("The application will proceed with updating the product, are you sure you want to continue?"));
    confirmBox.addButton(tr("Yes"), QMessageBox::YesRole);
    QAbstractButton* noBtn = confirmBox.addButton(tr("No"), QMessageBox::NoRole);
    /* show the message box */
    confirmBox.exec();
    /* if the user doesn't want to save the product, close */
    if(confirmBox.clickedButton() == noBtn) { this->close(); return; }

    /* get the product */
    auto it = productsDatabase.find(selectedProduct.getName());
    /* replace the properties */
    it->second.setName(product.getName());
    it->second.setBrand(product.getBrand());
    it->second.setExpiry(product.getExpiry());
    it->second.setPrice(product.getPrice());
    it->second.setQuantity(product.getQuantity());

    /* extract the node to modify the key */
    auto node = productsDatabase.extract(selectedProduct.getName());
    /* modify the key */
    node.key() = product.getName();
    /* reinsert the node in the map */
    productsDatabase.insert(std::move(node));
    /* reset the vairable */
    selectedProductCheck = false;
    /* create the success message box */
    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully updated the product");
    messageBox.setFixedSize(550, 300);
    /* close the dialog and return */
    this->close();
    newChanges = true;
    return;
}

void setInputBoxes(QLineEdit *f1, QLineEdit *f2, QLineEdit *f3, QSpinBox *f4, QDateEdit *f5) {
    /* set the QLineEdit boxes */
    f1->setText(QString::fromStdString(selectedProduct.getName()));
    f2->setText(QString::fromStdString(selectedProduct.getBrand()));
    f3->setText(QString::number(selectedProduct.getPrice()));
    /* set the qnty edit */
    f4->setValue(selectedProduct.getQuantity());
    /* set the date */
    QString dateString = QString::fromStdString(selectedProduct.getExpiry());
    QDate date = QDate::fromString(dateString, "dd/MM/yyyy");
    f5->setDate(date);
}
