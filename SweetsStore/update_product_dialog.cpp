#include "update_product_dialog.h"
#include "ui_update_product_dialog.h"

/* global variables */
const int prodNameLen = 20;
const int brandLen = 20;
const int PriceLen = 4;

UpdateProductDialog::UpdateProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateProductDialog)
{
    ui->setupUi(this);
    /* set the window */
    this->setGeometry(100, 100, 580, 615);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    /* set the current date */
    ui->dateWidget->setDate(QDate::currentDate());
    ui->dateWidget->setAlignment(Qt::AlignCenter);
    /* modify the input boxes */
    ui->prodNameBox->setAlignment(Qt::AlignCenter);
    ui->brandBox->setAlignment(Qt::AlignCenter);
    ui->priceBox->setAlignment(Qt::AlignCenter);
}

UpdateProductDialog::~UpdateProductDialog() {
    delete ui;
}

void UpdateProductDialog::on_prodNameBox_textChanged(const QString &arg1) {
    /* check if the user is passing the limit of characters */
    if(arg1.toStdString().length() > prodNameLen) { ui->prodNameBox->backspace(); }
}


void UpdateProductDialog::on_brandBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > brandLen) { ui->brandBox->backspace(); }
}


void UpdateProductDialog::on_priceBox_textChanged(const QString &arg1) {
    if(arg1.toStdString().length() > PriceLen) { ui->priceBox->backspace(); }
}

