#include<iostream>
#include<iomanip>
#include<utility>

template<class T>
void bubbleSort(T* arr, size_t sizeArr){

    int end = sizeArr - 1;
    for (int i = 0; i < sizeArr; ++i) {

        unsigned lastSwappedInd = 0;
        for (int j = 0; j < end; ++j) {
            if(arr[j] > arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                lastSwappedInd = j;
            }
        }

        end = lastSwappedInd;
        if(!lastSwappedInd){
            return;
        }
    }
}

int main(){

    int arr[] = {1,9,2,4,56,7,345,6};
    bubbleSort<int>(arr,8);
    for (int i = 0; i < 8; ++i) {
        std :: cout << arr[i] << " ";
    }
}