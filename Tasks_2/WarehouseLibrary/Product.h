#pragma once
#include <string>
#include <memory>

class Product {
protected:
    std::string name;
    std::string code;
    double basePrice;
    int quantity;

public:
    Product(const std::string& name, const std::string& code, const double price, const int quantity);
    virtual ~Product() = default;

    virtual std::string getInfo() const = 0;
    virtual double calculatePrice(int quantity = 1) const = 0;
    virtual std::string getType() const = 0;

    // Getters
    std::string getName() const;
    std::string getCode() const;
    double getBasePrice() const;
    int getQuantity() const;

    // Setters
    void setQuantity(const int newQuantity);
    void setBasePrice(const double newPrice);
};