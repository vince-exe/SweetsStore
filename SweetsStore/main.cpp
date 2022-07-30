#include "mainwindow.h"

#include <QApplication>
/* temp includes */
#include "view_employees_dialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    /* print the application path */
    qDebug() << "App path : " << qApp->applicationDirPath();

    MainWindow mainWindow;
    //ViewEmployeesDialog mainWindow;

    mainWindow.show();
    //mainWindow.exec();

    return a.exec();
}
