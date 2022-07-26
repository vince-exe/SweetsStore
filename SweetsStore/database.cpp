#include "database.h"

#include <stdio.h>
#include <string.h>
#include <QDebug>

/* defining the costant token character */
const char* tokenCharacter = ";";

/* defining the employee map */
std::map<std::string, Employee> employeeDatabase;

/* defining the products map */
std::map<std::string, Product> productsDatabase;

/* defining the current employee variable */
Employee currentEmployee;

/* store informations in the products map */
void storeProductsInformations(FILE* f, std::map<std::string, Product>* productsDatabase) {
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

/* store informations in the employees map */
void storeEmployeesInformations(FILE* f, std::map<std::string, Employee>* employeesDatabase) {
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
