#include "about_me_dialog.h"
#include "ui_aboutmedialog.h"

#include "database.h"

AboutMeDialog::AboutMeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutMeDialog) {
    ui->setupUi(this);
    /* window */
    this->setGeometry(100, 100, 589, 574);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* set First Name */
    ui->firstNameLabel->setText(QString::fromUtf8(currentEmployee.getFirstName().c_str()));
    /* set Last Name */
    ui->lastNameLabel->setText(QString::fromUtf8(currentEmployee.getLastName().c_str()));
    /* set Sex */
    ui->sexLabel->setText(QString(QChar::fromLatin1(currentEmployee.getSex())).toUpper());
    /* set Age */
    ui->ageLabel->setText(QString::number(currentEmployee.getAge()));
    /* set Salary */
    ui->salaryLabel->setText(QString::number(currentEmployee.getSalary()));
    /* set Email */
    ui->emailLabel->setText(QString::fromUtf8(currentEmployee.getEmail().c_str()));
    /* set Password */
    ui->passwordLabel->setText(QString::fromUtf8(currentEmployee.getPassword().c_str()));
}

AboutMeDialog::~AboutMeDialog() {
    delete ui;
}
