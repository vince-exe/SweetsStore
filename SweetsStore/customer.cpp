#include "customer.h"

#include "person.h"

Customer::Customer() { };

Customer::Customer(std::string firstName, std::string lastName, char sex, int age, float money, std::string email, std::string password)
         :Person(firstName, lastName, sex, age) {
    this->email = email;
    this->password = password;
    this->money = money;
}

void Customer::setEmail(std::string email) {
    this->email = email;
}

std::string Customer::getEmail() {
    return this->email;
}

void Customer::setPassword(std::string password) {
    this->password = password;
}

std::string Customer::getPassword() {
    return this->password;
}

void Customer::setMoney(float money) {
    this->money = money;
}

float Customer::getMoney() {
    return this->money;
}
