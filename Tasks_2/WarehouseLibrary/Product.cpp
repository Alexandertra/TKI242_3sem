#include "Product.h"

Product::Product(const std::string& name, const std::string& code,
    double price, int quantity)
    : name(name), code(code), basePrice(price), quantity(quantity) {
}

std::string Product::getInfo() const {
    return "Product: " + name + " (Code: " + code +
        "), Price: " + std::to_string(basePrice) +
        ", Quantity: " + std::to_string(quantity);
}

double Product::calculatePrice(int quantity) const {
    return basePrice * quantity;
}

std::string Product::getType() const {
    return "Base Product";
}

std::string Product::getName() const { return name; }
std::string Product::getCode() const { return code; }
double Product::getBasePrice() const { return basePrice; }
int Product::getQuantity() const { return quantity; }

void Product::setQuantity(int newQuantity) { quantity = newQuantity; }
void Product::setBasePrice(double newPrice) { basePrice = newPrice; }