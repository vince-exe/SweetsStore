#include "mainwindow.h"

#include <QApplication>
/* temp includes */
#include "employeewindow.h"
#include "view_products_dialog.h"
#include "update_product_dialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    /* print the application path */
    qDebug() << "App path : " << qApp->applicationDirPath();

    //ViewProductsDialog mainWindow;
    MainWindow mainWindow;
    //EmployeeWindow mainWindow;
    //UpdateProductDialog mainWindow;

    mainWindow.show();
    //mainWindow.exec();

    return a.exec();
}
