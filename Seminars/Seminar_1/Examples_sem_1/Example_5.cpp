#include<iostream>

//Example 5:

int smth(int *arr, size_t sizeArr){
    unsigned res = 0;
    for (int i = 1; i <= sizeArr; i+=2) {
        for (int j = 1; j <= i; ++j) {
            res++;
        }
    }
    return res;
}
