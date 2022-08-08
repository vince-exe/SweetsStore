#include "view_customer_dialog.h"
#include "ui_view_customer_dialog.h"

#include "utilities.h"
#include "employee_utilities.h"

#include <QMessageBox>

/* forms */
#include "sign_up_dialog.h"
#include "update_customer_dialog.h"

QStandardItemModel *modelCustomerMenu = new QStandardItemModel();
QStandardItemModel *searchModelCustomerMenu = new QStandardItemModel();

/* define the String List */
QStringList horizontalHeaderCustomerMenu;
QStringList verticalHeaderCustomerMenu;

void printCustomersTable(QStandardItemModel* model, std::map<std::string, Customer>* customerDatabase, QTableView* table) {
    int i = 0;
    /* fill the table with the informations */
    for(auto& value : *customerDatabase) {
        model->setItem(i, 0, getItem(QString::fromStdString(value.second.getFirstName())));
        model->setItem(i, 1, getItem(QString::fromStdString(value.second.getLastName())));
        model->setItem(i, 2, getItem(QChar(value.second.getSex())));
        model->setItem(i, 3, getItem(QString::number(value.second.getAge())));
        model->setItem(i, 4, getItem(QString::number(value.second.getMoney())));
        model->setItem(i, 5, getItem(QString::fromStdString(value.second.getEmail())));
        model->setItem(i, 6, getItem(QString::fromStdString(value.second.getPassword())));
        i++;
    }
    /* set the model to the table */
    table->setModel(model);
}

void printSearchedCustomer(QStandardItemModel *model, std::map<std::string, Customer> *customerDatabase, QTableView *table, std::string searchedCustomer) {
    int i = 0;
    /* fill the table with the informations */
    for(auto& value : *customerDatabase) {
        if(value.second.getEmail() == searchedCustomer || value.second.getFirstName() == searchedCustomer || value.second.getLastName() == searchedCustomer) {
            model->setItem(i, 0, getItem(QString::fromStdString(value.second.getFirstName())));
            model->setItem(i, 1, getItem(QString::fromStdString(value.second.getLastName())));
            model->setItem(i, 2, getItem(QChar(value.second.getSex())));
            model->setItem(i, 3, getItem(QString::number(value.second.getAge())));
            model->setItem(i, 4, getItem(QString::number(value.second.getMoney())));
            model->setItem(i, 5, getItem(QString::fromStdString(value.second.getEmail())));
            model->setItem(i, 6, getItem(QString::fromStdString(value.second.getPassword())));
            i++;
         }
    }
    /* set the model to the table */
    table->setModel(model);
}

ViewCustomerDialog::ViewCustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewCustomerDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 1280, 720);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    /* set the date */
    ui->timeButton->setText(QString::fromStdString(currentDateTime().c_str()));

    /* create the columns */
    horizontalHeaderCustomerMenu.append("First Name");
    horizontalHeaderCustomerMenu.append("Last Name");
    horizontalHeaderCustomerMenu.append("Sex");
    horizontalHeaderCustomerMenu.append("Age");
    horizontalHeaderCustomerMenu.append("Money");
    horizontalHeaderCustomerMenu.append("Email");
    horizontalHeaderCustomerMenu.append("Password");
    /* set the model */
    modelCustomerMenu->setHorizontalHeaderLabels(horizontalHeaderCustomerMenu);
    modelCustomerMenu->setVerticalHeaderLabels(verticalHeaderCustomerMenu);
    /* set the search model */
    searchModelCustomerMenu->setHorizontalHeaderLabels(horizontalHeaderCustomerMenu);
    searchModelCustomerMenu->setVerticalHeaderLabels(verticalHeaderCustomerMenu);
    /* set the table */
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->verticalHeader()->setDefaultSectionSize(59);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(145);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    /* print the table */
    printCustomersTable(modelCustomerMenu, &customersDatabase, ui->tableView);
}

ViewCustomerDialog::~ViewCustomerDialog() {
    horizontalHeaderCustomerMenu.clear();
    verticalHeaderCustomerMenu.clear();
    delete ui;
}

void ViewCustomerDialog::on_infoBtn_clicked() {
    QMessageBox messageBox;
    messageBox.information(0, "Info", "To update / remove a customer select it with a double click then press the button");
    messageBox.setFixedSize(550, 300);
    return;
}

