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
    Product(const std::string& name, const std::string& code, double price, int quantity);
    virtual ~Product() = default;

    virtual std::string getInfo() const;
    virtual double calculatePrice(int quantity = 1) const;
    virtual std::string getType() const;

    // Getters
    std::string getName() const;
    std::string getCode() const;
    double getBasePrice() const;
    int getQuantity() const;

    // Setters
    void setQuantity(int newQuantity);
    void setBasePrice(double newPrice);
};