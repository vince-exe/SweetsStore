/********************************************************************************
** Form generated from reading UI file 'add_product_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_PRODUCT_DIALOG_H
#define UI_ADD_PRODUCT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddProductDialog
{
public:
    QLabel *titleLabel;
    QLabel *label;
    QLineEdit *prodNameBox;
    QLabel *label_2;
    QDateEdit *dateWidget;
    QLabel *label_3;
    QLineEdit *prodNameBox_2;
    QLabel *label_4;
    QLineEdit *prodNameBox_3;
    QLabel *label_5;
    QSpinBox *spinBox;

    void setupUi(QDialog *AddProductDialog)
    {
        if (AddProductDialog->objectName().isEmpty())
            AddProductDialog->setObjectName(QString::fromUtf8("AddProductDialog"));
        AddProductDialog->resize(579, 612);
        titleLabel = new QLabel(AddProductDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(160, 20, 241, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font.setPointSize(30);
        font.setBold(true);
        titleLabel->setFont(font);
        label = new QLabel(AddProductDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 150, 221, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font1.setPointSize(20);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        prodNameBox = new QLineEdit(AddProductDialog);
        prodNameBox->setObjectName(QString::fromUtf8("prodNameBox"));
        prodNameBox->setGeometry(QRect(190, 158, 221, 41));
        prodNameBox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 16pt \"HP Simpified Jpan\";\n"
"	border: 4px solid rgb(26, 24, 24);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	background: rgb(117, 16, 60);\n"
"	color: rgb(223, 223, 223);\n"
"}"));
        label_2 = new QLabel(AddProductDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 240, 101, 51));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        dateWidget = new QDateEdit(AddProductDialog);
        dateWidget->setObjectName(QString::fromUtf8("dateWidget"));
        dateWidget->setGeometry(QRect(100, 243, 191, 51));
        dateWidget->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"	border: 4px solid rgb(26, 24, 24);   \n"
"	border-radius: 18px;\n"
"	padding-left: 10px;\n"
"	padding-top: 4px;\n"
"	padding-bottom: 4px;\n"
"	font: 700 16pt \"Roboto\";\n"
"	background: rgb(117, 16, 60);\n"
"	color: rgb(223, 223, 223);\n"
"}"));
        label_3 = new QLabel(AddProductDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 330, 91, 51));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        prodNameBox_2 = new QLineEdit(AddProductDialog);
        prodNameBox_2->setObjectName(QString::fromUtf8("prodNameBox_2"));
        prodNameBox_2->setGeometry(QRect(100, 337, 221, 41));
        prodNameBox_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 16pt \"HP Simpified Jpan\";\n"
"	border: 4px solid rgb(26, 24, 24);\n"
"	border-radius: 10px;\n"
"	padding-left: 10px;\n"
"	background: rgb(117, 16, 60);\n"
"	color: rgb(223, 223, 223);\n"
"}"));
        label_4 = new QLabel(AddProductDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 420, 81, 51));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        prodNameBox_3 = new QLineEdit(AddProductDialog);
        prodNameBox_3->setObjectName(QString::fromUtf8("prodNameBox_3"));
        prodNameBox_3->setGeometry(QRect(90, 428, 121, 41));
        prodNameBox_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 16pt \"HP Simpified Jpan\";\n"
"	border: 4px solid rgb(26, 24, 24);\n"
"	border-radius: 10px;\n"
"	padding-left: 25px;\n"
"	background: rgb(117, 16, 60);\n"
"	color: rgb(223, 223, 223);\n"
"}"));
        label_5 = new QLabel(AddProductDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 510, 131, 51));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(235, 235, 235)\n"
"}"));
        spinBox = new QSpinBox(AddProductDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(150, 510, 81, 51));

        retranslateUi(AddProductDialog);

        QMetaObject::connectSlotsByName(AddProductDialog);
    } // setupUi

    void retranslateUi(QDialog *AddProductDialog)
    {
        AddProductDialog->setWindowTitle(QCoreApplication::translate("AddProductDialog", "Dialog", nullptr));
        titleLabel->setText(QCoreApplication::translate("AddProductDialog", "Add Product", nullptr));
        label->setText(QCoreApplication::translate("AddProductDialog", "Product Name", nullptr));
        label_2->setText(QCoreApplication::translate("AddProductDialog", "Expire", nullptr));
        label_3->setText(QCoreApplication::translate("AddProductDialog", "Brand", nullptr));
        label_4->setText(QCoreApplication::translate("AddProductDialog", "Price", nullptr));
        label_5->setText(QCoreApplication::translate("AddProductDialog", "Quantity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddProductDialog: public Ui_AddProductDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_PRODUCT_DIALOG_H
