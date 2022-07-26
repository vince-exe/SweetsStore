#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

#include "person.h"


class Employee : public Person {
private:
    float salary;
    std::string email;
    std::string password;

public:
    /* default constructor */
    Employee();

    float getSalary();

    std::string getEmail();

    std::string getPassword();

    void setSalary(float salary);

    void setEmail(std::string email);

    void setPassword(std::string password);
};

#endif // EMPLOYEE_H
