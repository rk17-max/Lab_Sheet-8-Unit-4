#include "Sorting.h"
#include <iostream>

// Comparator function
bool compare(const Product& a, const Product& b, const std::string& attribute) {
    if (attribute == "price") return a.price < b.price;
    if (attribute == "rating") return a.rating < b.rating;
    if (attribute == "name") return a.name < b.name;
    return false;
}

// Bubble Sort
void bubbleSort(std::vector<Product>& products, const std::string& attribute) {
    int n = products.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!compare(products[j], products[j + 1], attribute)) {
                std::swap(products[j], products[j + 1]);
            }
        }
    }
    std::cout << "Products sorted using Bubble Sort!\n";
}

// Insertion Sort
void insertionSort(std::vector<Product>& products, const std::string& attribute) {
    int n = products.size();
    for (int i = 1; i < n; ++i) {
        Product key = products[i];
        int j = i - 1;
        while (j >= 0 && !compare(products[j], key, attribute)) {
            products[j + 1] = products[j];
            --j;
        }
        products[j + 1] = key;
    }
    std::cout << "Products sorted using Insertion Sort!\n";
}

// Merge Sort Helper
void merge(std::vector<Product>& products, int left, int mid, int right, const std::string& attribute) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Product> L(products.begin() + left, products.begin() + mid + 1);
    std::vector<Product> R(products.begin() + mid + 1, products.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j], attribute)) {
            products[k++] = L[i++];
        } else {
            products[k++] = R[j++];
        }
    }

    while (i < n1) products[k++] = L[i++];
    while (j < n2) products[k++] = R[j++];
}

// Merge Sort
void mergeSort(std::vector<Product>& products, int left, int right, const std::string& attribute) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(products, left, mid, attribute);
        mergeSort(products, mid + 1, right, attribute);

        merge(products, left, mid, right, attribute);
    }
    std::cout << "Products sorted using Merge Sort!\n";
}

// Quick Sort Helper
int partition(std::vector<Product>& products, int low, int high, const std::string& attribute) {
    Product pivot = products[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (compare(products[j], pivot, attribute)) {
            std::swap(products[++i], products[j]);
        }
    }
    std::swap(products[i + 1], products[high]);
    return i + 1;
}

// Quick Sort
void quickSort(std::vector<Product>& products, int low, int high, const std::string& attribute) {
    if (low < high) {
        int pi = partition(products, low, high, attribute);

        quickSort(products, low, pi - 1, attribute);
        quickSort(products, pi + 1, high, attribute);
    }
    std::cout << "Products sorted using Quick Sort!\n";
}
