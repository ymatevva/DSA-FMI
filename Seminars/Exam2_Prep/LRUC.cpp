#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<list>
using namespace std;

//
//class LRUCache {
//
//	list<pair<int, int>> data;
//	using listIter = typename list<pair<int,int>>::iterator;
//	unordered_map<int, listIter> dataMap;
//	
//	size_t capacity;
//public:
//	LRUCache(size_t capacity) :capacity(capacity) {}
//	int get(int key) {
//
//		if (dataMap.find(key) == dataMap.cend()) {
//			return -1;
//		}
//
//		auto it = dataMap[key];
//		data.splice(data.begin(), data, it);//we move this item at the beginig of data to show that we have used it
//		return it->second;
//	}
//
//	void put(int key, int val) {
//
//		if (dataMap.find(key) != dataMap.cend()) {
//			auto it = dataMap[key];
//			data.erase(it);//if we have the element we erase it
//		}
//
//		data.push_front({ key,val });//then we put the element in the begining 
//		dataMap[key] = data.begin();
//
//		if (data.size() > capacity) {//if we have reached cap we remove the last element from the data and the data map(least recently used)
//			dataMap.erase(data.back().first);
//			data.pop_back();
//		}
//		 
//	}
//};


template<typename Key,typename Value>
class LRUC {

	list<std::pair<Key, Value>> data;
	using CacheListIterator = typename list<std::pair<Key, Value>> ::iterator;
	unordered_map<Key, CacheListIterator> dataMap;
	size_t cap;
public:
	LRUC(size_t cap) :cap(cap) {}
	const Value& get(const Key& key){
	   
		if (dataMap.find(key) == dataMap.cend()) {
			return -1;
		}

		auto it = dataMap[key];
		data.splice(data.begin(), data, it);
		dataMap[key] = data.begin();
		return it->second;
	}
	void put(const Key& key, const Value& value) {

		if (dataMap.find(key) != dataMap.cend()) {
			auto it = dataMap[key];
			data.erase(it);
		}

		data.push_front({ key,value });
		dataMap[key] = data.begin();
		if (data.size() > cap) {
			dataMap.erase(data.back().first);
			data.pop_back();
		}
	}

};

int main() {
	LRUC<string,int> lru(2); // Capacity of 2
	lru.put("first", 1);   // Cache: [(1, 1)]
	lru.put("second", 2);   // Cache: [(2, 2), (1, 1)]
	std::cout << lru.get("first") << "\n"; // Output: 1, Cache: [(1, 1), (2, 2)]
	lru.put("third", 3);   // Cache: [(3, 3), (1, 1)] (evicts key 2)
	std::cout << lru.get("second") << "\n"; // Output: -1 (not found)
	lru.put("fourth", 4);   // Cache: [(4, 4), (3, 3)] (evicts key 1)
	std::cout << lru.get("first") << "\n"; // Output: -1 (not found)
	std::cout << lru.get("third") << "\n"; // Output: 3, Cache: [(3, 3), (4, 4)]
	std::cout << lru.get("fourth") << "\n"; // Output: 4, Cache: [(4, 4), (3, 3)]
}