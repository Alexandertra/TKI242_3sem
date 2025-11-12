#pragma once
#include "Product.h"

class PackagedProduct : public Product {
private:
    int itemsPerPackage;
    std::string packageType;

public:
    PackagedProduct(const std::string& name, const std::string& code,
        double price, int quantity, int itemsPerPackage,
        const std::string& packageType);

    std::string getInfo() const override;
    double calculatePrice(int quantity = 1) const override;
    std::string getType() const override;

    int getItemsPerPackage() const;
    std::string getPackageType() const;
}; 
