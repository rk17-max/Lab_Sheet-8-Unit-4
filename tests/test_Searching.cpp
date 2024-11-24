#include <iostream>
#include <vector>
#include <cassert>
#include "../src/Product.h"
#include "../src/Searching.h"

void testSequentialSearch() {
    std::vector<Product> products = {
        Product(101, "Laptop", "Electronics", 50000, 4.5),
        Product(102, "Smartphone", "Electronics", 30000, 4.8),
        Product(103, "Headphones", "Accessories", 2000, 4.1)
    };

    int index = sequentialSearch(products, "Laptop");
    assert(index == 0);

    index = sequentialSearch(products, "Smartwatch");
    assert(index == -1);

    std::cout << "Sequential Search test passed!\n";
}

void testBinarySearch() {
    std::vector<Product> products = {
        Product(101, "Headphones", "Accessories", 2000, 4.1),
        Product(102, "Smartphone", "Electronics", 30000, 4.8),
        Product(103, "Laptop", "Electronics", 50000, 4.5)
    };

    int index = binarySearch(products, 0, products.size() - 1, 102);
    assert(index == 1);

    index = binarySearch(products, 0, products.size() - 1, 104);
    assert(index == -1);

    std::cout << "Binary Search test passed!\n";
}

int main() {
    testSequentialSearch();
    testBinarySearch();
    std::cout << "All searching tests passed!" << std::endl;
    return 0;
}
