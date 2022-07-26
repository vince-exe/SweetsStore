#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>


class Person {
private:
    std::string firstName;

    std::string lastName;

    char sex;

    int age;

public:
    /* default constructor */
    Person();

    std::string getFirstName();

    std::string getLastName();

    char getSex();

    int getAge();

    void setFirstName(std::string firstName);

    void setLastName(std::string lastName);

    void setSex(char& sex);

    void setAge(int age);
};

#endif // PERSON_H
