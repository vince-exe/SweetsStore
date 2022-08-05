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
#include "customer.h"
#include "order.h"

/* define the map that will contain all the employees */
extern std::map<std::string, Employee> employeeDatabase;

/* define the map that will contain all the products */
extern std::map<std::string, Product> productsDatabase;

/* define a map that will contain all the customers */
extern std::map<std::string, Customer> customersDatabase;

/* define the map that will contain all the customers orders */
extern std::map<int, Order> ordersDatabase;

/* define the current employee */
extern Employee currentEmployee;

/* define the current customer */
extern Customer currentCustomer;

/* save the email ( key ) of the selected employee */
extern Employee selectedEmployee;

/* check if a row has been cliced ( employee ) */
extern bool selectedEmployeCheck;

/* save the name (key) of the selected product */
extern Product selectedProduct;

/* check if a row has been clicked */
extern bool selectedProductCheck;

/* take care of see if the user logged as customer */
extern bool loggedInAsCustomer;

/* keep trace of the selected order */
extern Order selectedOrder;

extern bool selectedOrderCheck;

/* read informations in the products file */
void readProductsInformations(FILE* f, std::map<std::string, Product>* productsDatabase);

/* read informations in the employees file */
void readEmployeesInformations(FILE* f, std::map<std::string, Employee>* employeesDatabase);

/* read informations in the customers file */
void readCustomersInformations(FILE* f, std::map<std::string, Customer>* customersDatabase);

/* read the informations in the orders file */
void readOrdersInformations(FILE* f, std::map<int, Order>* ordersDatabase);

/* store the informations in the products file */
void storeProductInformations(FILE* f, std::map<std::string, Product>* productsDatabase);

/* store the informations in the employees file */
void storeEmployeesInformations(FILE* f, std::map<std::string, Employee>* employeesDatabase);

/* store the informations of the customers */
void storeCustomersInformations(FILE *f, std::map<std::string, Customer> *customersDatabase);

/* store the informations of the orders */
void storeOrdersInformations(FILE* f, std::map<int, Order>* ordersDatabase);

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

/* check the email */
bool checkEmail(std::string email, const char* check);

/* return an item with the text aligned */
QStandardItem* getItem(QString string);

#endif // UTILITIES_H
