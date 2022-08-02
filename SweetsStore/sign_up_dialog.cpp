#include "sign_up_dialog.h"
#include "ui_sign_up_dialog.h"

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
