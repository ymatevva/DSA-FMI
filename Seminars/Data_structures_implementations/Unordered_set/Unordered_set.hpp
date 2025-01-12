#include<iostream>
#include<vector>
#include<forward_list>
#include<list>
#pragma once
using namespace std;

constexpr int MAX_LOAD_FACTOR = 0.75;

template<typename Key, typename Hash = std::hash<Key>>
class UnorderedSet {

	list<Key>data;
	vector<pair<typename list<Key>::iterator, size_t>> hashTable;

	Hash hash;

	size_t getBucketInd(const Key& key) const;
	double getCurrLoadFactor()const;
	void rehash(size_t newSize);

	typename list<Key>::iterator  getElByChainInd(size_t chainInd, const Key& key);
	typename list<Key>::const_iterator getElByChainInd(size_t chainInd, const Key& key) const;

public:
	UnorderedSet() {
		hashTable.resize(16, make_pair(data.end(), 0));
	}

	class ConstIter {
		typename list<Key>::const_iterator el;
		friend class UnorderedSet;
	public:
		ConstIter(typename list<Key>::const_iterator el) :el(el) {}
		ConstIter operator++() {
			ConstIter copy(*this);
			++(*this);
			return copy;
		}
		ConstIter& operator++(int dummy) {
			++el;
			return *this;
		}
		const Key& operator*()const {
			return *el;
		}
		const Key* operator->() const {
			return &(*el);
		}
		bool operator!=(const ConstIter& other) {
			return el != other.el;
		}
		bool operator==(const ConstIter& other) {
			return el == other.el;
		}
	};

	ConstIter cbegin() const {
		return ConstIter(data.cbegin());
	}
	ConstIter cend() const {
		return ConstIter(data.cend());
	}


	bool remove(const Key& key);
	bool remove(const ConstIter& iter);
	pair<bool, typename list<Key>::iterator> insert(const Key& key);
	ConstIter find(const Key& key) const;

};

template<typename Key, typename Hash>
inline size_t UnorderedSet<Key, Hash>::getBucketInd(const Key& key) const
{
	return hash(key) % hashTable.size();
}

template<typename Key, typename Hash>
inline double UnorderedSet<Key, Hash>::getCurrLoadFactor() const
{
	return static_cast<double>(data.size())/hashTable.size();
}

template<typename Key, typename Hash>
inline void UnorderedSet<Key, Hash>::rehash(size_t newSize)
{
	vector<Key>oldEls;
	ato it = data.begin();
	while (it != data.end()) {
		oldEls.push_back(*it);
		it++;
	}

	data.clear();
	hashTable.clear();
	hashTable.resize(newSize, make_pair(data.end(), 0));

	auto it = oldEls.begin();
	while (it != oldEls.end()) {
		insert(*it);
		it++;
	}
}

template<typename Key, typename Hash>
inline typename list<Key>::iterator UnorderedSet<Key, Hash>::getElByChainInd(size_t chainInd, const Key& key)
{
	size_t chainSize = hashTable[chainInd].second;
	if (!chainSize) {
		return data.end();
	}

	for (auto iter : hashTable[chainInd].first) {
		if (*iter == key) {
			return iter;
		}
	}

	return data.end();
}

template<typename Key, typename Hash>
inline typename list<Key>::const_iterator UnorderedSet<Key, Hash>::getElByChainInd(size_t chainInd, const Key& key) const
{
	size_t chainSize = hashTable[chainInd].second;
	if (!chainSize) {
		return data.cend();
	}

	for (auto iter : hashTable[chainInd].first) {
		if (*iter == key) {
			return iter;
		}
	}

	return data.cend();
}

template<typename Key, typename Hash>
inline bool UnorderedSet<Key, Hash>::remove(const Key& key)
{
	if (!hashTable.size()) {
		return false;
	}

	size_t bucketInd = getBucketInd(key);
	typename list<Key>::iterator found = getElByChainInd(bucketInd, key);

	if (found == cend()) {
		return false;
	}

	 pair<typename list<Key>::iterator,size_t>& bucket = hashTable[bucketInd];
	if (found == bucket.first) {
		typename list<Key>::iterator nextIt = found;
		nextIt++;
		bucket.first = nextIt;
	}
	
	data.erase(found);
	bucket.second--;
	return true;
}

template<typename Key, typename Hash>
inline bool UnorderedSet<Key, Hash>::remove(const ConstIter& iter)
{
	if (hashTable.size() == 0 || iter == data.cend()) {
		return;
	}

	return remove(*iter);
}

template<typename Key, typename Hash>
  pair<bool, typename list<Key>::iterator> UnorderedSet<Key, Hash>::insert(const Key& key)
{
	  if (hashTable.empty()) {
		  hashTable.resize(16, make_pair(data.cend(), 0));
	  }

	  size_t bucketInd = getBucketInd(key);
	  typename list<Key>::iterator found = getElByChainInd(bucketInd, key);

	  if (found != cend()) {
		  return make_pair(false, ConstIter(found));
	  }

	  pair<typename list<Key>::iterator, size_t>& bucket = hashTable[bucketInd];

	  if (bucket.second == 0) {
		  data.push_front(key);
		  bucket.first = data.begin();
	  }
	  else {
		  typename list<Key>::iterator newIt = data.insert(bucket.first, key);
		  bucket.first = newIt;
	  }

	  if (getCurrLoadFactor() > MAX_LOAD_FACTOR) {
		  resize(hashTable.size() * 2);
		  size_t newBucketInd = getBucketInd(key);
		  typename list<Key>::iterator newIt = getElByChainInd(bucketInd, key);
		  return make_pair(true, ConstIter(newIt);
	  }
	  return make_pair(true, ConstIter(found));
}

template<typename Key, typename Hash>
typename UnorderedSet<Key, Hash>::ConstIter UnorderedSet<Key, Hash>::find(const Key& key) const
{
	if (!hashTable.size()) {
		return cend();
	}

	size_t bucketInd = getBucketInd(key);
	typename list<Key>::iterator found = getElByChainInd(bucketInd, key);

	if (found == cend()) {
		return ConstIter(data.cend());
	}
	return ConstIter(found);

}
