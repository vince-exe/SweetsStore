#ifndef DATABASE_H
#define DATABASE_H

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

/* store informations in the products map */
void storeProductsInformations(FILE* f, std::map<std::string, Product>* productsDatabase);

/* store informations in the employees map */
void storeEmployeesInformations(FILE* f, std::map<std::string, Employee>* employeesDatabase);

#endif // DATABASE_H
