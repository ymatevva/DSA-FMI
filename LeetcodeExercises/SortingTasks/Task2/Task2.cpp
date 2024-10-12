#include<iostream>
#include<vector>
using namespace std;


int main() {

	int a = 0;
	int b = 4;
	if (b || a) {
		a++;
	}
	if(b&&a) {
		b++;
	}
	else if (b > a) {
		a += 4;
	}
	
	std::cout << a << b;;
	
}
