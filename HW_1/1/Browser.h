#include<cstring>
#include<iostream>
#include<vector>
#include<ctime>
#pragma once


class Browser {

private:

	struct Tab {

		std::string URL;
		long long timeOfLoading;
		Tab* prev;
		Tab* next;

		Tab() : URL("about:blank"), timeOfLoading(std::time(nullptr)), next(nullptr), prev(nullptr) {}
		Tab(const std::string& URL) :URL(URL), timeOfLoading(time(nullptr)), prev(nullptr), next(nullptr) {}

		void loadNewPage(const std::string& URL) {
			this->URL = URL;
			this->timeOfLoading = time(nullptr);
		}
	};

	Tab* firstTab = nullptr;
	Tab* lastTab = nullptr;
	Tab* currTab = nullptr;
	size_t countOfTabs = 0;

	void copyFrom(const Browser& other);
	void moveFrom(Browser&& other);
	void free();
private:
	Tab* split(Tab* firstTab);
	bool compareNodes(Tab* a, Tab* b, const std::string& sortBy)const;
	Tab* mergeLists(Tab* first, Tab* second, const std::string& sortBy);
	Tab* mergeSort(Tab* firstTab, const std::string& sortBy);
	void pushBack(Tab*& resultBegin, Tab*& resultEnd, Tab* toAdd);
	size_t openedTabs() const;
public:
	Browser();
	Browser(const Browser& other);
	Browser& operator=(const Browser& other);
	Browser(Browser&& other)noexcept;
	Browser& operator=(Browser&& other)noexcept;
	~Browser();

	void go(const std::string URL);
	void insert(const std::string URL);

	void back();
	void forward();

	void remove();
	void print() const;

	void sort(const std::string& sortBy);
};

