#include "about_me_dialog.h"
#include "ui_aboutmedialog.h"

#include "utilities.h"
#include "person.h"
#include "customer.h"
#include "employee.h"

AboutMeDialog::AboutMeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutMeDialog) {
    ui->setupUi(this);
    /* window */
    this->setGeometry(100, 100, 451, 567);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* create a person pointer */
    Person* p;
    if(loggedInAsCustomer) { p = &currentCustomer; } else { p = &currentEmployee; }

    /* set First Name */
    ui->firstNameBtn->setText(QString::fromUtf8(p->getFirstName().c_str()));
    /* set Last Name */
    ui->lastNameBtn->setText(QString::fromUtf8(p->getLastName().c_str()));
    /* set Sex */
    ui->sexBtn->setText(QString(QChar::fromLatin1(p->getSex())).toUpper());
    /* set Age */
    ui->ageBtn->setText(QString::number(p->getAge()));

    if(loggedInAsCustomer) {
        /* set the money */
        ui->salaryBtn->setText(QString::number(currentCustomer.getMoney()));
        /* set Email */
        ui->emailBtn->setText(QString::fromUtf8(currentCustomer.getEmail().c_str()));
        /* set Password */
        ui->passwordBtn->setText(QString::fromUtf8(currentCustomer.getPassword().c_str()));
    }
    else {
        /* set Salary */
        ui->salaryBtn->setText(QString::number(currentEmployee.getSalary()));
        /* set Email */
        ui->emailBtn->setText(QString::fromUtf8(currentEmployee.getEmail().c_str()));
        /* set Password */
        ui->passwordBtn->setText(QString::fromUtf8(currentEmployee.getPassword().c_str()));
    }
}

AboutMeDialog::~AboutMeDialog() {
    delete ui;
}
