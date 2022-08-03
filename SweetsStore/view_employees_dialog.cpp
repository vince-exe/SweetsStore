#include "view_employees_dialog.h"
#include "ui_view_employees_dialog.h"

#include <QTableView>
#include <QStandardItemModel>
#include <QScrollBar>
#include <QtWidgets>

#include "utilities.h"

/* forms */
#include "add_employee_dialog.h"
#include "update_employee_dialog.h"

QStandardItemModel *employeeModel = new QStandardItemModel();
QStandardItemModel *searchModelEmply = new QStandardItemModel();

/* define the String List */
QStringList horizontalHeaderEmply;
QStringList verticalHeaderEmply;

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

/* print the searched employee */
void printSearchedEmployee(QStandardItemModel *model, std::map<std::string, Employee> *employeeDatabase, QTableView *table, std::string searchedEmply) {
    /* set the model */
    searchModelEmply->setHorizontalHeaderLabels(horizontalHeaderEmply);
    searchModelEmply->setVerticalHeaderLabels(verticalHeaderEmply);

    int i = 0;
    for(auto& value : *employeeDatabase) {
        if(value.second.getFirstName() == searchedEmply || value.second.getEmail() == searchedEmply) {
            searchModelEmply->setItem(i, 0, getItem(QString::fromStdString(value.second.getFirstName())));
            searchModelEmply->setItem(i, 1, getItem(QString::fromStdString(value.second.getLastName())));
            searchModelEmply->setItem(i, 2, getItem(QChar(value.second.getSex())));
            searchModelEmply->setItem(i, 3, getItem(QString::number(value.second.getAge())));
            searchModelEmply->setItem(i, 4, getItem(QString::number(value.second.getSalary())));
            searchModelEmply->setItem(i, 5, getItem(QString::fromStdString(value.second.getEmail())));
            searchModelEmply->setItem(i, 6, getItem(QString::fromStdString(value.second.getPassword())));
        }
    }
    /* set the model to the table */
    table->setModel(searchModelEmply);
}

ViewEmployeesDialog::ViewEmployeesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewEmployeesDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 1280, 720);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    /* set the date */
    ui->timeButton->setText(QString::fromStdString(currentDateTime().c_str()));

    /* create the columns */
    horizontalHeaderEmply.append("First Name");
    horizontalHeaderEmply.append("Last Name");
    horizontalHeaderEmply.append("Sex");
    horizontalHeaderEmply.append("Age");
    horizontalHeaderEmply.append("Salary");
    horizontalHeaderEmply.append("Email");
    horizontalHeaderEmply.append("Password");
    /* set the model */
    employeeModel->setHorizontalHeaderLabels(horizontalHeaderEmply);
    employeeModel->setVerticalHeaderLabels(verticalHeaderEmply);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->verticalHeader()->setDefaultSectionSize(59);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(145);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    /* print the table */
    printEmployeesTable(employeeModel, &employeeDatabase, ui->tableView);
}

ViewEmployeesDialog::~ViewEmployeesDialog() {
    horizontalHeaderEmply.clear();
    verticalHeaderEmply.clear();
    delete ui;
}

void ViewEmployeesDialog::on_srchEmplyBox_textChanged(const QString &arg1) {

}

void ViewEmployeesDialog::on_infoBtn_clicked() {
    QMessageBox messageBox;
    messageBox.information(0, "Info", "To update / remove an employee, select with a double-click the employee row, and then use the buttons");
    messageBox.setFixedSize(550, 300);
}

/* add an employee to the employee database ( not in the employees file ) */
void ViewEmployeesDialog::on_addProdBtn_4_clicked() {
    AddEmployeeDialog addEmployeeWindow;
    addEmployeeWindow.setModal(true);
    addEmployeeWindow.show();
    addEmployeeWindow.exec();

    /* print the employees table */
    printEmployeesTable(employeeModel, &employeeDatabase, ui->tableView);
}

