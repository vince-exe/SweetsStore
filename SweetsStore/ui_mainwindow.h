/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QTextEdit *emailTextBox;
    QTextEdit *passTextBox;
    QLabel *citationLabel;
    QPushButton *signInButton;
    QPushButton *signUpButton;
    QLabel *copyrightLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(995, 631);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(370, 0, 511, 121));
        QFont font;
        font.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font.setPointSize(56);
        font.setBold(false);
        titleLabel->setFont(font);
        titleLabel->setScaledContents(false);
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setWordWrap(false);
        emailTextBox = new QTextEdit(centralwidget);
        emailTextBox->setObjectName(QString::fromUtf8("emailTextBox"));
        emailTextBox->setGeometry(QRect(130, 270, 400, 52));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Mono")});
        font1.setPointSize(18);
        font1.setBold(true);
        emailTextBox->setFont(font1);
        emailTextBox->setAcceptDrops(false);
        emailTextBox->setAutoFillBackground(false);
        emailTextBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        emailTextBox->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        emailTextBox->setCursorWidth(1);
        passTextBox = new QTextEdit(centralwidget);
        passTextBox->setObjectName(QString::fromUtf8("passTextBox"));
        passTextBox->setGeometry(QRect(740, 270, 400, 52));
        passTextBox->setFont(font1);
        passTextBox->setAcceptDrops(false);
        passTextBox->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        passTextBox->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        citationLabel = new QLabel(centralwidget);
        citationLabel->setObjectName(QString::fromUtf8("citationLabel"));
        citationLabel->setGeometry(QRect(330, 400, 721, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font2.setPointSize(20);
        font2.setBold(true);
        citationLabel->setFont(font2);
        signInButton = new QPushButton(centralwidget);
        signInButton->setObjectName(QString::fromUtf8("signInButton"));
        signInButton->setGeometry(QRect(300, 500, 191, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Source Code Pro")});
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(false);
        signInButton->setFont(font3);
        signInButton->setCursor(QCursor(Qt::ArrowCursor));
        signInButton->setStyleSheet(QString::fromUtf8(""));
        signInButton->setAutoRepeatInterval(200);
        signUpButton = new QPushButton(centralwidget);
        signUpButton->setObjectName(QString::fromUtf8("signUpButton"));
        signUpButton->setGeometry(QRect(770, 500, 191, 71));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Source Code Pro")});
        font4.setPointSize(18);
        font4.setBold(true);
        signUpButton->setFont(font4);
        copyrightLabel = new QLabel(centralwidget);
        copyrightLabel->setObjectName(QString::fromUtf8("copyrightLabel"));
        copyrightLabel->setGeometry(QRect(40, 685, 471, 15));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font5.setPointSize(10);
        font5.setBold(true);
        copyrightLabel->setFont(font5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 995, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Sweets   Store", nullptr));
        emailTextBox->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Cascadia Mono'; font-size:18pt; font-weight:700; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        emailTextBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "youremail@gmail.com", nullptr));
        passTextBox->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Cascadia Mono'; font-size:18pt; font-weight:700; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        passTextBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "*********", nullptr));
        citationLabel->setText(QCoreApplication::translate("MainWindow", "\" Everything is better with a donut in the mounth \"", nullptr));
        signInButton->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
        signUpButton->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        copyrightLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
