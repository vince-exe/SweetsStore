#ifndef MAINWINDOWUTILITIES_H
#define MAINWINDOWUTILITIES_H

#include <iostream>
#include <string>
#include <map>

#include "employee.h"

/* load the employees file */
bool loadEmployeesFile(const char *filePath, std::map<std::string, Employee>* employeeDatabase);

/* check the credentials for the SignIn */
bool checkSignInEmployee(std::string email, std::string password, std::map<std::string, Employee>* employeeDatabase);

/* check the email */
bool checkEmail(std::string email);

/* check the password */
bool checkPassowrd(std::string password);

/* check the credentials */
bool checkCredentials(std::string email, std::string password);

#endif // MAINWINDOWUTILITIES_H
