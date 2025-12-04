#pragma once
#include "Product.h"

class BulkProduct : public Product {
private:
    double weight;
    std::string unit;

public:
    BulkProduct(const std::string& name, const std::string& code,
        const double pricePerUnit, const double weight, const std::string& unit);

    std::string getInfo() const override;
    double calculatePrice(int quantity = 1) const override;
    std::string getType() const override;

    double getWeight() const;
    std::string getUnit() const;
    void setWeight(const double newWeight);
}; 
