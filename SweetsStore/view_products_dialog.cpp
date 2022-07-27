#include "view_products_dialog.h"
#include "ui_viewproductsdialog.h"

#include <QStandardItemModel>

#include "utilities.h"

/* fill the table with the informations */
void fillTable();

ViewProductsDialog::ViewProductsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewProductsDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 1280, 720);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    /* set the date */
    ui->dateLabel->setText("  " + QString::fromStdString(currentDateTime().c_str()));

    QStandardItemModel *model;
    QStringList horizontalHeader;
    QStringList verticalHeader;
    /* create the columns */
    horizontalHeader.append("Product Name");
    horizontalHeader.append("Expire Date");
    horizontalHeader.append("Brand Name");
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

    model->setItem(0, 0, new QStandardItem(QString("ciao")));

    ui->tableView->setModel(model);
}

ViewProductsDialog::~ViewProductsDialog() {
    delete ui;
}
