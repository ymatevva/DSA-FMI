#include"Browser.h"
//Used materials:
//For the sorting: https://github.com/Angeld55/Data_structures_and_algorithms_FMI/blob/main/Miscellaneous/singlyLinkedList_mergeSort.cpp
//https://github.com/Angeld55/Data_structures_and_algorithms_FMI/blob/main/DoublyLinkedList/DoublyLinkedList.hpp

void inputCommand() {

	Browser browser;

	std::cout << "Welcome to the browser." << '\n';
    std::cout << "For searching a concrete page:  GO "<< '\n';
    std::cout << "For adding a new tab :  INSERT "<< '\n';
    std::cout << "For removing the current tab:  REMOVE "<< '\n';
    std::cout << "For switching to the previous tab: BACK "<< '\n';
    std::cout << "For switching to the next tab:  FORWARD "<< '\n';
    std::cout << "For sorting the tabs:  SORT "<< '\n';
    std::cout << "For printing all tabs: PRINT "<< '\n';
    std::cout << "For closing the browser: END "<< '\n';

	while (true) {

		std::string command;
		std::cout << "Input command: " << std::endl;
		std::cin >> command;

		if (command == "GO") {
			
			std::string pageName;
			std::cout << "Enter name of the page: " << '\n';
			std::cin >> pageName;
			browser.go(pageName);
		}
		else if (command == "INSERT") {
			std::string newTabName;
			std::cout << "Enter name of the page of the new tab: " << '\n';
			std::cin >> newTabName;
			browser.insert(newTabName);
		}
		else if (command == "REMOVE") {
			browser.remove();
		}
		else if (command == "BACK") {
			browser.back();
		}
		else if (command == "FORWARD") {
			browser.forward();
		}
		else if (command == "PRINT") {
			browser.print();
		}
		else if (command == "SORT") {
			std::cout << "For sorting by time: TIME. For sorting by URL: URL." << std::endl;
				std::string sortBy;
				std::cin >> sortBy;
				if (sortBy == "TIME") {
					browser.sort("TIME");
				}
				else if (sortBy == "URL") {
					browser.sort("URL");
				}
		}
		else if (command == "END") {
			break;
		}
		else {
			std::cout << "Invalid command. Try again." << '\n';
		}

	}
}

int main() {

	inputCommand();
	return 0;
}

