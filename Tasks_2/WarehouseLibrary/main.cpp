#include <iostream>
#include <vector>
#include <memory>
#include "Product.h"
#include "PackagedProduct.h"
#include "BulkProduct.h"
#include "Customer.h"
#include "Warehouse.h"

int main() {
    setlocale(LC_ALL, "Russian");

    // Создание склада
    Warehouse warehouse;

    // Создание коллекции продуктов
    std::vector<std::shared_ptr<Product>> products;

    // Добавление различных типов продуктов
    products.push_back(std::make_shared<PackagedProduct>(
        "Sugar 1kg", "SUG001", 45.50, 100, 10, "Box"));

    products.push_back(std::make_shared<PackagedProduct>(
        "Flour 2kg", "FLR002", 32.75, 50, 5, "Bag"));

    products.push_back(std::make_shared<BulkProduct>(
        "Rice", "RCE003", 28.0, 500.0, "kg"));

    products.push_back(std::make_shared<BulkProduct>(
        "Beans", "BNS004", 45.0, 200.0, "kg"));

    products.push_back(std::make_shared<PackagedProduct>(
        "Salt 0.5kg", "SLT005", 15.25, 200, 20, "Package"));

    // Добавление продуктов на склад
    for (const auto& product : products) {
        warehouse.addProduct(product);
    }

    // Добавление клиентов
    warehouse.addCustomer(std::make_shared<Customer>("Supermarket Chain", "CUST001", 0.1));
    warehouse.addCustomer(std::make_shared<Customer>("Local Store", "CUST002", 0.05));
    warehouse.addCustomer(std::make_shared<Customer>("Wholesale Buyer", "CUST003", 0.15));
    warehouse.addCustomer(std::make_shared<Customer>("New Client", "CUST004", 0.0));

    // Демонстрация: итерация по коллекции базового типа
    std::cout << "=== CURRENT WAREHOUSE ASSORTMENT ===" << std::endl;
    for (const auto& product : products) {
        std::cout << product->getInfo() << std::endl;
        std::cout << "Type: " << product->getType() << std::endl;
        std::cout << "Price for 1 unit: " << product->calculatePrice(1) << std::endl;
        std::cout << "---" << std::endl;
    }

    // Демонстрация клиентов со скидкой
    std::cout << "\n=== CUSTOMERS WITH DISCOUNTS ===" << std::endl;
    auto customersWithDiscount = warehouse.getCustomersWithDiscount();
    for (const auto& customer : customersWithDiscount) {
        std::cout << customer->getInfo() << std::endl;

        // Демонстрация применения скидки
        double sampleAmount = 1000.0;
        double discountedAmount = customer->applyDiscount(sampleAmount);
        std::cout << "Sample discount on " << sampleAmount << ": " << discountedAmount << std::endl;
        std::cout << "---" << std::endl;
    }

    // Демонстрация различных расчетов цен
    std::cout << "\n=== PRICE CALCULATIONS DEMO ===" << std::endl;
    for (const auto& product : products) {
        std::cout << product->getName() << ":" << std::endl;
        std::cout << "  Single unit: " << product->calculatePrice(1) << std::endl;
        std::cout << "  10 units: " << product->calculatePrice(10) << std::endl;
    }

    std::cout << "\nWarehouse statistics:" << std::endl;
    std::cout << "Total products: " << warehouse.getProductCount() << std::endl;
    std::cout << "Total customers: " << warehouse.getCustomerCount() << std::endl;

    return 0;
}