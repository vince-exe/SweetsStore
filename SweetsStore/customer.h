#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"

class Customer : public Person {
private:
    float money;

    std::string email;

    std::string password;

public:
    Customer();

    Customer(std::string firstName, std::string lastName, char sex, int age, float money, std::string email, std::string password);

    void setEmail(std::string email);

    std::string getEmail();

    void setPassword(std::string password);

    std::string getPassword();

    void setMoney(float money);

    float getMoney();
};

#endif // CUSTOMER_H
