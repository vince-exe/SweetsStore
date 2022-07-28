#include "about_me_dialog.h"
#include "ui_aboutmedialog.h"

#include "utilities.h"

AboutMeDialog::AboutMeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutMeDialog) {
    ui->setupUi(this);
    /* window */
    this->setGeometry(100, 100, 451, 567);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* set First Name */
    ui->firstNameBtn->setText(QString::fromUtf8(currentEmployee.getFirstName().c_str()));
    /* set Last Name */
    ui->lastNameBtn->setText(QString::fromUtf8(currentEmployee.getLastName().c_str()));
    /* set Sex */
    ui->sexBtn->setText(QString(QChar::fromLatin1(currentEmployee.getSex())).toUpper());
    /* set Age */
    ui->ageBtn->setText(QString::number(currentEmployee.getAge()));
    /* set Salary */
    ui->salaryBtn->setText(QString::number(currentEmployee.getSalary()));
    /* set Email */
    ui->emailBtn->setText(QString::fromUtf8(currentEmployee.getEmail().c_str()));
    /* set Password */
    ui->passwordBtn->setText(QString::fromUtf8(currentEmployee.getPassword().c_str()));
}

AboutMeDialog::~AboutMeDialog() {
    delete ui;
}
