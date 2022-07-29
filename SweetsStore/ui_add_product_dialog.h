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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddProductDialog
{
public:
    QLabel *titleLabel;
    QLineEdit *prodNameBox;
    QDateEdit *dateWidget;
    QLineEdit *brandBox;
    QLineEdit *priceBox;
    QSpinBox *qntyBox;
    QLabel *label_6;
    QPushButton *saveButton;

    void setupUi(QDialog *AddProductDialog)
    {
        if (AddProductDialog->objectName().isEmpty())
            AddProductDialog->setObjectName(QString::fromUtf8("AddProductDialog"));
        AddProductDialog->resize(579, 612);
        AddProductDialog->setAutoFillBackground(false);
        AddProductDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: rgb(102, 16, 53);\n"
"}\n"
""));
        titleLabel = new QLabel(AddProductDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(160, 20, 241, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font.setPointSize(30);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: '#ebebeb';\n"
" background: '#75103c';\n"
" color: '#e8e8e8';\n"
" border: 4px solid '#1a1818';\n"
" border-radius: 15px;\n"
"}\n"
"\n"
"QLabel::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));
        prodNameBox = new QLineEdit(AddProductDialog);
        prodNameBox->setObjectName(QString::fromUtf8("prodNameBox"));
        prodNameBox->setGeometry(QRect(120, 140, 311, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HP Simpified Jpan")});
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        prodNameBox->setFont(font1);
        prodNameBox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 16pt \"HP Simpified Jpan\";\n"
"	border: 4px solid rgb(26, 24, 24);\n"
"	border-radius: 10px;\n"
"	background: rgb(117, 16, 60);\n"
"	color: rgb(209, 209, 209);\n"
"}"));
        dateWidget = new QDateEdit(AddProductDialog);
        dateWidget->setObjectName(QString::fromUtf8("dateWidget"));
        dateWidget->setGeometry(QRect(180, 230, 191, 51));
        dateWidget->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"	border: 4px solid rgb(26, 24, 24);   \n"
"	border-radius: 18px;\n"
"	padding-left: 10px;\n"
"	padding-top: 4px;\n"
"	padding-bottom: 4px;\n"
"	font: 700 16pt \"Roboto\";\n"
"	background: rgb(117, 16, 60);\n"
"	color: rgb(209, 209, 209);\n"
"}"));
        brandBox = new QLineEdit(AddProductDialog);
        brandBox->setObjectName(QString::fromUtf8("brandBox"));
        brandBox->setGeometry(QRect(120, 320, 311, 51));
        brandBox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 16pt \"HP Simpified Jpan\";\n"
"	border: 4px solid rgb(26, 24, 24);\n"
"	border-radius: 10px;\n"
"	background: rgb(117, 16, 60);\n"
"	color: rgb(209, 209, 209);\n"
"}"));
        priceBox = new QLineEdit(AddProductDialog);
        priceBox->setObjectName(QString::fromUtf8("priceBox"));
        priceBox->setGeometry(QRect(190, 390, 171, 61));
        priceBox->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	font: 16pt \"HP Simpified Jpan\";\n"
"	border: 4px solid rgb(26, 24, 24);\n"
"	background: rgb(117, 16, 60);\n"
"	color: rgb(209, 209, 209);\n"
"}"));
        qntyBox = new QSpinBox(AddProductDialog);
        qntyBox->setObjectName(QString::fromUtf8("qntyBox"));
        qntyBox->setGeometry(QRect(214, 480, 131, 61));
        qntyBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"	border: 4px solid rgb(26, 24, 24);   \n"
"	padding-left: 50px;\n"
"	padding-top: 4px;\n"
"	padding-bottom: 4px;\n"
"	font: 700 16pt \"Roboto\";\n"
"	background: rgb(117, 16, 60);\n"
"	color: rgb(209, 209, 209);\n"
"}"));
        label_6 = new QLabel(AddProductDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 580, 251, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font2.setPointSize(15);
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"color: rgb(209, 209, 209);\n"
"}"));
        saveButton = new QPushButton(AddProductDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(400, 550, 161, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font3.setPointSize(16);
        font3.setBold(true);
        saveButton->setFont(font3);
        saveButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: '#75103c';\n"
"color: rgb(209, 209, 209);\n"
"border: 4px solid '#1a1818';\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: rgb(84, 13, 43);\n"
"}"));

        retranslateUi(AddProductDialog);

        QMetaObject::connectSlotsByName(AddProductDialog);
    } // setupUi

    void retranslateUi(QDialog *AddProductDialog)
    {
        AddProductDialog->setWindowTitle(QCoreApplication::translate("AddProductDialog", "Dialog", nullptr));
        titleLabel->setText(QCoreApplication::translate("AddProductDialog", "Add Product", nullptr));
        prodNameBox->setPlaceholderText(QCoreApplication::translate("AddProductDialog", "Product Name", nullptr));
        brandBox->setPlaceholderText(QCoreApplication::translate("AddProductDialog", "Brand Name", nullptr));
        priceBox->setPlaceholderText(QCoreApplication::translate("AddProductDialog", "Price", nullptr));
        label_6->setText(QCoreApplication::translate("AddProductDialog", "Save your informations", nullptr));
        saveButton->setText(QCoreApplication::translate("AddProductDialog", "Save | Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddProductDialog: public Ui_AddProductDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_PRODUCT_DIALOG_H
