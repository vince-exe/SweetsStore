#include "person.h"

#include <iostream>
#include <string>

/* default constructor */
Person::Person() {}

std::string Person::getFirstName() {
    return this->firstName;
}

std::string Person::getLastName() {
    return this->lastName;
}

char Person::getSex() {
    return this->sex;
}

int Person::getAge() {
    return this->age;
}

void Person::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Person::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Person::setSex(char sex) {
    this->sex = sex;
}

void Person::setAge(int age) {
    this->age = age;
};
