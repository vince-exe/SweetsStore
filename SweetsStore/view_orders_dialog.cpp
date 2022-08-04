#include "view_orders_dialog.h"
#include "ui_view_orders_dialog.h"

#include <QMessageBox>
#include <QScrollBar>

#include "utilities.h"

/* create the models */
QStandardItemModel* modelOrder = new QStandardItemModel();
QStandardItemModel* searchModelOrder = new QStandardItemModel();

/* define the StringList */
QStringList horizontalHeaderOrder;
QStringList verticalHeaderOrder;


void printTable(std::map<int, Order> *ordersDatabase, QStandardItemModel *model, QTableView *table) {
    int i = 0;
    /* fill the table with the informations */
    for(auto& value : *ordersDatabase) {
        model->setItem(i, 0, getItem(QString::number(value.second.getId())));
        model->setItem(i, 1, getItem(QString::fromStdString(customersDatabase[currentCustomer.getEmail()].getFirstName())));
        model->setItem(i, 2, getItem(QString::fromStdString(productsDatabase[value.second.getProductId()].getName())));
        model->setItem(i, 3, getItem(QString::number(value.second.getQuantity())));
        model->setItem(i, 4, getItem(QString::number(value.second.getQuantity() * productsDatabase[value.second.getProductId()].getPrice())));
        model->setItem(i, 5, getItem(QString::fromStdString(value.second.getOrderDate())));
        i++;
    }
    /* set the model to the table */
    table->setModel(model);
}

ViewOrdersDialog::ViewOrdersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewOrdersDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 1200, 657);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    ui->timeButton->setText(QString::fromStdString(currentDateTime().c_str()));

    horizontalHeaderOrder.append("Order Id");
    horizontalHeaderOrder.append("Customer");
    horizontalHeaderOrder.append("Product");
    horizontalHeaderOrder.append("Quantity");
    horizontalHeaderOrder.append("Total Amount");
    horizontalHeaderOrder.append("Order Date");
    /* set the model */
    modelOrder->setHorizontalHeaderLabels(horizontalHeaderOrder);
    modelOrder->setVerticalHeaderLabels(verticalHeaderOrder);
    /* table settings */
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->verticalHeader()->setDefaultSectionSize(50);
    ui->tableView->verticalScrollBar()->setStyleSheet("background-color: #75103c;" "alternate-background-color: #540d2b;");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    /* print the table */
    printTable(&ordersDatabase, modelOrder, ui->tableView);
}

ViewOrdersDialog::~ViewOrdersDialog() {
    horizontalHeaderOrder.clear();
    verticalHeaderOrder.clear();
    delete ui;
}
