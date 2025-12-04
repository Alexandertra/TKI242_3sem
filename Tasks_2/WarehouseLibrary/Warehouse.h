#pragma once
#include "Product.h"
#include "Customer.h"
#include <vector>
#include <memory>
#include <string>

class Warehouse {
private:
    std::vector<std::shared_ptr<Product>> products;
    std::vector<std::shared_ptr<Customer>> customers;

public:
    void addProduct(std::shared_ptr<Product> product);
    void addCustomer(std::shared_ptr<Customer> customer);

    std::vector<std::shared_ptr<Product>> getCurrentAssortment() const;
    std::vector<std::shared_ptr<Customer>> getCustomersWithDiscount() const;

    bool sellProduct(const std::string& productCode, int quantity,
        const std::string& customerId = "");

    std::vector<std::string> getSalesReport() const;

    size_t getProductCount() const;
    size_t getCustomerCount() const;
}; 
