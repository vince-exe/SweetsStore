/********************************************************************************
** Form generated from reading UI file 'employeewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEWINDOW_H
#define UI_EMPLOYEEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeWindow
{
public:
    QWidget *centralwidget;
    QPushButton *infoButton;
    QPushButton *prodMenuBtn;
    QPushButton *srcProdBtn_2;
    QPushButton *srcProdBtn_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EmployeeWindow)
    {
        if (EmployeeWindow->objectName().isEmpty())
            EmployeeWindow->setObjectName(QString::fromUtf8("EmployeeWindow"));
        EmployeeWindow->resize(590, 640);
        QFont font;
        font.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font.setPointSize(16);
        EmployeeWindow->setFont(font);
        EmployeeWindow->setAutoFillBackground(false);
        EmployeeWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: rgb(102, 16, 53);\n"
"}"));
        centralwidget = new QWidget(EmployeeWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color: rgb(102, 16, 53);\n"
"}"));
        infoButton = new QPushButton(centralwidget);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));
        infoButton->setGeometry(QRect(480, 550, 91, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font1.setPointSize(20);
        font1.setBold(true);
        infoButton->setFont(font1);
        infoButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"text-align: center; \n"
"background: '#75103c';\n"
"border: 4px solid '#1a1818';\n"
"color: rgb(209, 209, 209);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        prodMenuBtn = new QPushButton(centralwidget);
        prodMenuBtn->setObjectName(QString::fromUtf8("prodMenuBtn"));
        prodMenuBtn->setGeometry(QRect(140, 160, 301, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        font2.setPointSize(20);
        font2.setBold(true);
        prodMenuBtn->setFont(font2);
        prodMenuBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        srcProdBtn_2 = new QPushButton(centralwidget);
        srcProdBtn_2->setObjectName(QString::fromUtf8("srcProdBtn_2"));
        srcProdBtn_2->setGeometry(QRect(140, 300, 301, 81));
        srcProdBtn_2->setFont(font2);
        srcProdBtn_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        srcProdBtn_3 = new QPushButton(centralwidget);
        srcProdBtn_3->setObjectName(QString::fromUtf8("srcProdBtn_3"));
        srcProdBtn_3->setGeometry(QRect(140, 440, 301, 81));
        srcProdBtn_3->setFont(font2);
        srcProdBtn_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"letter-spacing: 1px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 20, 381, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font3.setPointSize(35);
        font3.setBold(true);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: '#ebebeb';\n"
"border: 4px solid '#1a1818';\n"
"border-radius: 15px;\n"
"letter-spacing: 1px;\n"
"}"));
        EmployeeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EmployeeWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 590, 25));
        EmployeeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EmployeeWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EmployeeWindow->setStatusBar(statusbar);

        retranslateUi(EmployeeWindow);

        QMetaObject::connectSlotsByName(EmployeeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EmployeeWindow)
    {
        EmployeeWindow->setWindowTitle(QCoreApplication::translate("EmployeeWindow", "MainWindow", nullptr));
        infoButton->setText(QCoreApplication::translate("EmployeeWindow", "Me", nullptr));
        prodMenuBtn->setText(QCoreApplication::translate("EmployeeWindow", "Products Menu", nullptr));
        srcProdBtn_2->setText(QCoreApplication::translate("EmployeeWindow", "Employees Menu", nullptr));
        srcProdBtn_3->setText(QCoreApplication::translate("EmployeeWindow", "Customers Menu", nullptr));
        pushButton->setText(QCoreApplication::translate("EmployeeWindow", "Sweets Store", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeWindow: public Ui_EmployeeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEWINDOW_H
