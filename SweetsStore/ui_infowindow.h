/********************************************************************************
** Form generated from reading UI file 'infowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWINDOW_H
#define UI_INFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InfoWindow)
    {
        if (InfoWindow->objectName().isEmpty())
            InfoWindow->setObjectName(QString::fromUtf8("InfoWindow"));
        InfoWindow->resize(720, 600);
        QFont font;
        font.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font.setPointSize(28);
        InfoWindow->setFont(font);
        centralwidget = new QWidget(InfoWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 0, 221, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HP Simplified Jpan")});
        font1.setPointSize(28);
        font1.setBold(true);
        label->setFont(font1);
        InfoWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(InfoWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 720, 52));
        InfoWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(InfoWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        InfoWindow->setStatusBar(statusbar);

        retranslateUi(InfoWindow);

        QMetaObject::connectSlotsByName(InfoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InfoWindow)
    {
        InfoWindow->setWindowTitle(QCoreApplication::translate("InfoWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("InfoWindow", "About You", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWindow: public Ui_InfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
