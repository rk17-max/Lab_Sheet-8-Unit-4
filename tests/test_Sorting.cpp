#include <iostream>
#include <vector>
#include <cassert>
#include "../src/Product.h"
#include "../src/Sorting.h"

void testBubbleSort() {
    std::vector<Product> products = {
        Product(101, "Laptop", "Electronics", 50000, 4.5),
        Product(102, "Smartphone", "Electronics", 30000, 4.8),
        Product(103, "Headphones", "Accessories", 2000, 4.1)
    };

    bubbleSort(products, "price");

    assert(products[0].price == 2000);
    assert(products[1].price == 30000);
    assert(products[2].price == 50000);

    std::cout << "Bubble Sort test passed!\n";
}

void testQuickSort() {
    std::vector<Product> products = {
        Product(101, "Laptop", "Electronics", 50000, 4.5),
        Product(102, "Smartphone", "Electronics", 30000, 4.8),
        Product(103, "Headphones", "Accessories", 2000, 4.1)
    };

    quickSort(products, 0, products.size() - 1, "rating");

    assert(products[0].rating == 4.1);
    assert(products[1].rating == 4.5);
    assert(products[2].rating == 4.8);

    std::cout << "Quick Sort test passed!\n";
}

int main() {
    testBubbleSort();
    testQuickSort();
    std::cout << "All sorting tests passed!" << std::endl;
    return 0;
}
