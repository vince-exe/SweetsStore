#include "view_products_dialog.h"
#include "ui_viewproductsdialog.h"

#include <QStandardItemModel>
#include <QScrollBar>
#include <QMessageBox>

#include "utilities.h"
#include "product.h"

/* forms */
#include "add_product_dialog.h"
#include "update_product_dialog.h"

void printTable(QStandardItemModel* model, std::map<std::string, Product>* productsMap, QTableView* table);

/* return an item pointer with the text aligned */
QStandardItem* getItem(QString string) {
    QStandardItem* item = new QStandardItem;
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(string);

    return item;
}

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
        model->setItem(i, 0, getItem(QString::fromStdString(value.second.getName())));
        model->setItem(i, 1, getItem(QString::fromStdString(value.second.getExpiry())));
        model->setItem(i, 2, getItem(QString::fromStdString(value.second.getBrand())));
        model->setItem(i, 3, getItem(QString::number(value.second.getPrice())));
        model->setItem(i, 4, getItem(QString::number(value.second.getQuantity())));
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

void ViewProductsDialog::on_tableView_activated(const QModelIndex &index) {
    selectedProductCheck = true;
    /* get the product name*/
    QString prodName = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();
    /* get the expire date */
    QString expireDate = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 1)).toString();
    /* get the brand name */
    QString brandName = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 2)).toString();
    /* get the price */
    float price = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 3)).toFloat();
    /* get the quantity */
    int qnt = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 4)).toInt();

    /* set the product */
    selectedProduct.setName(prodName.toStdString());
    selectedProduct.setBrand(brandName.toStdString());
    selectedProduct.setExpiry(expireDate.toStdString());
    selectedProduct.setPrice(price);
    selectedProduct.setQuantity(qnt);
}

/* update prod button */
void ViewProductsDialog::on_addProdBtn_5_clicked() {
    /* if no row has been clicked, doesn't open the update UI */
    if(!selectedProductCheck) { return; }

    UpdateProductDialog updateDialog;
    updateDialog.setModal(true);
    updateDialog.show();
    updateDialog.exec();
    /* print the table */
    printTable(model, &productsDatabase, ui->tableView);
    newChanges = true;
    selectedProductCheck = false;
}

/* show an info message box */
void ViewProductsDialog::on_infoBtn_clicked() {
    QMessageBox messageBox;
    messageBox.information(0, "Info", "To update / delete a product, you have to select with a click the product row in the table");
    messageBox.show();
}

/* remove a product */
void ViewProductsDialog::on_rmProdBtn_clicked() {
    /* if no row has been clicked, return */
    if(!selectedProductCheck) { return; }

    QMessageBox confirmBox;
    confirmBox.setText(tr("The application will proceed with deleting the product, are you sure you want to continue?"));
    confirmBox.addButton(tr("Yes"), QMessageBox::YesRole);
    QAbstractButton* noBtn = confirmBox.addButton(tr("No"), QMessageBox::NoRole);
    /* show the message box */
    confirmBox.exec();
    /* if the user doesn't want to delete the product, close */
    if(confirmBox.clickedButton() == noBtn) { return; }

    /* erase the selected element from the map */
    productsDatabase.erase(selectedProduct.getName());
    /* print the success message box */
    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully removed the product");
    messageBox.setFixedSize(550, 300);
    messageBox.show();

    /* get the index of the selected row */
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    /* use the model to remove the row */
    model->removeRow(index.row(), index.parent());

    newChanges = true;
    selectedProductCheck = false;

    /* reprint the table */
    printTable(model, &productsDatabase, ui->tableView);
}
