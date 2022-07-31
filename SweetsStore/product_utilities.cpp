#include "product_utilities.h"

#include <QLineEdit>
#include <QSpinBox>
#include <QDateEdit>

void clearInputFields(QLineEdit *f1, QLineEdit *f2, QLineEdit *f3, QSpinBox *f4, QDateEdit *f5) {
    /* clear the widgets */
    f1->clear();
    f2->clear();
    f3->clear();
    f4->clear();

    f5->setDate(QDate::currentDate());
}
