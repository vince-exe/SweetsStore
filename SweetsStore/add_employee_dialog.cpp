#include "add_employee_dialog.h"
#include "ui_add_employee_dialog.h"

#include <QLineEdit>
#include <QSpinBox>
#include <QMessageBox>

#include "utilities.h"
#include "employee.h"
#include "employee_utilities.h"

AddEmployeeDialog::AddEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployeeDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 618, 612);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* align the input boxes */
    ui->firstNameBox->setAlignment(Qt::AlignCenter);
    ui->lastNameBox->setAlignment(Qt::AlignCenter);
    ui->passBox->setAlignment(Qt::AlignCenter);
    ui->emailBox->setAlignment(Qt::AlignCenter);
    ui->salaryBox->setAlignment(Qt::AlignCenter);
    ui->ageBox->setAlignment(Qt::AlignCenter);
}

AddEmployeeDialog::~AddEmployeeDialog() {
    delete ui;
}

/* check if he is passing the max len for the First Name */
void AddEmployeeDialog::on_firstNameBox_textChanged(const QString &arg1) {
     if(arg1.toStdString().length() > maxFirstNameLen) { ui->firstNameBox->backspace(); }
}

/* check if he is passing the len for the Last Name */
void AddEmployeeDialog::on_lastNameBox_textChanged(const QString &arg1) {
     if(arg1.toStdString().length() > maxLastNameLen) { ui->lastNameBox->backspace(); }
}

/* check if he is passing the len for the Email */
void AddEmployeeDialog::on_emailBox_textChanged(const QString &arg1) {
     if(arg1.toStdString().length() > maxEmailLen) { ui->emailBox->backspace(); }
}

/* check if he is passing the len for the Password */
void AddEmployeeDialog::on_passBox_textChanged(const QString &arg1) {
     if(arg1.toStdString().length() > maxPassLen) { ui->passBox->backspace(); }
}

/* check if he is passing the len for the Salary */
void AddEmployeeDialog::on_salaryBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxSalaryLen) { ui->salaryBox->backspace(); }
}

/* save the employee */
void AddEmployeeDialog::on_saveBtn_clicked() {
    if(!checkEmptyBoxes2(ui->emailBox, ui->passBox, ui->firstNameBox, ui->lastNameBox, ui->salaryBox, ui->ageBox)) {
        /* create an error QMessage Box */
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Input box can't be empty");
        messageBox.setFixedSize(550,300);

        clearBoxesEmployee(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }
    /* check if the put the @gmail.com in the email */
    if(!checkEmail(ui->emailBox->text().toStdString(), "@gmail.com")) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Email must be '@gmail.com'");
        messageBox.setFixedSize(550, 300);

        clearBoxesEmployee(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }
    Employee employee;
    /* set the employee */
    employee.setEmail(ui->emailBox->text().toStdString());
    employee.setPassword(ui->passBox->text().toStdString());
    employee.setFirstName(ui->firstNameBox->text().toStdString());
    employee.setLastName(ui->lastNameBox->text().toStdString());
    employee.setAge(ui->ageBox->text().toInt());
    /* set the salary */
    try {
        employee.setSalary(std::stof(ui->salaryBox->text().toStdString()));
    }
    catch(std::invalid_argument) {
        QMessageBox messageBox;
        messageBox.critical(0, "Invalid Salary", "Salary has to be a number");
        messageBox.setFixedSize(550,300);

        clearBoxesEmployee(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }
    /* set the sex */
    if(ui->maleBox->isChecked()) { employee.setSex(ui->maleBox->text().toStdString()[0]); }
    else { employee.setSex(ui->femaleBox->text().toStdString()[0]); }

    /* check if there is already an employee */
    if(employeeDatabase.find(employee.getEmail()) != employeeDatabase.end()) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "There is already an employee with the selected email");
        messageBox.setFixedSize(550, 300);

        clearBoxesEmployee(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }

    /* check if he wants to save the chages or exit without saving */
    QMessageBox confirmBox;
    confirmBox.setText(tr("The application will proceed with saving the employee, are you sure you want to continue?"));
    confirmBox.addButton(tr("Yes"), QMessageBox::YesRole);
    QAbstractButton* noBtn = confirmBox.addButton(tr("No"), QMessageBox::YesRole);
    /* show the message box */
    confirmBox.exec();
    /* if the user doesn't want to save the product, close */
    if(confirmBox.clickedButton() == noBtn) { this->close(); return; }

    /* insert the employee inside the database */
    employeeDatabase.insert(std::pair<std::string, Employee>(employee.getEmail(), employee));
    newChanges = true;

    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully added the employee");
    messageBox.setFixedSize(550,300);

    clearBoxesEmployee(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);

}

/* female box clicked */
void AddEmployeeDialog::on_femaleBox_clicked() {
    ui->maleBox->setChecked(false);
}

/* male box clicked */
void AddEmployeeDialog::on_maleBox_clicked() {
    ui->femaleBox->setChecked(false);
}

