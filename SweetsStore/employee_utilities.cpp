 #include "employee_utilities.h"

#include <iostream>

#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>

/* check if the boxes are empty */
bool checkEmptyBoxes2(QLineEdit *f1, QLineEdit *f2, QLineEdit *f3, QLineEdit *f4, QLineEdit *f5, QSpinBox *s1) {
    if(!f1->text().length() || !f2->text().length() || !f3->text().length() || !f4->text().length() || !f5->text().length()) {
        return false;
    }

    if(s1->text() == "0") { return false; }

    return true;
}

/* clear the given boxes */
void clearBoxesEmployee(QLineEdit* f1, QLineEdit* f2, QLineEdit* f3, QLineEdit* f4, QLineEdit* f5, QSpinBox* s1, QCheckBox* c1, QCheckBox* c2) {
    f1->clear();
    f2->clear();
    f3->clear();
    f4->clear();
    f5->clear();
    s1->setValue(0);
    c1->setCheckState(Qt::CheckState::Unchecked);
    c2->setCheckState(Qt::CheckState::Unchecked);
}
