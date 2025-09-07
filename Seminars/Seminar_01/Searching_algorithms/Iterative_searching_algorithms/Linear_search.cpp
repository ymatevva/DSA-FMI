#include<iostream>
#include<vector>

template<class T>
int linearSearch(const T* arr, size_t arrSize, const T& el){

    for(int i = 0 ; i < arrSize; i++){
        if(arr[i]==el){
            return i;
        }
    }
    return -1;
}

//B-C : O(1)
//W-C : O(n) -> n steps for n elements
//A-C : O(n) -> 1/n is the chance the element on certain pos to be the searched
// -> (1+...+n)/n -> (((n+1).n)/2)n => O(n)

int main(){

    int arr[] = {1,7,2,7,9,5};
    std::cout << "Position of 9:" << linearSearch(arr,6,9);
}
