#include <gtest/gtest.h>
#include "Product.h"
#include "PackagedProduct.h"
#include "BulkProduct.h"
#include "Customer.h"
#include "Warehouse.h"

TEST(ProductTest, BasicProductCreation) {
    Product product("Test Product", "TEST001", 10.0, 100);
    EXPECT_EQ(product.getName(), "Test Product");
    EXPECT_EQ(product.getCode(), "TEST001");
    EXPECT_EQ(product.getBasePrice(), 10.0);
    EXPECT_EQ(product.getQuantity(), 100);
}

TEST(PackagedProductTest, PackagedProductCreation) {
    PackagedProduct packaged("Packaged Test", "PKG001", 5.0, 50, 10, "Box");
    EXPECT_EQ(packaged.getName(), "Packaged Test");
    EXPECT_EQ(packaged.getItemsPerPackage(), 10);
    EXPECT_EQ(packaged.getPackageType(), "Box");
}

TEST(BulkProductTest, BulkProductCreation) {
    BulkProduct bulk("Bulk Test", "BLK001", 2.5, 100.0, "kg");
    EXPECT_EQ(bulk.getName(), "Bulk Test");
    EXPECT_EQ(bulk.getWeight(), 100.0);
    EXPECT_EQ(bulk.getUnit(), "kg");
}

TEST(CustomerTest, CustomerDiscount) {
    Customer customer("Test Customer", "CUST001", 0.1);
    EXPECT_EQ(customer.getName(), "Test Customer");
    EXPECT_EQ(customer.getDiscountRate(), 0.1);
    EXPECT_EQ(customer.applyDiscount(100.0), 90.0);
}

TEST(WarehouseTest, AddProductsAndCustomers) {
    Warehouse warehouse;

    auto product = std::make_shared<Product>("Test", "T001", 10.0, 100);
    auto customer = std::make_shared<Customer>("Test Cust", "C001", 0.1);

    warehouse.addProduct(product);
    warehouse.addCustomer(customer);

    EXPECT_EQ(warehouse.getProductCount(), 1);
    EXPECT_EQ(warehouse.getCustomerCount(), 1);
}

TEST(WarehouseTest, CustomersWithDiscount) {
    Warehouse warehouse;

    warehouse.addCustomer(std::make_shared<Customer>("With Discount", "C001", 0.1));
    warehouse.addCustomer(std::make_shared<Customer>("No Discount", "C002", 0.0));

    auto customersWithDiscount = warehouse.getCustomersWithDiscount();
    EXPECT_EQ(customersWithDiscount.size(), 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}