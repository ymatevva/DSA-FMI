#include<iostream>

template<class T>
int binarySearch(const T* arr, size_t sizeArr, const T& el){

    int left = 0;
    int right = sizeArr -1;
    while(left <= right){

        int mid = left + (right - left)/2;

        if(arr[mid]==el){
            return mid;
        }
        if(arr[mid] < el){
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    return -1;
}

//The array should be sorted
//B-C : O(1)
//W-C : O(logn) -> 2^k = n => k = log(n)
//A-C : O(logn)
int main(){

    int arr[] = {1,2,4,8,9};
    std::cout << binarySearch(arr,5,8);
}