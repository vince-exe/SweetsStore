#include "update_customer_dialog.h"
#include "ui_update_customer_dialog.h"

#include "utilities.h"
#include "employee_utilities.h"

#include <QMessageBox>

void resetInformationsCustomer(QLineEdit *l1, QLineEdit *l2, QLineEdit *l3, QLineEdit *l4, QLineEdit *l5, QSpinBox *s1, QCheckBox *c1, QCheckBox *c2) {
    l1->setText(QString::fromStdString(selectedCustomer.getFirstName()));
    l2->setText(QString::fromStdString(selectedCustomer.getLastName()));
    l3->setText(QString::fromStdString(selectedCustomer.getEmail()));
    l4->setText(QString::fromStdString(selectedCustomer.getPassword()));
    l5->setText(QString::number(selectedCustomer.getMoney()));
    s1->setValue(selectedCustomer.getAge());

    if(selectedCustomer.getSex() == 'M') {
        c1->setChecked(true);
    }
    else {
        c2->setChecked(true);
    }
}

UpdateCustomerDialog::UpdateCustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateCustomerDialog) {
    ui->setupUi(this);

    ui->titleLabel->setAlignment(Qt::AlignCenter);
    ui->firstNameBox->setAlignment(Qt::AlignCenter);
    ui->lastNameBox->setAlignment(Qt::AlignCenter);
    ui->emailBox->setAlignment(Qt::AlignCenter);
    ui->passBox->setAlignment(Qt::AlignCenter);
    ui->salaryBox->setAlignment(Qt::AlignCenter);
    ui->ageBox->setAlignment(Qt::AlignCenter);

    resetInformationsCustomer(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
}

UpdateCustomerDialog::~UpdateCustomerDialog() {
    delete ui;
}

void UpdateCustomerDialog::on_firstNameBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxFirstNameLen) { ui->firstNameBox->backspace(); }
}

void UpdateCustomerDialog::on_lastNameBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxLastNameLen) { ui->lastNameBox->backspace(); }
}

void UpdateCustomerDialog::on_emailBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxEmailLen) { ui->emailBox->backspace(); }
}

void UpdateCustomerDialog::on_passBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxPassLen) { ui->passBox->backspace(); }
}

void UpdateCustomerDialog::on_salaryBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxSalaryLen) { ui->salaryBox->backspace(); }
}


void UpdateCustomerDialog::on_maleBox_clicked() {
    ui->femaleBox->setChecked(false);
}


void UpdateCustomerDialog::on_femaleBox_clicked() {
    ui->maleBox->setChecked(false);
}

/* save button */
void UpdateCustomerDialog::on_saveBtn_clicked() {
    if(!checkEmptyBoxes2(ui->emailBox, ui->passBox, ui->firstNameBox, ui->lastNameBox, ui->salaryBox, ui->ageBox)) {
        /* create an error QMessage Box */
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Input box can't be empty");
        messageBox.setFixedSize(550,300);

        resetInformationsCustomer(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }
    /* check if the put the @gmail.com in the email */
    if(!checkEmail(ui->emailBox->text().toStdString(), "@gmail.com")) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Email must be '@gmail.com'");
        messageBox.setFixedSize(550, 300);

        resetInformationsCustomer(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }
    /* check if the selected at least one gender */
    if(!checkCheckBox(ui->maleBox, ui->femaleBox)) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "Selected a gender please");
        messageBox.setFixedSize(550, 300);

        resetInformationsCustomer(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }
    Customer customer;
    /* set the employee */
    customer.setEmail(ui->emailBox->text().toStdString());
    customer.setPassword(ui->passBox->text().toStdString());
    customer.setFirstName(ui->firstNameBox->text().toStdString());
    customer.setLastName(ui->lastNameBox->text().toStdString());
    customer.setAge(ui->ageBox->text().toInt());
    /* set the salary */
    try {
        customer.setMoney(std::stof(ui->salaryBox->text().toStdString()));
    }
    catch(std::invalid_argument) {
        QMessageBox messageBox;
        messageBox.critical(0, "Invalid Salary", "Salary has to be a number");
        messageBox.setFixedSize(550,300);

        resetInformationsCustomer(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }
    /* set the sex */
    if(ui->maleBox->isChecked()) { customer.setSex(ui->maleBox->text().toStdString()[0]); }
    else { customer.setSex(ui->femaleBox->text().toStdString()[0]); }

    /* if he changed the email */
    if(customer.getEmail() != selectedCustomer.getEmail()) {
        /* check if there is already an employee with that email*/
        /* check if the email already exist */
        if(employeeDatabase.find(customer.getEmail()) != employeeDatabase.end() || customersDatabase.find(customer.getEmail()) != customersDatabase.end()) {
            QMessageBox messageBox;
            messageBox.warning(0, "Warning", "There is already an account with this email");
            messageBox.setFixedSize(550, 300);

            resetInformationsCustomer(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->salaryBox, ui->ageBox, ui->maleBox, ui->femaleBox);
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
    auto it = customersDatabase.find(selectedCustomer.getEmail());
    /* replace the properties */
    it->second.setFirstName(customer.getFirstName());
    it->second.setLastName(customer.getLastName());
    it->second.setSex(customer.getSex());
    it->second.setEmail(customer.getEmail());
    it->second.setPassword(customer.getPassword());
    it->second.setMoney(customer.getMoney());

    /* extract the node to modify the key */
    auto node = customersDatabase.extract(selectedCustomer.getEmail());
    /* modify the key */
    node.key() = customer.getEmail();
    /* reinsert the node in the map */
    customersDatabase.insert(std::move(node));

    /* create the success message box */
    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully updated the employee");
    messageBox.setFixedSize(550, 300);
    /* close the dialog and return */
    this->close();
    newChanges = true;
    return;
}

