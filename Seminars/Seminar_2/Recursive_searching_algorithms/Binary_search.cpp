#include<iostream>

template<class T>
bool binarySearchRec(const T*arr, size_t sizeArr, const T&el){

    int mid = sizeArr/2;

    if(!sizeArr){
        return false;
    }
    if (arr[mid]== el){
        return true;
    }
    else if(arr[mid] < el){
            return binarySearchRec(arr + mid+ 1, sizeArr - mid- 1, el);}
    else {
        return binarySearchRec(arr , mid, el);
    }
}

//Complexity:
//T(n) = T(n/2) + T(n/2) + O(1) = > T(n/2) + O(1) => Master theorem => O(log(n))
int main(){
    int arr[] = {1,2,3,4,5,6};
    std::cout << binarySearchRec<int>(arr,6,6);
}