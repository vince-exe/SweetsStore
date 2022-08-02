#ifndef EMPLOYEE_UTILITIES_H
#define EMPLOYEE_UTILITIES_H

#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>

/* limits */
const int maxFirstNameLen = 15;
const int maxLastNameLen = 15;
const int maxEmailLen = 45;
const int maxPassLen = 20;
const int maxSalaryLen = 10;

bool checkEmptyBoxes2(QLineEdit *f1, QLineEdit *f2, QLineEdit *f3, QLineEdit *f4, QLineEdit *f5, QSpinBox *s1);

void clearBoxesEmployee(QLineEdit* f1, QLineEdit* f2, QLineEdit* f3, QLineEdit* f4, QLineEdit* f5, QSpinBox* s1, QCheckBox* c1, QCheckBox* c2);

bool checkCheckBox(QCheckBox* c1, QCheckBox* c2);

#endif // EMPLOYEE_UTILITIES_H
