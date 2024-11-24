#include "Product.h"
#include <iostream>
#include <algorithm>

Product::Product(int id, std::string name, std::string category, float price, float rating)
    : id(id), name(name), category(category), price(price), rating(rating) {}

void Product::display() const {
    std::cout << "ID: " << id
              << ", Name: " << name
              << ", Category: " << category
              << ", Price: " << price
              << ", Rating: " << rating << std::endl;
}

void addProduct(std::vector<Product>& products, const Product& product) {
    products.push_back(product);
    std::cout << "Product added successfully!\n";
}

void deleteProduct(std::vector<Product>& products, int id) {
    auto it = std::remove_if(products.begin(), products.end(),
                             [id](const Product& product) { return product.id == id; });
    if (it != products.end()) {
        products.erase(it, products.end());
        std::cout << "Product deleted successfully!\n";
    } else {
        std::cout << "Product not found!\n";
    }
}

void updateProduct(std::vector<Product>& products, int id, const Product& updatedProduct) {
    for (auto& product : products) {
        if (product.id == id) {
            product = updatedProduct;
            std::cout << "Product updated successfully!\n";
            return;
        }
    }
    std::cout << "Product not found!\n";
}
