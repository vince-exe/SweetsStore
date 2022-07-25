#include "info_window.h"
#include "ui_info_window.h"

InfoWindow::InfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfoWindow) {
    ui->setupUi(this);

    this->setGeometry(100, 50, 1300, 730);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    QPalette backgroundPalette;
    backgroundPalette.setColor(QPalette::Window, "#661035");
}

InfoWindow::~InfoWindow()
{
    delete ui;
}
