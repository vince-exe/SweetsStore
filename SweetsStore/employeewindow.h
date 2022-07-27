#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#include <QMainWindow>

#include "about_me_dialog.h"

/* get the current date */
const std::string currentDateTime();

namespace Ui {
class EmployeeWindow;
}

class EmployeeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeWindow(QWidget *parent = nullptr);
    ~EmployeeWindow();

private slots:

    void on_infoButton_clicked();

    void on_addProdBtn_clicked();

    void on_rmProdBtn_clicked();

    void on_srcProdBtn_clicked();

    void on_modProdBtn_clicked();

    void on_addEmplyBtn_clicked();

    void on_rmEmplyBtn_clicked();

    void on_srchEmplyBtn_clicked();

    void on_modEmplyBtn_clicked();

    void on_addCstmrBtn_clicked();

    void on_rmvCstmrBtn_clicked();

    void on_srcCstmrBtn_clicked();

    void on_modCstmrBtn_clicked();

    void on_addProdBtn_2_clicked();

private:
    Ui::EmployeeWindow *ui;
    AboutMeDialog* aboutMeWindow;
};

#endif // EMPLOYEEWINDOW_H
