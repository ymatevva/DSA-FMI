#include<iostream>

//One of the cons is that it is not in-place algorithm.
//The smarter version of the implementation is to make only one buffer array.
// => O(n) is the complexity in the context of used memory(for he buffer array with size n)
//What is the complexity in context of time?
//T(n) = 2*T(n/2) + O(n) => Master theorem => O(log(n)*n)
//It is better than alg with complexity O(n^2) but it is worse in the context of memory.
//!!!It is stable.

template<class T>
void Merge(T*firstArr, size_t firstSize, T* secondArr, size_t secSize, T* res){

    unsigned firstIter = 0;
    unsigned secIter = 0;
    unsigned resIter = 0;
    while(firstIter!=firstSize && secSize != secIter){
        res[resIter++] = (firstArr[firstIter] < secondArr[secIter] ? firstArr[firstIter++] : secondArr[secIter++]);
    }

    while(firstIter != firstSize){
        res[resIter++] = firstArr[firstIter++];
    }

    while(secIter != secSize){
        res[resIter++] = secondArr[secIter++];
    }
}

template<class T>
void mergeStep(T* initialArr, size_t sizeArr, T* buff){

    if(sizeArr <= 1){
        return;
    }

    size_t mid = sizeArr/2;

    mergeStep(initialArr,mid,buff);//sort the firstPart
    mergeStep(initialArr+mid,sizeArr - mid,buff+mid);//sort the second part

    Merge(initialArr,mid,initialArr+mid,sizeArr-mid,buff);
    for (int i = 0; i < sizeArr; ++i) {
     initialArr[i] = buff[i];
    }

}


template<class T>
void mergeSort(T* arr, size_t sizeArr){
    if(!arr || sizeArr == 0){
        return;
    }

    T* buff = new T[sizeArr];

    mergeStep(arr,sizeArr,buff);
    delete[] buff;

}


int main()
{
    int arr1[] = { 15,14,13,11,30,90,6,5,4,3,2,1};
    mergeSort(arr1, 12);

    for (int i = 0; i < 12; i++)
       std:: cout << arr1[i] << " ";
}