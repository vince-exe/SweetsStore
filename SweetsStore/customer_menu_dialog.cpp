#include "customer_menu_dialog.h"
#include "ui_customer_menu_dialog.h"

#include <iostream>

#include <QTableView>
#include <QScrollBar>
#include <QMessageBox>

#include "view_products_dialog.h"
#include "utilities.h"
#include "product_utilities.h"

/* forms */
#include "about_me_dialog.h"
#include "add_money_dialog.h"
#include "buy_product_dialog.h"
#include "view_orders_dialog.h"

/* create the models */
QStandardItemModel *productsModelCustomer = new QStandardItemModel();
QStandardItemModel* searchModelCustomer = new QStandardItemModel();

/* define the StringList */
QStringList horizontalHeaderCustomer;
QStringList verticalHeaderCustomer;

CustomerMenuDialog::CustomerMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerMenuDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 1280, 720);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    /* set the date */
    ui->timeButton->setText(QString::fromStdString(currentDateTime().c_str()));

    /* create the columns */
    horizontalHeaderCustomer.append("Name");
    horizontalHeaderCustomer.append("Expire Date");
    horizontalHeaderCustomer.append("Brand");
    horizontalHeaderCustomer.append("Price");
    horizontalHeaderCustomer.append("Quantity");
    /* set the model */
    productsModelCustomer->setHorizontalHeaderLabels(horizontalHeaderCustomer);
    productsModelCustomer->setVerticalHeaderLabels(verticalHeaderCustomer);
    /* set the search model */
    searchModelCustomer->setHorizontalHeaderLabels(horizontalHeaderCustomer);
    searchModelCustomer->setVerticalHeaderLabels(verticalHeaderCustomer);
    /* table settings */
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->verticalHeader()->setDefaultSectionSize(50);
    ui->tableView->verticalScrollBar()->setStyleSheet("background-color: #75103c;" "alternate-background-color: #540d2b;");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    /* print the table */
    printTable(productsModelCustomer, &productsDatabase, ui->tableView);
}

CustomerMenuDialog::~CustomerMenuDialog() {
    horizontalHeaderCustomer.clear();
    verticalHeaderCustomer.clear();
    delete ui;
}

/* about me dialog */
void CustomerMenuDialog::on_abtMeBtn_clicked() {
    AboutMeDialog aboutMeWindow;
    aboutMeWindow.setModal(true);
    aboutMeWindow.show();
    aboutMeWindow.exec();
}

/* when the user wants to add money to his bank account */
void CustomerMenuDialog::on_addMoneyBtn_clicked() {
    AddMoneyDialog addMoneyWindow;
    addMoneyWindow.setModal(true);
    addMoneyWindow.show();
    addMoneyWindow.exec();
}

/* when the user wants to buy a product istantly */
void CustomerMenuDialog::on_buyNowBtn_clicked() {
    if(!selectedProductCheck) { return; }

    selectedProductCheck = false;
    /* open the buy product window */
    BuyProductDialog buyProductWindow;
    buyProductWindow.setModal(true);
    buyProductWindow.show();
    buyProductWindow.exec();

    printTable(productsModelCustomer, &productsDatabase, ui->tableView);
}

/* when the user wants to select a product */
void CustomerMenuDialog::on_tableView_activated(const QModelIndex &index) {
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

/* view the orders */
void CustomerMenuDialog::on_viewOrdersBtn_clicked() {
    ViewOrdersDialog viewOrdersWindow;
    viewOrdersWindow.setModal(true);
    viewOrdersWindow.show();
    viewOrdersWindow.exec();
}

/* info button clicked */
void CustomerMenuDialog::on_infoBtn_clicked() {
    QMessageBox messageBox;
    messageBox.information(0, "Info", "To update / delete an order select it with a double click then use the buttons");
    messageBox.setFixedSize(550, 300);
}

/* check if the user pass the limit of characters for the product name */
void CustomerMenuDialog::on_srchProdBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > prodNameLen) { ui->srchProdBox->backspace(); }
}

/* search button clicked */
void CustomerMenuDialog::on_srchButton_clicked() {
    if(!ui->srchProdBox->text().toStdString().length()) {
        printTable(productsModelCustomer, &productsDatabase, ui->tableView);
        return;
    }

    /* print the searched product */
    printsearchedProduct(&productsDatabase, searchModelCustomer, ui->tableView, ui->srchProdBox->text().toStdString());
    ui->srchProdBox->clear();
 }

/* reset button for searching */
void CustomerMenuDialog::on_resetBtn_clicked() {
    /* print the table */
    printTable(productsModelCustomer, &productsDatabase, ui->tableView);
    ui->srchProdBox->clear();
}
