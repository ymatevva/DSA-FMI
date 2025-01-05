#include "Browser.h"


void Browser::copyFrom(const Browser& other) {

	firstTab = lastTab = currTab = new Tab();
	countOfTabs = 1;

	currTab->loadNewPage(other.firstTab->URL);

	Tab* otherIter = other.firstTab->next;

	while (otherIter != nullptr) {
		insert(otherIter->URL);
		otherIter = otherIter->next;
	}

	//searching the new current tab

	Tab* newIter = firstTab;
	otherIter = other.firstTab;


	while (otherIter != nullptr && otherIter != other.currTab) {
		newIter = newIter->next;
		otherIter = otherIter->next;
	}

	currTab = newIter;
}

void Browser::moveFrom(Browser&& other) {

	firstTab = other.firstTab;
	lastTab = other.lastTab;
	currTab = other.currTab;
	countOfTabs = other.countOfTabs;

	other.firstTab = nullptr;
	other.lastTab = nullptr;
	other.currTab = nullptr;
	other.countOfTabs = 0;
}

void Browser::free() {
	Tab* iter = firstTab;

	while (iter != nullptr) {

		Tab* currToDel = iter;
		iter = iter->next;
		delete currToDel;
	}
	firstTab = lastTab = currTab = nullptr;
	countOfTabs = 0;
}

Browser::Tab* Browser::mergeSort(Tab* firstTab, const std::string& sortBy)
{
	if (!firstTab || !firstTab->next) {
		return firstTab;
	}

	Tab* mid = split(firstTab);
	Tab* left = firstTab;
	Tab* right = mid->next;

	if (right) {
		right->prev = nullptr;
	}
	mid->next = nullptr;
	left = mergeSort(left, sortBy);
	right = mergeSort(right, sortBy);

	return mergeLists(left, right, sortBy);
}

Browser::Tab* Browser::split(Tab* firstTab)
{
	Tab* fast = firstTab->next;
	Tab* slow = firstTab;

	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;

}
void Browser::pushBack(Tab*& resultBegin, Tab*& resultEnd, Tab* toAdd) {
	if (!resultBegin) {
		resultBegin = resultEnd = toAdd;
	}
	else {
		resultEnd->next = toAdd;
		toAdd->prev = resultEnd;
		resultEnd = toAdd;
	}
}

bool Browser::compareNodes(Tab* a, Tab* b, const std::string& sortBy)const
{
	if (sortBy == "URL") return a->URL < b->URL || (a->URL == b->URL && a->timeOfLoading < b->timeOfLoading);
	if (sortBy == "TIME") return a->timeOfLoading < b->timeOfLoading || (a->timeOfLoading == b->timeOfLoading && a->URL < b->URL);
}

Browser::Tab* Browser::mergeLists(Tab* first, Tab* second, const std::string& sortBy)
{
	Tab* resultBegin = nullptr;
	Tab* resultEnd = nullptr;

	while (first && second)
	{
	
		if (compareNodes(first, second, sortBy)) {
			pushBack(resultBegin, resultEnd, first);
			first = first->next;
		}
		else {
			pushBack(resultBegin, resultEnd, second);
			second = second->next;
		}
	}

	if (!first) {
		pushBack(resultBegin, resultEnd, second);
	}
	else {
		pushBack(resultBegin, resultEnd, first);
	}
	return resultBegin;
}



Browser::Browser() : countOfTabs(1) {
	currTab = lastTab = firstTab = new Tab();
}



Browser::Browser(const Browser& other) :firstTab(nullptr), lastTab(nullptr), currTab(nullptr)
{
	copyFrom(other);
}

Browser& Browser::operator=(const Browser& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Browser::Browser(Browser&& other) noexcept {
	moveFrom(std::move(other));
}

Browser& Browser::operator=(Browser&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Browser::~Browser() {
	free();
}

void Browser::go(const std::string URL) {
	currTab->loadNewPage(URL);
}


size_t Browser::openedTabs() const {
	return countOfTabs;
}

void Browser::back() {
	if (currTab == firstTab) {
		return;
	}
	currTab = currTab->prev;
}

void Browser::forward() {
	if (currTab == lastTab) {
		return;
	}
	currTab = currTab->next;
}

void Browser::insert(const std::string URL)
{
	Tab* toAdd = new Tab(URL);

	toAdd->next = currTab->next;
	toAdd->prev = currTab;

	if (currTab->next != nullptr) {
		currTab->next->prev = toAdd;
	}
	else {
		lastTab = toAdd;
	}

	currTab->next = toAdd;
	currTab = toAdd;
	countOfTabs++;
}
void Browser::remove() {

	if (countOfTabs == 1) {
		free();
		firstTab = lastTab = currTab = new Tab();
		countOfTabs = 1;
		return;
	}

	Tab* toDel = currTab;


	if (toDel->prev != nullptr) {
		toDel->prev->next = toDel->next;
	}
	else {
		firstTab = toDel->next;//if it is pop_front 
	}

	if (toDel->next != nullptr) {
		toDel->next->prev = toDel->prev;
		currTab = toDel->next;//the new currTab is dependent on whether the next element is nullptr 
	}
	else {
		lastTab = toDel->prev;//if it is pop_back
		currTab = toDel->prev;//if the next element has been nullptr
	}

	delete toDel;
	countOfTabs--;
}

void Browser::print() const {
	Tab* iter = firstTab;

	while (iter != nullptr) {

		if (iter == currTab) {
			std::cout << ">" << iter->URL << " " << iter->timeOfLoading << '\n';
		}
		else {
			std::cout << iter->URL << " " << iter->timeOfLoading << '\n';
		}
		iter = iter->next;
	}
}


void Browser::sort(const std::string& sortBy) {

	if (openedTabs() == 1) {
		return;
	}

	firstTab = mergeSort(firstTab, sortBy);
	currTab = firstTab;//the current tab becomes the first one
}
