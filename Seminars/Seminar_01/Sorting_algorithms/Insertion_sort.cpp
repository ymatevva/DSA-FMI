#include<iostream>


template<class T>
void insertionSort(T* arr, size_t sizeArr){

    for (int i = 1; i < sizeArr; ++i) {

        T el = arr[i];
        int ind = i-1;
        while(ind >= 0 && arr[ind] > el){
            arr[ind+1] = arr[ind];
            ind --;
        }
        arr[ind+1] = el;
    }
}
//It is stable.
//B-C : O(n)
//W-C : O(n^2)
//A-C : O(n^2)
int main() {

    int arr[] = {1, 8, 7, 9, 5};
    insertionSort<int>(arr, 5);
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
}