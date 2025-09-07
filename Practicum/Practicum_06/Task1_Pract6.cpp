#include<iostream>
#include<queue>
#include<stack>
#include<vector>

//Leetcode: 1700
//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=problem-list-v2&envId=awte4jlm

using namespace std;
int countStudentsWithoutLunch(vector<int>& students, vector<int>& sandwiches) {

	std::stack<int> sandwichStack;
	for (int i = sandwiches.size() - 1; i >= 0; i--) {
		sandwichStack.push(sandwiches[i]);
	}


	std::queue<int> studentsQ;
	for (int i = 0; i < students.size(); i++) {
		studentsQ.push(students[i]);
	}

	size_t initialStudentsCount = students.size();

	while (true) {

		unsigned count = 0;

		for (int i = 0; i < initialStudentsCount; i++) {

			if (studentsQ.front() == sandwichStack.top()) {
				sandwichStack.pop();
				studentsQ.pop();
			}
			else {
				int tmp = studentsQ.front();
				studentsQ.pop();
				studentsQ.push(tmp);
				count++;//we count how many students didnt like their lunch
			}
		}

		if (count == initialStudentsCount) {
			break;
		}
		initialStudentsCount = count;
	}
	return initialStudentsCount;
}
int main() {

	vector<int> vec1 = { 1,1,1,0,1,1 };
	vector<int> vec2 = {1, 0, 0, 0, 1, 1};

	std::cout << countStudentsWithoutLunch(vec1, vec2);
	return 0;
}