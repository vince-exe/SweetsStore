#include "mainwindow.h"

#include <QApplication>
#include "employeewindow.h"
#include "add_product_dialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    //MainWindow mainWindow;
    //EmployeeWindow mainWindow;
    AddProductDialog mainWindow;
    mainWindow.show();
     mainWindow.exec();
    //return a.exec();
}
