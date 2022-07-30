#include "utilities.h"

#include <stdio.h>
#include <string.h>

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

/* defining the current employee variable */
Employee currentEmployee;

/* save the name (key) of the selected product */
Product selectedProduct;
/* check if a row has been clicked */
bool selectedProductCheck = false;

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

/* store the informations in the products map */
void storeProductInformations(FILE* f, std::map<std::string, Product>* productsDatabase) {
    char buffer[1024];

    for(auto it = productsDatabase->begin(); it != productsDatabase->end(); it++) {
        sprintf(buffer, "%s;%s;%s;%0.2f;%d\n", it->second.getName().c_str(), it->second.getExpiry().c_str(), it->second.getBrand().c_str(), it->second.getPrice(), it->second.getQuantity());
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

void clearInputFields(QLineEdit *f1, QLineEdit *f2, QLineEdit *f3, QSpinBox *f4, QDateEdit *f5) {
    /* clear the widgets */
    f1->clear();
    f2->clear();
    f3->clear();
    f4->clear();

    f5->setDate(QDate::currentDate());
}
