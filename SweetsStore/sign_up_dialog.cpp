#include "sign_up_dialog.h"
#include "ui_sign_up_dialog.h"

#include <QMessageBox>

#include "main_window_utilities.h"
#include "employee_utilities.h"

#include "utilities.h"
#include "customer.h"

#include <iostream>

void clearBoxes(QLineEdit* l1, QLineEdit* l2, QLineEdit* l3, QLineEdit* l4, QLineEdit* l5, QSpinBox* s1, QCheckBox* c1, QCheckBox* c2) {
    l1->clear();
    l2->clear();
    l3->clear();
    l4->clear();
    l5->clear();
    s1->clear();
    c1->setChecked(false);
    c2->setChecked(false);
}

SignUpDialog::SignUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpDialog) {
    ui->setupUi(this);

    /* align the items */
    ui->titleLabel->setAlignment(Qt::AlignCenter);
    ui->emailBox->setAlignment(Qt::AlignCenter);
    ui->passBox->setAlignment(Qt::AlignCenter);
    ui->firstNameBox->setAlignment(Qt::AlignCenter);
    ui->lastNameBox->setAlignment(Qt::AlignCenter);
    ui->moneyBox->setAlignment(Qt::AlignCenter);
}

SignUpDialog::~SignUpDialog() {
    delete ui;
}

void SignUpDialog::on_firstNameBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxFirstNameLen) { ui->firstNameBox->backspace(); }
}

void SignUpDialog::on_lastNameBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxLastNameLen) { ui->lastNameBox->backspace(); }
}

void SignUpDialog::on_emailBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxEmailLen) { ui->emailBox->backspace(); }
}

void SignUpDialog::on_passBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxPassLen) { ui->passBox->backspace(); }
}

void SignUpDialog::on_moneyBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxSalaryLen) { ui->moneyBox->backspace(); }
}

void SignUpDialog::on_femaleBox_clicked() {
    ui->maleBox->setChecked(false);
}

void SignUpDialog::on_maleBox_clicked() {
    ui->femaleBox->setChecked(false);
}

/* when i press the button to Sign Up */
void SignUpDialog::on_signUpBtn_clicked() {

    std::string email = ui->emailBox->text().toStdString();
    std::string password = ui->passBox->text().toStdString();

    if(!checkEmail(email, "@gmail.com")) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "Email has to be '@gmail.com'");
        messageBox.setFixedSize(550, 300);

        clearBoxes(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->moneyBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }
    if(!checkPassowrd(password)) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "Password has to be at least 8 characters");
        messageBox.setFixedSize(550, 300);

        clearBoxes(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->moneyBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }

    float money;
    try {
        money = std::stof(ui->moneyBox->text().toStdString());
    }
    catch(std::invalid_argument) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "Insert a valid amount of money");
        messageBox.setFixedSize(550, 300);

        clearBoxes(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->moneyBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }

    /* check if the email already exist */
    if(employeeDatabase.find(email) != employeeDatabase.end() || customersDatabase.find(email) != customersDatabase.end()) {
        QMessageBox messageBox;
        messageBox.warning(0, "Warning", "There is already an account with this email");
        messageBox.setFixedSize(550, 300);

        clearBoxes(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->moneyBox, ui->ageBox, ui->maleBox, ui->femaleBox);
        return;
    }

    std::string firstName = ui->firstNameBox->text().toStdString();
    std::string lastName = ui->lastNameBox->text().toStdString();
    char sex;
    if(ui->maleBox->isChecked()) { sex = 'M'; } else { sex = 'F'; }
    int age = ui->ageBox->value();

    FILE* f = fopen("files/customers.txt", "w");
    /* insert the information inside the database */
    customersDatabase.insert(std::pair<std::string, Customer>(email, Customer(firstName, lastName, sex, age, money, email, password)));
    /* store the informations in the customers file */
    storeCustomersInformations(f, &customersDatabase);
    fclose(f);

    QMessageBox messageBox;
    messageBox.information(0, "Success", "Successfully registrated, to use the application close this window and login");
    messageBox.setFixedSize(550, 300);

    clearBoxes(ui->firstNameBox, ui->lastNameBox, ui->emailBox, ui->passBox, ui->moneyBox, ui->ageBox, ui->maleBox, ui->femaleBox);
    return;
}

