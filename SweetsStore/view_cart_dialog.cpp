#include "view_cart_dialog.h"
#include "ui_view_cart_dialog.h"

#include <QMessageBox>
#include <QStandardItemModel>
#include <QScrollBar>

#include "utilities.h"
#include "product.h"

/* create the models */
QStandardItemModel* modelCart = new QStandardItemModel();
QStandardItemModel* searchModelCart = new QStandardItemModel();

/* define the StringList */
QStringList horizontalHeaderCart;
QStringList verticalHeaderCart;

void printTable(std::vector<std::string>* customerCart, std::map<std::string, Product>* productsDatabase, QStandardItemModel* model, QTableView* table) {
    int i = 0;
    /* fill the table with the informations */

    for(auto& value : *customerCart) {
        /* get the product from the products database */
        auto product = productsDatabase->find(value);

        model->setItem(i, 0, getItem(QString::fromStdString(product->second.getName())));
        model->setItem(i, 1, getItem(QString::fromStdString(product->second.getExpiry())));
        model->setItem(i, 2, getItem(QString::fromStdString(product->second.getBrand())));
        model->setItem(i, 3, getItem(QString::number(product->second.getPrice())));
        model->setItem(i, 4, getItem(QString::number(product->second.getQuantity())));
        i++;
    }
    /* set the model to the table */
    table->setModel(model);
}

ViewCartDialog::ViewCartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewCartDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 1200, 657);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    ui->timeButton->setText(QString::fromStdString(currentDateTime().c_str()));

    /* create the columns */
    horizontalHeaderCart.append("Name");
    horizontalHeaderCart.append("Expire Date");
    horizontalHeaderCart.append("Brand");
    horizontalHeaderCart.append("Price");
    horizontalHeaderCart.append("Quantity");
    /* set the model */
    modelCart->setHorizontalHeaderLabels(horizontalHeaderCart);
    modelCart->setVerticalHeaderLabels(verticalHeaderCart);
    /* set the searching model */
    searchModelCart->setVerticalHeaderLabels(horizontalHeaderCart);
    searchModelCart->setVerticalHeaderLabels(verticalHeaderCart);
    /* table settings */
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->verticalHeader()->setDefaultSectionSize(50);
    ui->tableView->verticalScrollBar()->setStyleSheet("background-color: #75103c;" "alternate-background-color: #540d2b;");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    printTable(&customerCart, &productsDatabase, modelCart, ui->tableView);
}

ViewCartDialog::~ViewCartDialog() {
    horizontalHeaderCart.clear();
    verticalHeaderCart.clear();
    delete ui;
}

void ViewCartDialog::on_infoBtn_clicked() {
    QMessageBox messageBox;
    messageBox.information(0, "Info", "To delete a product in your cart, select it with a double click then press the button");
}
