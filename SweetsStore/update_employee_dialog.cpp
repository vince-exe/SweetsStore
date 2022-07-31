#include "update_employee_dialog.h"
#include "ui_update_employee_dialog.h"

#include "utilities.h"

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

    ui->firstNameBox->setText(QString::fromStdString(selectedEmployee.getFirstName()));
    ui->lastNameBox->setText(QString::fromStdString(selectedEmployee.getLastName()));
    ui->emailBox->setText(QString::fromStdString(selectedEmployee.getEmail()));
    ui->passBox->setText(QString::fromStdString(selectedEmployee.getPassword()));
    ui->salaryBox->setText(QString::number(selectedEmployee.getSalary()));
    ui->ageBox->setValue(selectedEmployee.getAge());

    if(selectedEmployee.getSex() == 'M') {
        ui->maleBox->setChecked(true);
    }
    else {
        ui->femaleBox->setChecked(true);
    }
}

UpdateEmployeeDialog::~UpdateEmployeeDialog() {
    delete ui;
}
