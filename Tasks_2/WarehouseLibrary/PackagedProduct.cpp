#include "PackagedProduct.h"

PackagedProduct::PackagedProduct(const std::string& name, const std::string& code,
    const double price, const int quantity, const int itemsPerPackage,
    const std::string& packageType)
    : Product(name, code, price, quantity),
    itemsPerPackage(itemsPerPackage),
    packageType(packageType) {
}

std::string PackagedProduct::getInfo() const {
    return "Packaged " + Product::getInfo() +
        ", Package: " + packageType +
        " (" + std::to_string(itemsPerPackage) + " items)";
}

double PackagedProduct::calculatePrice(int quantity) const {
    int packages = (quantity + itemsPerPackage - 1) / itemsPerPackage;
    return basePrice * packages * itemsPerPackage;
}

std::string PackagedProduct::getType() const {
    return "Packaged Product";
}

int PackagedProduct::getItemsPerPackage() const {
    return itemsPerPackage;
}

std::string PackagedProduct::getPackageType() const {
    return packageType;
}