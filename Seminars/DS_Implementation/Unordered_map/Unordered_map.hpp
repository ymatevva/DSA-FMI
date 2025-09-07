#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include<forward_list>
#include<list>
#pragma once

using namespace std;
constexpr int MAX_LOAD_FACTOR = 0.75;

template<typename Key,typename Value, typename Hash = std::hash<Key>>
class UnorderedMap {

	using Element =  pair<Key, Value>;

	list<Element> data;
	vector<forward_list<typename list<Element>::iterator>> hashT;
	Hash hash;

	size_t getBucketInd(const Key& key) const;
	double getCurrLoadFactor()const;
	void resize();
public:
	UnorderedMap();
	class ConstIter {
		typename list<Element>::const_iterator el;
		friend class UnorderedMap;
	public:
		ConstIter(typename list<Element>::const_iterator el) :el(el) {}
		ConstIter operator++() {
			ConstIter copy(*this);
			++(*this);
			return copy;
		}
		ConstIter& operator++(int dummy) {
			++el;
			return *this;
		}
		const Element& operator*() const {
			return *el;
		}
		const Element* operator->()const {
			return &(*el);
		}
		bool operator==(const ConstIter& other) {
			return el == other.el;
		}
		bool operator!=(const ConstIter& other) {
			return !(this == &other);
		}
	};

	ConstIter cend() const {
		return ConstIter(data.cend());
	}
	ConstIter cbegin()const {
		return ConstIter(data.cbegin());
	}

	ConstIter find(const Key& key) const;
	void add(const Key& key, const Value& val);
	void remove(const Key& key);
};

template<typename Key, typename Value, typename Hash>
size_t UnorderedMap<Key, Value, Hash>::getBucketInd(const Key& key) const
{
	return hash(key) % hashT.size();
}

template<typename Key, typename Value, typename Hash>
double UnorderedMap<Key, Value, Hash>::getCurrLoadFactor() const
{
	return static_cast<double>(data.size())/hashT.size();
}

template<typename Key, typename Value, typename Hash>
void UnorderedMap<Key, Value, Hash>::resize()
{
	size_t newTableSize = hashT.size() * 2;
	vector<forward_list<typename list<Element>::iterator>> newHTable;
	for (auto it = data.begin(); it != data.end(); it++) {
		size_t newBucketInd = getBucketInd(it->first);
		newHTable[newBucketInd].push_front(it);
	}

	hashT = move(newHTable);
}

template<typename Key, typename Value, typename Hash>
UnorderedMap<Key, Value, Hash>::UnorderedMap()
{
	hashT.resize(8);
}

template<typename Key, typename Value, typename Hash>
typename UnorderedMap<Key, Value, Hash>::ConstIter UnorderedMap<Key, Value, Hash>::find(const Key& key) const
{
	size_t bucketInd = getBucketInd(key);
	const auto& bucket = hashT[bucketInd];

	auto iter = find_if(bucket.begin(), bucket.end(), [&key](const auto& it) {
		return (it->first == key);
		});

	if (iter == bucket.cend()) {
		return cend();
	}
	return ConstIter(*iter);
}

template<typename Key, typename Value, typename Hash>
void UnorderedMap<Key, Value, Hash>::add(const Key& key, const Value& val)
{
	size_t bucketInd = getBucketInd(key);
	 auto& bucket = hashT[bucketInd];

	auto iter = find_if(bucket.begin(), bucket.end(), [&key](const auto& it) {
		return (it->first == key);
		});

	if (iter == bucket.cend()) {
		return ;
	}
	
	data.emplace_back(key);
	bucket.push_front(--data.end());
}

template<typename Key, typename Value, typename Hash>
void UnorderedMap<Key, Value, Hash>::remove(const Key& key)
{

	size_t bucketInd = getBucketInd(key);
	auto& bucket = hashT[bucketInd];

	bucket.remove_if([this, &key](const auto& it) {

		if (it->first == key) {
			bucket.erase(it);
			return true;
		}
	return false;
		});
}
