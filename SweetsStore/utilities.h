#ifndef UTILITIES_H
#define UTILITIES_H

#include <map>
#include <iostream>
#include <string>
#include <fstream>

#include <QDateEdit>
#include <QSpinBox>
#include <QStandardItem>

#include "employee.h"
#include "product.h"

/* define the map that will contain all the employees */
extern std::map<std::string, Employee> employeeDatabase;

/* define the map that will contain all the products */
extern std::map<std::string, Product> productsDatabase;

/* define the current employee */
extern Employee currentEmployee;

/* save the name (key) of the selected product */
extern Product selectedProduct;
/* check if a row has been clicked */
extern bool selectedProductCheck;

/* read informations in the products map */
void readProductsInformations(FILE* f, std::map<std::string, Product>* productsDatabase);

/* read informations in the employees map */
void readEmployeesInformations(FILE* f, std::map<std::string, Employee>* employeesDatabase);

/* store the informations in the products map */
void storeProductInformations(FILE* f, std::map<std::string, Product>* productsDatabase);

/* defining a variable that check if there are new changes in the application */
extern bool newChanges;

/* transform a string into a lower string */
std::string lowerStr(std::string string);

/* get the current date */
const std::string currentDateTime();

/* check the current date */
bool checkDate(QDateEdit *dateEdit);

/* check if the input boxes are empties */
bool checkEmptiesBox(QLineEdit *firstInput, QLineEdit *secondInput, QLineEdit *thirdInput, QSpinBox *spinBox);

/* clear the widgets */
void clearInputFields(QLineEdit* f1, QLineEdit* f2, QLineEdit* f3, QSpinBox* f4, QDateEdit* f5);

/* return an item with the text aligned */
QStandardItem* getItem(QString string);

#endif // UTILITIES_H
