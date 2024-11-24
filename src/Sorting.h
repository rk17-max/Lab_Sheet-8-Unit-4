#ifndef SORTING_H
#define SORTING_H

#include "Product.h"
#include <vector>

// Sorting algorithms
void bubbleSort(std::vector<Product>& products, const std::string& attribute);
void insertionSort(std::vector<Product>& products, const std::string& attribute);
void mergeSort(std::vector<Product>& products, int left, int right, const std::string& attribute);
void quickSort(std::vector<Product>& products, int low, int high, const std::string& attribute);

#endif // SORTING_H
