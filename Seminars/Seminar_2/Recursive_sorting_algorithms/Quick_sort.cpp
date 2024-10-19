#include<iostream>

//We choose element as a pivot and put elements smaller than the pivot on the left and the other ones on the right
//Then the alg is implied on these two parts and etc.
//The cons are that partition func implementation is complex and that it is not easy not to use extra memory
//If we choose the middle el as a pivot one: T(n) = 2*T(n/2) + n(for partition func)=>MT=> O(n*log(n))\
//If we choose the last el as a pivot one =>O(n^2)
//The partition func returns the new index of the pivot

template<class T>
size_t advancedPart(T* initialArr,size_t sizeArr){

    if(initialArr[0] > initialArr[sizeArr - 1]){
        std::swap(initialArr[0] ,initialArr[sizeArr - 1]);// to reduce the likelihood of W_C
    }


    T& pivot = initialArr[sizeArr - 1];
    size_t left = 0;
    size_t right = sizeArr-1;


    while(true){

        while(initialArr[++left] < pivot);

        while(initialArr[--right] > pivot){
            if(left == right){
                break;
            }
        }

        if(left >= right){
            break;
        }
        std::swap(initialArr[left],initialArr[right]);
    }
    std::swap(initialArr[left],pivot);
    return left;
}

template<class T>
void quickSort(T* arr,size_t sizeArr) {
    if(!arr || sizeArr <= 1){
        return;
    }

    size_t pivotInd = advancedPart(arr,sizeArr);
    quickSort(arr,pivotInd);
    quickSort(arr+pivotInd+1,sizeArr - 1 - pivotInd);

}
int main(){

    int arr[] = {1,8,3,9,4,5,23,45,90,7,12};

    quickSort<int>(arr,11);
    for (int i = 0; i < 11 ; ++i) {
        std::cout << arr[i] << " ";
    }
}