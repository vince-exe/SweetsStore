#include "product.h"

Product::Product() {};

std::string Product::getName() {
    return this->name;
}

std::string Product::getExpiry() {
    return this->expiry;
}

std::string Product::getBrand() {
    return this->brand;
}

float Product::getPrice() {
    return this->price;
}

int Product::getId() {
    return this->id;
}

int Product::getQuantity() {
    return this->quanity;
}

void Product::setName(std::string name) {
    this->name = name;
}

void Product::setExpiry(std::string expiry) {
    this->expiry = expiry;
}

void Product::setBrand(std::string brand) {
    this->brand = brand;
}

void Product::setPrice(float price) {
    this->price = price;
}

void Product::setId(int id) {
    this->id = id;
}

void Product::setQuantity(int quantity) {
    this->quanity = quantity;
}
