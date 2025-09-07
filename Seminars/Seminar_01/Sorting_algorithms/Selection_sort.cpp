#include<iostream>
#include<utility>

template<class T>
void selectionSort( T* arr, size_t sizeArr){

    for (int i = 0; i < sizeArr-1 ; ++i) {

        int minElInd = i;
        for (int j = i+1; j < sizeArr ; ++j) {

            if(arr[j] < arr[minElInd]){
                minElInd = j;
            }
        }
        if(minElInd != i){
            std::swap(arr[minElInd],arr[i]);
        }
    }
}

// Stability: NO -> 221
//B-C: O(n^2)
//W-C: O(n^2)
//A-C: O(n^2)

int main(){

    int arr[] = {1,3,4,5,2,5,7,3,0,0,3};

    selectionSort<int>(arr,11);
    for (int i = 0; i < 11; ++i) {
        std::cout << arr[i] << " ";
    }

}