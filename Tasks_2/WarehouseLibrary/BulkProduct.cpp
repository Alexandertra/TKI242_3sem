#include "BulkProduct.h"

BulkProduct::BulkProduct(const std::string& name, const std::string& code,
    const double pricePerUnit, const double weight, const std::string& unit)
    : Product(name, code, pricePerUnit, static_cast<int>(weight)),
    weight(weight), unit(unit) {
}

std::string BulkProduct::getInfo() const {
    return "Bulk " + Product::getInfo() +
        ", Weight: " + std::to_string(weight) + " " + unit;
}

double BulkProduct::calculatePrice(int quantity) const {
    return basePrice * weight;
}

std::string BulkProduct::getType() const {
    return "Bulk Product";
}

double BulkProduct::getWeight() const {
    return weight;
}

std::string BulkProduct::getUnit() const {
    return unit;
}

void BulkProduct::setWeight(double newWeight) {
    weight = newWeight;
    quantity = static_cast<int>(newWeight);
}