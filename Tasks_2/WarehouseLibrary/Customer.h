#pragma once
#include <string>
#include <memory>

class Customer {
private:
    std::string name;
    std::string id;
    double discountRate;

public:
    Customer(const std::string& name, const std::string& id, const double discountRate = 0.0);

    std::string getInfo() const;
    double getDiscountRate() const;
    void setDiscountRate(double newRate);

    std::string getName() const;
    std::string getId() const;

    double applyDiscount(double amount) const;
}; 
