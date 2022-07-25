#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include "employee.h"

/* define the map that will contain all the employees */
extern std::map<std::string, Employee> employeeDatabase;

/* define the current employee */
extern Employee currentEmployee;

#endif // DATABASE_H
