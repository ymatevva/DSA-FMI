#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void canBeBalanced(vector<int>& elements,size_t numElements) {
   
    sort(elements.begin(), elements.end());

    for (int i = numElements-1; i >= 0; i--)
    {
        int leftPos = 0;
        int rightPos = i - 1;
        int el = elements[i];

        while (leftPos < rightPos) {
          
            int sum = elements[leftPos] + elements[rightPos];

            if (sum == el) {
                return true;
            }

            else if (sum < el) {
                leftPos++;
            }
            else {
                rightPos--;
            }
        }
    }
    return false;
}
 
int main() {
    

    vector<int> vec = { 2,3,4,5,10 };
    
    std::cout << canBeBalanced(vec,5) << std::endl;

}