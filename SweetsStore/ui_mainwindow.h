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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *citationLabel;
    QPushButton *signInButton;
    QPushButton *signUpButton;
    QLabel *copyrightLabel;
    QLabel *imageLabel_2;
    QLabel *imageLabel_4;
    QLineEdit *emailBox;
    QLineEdit *passBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(519, 514);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: rgb(102, 16, 53);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(60, 20, 401, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font.setPointSize(30);
        font.setBold(false);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"background-color: rgb(102, 16, 53);\n"
"color: rgb(209, 209, 209);\n"
"border: 5px solid '#000000';\n"
"border-radius: 16px;\n"
"padding-bottom: 4px;\n"
"}\n"
"\n"
"QLabel::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        titleLabel->setScaledContents(false);
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setWordWrap(false);
        citationLabel = new QLabel(centralwidget);
        citationLabel->setObjectName(QString::fromUtf8("citationLabel"));
        citationLabel->setGeometry(QRect(20, 120, 481, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font1.setPointSize(14);
        font1.setBold(false);
        citationLabel->setFont(font1);
        citationLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(209, 209, 209);\n"
"}"));
        signInButton = new QPushButton(centralwidget);
        signInButton->setObjectName(QString::fromUtf8("signInButton"));
        signInButton->setGeometry(QRect(70, 380, 161, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Source Code Pro")});
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setItalic(false);
        signInButton->setFont(font2);
        signInButton->setCursor(QCursor(Qt::ArrowCursor));
        signInButton->setAutoFillBackground(false);
        signInButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#661035'; \n"
"color: rgb(209, 209, 209);\n"
" border: 4px solid '#000000';\n"
" border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background-color: rgb(84, 13, 43);\n"
"}"));
        signInButton->setAutoRepeatInterval(200);
        signUpButton = new QPushButton(centralwidget);
        signUpButton->setObjectName(QString::fromUtf8("signUpButton"));
        signUpButton->setGeometry(QRect(280, 380, 161, 61));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Source Code Pro")});
        font3.setPointSize(18);
        font3.setBold(true);
        signUpButton->setFont(font3);
        signUpButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#661035';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#000000';\n"
" border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background-color: rgb(84, 13, 43);\n"
"}"));
        signUpButton->setAutoRepeatInterval(200);
        copyrightLabel = new QLabel(centralwidget);
        copyrightLabel->setObjectName(QString::fromUtf8("copyrightLabel"));
        copyrightLabel->setGeometry(QRect(40, 685, 471, 15));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font4.setPointSize(10);
        font4.setBold(true);
        copyrightLabel->setFont(font4);
        copyrightLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(219, 219, 219);\n"
"}\n"
""));
        imageLabel_2 = new QLabel(centralwidget);
        imageLabel_2->setObjectName(QString::fromUtf8("imageLabel_2"));
        imageLabel_2->setGeometry(QRect(1000, 30, 231, 151));
        imageLabel_4 = new QLabel(centralwidget);
        imageLabel_4->setObjectName(QString::fromUtf8("imageLabel_4"));
        imageLabel_4->setGeometry(QRect(1040, 540, 231, 151));
        emailBox = new QLineEdit(centralwidget);
        emailBox->setObjectName(QString::fromUtf8("emailBox"));
        emailBox->setGeometry(QRect(60, 190, 401, 51));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Cascadia Mono")});
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setItalic(false);
        emailBox->setFont(font5);
        emailBox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: 3px solid '#000000';\n"
" text-align: center;\n"
" border-radius:10px;\n"
" padding-top: 5px;\n"
" background: '#661035';\n"
"color: rgb(209, 209, 209);\n"
"}\n"
"\n"
"QLineEdit::hover {\n"
"border: 4px solid '#000000';\n"
"}\n"
"\n"
"QLineEdit::focus {\n"
"border: 4px solid '#000000';\n"
"}"));
        emailBox->setAlignment(Qt::AlignCenter);
        passBox = new QLineEdit(centralwidget);
        passBox->setObjectName(QString::fromUtf8("passBox"));
        passBox->setGeometry(QRect(60, 280, 401, 51));
        passBox->setFont(font5);
        passBox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: 3px solid '#000000';\n"
" text-align: center;\n"
" border-radius:10px;\n"
" padding-top: 5px;\n"
" background: '#661035';\n"
"color: rgb(209, 209, 209);\n"
"}\n"
"\n"
"QLineEdit::hover {\n"
"border: 4px solid '#000000';\n"
"}\n"
"\n"
"QLineEdit::focus {\n"
"border: 4px solid '#000000';\n"
"}"));
        passBox->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        passBox->setEchoMode(QLineEdit::Password);
        passBox->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 519, 25));
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
        citationLabel->setText(QCoreApplication::translate("MainWindow", "\" Everything is better with a donut in the mounth \"", nullptr));
        signInButton->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
        signUpButton->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        copyrightLabel->setText(QCoreApplication::translate("MainWindow", "Copyright \302\251 2022 vince-exe. All rights reserved", nullptr));
        imageLabel_2->setText(QString());
        imageLabel_4->setText(QString());
        emailBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "youremail@gmail.com", nullptr));
        passBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "************", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
