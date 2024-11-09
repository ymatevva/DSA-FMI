#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;


int calPoints(vector<string>& operations) {

    int totalSum = 0;

    stack<int>myStack;
    for (int i = 0; i < operations.size(); i++) {

        if (operations[i] == "C") {
            myStack.pop();
        }
        else if (operations[i] == "D") {
            myStack.push(myStack.top() * 2);
        }
        else if (operations[i] == "+") {
            int currSum = 0;
            stack<int>tmp = myStack;
            currSum += tmp.top();
            tmp.pop();
            currSum += tmp.top();
            myStack.push(currSum);
        }
        else {
            myStack.push(stoi(operations[i]));
        }
    }
    size_t end = myStack.size();
    for (int i = 0; i <end ; i++) {
        totalSum += (myStack.top());
        myStack.pop();
    }
    return totalSum;
}


int main() {

    std::vector<std::string> tokens = { "5","2","C","D","+" };
    std::cout << "Result: " << calPoints(tokens) << std::endl; // Output: 9
    return 0;
}