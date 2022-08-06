#define _GNU_SOURCE

#include "utilities.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <QDebug>
#include <QDateEdit>
#include <QLineEdit>

/* defining the costant token character */
const char* tokenCharacter = ";";

/* defining a variable that check if there are new changes in the application */
bool newChanges = false;

/* defining the employee map */
std::map<std::string, Employee> employeeDatabase;

/* defining the products map */
std::map<std::string, Product> productsDatabase;

/* defining a map that will contain all the customers */
std::map<std::string, Customer> customersDatabase;

/* defining the map that will contain all the customers orders */
std::map<int, Order> ordersDatabase;

/* defining the vector that will be used as product cart */
std::vector<std::string> customerCart;

/* defining the current employee variable */
Employee currentEmployee;

/* defining the current customer */
Customer currentCustomer;

/* save the email ( key ) of the selected employee */
Employee selectedEmployee;

/* check if a row has been cliced ( employee ) */
bool selectedEmployeCheck = false;

/* save the name (key) of the selected product */
Product selectedProduct;

/* check if a row has been clicked ( product ) */
bool selectedProductCheck = false;

bool loggedInAsCustomer = false;

Order selectedOrder;

bool selectedOrderCheck = false;

/* read informations in the products map */
void readProductsInformations(FILE* f, std::map<std::string, Product>* productsDatabase) {
    char buffer[1024];
    char* token = NULL;
    Product product;

    while(fgets(buffer, 1024, f)) {
        /* delete the \n from the buffer */
        buffer[strlen(buffer) - 1] = '\0';

        token = strtok(buffer, tokenCharacter);

        if(token != NULL) {
            /* set the name */
            product.setName(token);
            /* seth the expire date */
            token = strtok(NULL, tokenCharacter);
            product.setExpiry(token);
            /* set the brand name */
            token = strtok(NULL, tokenCharacter);
            product.setBrand(token);
            /* set the price */
            token = strtok(NULL, tokenCharacter);
            product.setPrice(atof(token));
            /* set the quantity */
            token = strtok(NULL, tokenCharacter);
            product.setQuantity(atoi(token));

            /* insert the informations in the map */
            productsDatabase->insert(std::pair<std::string, Product>(product.getName(), product));
        }
    }
}

void readMyCartInformations(FILE *f, std::vector<std::string> *customerCart) {
    char buffer[1024];

    while(fgets(buffer, sizeof(buffer), f)) {
        buffer[strlen(buffer) - 1] = '\0';
        customerCart->push_back(buffer);
    }
}

/* store the informations in the products map */
void storeProductInformations(FILE* f, std::map<std::string, Product>* productsDatabase) {
    char buffer[1024];

    for(auto it = productsDatabase->begin(); it != productsDatabase->end(); it++) {
        sprintf(buffer, "%s;%s;%s;%0.2f;%d\n", it->second.getName().c_str(), it->second.getExpiry().c_str(), it->second.getBrand().c_str(), it->second.getPrice(), it->second.getQuantity());
        fprintf(f, buffer);
    }
}

/* store the informations in the my_cart file */
void storeMyCartInformations(FILE* f, std::vector<std::string>* customerCart) {
    for(std::string& product : *customerCart) {
        fprintf(f, "%s\n", product.c_str());
    }
}

/* store the informations in the employees file */
void storeEmployeesInformations(FILE* f, std::map<std::string, Employee>* employeesDatabase) {
    char buffer[1024];

    for(auto it = employeesDatabase->begin(); it != employeesDatabase->end(); it++)  {
        sprintf(buffer, "%s;%s;%c;%d;%0.2f;%s;%s\n", it->second.getFirstName().c_str(), it->second.getLastName().c_str(), it->second.getSex(), it->second.getAge(), it->second.getSalary(), it->second.getEmail().c_str(), it->second.getPassword().c_str());
        fprintf(f, buffer);
    }
}

void storeCustomersInformations(FILE *f, std::map<std::string, Customer> *customersDatabase) {
    char buffer[1024];

    for(auto it = customersDatabase->begin(); it != customersDatabase->end(); it++) {
        sprintf(buffer, "%s;%s;%c;%d;%0.2f;%s;%s\n", it->second.getFirstName().c_str(), it->second.getLastName().c_str(), it->second.getSex(), it->second.getAge(), it->second.getMoney(), it->second.getEmail().c_str(), it->second.getPassword().c_str());
        fprintf(f, buffer);
    }
}

void storeOrdersInformations(FILE *f, std::map<int, Order> *ordersDatabase) {
    char buffer[1024];

    for(auto it = ordersDatabase->begin(); it != ordersDatabase->end(); it++) {
        sprintf(buffer, "%d;%s;%s;%s;%d\n", it->second.getId(), it->second.getCustomerId().c_str(), it->second.getProductId().c_str(), it->second.getOrderDate().c_str(), it->second.getQuantity());
        fprintf(f, buffer);
    }
}

