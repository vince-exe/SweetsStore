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
#include <QtWidgets/QLabel>
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
    QLabel *infoLabel;
    QLabel *titleLabel;
    QPushButton *infoButton;
    QLabel *dateLabel;
    QPushButton *addProdBtn;
    QPushButton *rmProdBtn;
    QPushButton *srcProdBtn;
    QPushButton *modProdBtn;
    QPushButton *addEmplyBtn;
    QPushButton *rmEmplyBtn;
    QPushButton *srchEmplyBtn;
    QPushButton *modEmplyBtn;
    QPushButton *addCstmrBtn;
    QPushButton *rmvCstmrBtn;
    QPushButton *srcCstmrBtn;
    QPushButton *modCstmrBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EmployeeWindow)
    {
        if (EmployeeWindow->objectName().isEmpty())
            EmployeeWindow->setObjectName(QString::fromUtf8("EmployeeWindow"));
        EmployeeWindow->resize(1280, 720);
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
        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setGeometry(QRect(15, 670, 501, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font1.setPointSize(22);
        font1.setBold(true);
        infoLabel->setFont(font1);
        infoLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: #ebebeb;\n"
"}"));
        infoLabel->setTextFormat(Qt::PlainText);
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(490, 10, 381, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font2.setPointSize(40);
        font2.setBold(true);
        titleLabel->setFont(font2);
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: '#ebebeb';\n"
"}"));
        infoButton = new QPushButton(centralwidget);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));
        infoButton->setGeometry(QRect(40, 30, 81, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font3.setPointSize(20);
        font3.setBold(true);
        infoButton->setFont(font3);
        infoButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"text-align: center; \n"
"background: '#661035'; \n"
"border: 3px solid '#1a1818';\n"
"color: rgb(209, 209, 209);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"border: 4px solid '#000000';\n"
"}"));
        dateLabel = new QLabel(centralwidget);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setGeometry(QRect(900, 20, 371, 71));
        dateLabel->setFont(font1);
        dateLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QLabel::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}\n"
""));
        addProdBtn = new QPushButton(centralwidget);
        addProdBtn->setObjectName(QString::fromUtf8("addProdBtn"));
        addProdBtn->setGeometry(QRect(90, 200, 231, 61));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font4.setPointSize(16);
        font4.setBold(true);
        addProdBtn->setFont(font4);
        addProdBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        rmProdBtn = new QPushButton(centralwidget);
        rmProdBtn->setObjectName(QString::fromUtf8("rmProdBtn"));
        rmProdBtn->setGeometry(QRect(380, 200, 231, 61));
        rmProdBtn->setFont(font4);
        rmProdBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        srcProdBtn = new QPushButton(centralwidget);
        srcProdBtn->setObjectName(QString::fromUtf8("srcProdBtn"));
        srcProdBtn->setGeometry(QRect(670, 200, 231, 61));
        srcProdBtn->setFont(font4);
        srcProdBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        modProdBtn = new QPushButton(centralwidget);
        modProdBtn->setObjectName(QString::fromUtf8("modProdBtn"));
        modProdBtn->setGeometry(QRect(960, 200, 231, 61));
        modProdBtn->setFont(font4);
        modProdBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        addEmplyBtn = new QPushButton(centralwidget);
        addEmplyBtn->setObjectName(QString::fromUtf8("addEmplyBtn"));
        addEmplyBtn->setGeometry(QRect(90, 360, 231, 61));
        addEmplyBtn->setFont(font4);
        addEmplyBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        rmEmplyBtn = new QPushButton(centralwidget);
        rmEmplyBtn->setObjectName(QString::fromUtf8("rmEmplyBtn"));
        rmEmplyBtn->setGeometry(QRect(380, 360, 231, 61));
        rmEmplyBtn->setFont(font4);
        rmEmplyBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        srchEmplyBtn = new QPushButton(centralwidget);
        srchEmplyBtn->setObjectName(QString::fromUtf8("srchEmplyBtn"));
        srchEmplyBtn->setGeometry(QRect(670, 360, 231, 61));
        srchEmplyBtn->setFont(font4);
        srchEmplyBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        modEmplyBtn = new QPushButton(centralwidget);
        modEmplyBtn->setObjectName(QString::fromUtf8("modEmplyBtn"));
        modEmplyBtn->setGeometry(QRect(960, 360, 231, 61));
        modEmplyBtn->setFont(font4);
        modEmplyBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        addCstmrBtn = new QPushButton(centralwidget);
        addCstmrBtn->setObjectName(QString::fromUtf8("addCstmrBtn"));
        addCstmrBtn->setGeometry(QRect(90, 520, 231, 61));
        addCstmrBtn->setFont(font4);
        addCstmrBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        rmvCstmrBtn = new QPushButton(centralwidget);
        rmvCstmrBtn->setObjectName(QString::fromUtf8("rmvCstmrBtn"));
        rmvCstmrBtn->setGeometry(QRect(380, 520, 231, 61));
        rmvCstmrBtn->setFont(font4);
        rmvCstmrBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        srcCstmrBtn = new QPushButton(centralwidget);
        srcCstmrBtn->setObjectName(QString::fromUtf8("srcCstmrBtn"));
        srcCstmrBtn->setGeometry(QRect(670, 520, 231, 61));
        srcCstmrBtn->setFont(font4);
        srcCstmrBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        modCstmrBtn = new QPushButton(centralwidget);
        modCstmrBtn->setObjectName(QString::fromUtf8("modCstmrBtn"));
        modCstmrBtn->setGeometry(QRect(960, 520, 231, 61));
        modCstmrBtn->setFont(font4);
        modCstmrBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        EmployeeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EmployeeWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 25));
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
        infoLabel->setText(QString());
        titleLabel->setText(QCoreApplication::translate("EmployeeWindow", "Sweets Store", nullptr));
        infoButton->setText(QCoreApplication::translate("EmployeeWindow", "Me", nullptr));
        dateLabel->setText(QString());
        addProdBtn->setText(QCoreApplication::translate("EmployeeWindow", "Add Product", nullptr));
        rmProdBtn->setText(QCoreApplication::translate("EmployeeWindow", "Remove Product", nullptr));
        srcProdBtn->setText(QCoreApplication::translate("EmployeeWindow", "Search Product", nullptr));
        modProdBtn->setText(QCoreApplication::translate("EmployeeWindow", "Modify Product", nullptr));
        addEmplyBtn->setText(QCoreApplication::translate("EmployeeWindow", "Add Employee", nullptr));
        rmEmplyBtn->setText(QCoreApplication::translate("EmployeeWindow", "Remove Employee", nullptr));
        srchEmplyBtn->setText(QCoreApplication::translate("EmployeeWindow", "Search Employee", nullptr));
        modEmplyBtn->setText(QCoreApplication::translate("EmployeeWindow", "Modify Employee", nullptr));
        addCstmrBtn->setText(QCoreApplication::translate("EmployeeWindow", "Add Customer", nullptr));
        rmvCstmrBtn->setText(QCoreApplication::translate("EmployeeWindow", "Remove Customer", nullptr));
        srcCstmrBtn->setText(QCoreApplication::translate("EmployeeWindow", "Search Customer", nullptr));
        modCstmrBtn->setText(QCoreApplication::translate("EmployeeWindow", "Modify Customer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeWindow: public Ui_EmployeeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEWINDOW_H
