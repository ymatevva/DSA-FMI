#include<iostream>

template<class T>
int binarySearch(const T* arr, size_t sizeArr, const T& el){

    int left = 0;
    int right = sizeArr -1;
    while(left<=right){

        int mid = left +(right-left)/2;

        if(arr[mid] == el){
            return mid;
        }
        else if(arr[mid] < el){
            left = mid+1;
        }
        else{
            right = mid -1;
        }

    }
    return -1;
}
//Example 3:
template<class T>
void printIndexes(const T*arr, size_t sizeArr){

    for (int i = 0; i < sizeArr; ++i) {
        std::cout << binarySearch(arr, sizeArr,i)<< " ";
    }
}

//Here the algorithm on every step form 0 - n-1 does the binarySearch;
//The binary search function in A-C has complexity of O(log(n)),so the complexity of printIndexes is O(n.log(n))