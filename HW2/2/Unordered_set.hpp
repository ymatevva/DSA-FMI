#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <functional>
using namespace std;

//https://github.com/Angeld55/Data_structures_and_algorithms_FMI/blob/main/SeparateChainingHash_InsertionOrder/InsertionOrderHashMap.hpp
//For remove/remove_if functions i used method erase_after of forward list : https://stackoverflow.com/questions/47625749/how-to-move-or-delete-a-specific-element-in-stdforward-list
namespace Constants {
	constexpr double MAX_LOAD_FACTOR = 0.75;
}

template <typename Key, typename Hash = std::hash<Key>>
class UnorderedSet {

	std::vector<std::forward_list<Key>> buckets;
	Hash myHash;

	size_t getHashCode(const Key& key) const;
	void resize();

public:
	class Iterator {
		typename std::vector<std::forward_list<Key>>::iterator bucketIt;
		typename std::forward_list<Key>::iterator listIt;

		std::vector<std::forward_list<Key>>& buckets;

		friend class UnorderedSet;

		Iterator(std::vector<std::forward_list<Key>>& buckets, typename std::vector<std::forward_list<Key>>::iterator bucketIt,
			typename std::forward_list<Key>::iterator listIt)
			: buckets(buckets), bucketIt(bucketIt), listIt(listIt) {}

	public:
		Key& operator*() {
			return *listIt;
		}

		Key* operator->() {
			return &(*listIt);
		}
		Iterator& operator++() {
			listIt++;

			while (bucketIt != buckets.end() && listIt == bucketIt->end()) {
				++bucketIt;

				listIt = (bucketIt != buckets.end()) ? bucketIt->begin() : typename std::forward_list<Key>::iterator();
			}

			if (bucketIt == buckets.end()) {
				listIt = typename std::forward_list<Key>::iterator();
			}

			return *this;
		}
		
		Iterator operator++(int dummy) {
			Iterator copy(*this);
			++(*this);
			return copy;
		}

		bool operator==(const Iterator& other) const {
			return bucketIt == other.bucketIt && listIt == other.listIt;
		}

		bool operator!=(const Iterator& other) const {
			return !(*this == other);
		}
	};


	class ConstIterator {
		typename std::vector<std::forward_list<Key>>::const_iterator bucketIt;
		typename std::forward_list<Key>::const_iterator listIt;

		const std::vector<std::forward_list<Key>>& buckets;

		friend class UnorderedSet;

		ConstIterator(const std::vector<std::forward_list<Key>>& buckets, typename std::vector<std::forward_list<Key>>::const_iterator bucketIt,
			typename std::forward_list<Key>::const_iterator listIt)
			: buckets(buckets), bucketIt(bucketIt), listIt(listIt) {}

	public:
		const Key& operator*() const {
			return *listIt;
		}

		const Key* operator->() const {
			return &(*listIt);
		}

		ConstIterator& operator++() {
			listIt++;

			while (bucketIt != buckets.cend() && listIt == bucketIt->end()) {
				bucketIt++; 
				
				listIt = (bucketIt != buckets.cend()) ? bucketIt->begin() : typename std::forward_list<Key>::const_iterator();
 			}

			if (bucketIt == buckets.cend()) {
				listIt = typename std::forward_list<Key>::const_iterator(); 
			}

			return *this;
		}

		ConstIterator operator++(int dummy) {
			ConstIterator copy(*this);
			++(*this);
			return copy;
		}

		bool operator==(const ConstIterator& other) const {
			return bucketIt == other.bucketIt && listIt == other.listIt;
		}

		bool operator!=(const ConstIterator& other) const {
			return !(*this == other);
		}
	};

public:
	UnorderedSet();
	size_t getBucketCount() const;
	void insert(const Key& el);

	bool remove(const Key& el);
	ConstIterator remove(ConstIterator& iter);

	ConstIterator find(const Key& el) const;

	bool empty() const;
	size_t getElementsCount() const;
	double getLoadFactor() const;

	template<typename Predicate>
	void erase_if(Predicate predicate);
	void clear();
	
	Iterator begin();
	Iterator end();

	ConstIterator cbegin() const;
	ConstIterator cend() const;
};

template<typename Key, typename Hash>
size_t UnorderedSet<Key, Hash>::getHashCode(const Key& key) const {
	return myHash(key) % buckets.size();
}

template<typename Key, typename Hash>
void UnorderedSet<Key, Hash>::resize() {

	size_t newBucketCount = buckets.size() * 2;

	std::vector<std::forward_list<Key>> tmp(newBucketCount);

	for (const auto& bucket : buckets) {
		for (const auto& el : bucket) {
			size_t newBucketInd = getHashCode(el) % newBucketCount;
			tmp[newBucketInd].push_front(el);
		}
	}

	buckets = std::move(tmp);
}

template<typename Key, typename Hash>
UnorderedSet<Key, Hash>::UnorderedSet() {
	buckets.resize(8);
}

template<typename Key, typename Hash>
inline size_t UnorderedSet<Key, Hash>::getBucketCount() const
{
		return buckets.size();
	
}

