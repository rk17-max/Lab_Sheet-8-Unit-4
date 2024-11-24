#include <iostream>
#include "Product.h"
#include "Sorting.h"

int main() {
    std::vector<Product> products;

    // Add some products
    addProduct(products, Product(101, "Laptop", "Electronics", 50000, 4.5));
    addProduct(products, Product(102, "Smartphone", "Electronics", 30000, 4.8));
    addProduct(products, Product(103, "Headphones", "Accessories", 2000, 4.1));

    // Display products
    std::cout << "Product List:\n";
    for (const auto& product : products) product.display();

    // Sort products by price
    bubbleSort(products, "price");
    std::cout << "\nSorted by Price:\n";
    for (const auto& product : products) product.display();

    return 0;
}
