#include "view_cart_dialog.h"
#include "ui_view_cart_dialog.h"

#include <QMessageBox>
#include <QStandardItemModel>
#include <QScrollBar>

#include "utilities.h"
#include "product.h"
#include "product_utilities.h"

/* forms */
#include "buy_product_dialog.h"

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

void printSearchedCartProd(std::vector<std::string>* customerCart, std::map<std::string, Product>* productsDatabase, QStandardItemModel* searchModel, QTableView* table, std::string search) {
    int i = 0;
    /* fill the table with the informations */

    for(auto& value : *customerCart) {
        /* get the product from the products database */
        auto product = productsDatabase->find(value);
        if(product->second.getName() == search || product->second.getBrand() == search) {
            searchModel->setItem(i, 0, getItem(QString::fromStdString(product->second.getName())));
            searchModel->setItem(i, 1, getItem(QString::fromStdString(product->second.getExpiry())));
            searchModel->setItem(i, 2, getItem(QString::fromStdString(product->second.getBrand())));
            searchModel->setItem(i, 3, getItem(QString::number(product->second.getPrice())));
            searchModel->setItem(i, 4, getItem(QString::number(product->second.getQuantity())));
            i++;
        }
    }
    /* set the model to the table */
    table->setModel(searchModel);
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
    searchModelCart->setHorizontalHeaderLabels(horizontalHeaderCart);
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

/* check that the user doesn't pass the limit of characters in the search box */
void ViewCartDialog::on_srchProductBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > prodNameLen) { ui->srchProductBox->backspace(); }
}

void ViewCartDialog::on_srchButton_clicked() {
    printSearchedCartProd(&customerCart, &productsDatabase, searchModelCart, ui->tableView, ui->srchProductBox->text().toStdString());
    ui->srchProductBox->clear();
}

void ViewCartDialog::on_resetBtn_clicked() {
    ui->srchProductBox->clear();
    printTable(&customerCart, &productsDatabase, modelCart, ui->tableView);
}

/* when the user double click on an item */
void ViewCartDialog::on_tableView_activated(const QModelIndex &index) {
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

void ViewCartDialog::on_rmvProductBtn_clicked() {
    if(!selectedProductCheck) { return; }
    selectedProductCheck = false;

    QMessageBox confirmBox;
    confirmBox.setText(tr("The application will proceed with deleting the product, are you sure you want to continue?"));
    confirmBox.addButton(tr("Yes"), QMessageBox::YesRole);
    QAbstractButton* noBtn = confirmBox.addButton(tr("No"), QMessageBox::NoRole);
    /* show the message box */
    confirmBox.exec();
    /* if the user doesn't want to delete the product, close */
    if(confirmBox.clickedButton() == noBtn) { return; }

    /* erase the selected element from the vector */
    customerCart.erase(std::find(customerCart.begin(), customerCart.end(), selectedProduct.getName()));

    /* save the changes in the file */
    FILE* f = fopen("files/my_cart.txt", "w");
    storeMyCartInformations(f, &customerCart);
    fclose(f);

    /* print the success message box */
    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully removed the product");
    messageBox.setFixedSize(550, 300);
    messageBox.show();

    /* get the index of the selected row */
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    /* use the model to remove the row */
    modelCart->removeRow(index.row(), index.parent());

    /* reprint the table */
    printTable(&customerCart, &productsDatabase, modelCart, ui->tableView);
}

/* if he wants to buy a specific product from the cart */
void ViewCartDialog::on_buySelectedBtn_clicked() {
    if(!selectedProductCheck) { return; }
    selectedProductCheck = false;

    /* we store the value of the money before the user proceeds, to see if he bought the product */
    float moneyBefore = currentCustomer.getMoney();

    BuyProductDialog buyProductWindow;
    buyProductWindow.setModal(true);
    buyProductWindow.show();
    buyProductWindow.exec();

    /* if he bought the product */
    if(moneyBefore != currentCustomer.getMoney()) {
        customerCart.erase(std::find(customerCart.begin(), customerCart.end(), selectedProduct.getName()));

        FILE* f = fopen("files/my_cart.txt", "w");
        storeMyCartInformations(f, &customerCart);
        fclose(f);

        /* get the index of the selected row */
        QModelIndex index = ui->tableView->selectionModel()->currentIndex();
        /* use the model to remove the row */
        modelCart->removeRow(index.row(), index.parent());

        printTable(&customerCart, &productsDatabase, modelCart, ui->tableView);
    }
}
