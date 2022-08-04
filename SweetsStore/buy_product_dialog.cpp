#include "buy_product_dialog.h"
#include "ui_buy_product_dialog.h"

#include <QMessageBox>

#include "utilities.h"
#include "order.h"

BuyProductDialog::BuyProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuyProductDialog) {
    ui->setupUi(this);

    ui->titleLabel->setAlignment(Qt::AlignCenter);
    ui->prodBox->setAlignment(Qt::AlignCenter);

    ui->moneyBox->setText(QString::number(selectedProduct.getPrice()));
    ui->prodBox->setText(QString::fromStdString(selectedProduct.getName()));
    ui->qntyBox->setMinimum(1);
    ui->qntyBox->setMaximum(selectedProduct.getQuantity());
}

BuyProductDialog::~BuyProductDialog() {
    delete ui;
}

/* when the user wants to buy a product */
void BuyProductDialog::on_saveBtn_clicked() {
    /* check if the user has enough money */
    if(currentCustomer.getMoney() < std::stof(ui->moneyBox->text().toStdString())) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "You don't have enough money");
        messageBox.setFixedSize(550, 300);
        this->close();
        return;
    }
    int quantity = std::atoi(ui->qntyBox->text().toStdString().c_str());
    currentCustomer.setMoney(currentCustomer.getMoney() - std::stof(ui->moneyBox->text().toStdString()));

    ordersDatabase.insert(std::pair<int, Order>(Order::lastOrderId, Order(Order::lastOrderId, currentCustomer.getEmail(), selectedProduct.getName(), currentDateTime(), quantity)));
    Order::lastOrderId += 1;

    /* update the quantity of the product */
    productsDatabase[selectedProduct.getName()].setQuantity(selectedProduct.getQuantity() - quantity);

    /* update the customers database */
    customersDatabase[currentCustomer.getEmail()] = currentCustomer;

    /* save the updated in the system files */
    FILE* f = fopen("files/orders.txt", "w");
    storeOrdersInformations(f, &ordersDatabase);
    fclose(f);

    f = fopen("files/products.txt", "w");
    storeProductInformations(f, &productsDatabase);
    fclose(f);

    f = fopen("files/customers.txt", "w");
    storeCustomersInformations(f, &customersDatabase);
    fclose(f);

    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully bought to product");
    messageBox.setFixedSize(550, 300);

    this->close();
}

/* every time that the user changes the quantity, we update the price */
void BuyProductDialog::on_qntyBox_valueChanged(int arg1) {
    ui->moneyBox->setText(QString::number(arg1 * selectedProduct.getPrice()));
}