/* add a new customer */
void ViewCustomerDialog::on_addCustomerBtn_clicked() {
    SignUpDialog signUpWindow;
    signUpWindow.setModal(true);
    signUpWindow.show();
    signUpWindow.exec();

    printCustomersTable(modelCustomerMenu, &customersDatabase, ui->tableView);
}

void ViewCustomerDialog::on_tableView_activated(const QModelIndex &index) {
    selectedCustomerCheck = true;

    /* get the First Name */
    QString firstName = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();
    /* get the Last Name */
    QString lastName = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 1)).toString();
    /* get the sex */
    QString sex = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 2)).toString();
    /* get the Age */
    int age = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 3)).toInt();
    /* get the salary */
    float salary = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 4)).toFloat();
    /* get the email */
    QString email = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 5)).toString();
    /* get the password */
    QString password = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 6)).toString();

    /* set the employee */
    selectedCustomer.setFirstName(firstName.toStdString());
    selectedCustomer.setLastName(lastName.toStdString());
    selectedCustomer.setSex(sex.toStdString()[0]);
    selectedCustomer.setAge(age);
    selectedCustomer.setMoney(salary);
    selectedCustomer.setEmail(email.toStdString());
    selectedCustomer.setPassword(password.toStdString());
}

/* update a customer */
void ViewCustomerDialog::on_updtCustomerBtn_clicked() {
    if(!selectedCustomerCheck) { return; }
    selectedCustomerCheck = false;

    UpdateCustomerDialog updateCustomerWindow;
    updateCustomerWindow.setModal(true);
    updateCustomerWindow.show();
    updateCustomerWindow.exec();
}

/* remove a customer */
void ViewCustomerDialog::on_rmCustomerBtn_clicked() {
    if(!selectedCustomerCheck) { return; }
    selectedCustomerCheck = false;

    QMessageBox confirmBox;
    confirmBox.setText(tr("The application will proceed with deleting the employee, are you sure you want to continue?"));
    confirmBox.addButton(tr("Yes"), QMessageBox::YesRole);
    QAbstractButton* noBtn = confirmBox.addButton(tr("No"), QMessageBox::NoRole);
    /* show the message box */
    confirmBox.exec();
    /* if the user doesn't want to delete the customer, close */
    if(confirmBox.clickedButton() == noBtn) { return; }

    /* erase the selected element from the map */
    customersDatabase.erase(selectedCustomer.getEmail());
    /* print the success message box */
    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully removed the employee");
    messageBox.setFixedSize(550, 300);
    messageBox.show();

    /* get the index of the selected row */
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    /* use the model to remove the row */
    modelCustomerMenu->removeRow(index.row(), index.parent());

    newChanges = true;
    /* reprint the table */
    printCustomersTable(modelCustomerMenu, &customersDatabase, ui->tableView);
}

/* save all the changes */
void ViewCustomerDialog::on_saveBtn_clicked() {
    /* check if there aren't new changes to save */
    if(!newChanges) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "There aren't new changes to save");
        messageBox.setFixedSize(550, 300);
        return;
    }

    /* open it in write mode */
    FILE* file = fopen("files/customers.txt", "w");
    /* store the informations in the file */
    storeCustomersInformations(file, &customersDatabase);
    /* close the customer file */
    fclose(file);
    /* reset the new changes variable */
    newChanges = false;

    QMessageBox messageBox;
    messageBox.information(0, "Success", "The application has successfully saved the changes");
    messageBox.setFixedSize(550,300);
    messageBox.show();
}

void ViewCustomerDialog::on_srchButton_clicked() {
    printSearchedCustomer(searchModelCustomerMenu, &customersDatabase, ui->tableView, ui->srchCustomerBox->text().toStdString());
    ui->srchCustomerBox->clear();
}

void ViewCustomerDialog::on_resetBtn_clicked() {
    printCustomersTable(modelCustomerMenu, &customersDatabase, ui->tableView);
    ui->srchCustomerBox->clear();
}

/* check that the user doesn't pass the limit of characters for the search box */
void ViewCustomerDialog::on_srchCustomerBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxEmailLen) { ui->srchCustomerBox->backspace(); }
}

