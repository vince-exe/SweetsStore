/********************************************************************************
** Form generated from reading UI file 'aboutmedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTMEDIALOG_H
#define UI_ABOUTMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutMeDialog
{
public:
    QLabel *label_8;
    QPushButton *firstNameBtn;
    QPushButton *lastNameBtn;
    QPushButton *sexBtn;
    QPushButton *ageBtn;
    QPushButton *salaryBtn;
    QPushButton *emailBtn;
    QPushButton *passwordBtn;

    void setupUi(QDialog *AboutMeDialog)
    {
        if (AboutMeDialog->objectName().isEmpty())
            AboutMeDialog->setObjectName(QString::fromUtf8("AboutMeDialog"));
        AboutMeDialog->resize(451, 567);
        AboutMeDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: rgb(102, 16, 53);\n"
"}"));
        label_8 = new QLabel(AboutMeDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(180, 530, 431, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font.setPointSize(14);
        font.setBold(true);
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(191, 191, 191)\n"
"}"));
        firstNameBtn = new QPushButton(AboutMeDialog);
        firstNameBtn->setObjectName(QString::fromUtf8("firstNameBtn"));
        firstNameBtn->setGeometry(QRect(70, 40, 301, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        font1.setPointSize(17);
        font1.setBold(true);
        firstNameBtn->setFont(font1);
        firstNameBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(84, 13, 43);\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"letter-spacing: 1px;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        lastNameBtn = new QPushButton(AboutMeDialog);
        lastNameBtn->setObjectName(QString::fromUtf8("lastNameBtn"));
        lastNameBtn->setGeometry(QRect(70, 140, 301, 61));
        lastNameBtn->setFont(font1);
        lastNameBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(84, 13, 43);\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"letter-spacing: 1px;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        sexBtn = new QPushButton(AboutMeDialog);
        sexBtn->setObjectName(QString::fromUtf8("sexBtn"));
        sexBtn->setGeometry(QRect(160, 240, 121, 61));
        sexBtn->setFont(font1);
        sexBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(84, 13, 43);\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"letter-spacing: 1px;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        ageBtn = new QPushButton(AboutMeDialog);
        ageBtn->setObjectName(QString::fromUtf8("ageBtn"));
        ageBtn->setGeometry(QRect(20, 240, 121, 61));
        ageBtn->setFont(font1);
        ageBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(84, 13, 43);\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"letter-spacing: 1px;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        salaryBtn = new QPushButton(AboutMeDialog);
        salaryBtn->setObjectName(QString::fromUtf8("salaryBtn"));
        salaryBtn->setGeometry(QRect(310, 240, 121, 61));
        salaryBtn->setFont(font1);
        salaryBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(84, 13, 43);\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"letter-spacing: 1px;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        emailBtn = new QPushButton(AboutMeDialog);
        emailBtn->setObjectName(QString::fromUtf8("emailBtn"));
        emailBtn->setGeometry(QRect(70, 340, 301, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft PhagsPa")});
        font2.setPointSize(10);
        font2.setBold(true);
        emailBtn->setFont(font2);
        emailBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(84, 13, 43);\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"letter-spacing: 1px;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        passwordBtn = new QPushButton(AboutMeDialog);
        passwordBtn->setObjectName(QString::fromUtf8("passwordBtn"));
        passwordBtn->setGeometry(QRect(70, 440, 301, 61));
        passwordBtn->setFont(font1);
        passwordBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(84, 13, 43);\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"letter-spacing: 1px;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));

        retranslateUi(AboutMeDialog);

        QMetaObject::connectSlotsByName(AboutMeDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutMeDialog)
    {
        AboutMeDialog->setWindowTitle(QCoreApplication::translate("AboutMeDialog", "Dialog", nullptr));
        label_8->setText(QCoreApplication::translate("AboutMeDialog", "Keep your informations private.", nullptr));
        firstNameBtn->setText(QString());
        lastNameBtn->setText(QString());
        sexBtn->setText(QString());
        ageBtn->setText(QString());
        salaryBtn->setText(QString());
        emailBtn->setText(QString());
        passwordBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutMeDialog: public Ui_AboutMeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTMEDIALOG_H
