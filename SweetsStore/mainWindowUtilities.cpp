#include "mainWindowUtilities.h"

#include <iostream>
#include <string>
#include <map>
#include <fstream>

#include "employee.h"
#include "database.h"

bool checkSignInEmployee(std::string email, std::string password, std::map<std::string, Employee>* employeeDatabase) {
    /* get the key */
    auto key = employeeDatabase->find(email);
    /* if the key doesn't exist */
    if(key == employeeDatabase->end()) { return false; }

    /* check if the password is correct */
    if(key->second.getPassword() == password) {
        /* fill the current employee variable */
        currentEmployee = key->second;

        return true;
    }

    return false;
}

bool loadEmployeesFile(const char *filePath, std::map<std::string, Employee>* employeeDatabase) {
    /* open the employees file in reading mod */
    std::fstream file(filePath, std::fstream::in);

    /* check if the program failed to load the file */
    if(!file) { return false; }

    /* create the employee object */
    Employee employee;
    /* create the temp buffer */
    std::string tmpBuffer;

    while(file.good()) {
        /* First Name */
        getline(file, tmpBuffer);
        employee.setFirstName(tmpBuffer);
        /* Last Name */
        getline(file, tmpBuffer);
        employee.setLastName(tmpBuffer);
        /* Sex */
        getline(file, tmpBuffer);
        employee.setSex(tmpBuffer[0]);
        /* Age */
        getline(file, tmpBuffer);
        employee.setAge(std::stoi(tmpBuffer));
        /* Salary */
        getline(file, tmpBuffer);
        employee.setSalary(std::stof(tmpBuffer));
        /* Email */
        getline(file, tmpBuffer);
        employee.setEmail(tmpBuffer);
        /* Password */
        getline(file, tmpBuffer);
        employee.setPassword(tmpBuffer);

        employeeDatabase->insert(std::pair<std::string, Employee>(employee.getEmail(), employee));
    }
    /* close the file */
    file.close();

    return true;
}

bool checkEmail(std::string email) {
    const std::string check = "@gmail.com";

    if(!email.length() or email.length() <= check.length()) { return false; }

    size_t start = email.find("@");
    if(start == email.npos) { return false; }

    if(email.compare(start, check.length(), check) != 0) { return false; };

    return true;
}

bool checkPassowrd(std::string password) {
    if(!password.length() or password.length() < 8) { return false; }

    return true;
}

bool checkCredentials(std::string email, std::string password) {
    if(!checkEmail(email) or !checkPassowrd(password)) { return false; }

    return true;
}
