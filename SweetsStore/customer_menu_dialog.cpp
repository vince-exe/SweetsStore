#include "customer_menu_dialog.h"
#include "ui_customer_menu_dialog.h"

#include <QTableView>
#include <QScrollBar>

#include "view_products_dialog.h"
#include "utilities.h"

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
    delete ui;
}
