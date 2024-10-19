#include<iostream>

//Example 4:

void printPairs(int* arr, size_t sizeArr){

    for (int i = 0; i < sizeArr; ++i) {
        for (int j = 0; j < sizeArr; ++j) {
            std::cout << arr[i] << " " << arr[j] << "\n";
        }
    }
}

//The complexity is O(n^2), bc for each i from 0 - sizeArr the inner loop will make 0 - sizeArr steps => (n)(for outer loop)*O(n)(for inner loop)