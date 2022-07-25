#include "mainwindow.h"

#include <QApplication>
/* temp includes */
#include "employeewindow.h"
#include "add_product_dialog.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    /* print the application path */
    qDebug() << "App path : " << qApp->applicationDirPath();

    // AddProductDialog mainWindow;
    MainWindow mainWindow;
    //EmployeeWindow mainWindow;
    mainWindow.show();
    //mainWindow.exec();

    return a.exec();
}
