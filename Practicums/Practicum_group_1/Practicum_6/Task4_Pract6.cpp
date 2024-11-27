#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<iomanip>
#include<string>w

using namespace std;

//Leetcode: 1823
//https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=problem-list-v2&envId=awthx4gv

int findTheWinner(int n, int k) {

	std::queue<int> friendsInGame;
	for (size_t i = 1; i <= n; i++)
	{
		friendsInGame.push(i);
	}
	while (friendsInGame.size() != 1) {

		for (size_t i = 1; i < k; i++)
		{
			int currFr = friendsInGame.front();
			friendsInGame.pop();
			friendsInGame.push(currFr);
		}
		friendsInGame.pop();
	}
	return friendsInGame.front();
}
int main() {

	std::cout << findTheWinner(5, 2);


	return 0;
}