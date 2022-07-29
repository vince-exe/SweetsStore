#include "view_products_dialog.h"
#include "ui_viewproductsdialog.h"

#include <QStandardItemModel>
#include <QScrollBar>
#include <QMessageBox>

#include "utilities.h"
#include "product.h"

/* forms */
#include "add_product_dialog.h"

void printTable(QStandardItemModel* model, std::map<std::string, Product>* productsMap, QTableView* table);

/* create the model */
QStandardItemModel *model = new QStandardItemModel();

ViewProductsDialog::ViewProductsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewProductsDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 1280, 720);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    /* set the date */
    ui->timeButton->setText(QString::fromStdString(currentDateTime().c_str()));

    QStringList horizontalHeader;
    QStringList verticalHeader;
    /* create the columns */
    horizontalHeader.append("Name");
    horizontalHeader.append("Expire Date");
    horizontalHeader.append("Brand");
    horizontalHeader.append("Price");
    horizontalHeader.append("Quantity");
    /* set the model */
    model->setHorizontalHeaderLabels(horizontalHeader);
    model->setVerticalHeaderLabels(verticalHeader);
    /* table settings */
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->verticalHeader()->setDefaultSectionSize(50);
    ui->tableView->verticalScrollBar()->setStyleSheet("background-color: #75103c;" "alternate-background-color: #540d2b;");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    /* print the table */
    printTable(model, &productsDatabase, ui->tableView);
}

ViewProductsDialog::~ViewProductsDialog() {
    delete ui;
}

void printTable(QStandardItemModel* model, std::map<std::string, Product>* productsDatabase, QTableView* table) {
    int i = 0;
    /* fill the table with the informations */
    for(auto& value : *productsDatabase) {
        model->setItem(i, 0, new QStandardItem(QString::fromStdString(value.second.getName())));
        model->setItem(i, 1, new QStandardItem(QString::fromStdString(value.second.getExpiry())));
        model->setItem(i, 2, new QStandardItem(QString::fromStdString(value.second.getBrand())));
        model->setItem(i, 3, new QStandardItem(QString::number(value.second.getPrice())));
        model->setItem(i, 4, new QStandardItem(QString::number(value.second.getQuantity())));
        i++;
    }
    /* set the model to the table */
    table->setModel(model);
}

/* add a product to the database ( but doesn't save it in the file ) */
void ViewProductsDialog::on_addProdBtn_4_clicked() {
    AddProductDialog addWindow;
    addWindow.setModal(true);
    addWindow.show();

    addWindow.exec();
    /* reprint the table */
    printTable(model, &productsDatabase, ui->tableView);
}

/* save the products database in the products file */
void ViewProductsDialog::on_addProdBtn_2_clicked() {
    /* check if there aren't new changes to save */
    if(!newChanges) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "There aren't new changes to save");
        messageBox.setFixedSize(550, 300);
        return;
    }

    /* open the file in reading mode to check if exist */
    FILE* file = fopen("files/products.txt", "r");

    if(!file) {
        QMessageBox messageBox;
        messageBox.critical(0, "Fatal Error", "The application failed to save the changes");
        messageBox.setFixedSize(550,300);

        exit(-1);
    }
    fclose(file);

    /* open it in write mode */
    file = fopen("files/products.txt", "w");
    /* store the informations in the file */
    storeProductInformations(file, &productsDatabase);
    /* close the product file */
    fclose(file);
    /* reset the new changes variable */
    newChanges = false;

    QMessageBox messageBox;
    messageBox.setText(tr("The application has successfully saved the changes"));

    messageBox.addButton(tr("Continue"), QMessageBox::YesRole);
    QAbstractButton* exitButton = messageBox.addButton(tr("Exit"), QMessageBox::NoRole);

    messageBox.exec();

    if(messageBox.clickedButton() == exitButton) { this->close(); return; }
}

