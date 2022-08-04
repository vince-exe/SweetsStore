#include "order.h"

#include <iostream>

int Order::lastOrderId = 0;

Order::Order() {}

Order::Order(int id, std::string customerId, std::string productId, std::string orderDate, int quantity) {
    this->id = id;
    this->customerId = customerId;
    this->productId = productId;
    this->orderDate = orderDate;
    this->quantity = quantity;
}

int Order::getId() {
    return this->id;
}

int Order::getQuantity() {
    return this->quantity;
}

std::string Order::getCustomerId() {
    return this->customerId;
}

std::string Order::getProductId() {
    return this->productId;
}

std::string Order::getOrderDate() {
    return this->orderDate;
}

void Order::setId(int id) {
    this->id = id;
}

void Order::setCustomerId(std::string customerId) {
    this->customerId = customerId;
}

void Order::setProductId(std::string productId) {
    this->productId = productId;
}

void Order::setOrderDate(std::string orderDate) {
    this->orderDate = orderDate;
}

void Order::setQuantity(int quantity) {
    this->quantity = quantity;
};
