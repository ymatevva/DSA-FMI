#include<iostream>

//Example 2:
int factoriel(int num){
    unsigned res = 1;
    while(num != 0){
        res*=num;
        num--;
    }
    return res;
}

//The complexity is O(n), bc the bigger the input the more steps the algorithm makes
