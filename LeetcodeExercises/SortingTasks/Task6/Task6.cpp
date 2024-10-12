#include<iostream>
#include<algorithm>
using namespace std;

bool checkIfExist(vector<int>& arr) {

    vector<int> sorted= arr;
    sort(sorted.begin(),sorted.end());

    for (int i = 0; i < sorted.size() ; ++i) {

        int left = 0;
        int right = sorted.size()-1;

        while(left < right){

            int curPos = left + (right-left)/2;
            if(sorted[curPos]*2 == sorted[i] && curPos != i){
                return true;
            }
            else if(sorted[curPos]*2 < sorted[i]){
                left++;
            }
            else{
                right--;
            }
        }
    }
return false;
}
int main(){

vector<int> vec = {-2,0,10,-19,4,6,-8};
std::cout << std::boolalpha <<checkIfExist(vec);
return 0;
}