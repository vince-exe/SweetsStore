#include "add_employee_dialog.h"
#include "ui_add_employee_dialog.h"

/* limits */
const int maxFirstNameLen = 15;
const int maxLastNameLen = 15;
const int maxEmailLen = 45;
const int maxPassLen = 20;
const int maxSalaryLen = 10;

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

void AddEmployeeDialog::on_salaryBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > maxSalaryLen) { ui->salaryBox->backspace(); }
}

