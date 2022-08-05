#include "view_orders_dialog.h"
#include "ui_view_orders_dialog.h"

#include <QMessageBox>
#include <QScrollBar>

#include "utilities.h"
#include "order.h"
#include "product_utilities.h"

/* forms */
#include "update_order_dialog.h"

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

void printSearchedOrder(std::map<int, Order> *ordersDatabase, QStandardItemModel *searchModel, QTableView *table, std::string search) {
    int i = 0;
    /* fill the table with the informations */
    for(auto& value : *ordersDatabase) {
        if(value.second.getProductId() == search || value.second.getOrderDate() == search) {
            searchModel->setItem(i, 0, getItem(QString::number(value.second.getId())));
            searchModel->setItem(i, 1, getItem(QString::fromStdString(customersDatabase[currentCustomer.getEmail()].getFirstName())));
            searchModel->setItem(i, 2, getItem(QString::fromStdString(productsDatabase[value.second.getProductId()].getName())));
            searchModel->setItem(i, 3, getItem(QString::number(value.second.getQuantity())));
            searchModel->setItem(i, 4, getItem(QString::number(value.second.getQuantity() * productsDatabase[value.second.getProductId()].getPrice())));
            searchModel->setItem(i, 5, getItem(QString::fromStdString(value.second.getOrderDate())));
            i++;
         }
    }
    /* set the model to the table */
    table->setModel(searchModel);
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
    /* set the search model */
    searchModelOrder->setVerticalHeaderLabels(verticalHeaderOrder);
    searchModelOrder->setHorizontalHeaderLabels(horizontalHeaderOrder);
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

void ViewOrdersDialog::on_tableView_activated(const QModelIndex &index) {
    QString prodName = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 2)).toString();
    int quantity = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 3)).toInt();
    int orderId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toInt();

    /* set the selected order */
    selectedOrder.setId(orderId);
    selectedOrder.setProductId(prodName.toStdString());
    selectedOrder.setQuantity(quantity);
    selectedOrderCheck = true;
}

/* update an order */
void ViewOrdersDialog::on_updtOrderBtn_clicked() {
    if(!selectedOrderCheck) { return; }

    UpdateOrderDialog updateOrderWindow;
    updateOrderWindow.setModal(true);
    updateOrderWindow.show();
    updateOrderWindow.exec();

    selectedOrderCheck = false;
    printTable(&ordersDatabase, modelOrder, ui->tableView);
}

void ViewOrdersDialog::on_infoBtn_clicked() {
    QMessageBox messageBox;
    messageBox.information(0, "Info", "To update / remove an order select it with a double click in the order row");
    messageBox.setFixedSize(550, 300);
    return;
}

/* search an order */
void ViewOrdersDialog::on_srchButton_clicked() {
    if(!ui->srchButton->text().length()) {
        printTable(&ordersDatabase, modelOrder, ui->tableView);
        return;
    }
    printSearchedOrder(&ordersDatabase, searchModelOrder, ui->tableView, ui->srchOrderBox->text().toStdString());
    ui->srchOrderBox->clear();
}

void ViewOrdersDialog::on_resetBtn_clicked() {
    ui->srchOrderBox->clear();
    printTable(&ordersDatabase, modelOrder, ui->tableView);
}

/* check if the user doesn't pass the limit of characters inside the search box */
void ViewOrdersDialog::on_srchOrderBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > prodNameLen) { ui->srchOrderBox->backspace(); }
}

/* remove an order */
void ViewOrdersDialog::on_rmvOrderBtn_clicked() {
    /* if no row has been clicked, return */
    if(!selectedOrderCheck) { return; }

    selectedOrderCheck = false;

    QMessageBox confirmBox;
    confirmBox.setText(tr("The application will proceed with deleting the order, all the money will be returned to your bank account, are you sure you want to continue?"));
    confirmBox.addButton(tr("Yes"), QMessageBox::YesRole);
    QAbstractButton* noBtn = confirmBox.addButton(tr("No"), QMessageBox::NoRole);
    /* show the message box */
    confirmBox.exec();
    /* if the user doesn't want to delete the order, close */
    if(confirmBox.clickedButton() == noBtn) { return; }

    /* erase the selected order from the map */
    ordersDatabase.erase(ordersDatabase.find(selectedOrder.getId()));
    /* print the success message box */
    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully removed the employee");
    messageBox.setFixedSize(550, 300);
    messageBox.show();

    /* store the change in the order file */
    FILE* f = fopen("files/orders.txt", "w");
    storeOrdersInformations(f, &ordersDatabase);
    fclose(f);

    /* store the changes in the products file */
    productsDatabase[selectedOrder.getProductId()].setQuantity(productsDatabase[selectedOrder.getProductId()].getQuantity() + selectedOrder.getQuantity());
    f = fopen("files/products.txt", "w");
    storeProductInformations(f, &productsDatabase);
    fclose(f);

    currentCustomer.setMoney(currentCustomer.getMoney() + productsDatabase[selectedOrder.getProductId()].getPrice() * selectedOrder.getQuantity());
    customersDatabase[currentCustomer.getEmail()].setMoney(currentCustomer.getMoney());

    /* store the informations in the customer file */
    f = fopen("files/customers.txt", "w");
    storeCustomersInformations(f, &customersDatabase);
    fclose(f);

    /* get the index of the selected row */
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    /* use the model to remove the row */
    modelOrder->removeRow(index.row(), index.parent());

    /* reprint the table */
    printTable(&ordersDatabase, modelOrder, ui->tableView);
}

