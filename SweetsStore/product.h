#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>


class Product {
private:
    std::string name;

    std::string expiry;

    std::string brand;

    float price;

    int id;

    int quanity;

public:
    /* default constructor */
    Product();

    std::string getName();

    std::string getExpiry();

    std::string getBrand();

    float getPrice();

    int getId();

    int getQuantity();

    void setName(std::string name);

    void setExpiry(std::string expiry);

    void setBrand(std::string brand);

    void setPrice(float price);

    void setId(int id);

    void setQuantity(int quantity);
};

#endif // PRODUCT_H
