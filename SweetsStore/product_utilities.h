#ifndef PRODUCT_UTILITIES_H
#define PRODUCT_UTILITIES_H

#include <QLineEdit>
#include <QSpinBox>
#include <QDateEdit>

const int prodNameLen = 20;
const int brandLen = 20;
const int PriceLen = 10;

/* clear the widgets */
void clearInputFields(QLineEdit* f1, QLineEdit* f2, QLineEdit* f3, QSpinBox* f4, QDateEdit* f5);

#endif // PRODUCT_UTILITIES_H
