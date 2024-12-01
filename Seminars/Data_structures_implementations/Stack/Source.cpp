#include <iostream>
#include "ArrayStack.hpp"
#include"LinkedStack.hpp"

int main()
{

	ArrayStack<int> arrStack;
	arrStack.push(3);
	arrStack.push(5);
	arrStack.push(7);
	std::cout << arrStack.getSize() << std::endl;
	std::cout << arrStack.peek() << std::endl;
	arrStack.pop();
	std::cout << arrStack.peek() << std::endl;

	ArrayStack<int> newArrStack = arrStack;
	std::cout << newArrStack.getSize() << std::endl;


	LinkedStack<int> list;
	list.push(15);
	list.push(20);
	std::cout << list.peek() << std::endl;
	list.pop();
	std::cout << list.empty() << std::endl;
	std::cout << list.peek() << std::endl;
	list.pop();

	list.push(100);

	LinkedStack<int> newList = list;
	std::cout << newList.peek() << std::endl;

	return 0;
}