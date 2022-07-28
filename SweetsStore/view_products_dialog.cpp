#include "view_products_dialog.h"
#include "ui_viewproductsdialog.h"

#include <QStandardItemModel>

#include "utilities.h"
#include "product.h"

ViewProductsDialog::ViewProductsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewProductsDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 1280, 720);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    /* set the date */
    ui->timeButton->setText(QString::fromStdString(currentDateTime().c_str()));

    QStandardItemModel *model;
    QStringList horizontalHeader;
    QStringList verticalHeader;
    /* create the columns */
    horizontalHeader.append("Name");
    horizontalHeader.append("Expire Date");
    horizontalHeader.append("Brand");
    horizontalHeader.append("Price");
    horizontalHeader.append("Quantity");
    /* create the model */
    model = new QStandardItemModel();
    /* set the model */
    model->setHorizontalHeaderLabels(horizontalHeader);
    model->setVerticalHeaderLabels(verticalHeader);
    /* table settings */
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->verticalHeader()->setDefaultSectionSize(50);

    int i = 0;
    /* fill the table with the informations */
    for(auto& value : productsDatabase) {
        model->setItem(i, 0, new QStandardItem(QString::fromStdString(value.second.getName())));
        model->setItem(i, 1, new QStandardItem(QString::fromStdString(value.second.getExpiry())));
        model->setItem(i, 2, new QStandardItem(QString::fromStdString(value.second.getBrand())));
        model->setItem(i, 3, new QStandardItem(QString::number(value.second.getPrice())));
        model->setItem(i, 4, new QStandardItem(QString::number(value.second.getQuantity())));
        i++;
    }
    /* set the model to the table */
    ui->tableView->setModel(model);
}

ViewProductsDialog::~ViewProductsDialog() {
    delete ui;
}
