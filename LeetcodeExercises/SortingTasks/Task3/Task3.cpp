#include<iostream>
#include<vector>


vector<int> findErrorNums(vector<int>& nums) {
      
      vector<int> countEl(nums.size(),0);
      for(int i = 0; i < nums.size();i++){
        countEl[nums[i]-1]++;
      }

      vector<int>res(2,0);
      for(int i = 0; i < countEl.size();i++){
        if(countEl[i]==2){
            res[0] = i+1;
        }
        else if(countEl[i]==0){
            res[1] = i+1;
        }
      }
      return res;
    }

int main(){

vector<int> vec = {1,1,3};
vector<int> res = findErrorNums(vec);
for(int i = 0; i < 2;i++){
std::cout << res[i];
}
