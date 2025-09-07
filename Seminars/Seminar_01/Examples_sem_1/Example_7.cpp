#include<iostream>
#include<cmath>

//Var 1:
bool isPrime(int num){

    if(n <= 1){
        return false;
    }

    for (int i = 2; i <= sqrt(num) ; ++i) {
        if(num%i)
            return false;
    }
    return true;
}

//Here on each iteration from 2 to sqrt(num) the func sqrt is called. Sqrt has complexity of log(n) so the final res will be O(sqrt(n)*log(n))

//Var 2:
bool isPrime(int num){

    if(n <= 1){
        return false;
    }

    int end = sqrt(num);
    for (int i = 2; i <= end; ++i) {
        if(num%i)
            return false;
    }
    return true;
}

//Here we only calculate sqrt(num) once.
// => The res is O(sqrt(num) + log(n)) = > but this is equal to O*(sqrt(num))(the biggerOne)