void ViewEmployeesDialog::on_saveBtn_clicked() {
    /* check if there aren't new changes to save */
    if(!newChanges) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "There aren't new changes to save");
        messageBox.setFixedSize(550, 300);
        return;
    }

    /* open the file in reading mode to check if exist */
    FILE* file = fopen("files/employees.txt", "r");

    if(!file) {
        QMessageBox messageBox;
        messageBox.critical(0, "Fatal Error", "The application failed to save the changes");
        messageBox.setFixedSize(550,300);

        exit(-1);
    }
    fclose(file);

    /* open it in write mode */
    file = fopen("files/employees.txt", "w");
    /* store the informations in the file */
    storeEmployeesInformations(file, &employeeDatabase);
    /* close the employees file */
    fclose(file);
    /* reset the new changes variable */
    newChanges = false;

    QMessageBox messageBox;
    messageBox.information(0, "Success", "The application has successfully saved the changes");
    messageBox.setFixedSize(550,300);
    messageBox.show();
}

/* save the selected employee */
void ViewEmployeesDialog::on_tableView_activated(const QModelIndex &index) {
    selectedEmployeCheck = true;

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
    selectedEmployee.setFirstName(firstName.toStdString());
    selectedEmployee.setLastName(lastName.toStdString());
    selectedEmployee.setSex(sex.toStdString()[0]);
    selectedEmployee.setAge(age);
    selectedEmployee.setSalary(salary);
    selectedEmployee.setEmail(email.toStdString());
    selectedEmployee.setPassword(password.toStdString());
}

/* update an employee */
void ViewEmployeesDialog::on_updtBtn_clicked() {
    if(!selectedEmployeCheck) { return; }

    UpdateEmployeeDialog UpdateEmployeeWindow;
    UpdateEmployeeWindow.setModal(true);
    UpdateEmployeeWindow.show();
    UpdateEmployeeWindow.exec();

    selectedEmployeCheck = false;
    printEmployeesTable(employeeModel, &employeeDatabase, ui->tableView);
}

/* remove an employee from the database */
void ViewEmployeesDialog::on_rmEmplyBtn_clicked() {
    /* if no row has been clicked, return */
    if(!selectedEmployeCheck) { return; }

    /* if he wants to remove him self */
    if(selectedEmployee.getEmail() == currentEmployee.getEmail()) {
        QMessageBox messageBox;
        messageBox.warning(0, "Waring", "You can't delete yourself");
        messageBox.setFixedSize(550, 300);
        return;
    }

    QMessageBox confirmBox;
    confirmBox.setText(tr("The application will proceed with deleting the employee, are you sure you want to continue?"));
    confirmBox.addButton(tr("Yes"), QMessageBox::YesRole);
    QAbstractButton* noBtn = confirmBox.addButton(tr("No"), QMessageBox::NoRole);
    /* show the message box */
    confirmBox.exec();
    /* if the user doesn't want to delete the employee, close */
    if(confirmBox.clickedButton() == noBtn) { return; }

    /* erase the selected element from the map */
    employeeDatabase.erase(selectedEmployee.getEmail());
    /* print the success message box */
    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully removed the employee");
    messageBox.setFixedSize(550, 300);
    messageBox.show();

    /* get the index of the selected row */
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    /* use the model to remove the row */
    employeeModel->removeRow(index.row(), index.parent());

    newChanges = true;
    selectedEmployeCheck = false;

    /* reprint the table */
    printEmployeesTable(employeeModel, &employeeDatabase, ui->tableView);
}

/* reprint the table */
void ViewEmployeesDialog::on_resetBtn_clicked() {
    printEmployeesTable(employeeModel, &employeeDatabase, ui->tableView);
    ui->srchEmplyBox->clear();
}

/* search an employee */
void ViewEmployeesDialog::on_srchButton_clicked() {
    if(!ui->srchEmplyBox->text().length()) {
        printEmployeesTable(employeeModel, &employeeDatabase, ui->tableView);
        ui->srchEmplyBox->clear();
        return;
    }
    /* print the searched emply */
    printSearchedEmployee(searchModelEmply, &employeeDatabase, ui->tableView, ui->srchEmplyBox->text().toStdString());
    ui->srchEmplyBox->clear();
}
