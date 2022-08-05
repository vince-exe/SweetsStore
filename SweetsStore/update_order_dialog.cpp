#include "update_order_dialog.h"
#include "ui_update_order_dialog.h"

#include "utilities.h"

#include <QMessageBox>

float selectedProdPrice = 0;

UpdateOrderDialog::UpdateOrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateOrderDialog) {
    ui->setupUi(this);

    ui->titleLabel->setAlignment(Qt::AlignCenter);
    ui->prodBox->setAlignment(Qt::AlignCenter);

    selectedProdPrice = productsDatabase[selectedOrder.getProductId()].getPrice();
    ui->moneyBox->setText(QString::number(selectedOrder.getQuantity() * selectedProdPrice));
    ui->prodBox->setText(QString::fromStdString(selectedOrder.getProductId().c_str()));
    ui->qntyBox->setValue(selectedOrder.getQuantity());
    ui->qntyBox->setMinimum(1);
    ui->qntyBox->setMaximum(productsDatabase[selectedOrder.getProductId()].getQuantity());
}

UpdateOrderDialog::~UpdateOrderDialog() {
    delete ui;
}

/* update the product */
void UpdateOrderDialog::on_updateBtn_clicked() {
    int newQuantity = ui->qntyBox->text().toInt();
    float price = ui->moneyBox->text().toFloat();

    if(newQuantity == selectedOrder.getQuantity()) {
        QMessageBox messageBox;
        messageBox.information(0, "Success", "Successfully updated the order");
        messageBox.setFixedSize(550, 300);
        this->close(); return;
    }
    /* check if the user has enough money */
    if(currentCustomer.getMoney() < price) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "You don't have enough money");

        ui->qntyBox->setValue(selectedOrder.getQuantity());
        ui->moneyBox->setText(QString::number(selectedProdPrice * selectedOrder.getQuantity()));

        messageBox.setFixedSize(550, 300);
        return;
    }

    ordersDatabase[selectedOrder.getId()].setQuantity(newQuantity);

    int def_quatity = productsDatabase[selectedOrder.getProductId()].getQuantity();
    /* update the new quantity */
    if(newQuantity > selectedOrder.getQuantity()) {
        productsDatabase[selectedOrder.getProductId()].setQuantity(def_quatity - (newQuantity - selectedOrder.getQuantity()));
    }
    else {
        productsDatabase[selectedOrder.getProductId()].setQuantity(def_quatity + (selectedOrder.getQuantity() - newQuantity));
    }

    /* update the money at the customer */
    if(newQuantity > selectedOrder.getQuantity()) {
        currentCustomer.setMoney(currentCustomer.getMoney() - (selectedProdPrice * (newQuantity - selectedOrder.getQuantity())));
    }
    else {
        currentCustomer.setMoney(currentCustomer.getMoney() + (selectedProdPrice * (selectedOrder.getQuantity() - newQuantity)));
    }

    customersDatabase[currentCustomer.getEmail()].setMoney(currentCustomer.getMoney());

    /* store the informations in the files */
    FILE* f = fopen("files/products.txt", "w");
    storeProductInformations(f, &productsDatabase);
    fclose(f);

    f = fopen("files/orders.txt", "w");
    storeOrdersInformations(f, &ordersDatabase);
    fclose(f);

    f = fopen("files/customers.txt", "w");
    storeCustomersInformations(f, &customersDatabase);
    fclose(f);

    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully update the order");
    messageBox.setFixedSize(550, 300);
    this->close(); return;
}

/* set the value in the money box based on the quantity that the user select */
void UpdateOrderDialog::on_qntyBox_valueChanged(int arg1) {
    ui->moneyBox->setText(QString::number(selectedProdPrice * arg1));
}

