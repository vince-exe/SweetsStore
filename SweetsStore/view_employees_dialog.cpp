#include "view_employees_dialog.h"
#include "ui_view_employees_dialog.h"

#include <QTableView>
#include <QStandardItemModel>
#include <QScrollBar>
#include <QtWidgets>

#include "utilities.h"

QStandardItemModel *employeeModel = new QStandardItemModel();


ViewEmployeesDialog::ViewEmployeesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewEmployeesDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 1280, 720);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    /* set the date */
    ui->timeButton->setText(QString::fromStdString(currentDateTime().c_str()));
    ui->srchEmplyBox->setPlaceholderText("Search Employee");

    QStringList horizontalHeader;
    QStringList verticalHeader;
    /* create the columns */
    horizontalHeader.append("First Name");
    horizontalHeader.append("Last Name");
    horizontalHeader.append("Sex");
    horizontalHeader.append("Age");
    horizontalHeader.append("Salary");
    horizontalHeader.append("Email");
    horizontalHeader.append("Password");
    /* set the model */
    employeeModel->setHorizontalHeaderLabels(horizontalHeader);
    employeeModel->setVerticalHeaderLabels(verticalHeader);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->verticalHeader()->setDefaultSectionSize(59);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(145);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    /* print the table */
    printEmployeesTable(employeeModel, &employeeDatabase, ui->tableView);
}

ViewEmployeesDialog::~ViewEmployeesDialog() {
    delete ui;
}

/* print the employees table */
void printEmployeesTable(QStandardItemModel* model, std::map<std::string, Employee>* employeeDatabase, QTableView* table) {
    int i = 0;
    /* fill the table with the informations */
    for(auto& value : *employeeDatabase) {
        model->setItem(i, 0, getItem(QString::fromStdString(value.second.getFirstName())));
        model->setItem(i, 1, getItem(QString::fromStdString(value.second.getLastName())));
        model->setItem(i, 2, getItem(QChar(value.second.getSex())));
        model->setItem(i, 3, getItem(QString::number(value.second.getAge())));
        model->setItem(i, 4, getItem(QString::number(value.second.getSalary())));
        model->setItem(i, 5, getItem(QString::fromStdString(value.second.getEmail())));
        model->setItem(i, 6, getItem(QString::fromStdString(value.second.getPassword())));
        i++;
    }
    /* set the model to the table */
    table->setModel(model);
}

void ViewEmployeesDialog::on_srchEmplyBox_textChanged(const QString &arg1) {

}

