#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int findKthLargest(vector<int>& nums, int k) {

    priority_queue<int> tmp;
    for (int i = 0; i < nums.size(); i++) {
        tmp.push(nums[i]);
    }

    size_t count = k - 1;
    while (count--) {
        tmp.pop();
    }
    return tmp.top();

}

int main() {

    vector<int> vec = { 1,7,2,3,9 };
    std::cout << findKthLargest(vec, 2);
}