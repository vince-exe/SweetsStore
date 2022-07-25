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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddProductDialog
{
public:
    QLabel *titleLabel;
    QLineEdit *lineEdit;

    void setupUi(QDialog *AddProductDialog)
    {
        if (AddProductDialog->objectName().isEmpty())
            AddProductDialog->setObjectName(QString::fromUtf8("AddProductDialog"));
        AddProductDialog->resize(579, 612);
        titleLabel = new QLabel(AddProductDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(170, 20, 241, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font.setPointSize(30);
        font.setBold(true);
        titleLabel->setFont(font);
        lineEdit = new QLineEdit(AddProductDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 160, 240, 40));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 2px solid rgb(37, 39, 48);\n"
"	border-radius: 20px;\n"
"	color: #FFF;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"	background-color: rgb(34, 36, 44);\n"
"}"));

        retranslateUi(AddProductDialog);

        QMetaObject::connectSlotsByName(AddProductDialog);
    } // setupUi

    void retranslateUi(QDialog *AddProductDialog)
    {
        AddProductDialog->setWindowTitle(QCoreApplication::translate("AddProductDialog", "Dialog", nullptr));
        titleLabel->setText(QCoreApplication::translate("AddProductDialog", "Add Product", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("AddProductDialog", "Product Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddProductDialog: public Ui_AddProductDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_PRODUCT_DIALOG_H
