#include "Warehouse.h"
#include <algorithm>

void Warehouse::addProduct(std::shared_ptr<Product> product) {
    products.push_back(product);
}

void Warehouse::addCustomer(std::shared_ptr<Customer> customer) {
    customers.push_back(customer);
}

std::vector<std::shared_ptr<Product>> Warehouse::getCurrentAssortment() const {
    return products;
}

std::vector<std::shared_ptr<Customer>> Warehouse::getCustomersWithDiscount() const {
    std::vector<std::shared_ptr<Customer>> customersWithDiscount;
    for (const auto& customer : customers) {
        if (customer->getDiscountRate() > 0.0) {
            customersWithDiscount.push_back(customer);
        }
    }
    return customersWithDiscount;
}

bool Warehouse::sellProduct(const std::string& productCode, int quantity,
    const std::string& customerId) {
    auto it = std::find_if(products.begin(), products.end(),
        [&productCode](const std::shared_ptr<Product>& product) {
            return product->getCode() == productCode;
        });

    if (it != products.end() && (*it)->getQuantity() >= quantity) {
        (*it)->setQuantity((*it)->getQuantity() - quantity);
        return true;
    }
    return false;
}

std::vector<std::string> Warehouse::getSalesReport() const {
    return { "Sales report: Feature under development" };
}

size_t Warehouse::getProductCount() const {
    return products.size();
}

size_t Warehouse::getCustomerCount() const {
    return customers.size();
}