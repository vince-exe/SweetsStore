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

QT_BEGIN_NAMESPACE

class Ui_AboutMeDialog
{
public:
    QLabel *titleLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *sexLabel;
    QLabel *ageLabel;
    QLabel *salaryLabel;
    QLabel *emailLabel;
    QLabel *passwordLabel;

    void setupUi(QDialog *AboutMeDialog)
    {
        if (AboutMeDialog->objectName().isEmpty())
            AboutMeDialog->setObjectName(QString::fromUtf8("AboutMeDialog"));
        AboutMeDialog->resize(589, 574);
        titleLabel = new QLabel(AboutMeDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(210, 10, 201, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font.setPointSize(28);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        label = new QLabel(AboutMeDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 90, 211, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font1.setPointSize(25);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        label_2 = new QLabel(AboutMeDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 160, 211, 71));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        label_3 = new QLabel(AboutMeDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 220, 81, 71));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        label_4 = new QLabel(AboutMeDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 280, 81, 71));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        label_5 = new QLabel(AboutMeDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 340, 131, 71));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        label_6 = new QLabel(AboutMeDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 400, 121, 71));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        label_7 = new QLabel(AboutMeDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 460, 211, 71));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        label_8 = new QLabel(AboutMeDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(320, 540, 431, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font2.setPointSize(14);
        font2.setBold(true);
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(191, 191, 191)\n"
"}"));
        firstNameLabel = new QLabel(AboutMeDialog);
        firstNameLabel->setObjectName(QString::fromUtf8("firstNameLabel"));
        firstNameLabel->setGeometry(QRect(220, 90, 311, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font3.setPointSize(16);
        firstNameLabel->setFont(font3);
        firstNameLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        lastNameLabel = new QLabel(AboutMeDialog);
        lastNameLabel->setObjectName(QString::fromUtf8("lastNameLabel"));
        lastNameLabel->setGeometry(QRect(210, 160, 311, 71));
        lastNameLabel->setFont(font3);
        lastNameLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        sexLabel = new QLabel(AboutMeDialog);
        sexLabel->setObjectName(QString::fromUtf8("sexLabel"));
        sexLabel->setGeometry(QRect(130, 220, 31, 71));
        sexLabel->setFont(font3);
        sexLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        ageLabel = new QLabel(AboutMeDialog);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));
        ageLabel->setGeometry(QRect(110, 280, 131, 71));
        ageLabel->setFont(font3);
        ageLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        salaryLabel = new QLabel(AboutMeDialog);
        salaryLabel->setObjectName(QString::fromUtf8("salaryLabel"));
        salaryLabel->setGeometry(QRect(160, 340, 401, 71));
        salaryLabel->setFont(font3);
        salaryLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235);\n"
"}"));
        emailLabel = new QLabel(AboutMeDialog);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));
        emailLabel->setGeometry(QRect(140, 400, 211, 71));
        emailLabel->setFont(font3);
        emailLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        passwordLabel = new QLabel(AboutMeDialog);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(200, 460, 211, 71));
        passwordLabel->setFont(font3);
        passwordLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));

        retranslateUi(AboutMeDialog);

        QMetaObject::connectSlotsByName(AboutMeDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutMeDialog)
    {
        AboutMeDialog->setWindowTitle(QCoreApplication::translate("AboutMeDialog", "Dialog", nullptr));
        titleLabel->setText(QCoreApplication::translate("AboutMeDialog", "About You", nullptr));
        label->setText(QCoreApplication::translate("AboutMeDialog", "First Name: ", nullptr));
        label_2->setText(QCoreApplication::translate("AboutMeDialog", "Last Name:", nullptr));
        label_3->setText(QCoreApplication::translate("AboutMeDialog", "Sex:", nullptr));
        label_4->setText(QCoreApplication::translate("AboutMeDialog", "Age:", nullptr));
        label_5->setText(QCoreApplication::translate("AboutMeDialog", "Salary:", nullptr));
        label_6->setText(QCoreApplication::translate("AboutMeDialog", "Email:", nullptr));
        label_7->setText(QCoreApplication::translate("AboutMeDialog", "Password:", nullptr));
        label_8->setText(QCoreApplication::translate("AboutMeDialog", "Keep your informations private.", nullptr));
        firstNameLabel->setText(QString());
        lastNameLabel->setText(QString());
        sexLabel->setText(QString());
        ageLabel->setText(QString());
        salaryLabel->setText(QString());
        emailLabel->setText(QString());
        passwordLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutMeDialog: public Ui_AboutMeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTMEDIALOG_H
