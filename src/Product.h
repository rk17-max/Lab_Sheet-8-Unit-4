#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

class Product {
public:
    int id;
    std::string name;
    std::string category;
    float price;
    float rating;

    // Constructor
    Product(int id, std::string name, std::string category, float price, float rating);

    // Display product details
    void display() const;
};

// Function declarations for managing products
void addProduct(std::vector<Product>& products, const Product& product);
void deleteProduct(std::vector<Product>& products, int id);
void updateProduct(std::vector<Product>& products, int id, const Product& updatedProduct);

#endif // PRODUCT_H
