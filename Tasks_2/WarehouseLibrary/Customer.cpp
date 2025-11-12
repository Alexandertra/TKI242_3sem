#include "Customer.h"

Customer::Customer(const std::string& name, const std::string& id, double discountRate)
    : name(name), id(id), discountRate(discountRate) {
}

std::string Customer::getInfo() const {
    return "Customer: " + name + " (ID: " + id +
        "), Discount: " + std::to_string(discountRate * 100) + "%";
}

double Customer::getDiscountRate() const {
    return discountRate;
}

void Customer::setDiscountRate(double newRate) {
    discountRate = newRate;
}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getId() const {
    return id;
}

double Customer::applyDiscount(double amount) const {
    return amount * (1.0 - discountRate);
}