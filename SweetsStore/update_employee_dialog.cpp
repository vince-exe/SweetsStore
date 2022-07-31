#include "update_employee_dialog.h"
#include "ui_update_employee_dialog.h"

#include <QMessageBox>

#include "utilities.h"
#include "employee_utilities.h"

void resetInformations(QLineEdit* l1, QLineEdit* l2, QLineEdit* l3, QLineEdit* l4, QLineEdit* l5, QSpinBox* s1, QCheckBox* c1, QCheckBox* c2) {
    l1->setText(QString::fromStdString(selectedEmployee.getFirstName()));
    l2->setText(QString::fromStdString(selectedEmployee.getLastName()));
    l3->setText(QString::fromStdString(selectedEmployee.getEmail()));
    l4->setText(QString::fromStdString(selectedEmployee.getPassword()));
    l5->setText(QString::number(selectedEmployee.getSalary()));
    s1->setValue(selectedEmployee.getAge());

    if(selectedEmployee.getSex() == 'M') {
        c1->setChecked(true);
    }
    else {
        c2->setChecked(true);
    }
}

UpdateEmployeeDialog::UpdateEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateEmployeeDialog) {
    ui->setupUi(this);

    ui->firstNameBox->setAlignment(Qt::AlignCenter);
    ui->lastNameBox->setAlignment(Qt::AlignCenter);
    ui->emailBox->setAlignment(Qt::AlignCenter);
    ui->passBox->setAlignment(Qt::AlignCenter);
    ui->salaryBox->setAlignment(Qt::AlignCenter);
    ui->ageBox->setAlignment(Qt::AlignCenter);

    resetInformations(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
}

UpdateEmployeeDialog::~UpdateEmployeeDialog() {
    delete ui;
}

/* Male box clicked */
void UpdateEmployeeDialog::on_maleBox_clicked() {
    ui->femaleBox->setChecked(false);
}

/* female box clicked */
void UpdateEmployeeDialog::on_femaleBox_clicked() {
    ui->maleBox->setChecked(false);
}

void UpdateEmployeeDialog::on_lastNameBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxLastNameLen) { ui->lastNameBox->backspace(); }
}


void UpdateEmployeeDialog::on_firstNameBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxFirstNameLen) { ui->firstNameBox->backspace(); }
}


void UpdateEmployeeDialog::on_passBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxPassLen) { ui->passBox->backspace(); }
}


void UpdateEmployeeDialog::on_emailBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxEmailLen) { ui->emailBox->backspace(); }
}


void UpdateEmployeeDialog::on_salaryBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxSalaryLen) { ui->salaryBox->backspace(); }
}

/* save button */
void UpdateEmployeeDialog::on_saveBtn_clicked() {
    if(!checkEmptyBoxes2(ui->emailBox, ui->passBox, ui->firstNameBox, ui->lastNameBox, ui->salaryBox, ui->ageBox)) {
        /* create an error QMessage Box */
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Input box can't be empty");
        messageBox.setFixedSize(550,300);

        resetInformations(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }
    /* check if the put the @gmail.com in the email */
    if(!checkEmail(ui->emailBox->text().toStdString(), "@gmail.com")) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Email must be '@gmail.com'");
        messageBox.setFixedSize(550, 300);

        resetInformations(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
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

        resetInformations(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }
    /* set the sex */
    if(ui->maleBox->isChecked()) { employee.setSex(ui->maleBox->text().toStdString()[0]); }
    else { employee.setSex(ui->femaleBox->text().toStdString()[0]); }

    /* if he changed the email */
    if(employee.getEmail() != selectedEmployee.getEmail()) {
        /* check if there is already an employee with that email*/
        if(employeeDatabase.find(employee.getEmail()) != employeeDatabase.end()) {
            QMessageBox messageBox;
            messageBox.warning(0, "Warning", "There is already an employee with the selected email");
            messageBox.setFixedSize(550, 300);

            resetInformations(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
            return;
        }
    }

    /* check if he wants to save the chages or exit without saving */
    QMessageBox confirmBox;
    confirmBox.setText(tr("The application will proceed with updating the employee, are you sure you want to continue?"));
    confirmBox.addButton(tr("Yes"), QMessageBox::YesRole);
    QAbstractButton* noBtn = confirmBox.addButton(tr("No"), QMessageBox::YesRole);
    /* show the message box */
    confirmBox.exec();
    /* if the user doesn't want to save the employee, close */
    if(confirmBox.clickedButton() == noBtn) { this->close(); return; }

    /* get the employee */
    auto it = employeeDatabase.find(selectedEmployee.getEmail());
    /* replace the properties */
    it->second.setFirstName(employee.getFirstName());
    it->second.setLastName(employee.getLastName());
    it->second.setSex(employee.getSex());
    it->second.setEmail(employee.getEmail());
    it->second.setPassword(employee.getPassword());
    it->second.setSalary(employee.getSalary());

    /* extract the node to modify the key */
    auto node = employeeDatabase.extract(selectedEmployee.getEmail());
    /* modify the key */
    node.key() = employee.getEmail();
    /* reinsert the node in the map */
    employeeDatabase.insert(std::move(node));

    /* create the success message box */
    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully updated the employee");
    messageBox.setFixedSize(550, 300);
    /* close the dialog and return */
    this->close();
    newChanges = true;
    return;
}

