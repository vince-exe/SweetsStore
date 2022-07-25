#include "add_product_dialog.h"
#include "ui_add_product_dialog.h"

const int maxStrLen = 15;

AddProductDialog::AddProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProductDialog) {
    ui->setupUi(this);

    this->setGeometry(100, 100, 580, 615);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    /* background*/
    QPalette backgroundPalette;
    backgroundPalette.setColor(QPalette::Window, "#661035");

    this->setAutoFillBackground(true);
    this->setPalette(backgroundPalette);

    /* title label */
    ui->titleLabel->setStyleSheet("color: '#ebebeb'; background: '#75103c';  color: '#e8e8e8'; border: 4px solid '#1a1818'; border-radius: 15px;");
}

AddProductDialog::~AddProductDialog() {
    delete ui;
}