template<typename Key, typename Hash>
void UnorderedSet<Key, Hash>::insert(const Key& el) {
	if (getLoadFactor() >= Constants::MAX_LOAD_FACTOR) {
		resize();
	}

	size_t elBucketInd = getHashCode(el);
	auto& elBucket = buckets[elBucketInd];


	auto iter = std::find_if(elBucket.begin(), elBucket.end(), [&el](const auto& it) {
		return it == el;
		});

	if (iter != elBucket.end()) {
		return;
	}

	elBucket.push_front(el);
}

template<typename Key, typename Hash>
bool UnorderedSet<Key, Hash>::remove(const Key& el) {

	if (empty()) {
		throw std::exception("The set is empty.");
	}

	size_t elBucketInd = getHashCode(el);
	auto& elBucket = buckets[elBucketInd];

	auto prev = elBucket.before_begin();

	for (auto it = elBucket.begin(); it != elBucket.end(); it++) {
		if (*it == el) {
			elBucket.erase_after(prev);
			break;
		}

		prev = it;
	}

}

template<typename Key, typename Hash>
typename UnorderedSet<Key, Hash>::ConstIterator UnorderedSet<Key, Hash>::remove(ConstIterator& iter) {

	if (empty()) {
		throw std::exception("The set is empty.");
	}

	if (iter == cend() || find(*iter) == cend()) {
		return cend();
	}

	size_t elBucketInd = getHashCode(*iter);
	auto& elBucket = buckets[elBucketInd];

	auto prev = elBucket.before_begin();
	auto curr = elBucket.begin();

	while(curr != elBucket.end()){
		if (*curr == *iter) {
			break;
		}
		prev = curr;
		++curr;
	}

	curr = elBucket.erase_after(prev);

	while (curr == elBucket.end() && ++iter.bucketIt != buckets.end() && iter.bucketIt->empty()) {}

	if (iter.bucketIt != buckets.end()) {
		return ConstIterator(buckets, iter.bucketIt, iter.bucketIt->begin());
	}

	return cend();


}

template<typename Key, typename Hash>
typename UnorderedSet<Key, Hash>::ConstIterator UnorderedSet<Key, Hash>::find(const Key& el) const {
	size_t elBucketInd = getHashCode(el);
	const auto& elBucket = buckets[elBucketInd];

	auto iter = std::find_if(elBucket.begin(), elBucket.end(), [&el](const auto& it) {
		return it == el;
		});

	if (iter != elBucket.end()) {
		return ConstIterator(buckets, buckets.begin() + elBucketInd, iter);
	}

	return cend();
}

template<typename Key, typename Hash>
bool UnorderedSet<Key, Hash>::empty() const {
	return getElementsCount() == 0;
}

template<typename Key, typename Hash>
void UnorderedSet<Key, Hash>::clear() {
	for (auto& bucket : buckets) {
		bucket.clear();
	}
	buckets.clear();
}

template<typename Key, typename Hash>
size_t UnorderedSet<Key, Hash>::getElementsCount() const {
	size_t countElements = 0;
	for (const auto& bucket : buckets) {
		for (const auto& iter : bucket) {
			countElements++;
		}
	}
	return countElements;
}

template<typename Key, typename Hash>
double UnorderedSet<Key, Hash>::getLoadFactor() const {
	return static_cast<double>(getElementsCount()) / buckets.size();
}

template<typename Key, typename Hash>
template<typename Predicate>
void UnorderedSet<Key, Hash>::erase_if(Predicate predicate) {
	for (auto& bucket : buckets) {
		auto prev = bucket.before_begin();
		for (auto it = bucket.begin(); it != bucket.end();) {
			if (predicate(*it)) {
				it = bucket.erase_after(prev);
			}
			else {
				prev = it; 
				++it;      
			}
		}
	}
}

template<typename Key, typename Hash>
typename UnorderedSet<Key, Hash>::Iterator UnorderedSet<Key, Hash>::begin() {
	for (auto bucketIt = buckets.begin(); bucketIt != buckets.end(); bucketIt++) {
		if (!bucketIt->empty()) {
			return Iterator(buckets, bucketIt, bucketIt->begin());
		}
	}
	return end();
}

template<typename Key, typename Hash>
typename UnorderedSet<Key, Hash>::Iterator UnorderedSet<Key, Hash>::end() {
	return Iterator(buckets, buckets.end(), typename std::forward_list<Key>::iterator());
}
template<typename Key, typename Hash>
typename UnorderedSet<Key, Hash>::ConstIterator UnorderedSet<Key, Hash>::cbegin() const {
	for (auto bucketIt = buckets.cbegin(); bucketIt != buckets.cend(); bucketIt++) {
		if (!bucketIt->empty()) {
			return ConstIterator(buckets, bucketIt, bucketIt->cbegin());
		}
	}
	return cend();
}

template<typename Key, typename Hash>
typename UnorderedSet<Key, Hash>::ConstIterator UnorderedSet<Key, Hash>::cend() const {
	return ConstIterator(buckets, buckets.cend(), typename std::forward_list<Key>::const_iterator());
}
