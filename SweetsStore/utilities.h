#ifndef UTILITIES_H
#define UTILITIES_H

#include <map>
#include <iostream>
#include <string>
#include <fstream>

#include "employee.h"
#include "product.h"

/* define the map that will contain all the employees */
extern std::map<std::string, Employee> employeeDatabase;

/* define the map that will contain all the products */
extern std::map<std::string, Product> productsDatabase;

/* define the current employee */
extern Employee currentEmployee;

/* save the name (key) of the selected product */
extern Product* selectedProduct;

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

#endif // UTILITIES_H
