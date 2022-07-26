#include "employee.h"

Employee::Employee() : Person() {}

float Employee::getSalary() {
    return this->salary;
}

std::string Employee::getEmail() {
    return this->email;
}

std::string Employee::getPassword() {
    return this->password;
}

void Employee::setSalary(float salary) {
    this->salary = salary;
}

void Employee::setEmail(std::string email) {
    this->email = email;
}

void Employee::setPassword(std::string password) {
    this->password = password;
};
