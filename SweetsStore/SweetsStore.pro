QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

UI_DIR = $$PWD

SOURCES += \
    about_me_dialog.cpp \
    add_employee_dialog.cpp \
    add_money_dialog.cpp \
    add_product_dialog.cpp \
    customer.cpp \
    customer_menu_dialog.cpp \
    employee.cpp \
    employee_utilities.cpp \
    employeewindow.cpp \
    main.cpp \
    main_window_utilities.cpp \
    mainwindow.cpp \
    person.cpp \
    product.cpp \
    product_utilities.cpp \
    sign_up_dialog.cpp \
    update_employee_dialog.cpp \
    update_product_dialog.cpp \
    utilities.cpp \
    view_employees_dialog.cpp \
    view_products_dialog.cpp

HEADERS += \
    about_me_dialog.h \
    add_employee_dialog.h \
    add_money_dialog.h \
    add_product_dialog.h \
    customer.h \
    customer_menu_dialog.h \
    employee.h \
    employee_utilities.h \
    employeewindow.h \
    main_window_utilities.h \
    mainwindow.h \
    person.h \
    product.h \
    product_utilities.h \
    sign_up_dialog.h \
    update_employee_dialog.h \
    update_product_dialog.h \
    utilities.h \
    view_employees_dialog.h \
    view_products_dialog.h

FORMS += \
    aboutmedialog.ui \
    add_employee_dialog.ui \
    add_money_dialog.ui \
    add_product_dialog.ui \
    customer_menu_dialog.ui \
    employeewindow.ui \
    mainwindow.ui \
    sign_up_dialog.ui \
    update_employee_dialog.ui \
    update_product_dialog.ui \
    view_employees_dialog.ui \
    viewproductsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
