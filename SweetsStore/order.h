#ifndef ORDER_H
#define ORDER_H

#include <iostream>

class Order {
public:
    static int lastOrderId;

private:
    int id;

    int quantity;

    std::string customerId;

    std::string productId;

    std::string orderDate;


public:
    Order();

    Order(int id, std::string customerId, std::string productId, std::string orderDate, int quantity);

    int getId();

    int getQuantity();

    std::string getCustomerId();

    std::string getProductId();

    std::string getOrderDate();

    void setId(int id);

    void setCustomerId(std::string customerId);

    void setProductId(std::string productId);

    void setOrderDate(std::string orderDate);

    void setQuantity(int quantity);
};

#endif // ORDER_H