/* read informations in the employees map */
void readEmployeesInformations(FILE* f, std::map<std::string, Employee>* employeesDatabase) {
    char buffer[1024];
    char* token = NULL;
    Employee employee;

    while(fgets(buffer, 1024, f)) {
        /* delete the \n from the buffer */
        buffer[strlen(buffer) - 1] = '\0';

        token = strtok(buffer, tokenCharacter);

        if(token != NULL) {
            /* set the First Name */
            employee.setFirstName(token);
            /* set the Last Name */
            token = strtok(NULL, tokenCharacter);
            employee.setLastName(token);
            /* set the Sex */
            token = strtok(NULL, tokenCharacter);
            employee.setSex(token[0]);
            /* set the Age */
            token = strtok(NULL, tokenCharacter);
            employee.setAge(atoi(token));
            /* set the Salary */
            token = strtok(NULL, tokenCharacter);
            employee.setSalary(atof(token));
            /* set the Email */
            token = strtok(NULL, tokenCharacter);
            employee.setEmail(token);
            /* set the Password */
            token = strtok(NULL, tokenCharacter);
            employee.setPassword(token);
            /* insert the informations in the map */
            employeesDatabase->insert(std::pair<std::string, Employee>(employee.getEmail(), employee));
        }
    }
}

void readCustomersInformations(FILE *f, std::map<std::string, Customer> *customersDatabase) {
    char buffer[1024];
    char* token = NULL;
    Customer customer;

    while(fgets(buffer, 1024, f)) {
        /* delete the \n from the buffer */
        buffer[strlen(buffer) - 1] = '\0';

        token = strtok(buffer, tokenCharacter);

        if(token != NULL) {
            /* set the First Name */
            customer.setFirstName(token);
            /* set the Last Name */
            token = strtok(NULL, tokenCharacter);
            customer.setLastName(token);
            /* set the Sex */
            token = strtok(NULL, tokenCharacter);
            customer.setSex(token[0]);
            /* set the Age */
            token = strtok(NULL, tokenCharacter);
            customer.setAge(atoi(token));
            /* set the Salary */
            token = strtok(NULL, tokenCharacter);
            customer.setMoney(atof(token));
            /* set the Email */
            token = strtok(NULL, tokenCharacter);
            customer.setEmail(token);
            /* set the Password */
            token = strtok(NULL, tokenCharacter);
            customer.setPassword(token);
            /* insert the informations in the map */
            customersDatabase->insert(std::pair<std::string, Customer>(customer.getEmail(), customer));
        }
    }
}

void readOrdersInformations(FILE *f, std::map<int, Order> *ordersDatabase) {
    char buffer[1024];
    char* token = NULL;
    Order order;

    while(fgets(buffer, 1024, f)) {
        /* delete the \n from the buffer */
        buffer[strlen(buffer) - 1] = '\0';

        token = strtok(buffer, tokenCharacter);

        if(token != NULL) {
            order.setId(std::atoi(token));

            token = strtok(NULL, tokenCharacter);
            order.setCustomerId(token);

            token = strtok(NULL, tokenCharacter);
            order.setProductId(token);

            token = strtok(NULL, tokenCharacter);
            order.setOrderDate(token);

            token = strtok(NULL, tokenCharacter);
            order.setQuantity(std::atoi(token));

            /* insert the order in the orders database */
            ordersDatabase->insert(std::pair<int, Order>(order.getId(), order));
            Order::lastOrderId += 1;
        }
    }
}

/* transform a std::string into lower */
std::string lowerStr(std::string string) {
    std::for_each(string.begin(), string.end(), [](char & c) {
        c = ::tolower(c);
    });

    return string;
}

/* function to get the current time */
const std::string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    return buf;
}

bool checkDate(QDateEdit *dateEdit) {
    int dayEdit, monthEdit, yearEdit;
    /* save the informations in the variables */
    dateEdit->date().getDate(&yearEdit, &monthEdit, &dayEdit);

    int currDay, currMonth, currYear;
    QDate::currentDate().getDate(&currYear, &currMonth, &currDay);

    /* simple case (year) */
    if(yearEdit < currYear) { return false; }

    if(yearEdit == currYear) {
        if(monthEdit < currMonth ) { return false; }

        else if(monthEdit > currMonth) { return true; }

        if(dayEdit <= currDay) { return false; }
    }

    return true;
}

bool checkEmptiesBox(QLineEdit *firstInput, QLineEdit *secondInput, QLineEdit *thirdInput, QSpinBox *spinBox) {
    if(!firstInput->text().length() or !secondInput->text().length() or !thirdInput->text().length()) {
        return false;
    }

    if(spinBox->text().toStdString() == "0") { return false; }

    return true;
}

bool checkEmail(std::string email, const char* check) {
    if(!email.length() or email.length() <= std::strlen(check)) { return false; }

    size_t start = email.find("@");
    if(start == email.npos) { return false; }

    if(email.compare(start, std::strlen(check), check) != 0) { return false; };

    return true;
}

/* return an item pointer with the text aligned */
QStandardItem* getItem(QString string) {
    QStandardItem* item = new QStandardItem;
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(string);

    return item;
}
