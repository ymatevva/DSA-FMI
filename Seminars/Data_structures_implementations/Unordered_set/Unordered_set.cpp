#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include<list>
#pragma once

using namespace std;

//!!!the implementation hasnt been tested and contains logic issues

constexpr double MAX_LOAD_FACTOR = 0.75;

template<typename Key, typename Hash = std::hash<Key>>
class UnorderedSet {

	list<Key>data;//we store the elemnts in doubly linked list for fast remove/insert
	vector<pair<typename list<Key>::iterator, size_t>> hashT;//we have iterators to our lists of elements with the same hash and also the sec part of the hasT is how many elements there are in one bucket

	size_t elCount = 0;//totalElcount 
	Hash hash;


	typename list<Key>::iterator getChainByInd(size_t chainInd, const Key& el);//with this func we get iterator to the chain in which is the concrete el
	typename list<Key>::const_iterator getChainByInd(size_t chainInd, const Key& el)const ;
	size_t getBucketInd(const Key& el)const;// we get the index of the chain in which the element 
	double getCurrLoadF() const;
public:
	class ConstIter {
		typename list<Key>::const_iterator el;
		friend class UnorderedSet;
	public:
		ConstIter(typename list<Key>::const_iterator el) : el(el) {}
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
		const Key* operator->()const {
			return &(*el);
		}
		//op==/op!= too

	};


	pair<bool, typename list<Key>::iterator> insert(const Key& el);
	ConstIter find(const Key& el) const;
	bool remove(const ConstIter& iter);
	bool remove(const Key& el);
	void rehash(size_t newSize);
	

	bool empty()const;
	size_t getSize()const;
	void clear();
};

template<typename Key, typename Hash>
typename list<Key>::iterator UnorderedSet<Key, Hash>::getChainByInd(size_t chainInd, const Key& el)
{
	//first we should check if the bucket with this ind is empty
	size_t elInBucket = hashT[chainInd].second;

	if (!elInBucket) {
		return data.end();
	}

	//if it is not empty then we should find the concrete el and return iterator to it

	for (auto iter : hashT[chainInd].first) {
		if (*iter == el) {
			return iter;
		}
	}

	//if we haven found the element then we  return invalid it
	return data.end();
}

template<typename Key, typename Hash>
typename list<Key>::const_iterator UnorderedSet<Key, Hash>::getChainByInd(size_t chainInd, const Key& el) const
{
	//first we should check if the bucket with this ind is empty
	size_t elInBucket = hashT[chainInd].second;

	if (!elInBucket) {
		return data.cend();
	}

	//if it is not empty then we should find the concrete el and return iterator to it

	for (auto iter : hashT[chainInd].first) {
		if (*iter == el) {
			return iter;
		}
	}

	//if we haven found the element then we  return invalid it
	return data.cend();
}

template<typename Key, typename Hash>
size_t UnorderedSet<Key, Hash>::getBucketInd(const Key& el) const
{
	return hash(el)% hastT.size();
}

template<typename Key, typename Hash>
double UnorderedSet<Key, Hash>::getCurrLoadF() const
{
	return static_cast<double>(elCount) / hashT.size();
}

template<typename Key, typename Hash>
pair<bool, typename list<Key>::iterator> UnorderedSet<Key, Hash>::insert(const Key& el)
{
	if (hashT.empty()) {
		hashT.resize(16, make_pair(data.end(), 0));
	}

	size_t bI = getBucketInd(el);
	auto found = getChainByInd(bI, el);

	if (found != cend()) {
		return make_pair(false, ConstIter(found));
	}

	auto& bucket = hashT[bI];

	if (bucket.second == 0) {
		data.push_front(el);
		bucket.first = data. begin();
	}
	else {
		auto it = data.insert(bucket.first,el);
		bucket.first = it;

	}

	bucket.second++;
	elCount++;

	double currLF = getCurrLoadF();
	if (currLF > MAX_LOAD_FACTOR) {
		rehash(hashT.sisze() * 2);
		auto newPlace = getChainByInd(getBucketInd(el), el);
		return make_pair(true, CI(newPlace));
	}

	return make_pair(true, CI(bucket.first));
}

template<typename Key, typename Hash>
UnorderedSet<Key, Hash>::ConstIter UnorderedSet<Key, Hash>::find(const Key& el) const
{
	if (hashT.empty()) {//if there are no elements then this el wont be found -> cend()
		return cend();
	}

	size_t bI = getBucketInd(el);
	typename list<Key>::const_iterator found = getChainByInd(bI, el);// then we search for it

	if (found == cend()) {
		return cend();
	}

	return ConstIter(found);
}

template<typename Key, typename Hash>
bool UnorderedSet<Key, Hash>::remove(const ConstIter& iter)
{
	if (hashT.empty() || iter == cend()) {// if we want to remove inavlid value or there are no elements
		return false;
	}

	return remove(*iter);
}

template<typename Key, typename Hash>
bool UnorderedSet<Key, Hash>::remove(const Key& el)
{
	if (hashT.empty()) {
		return false;//if we want to remove le but the set empty then -> false
	}

	size_t bI = getBucketInd(el);
	typename list<Key>::iterator found = getChainByInd(bI, el);
	if (found == cend()) {// if not found =>false
		retrun false;
	}

	pair<typename list<Key>::iterator, size_t>& bucket = hashT[bI];
	// if we have found the el then we should get the bucket where it is in 

	if (found == bucket.first) {// if it is the start el then we should move the start to the next el
		typename list<Key>::next = found;
		next++;
		bucket.first = next;
	}

	data.erase(found);//removing the element form the list
	elCount--;
	bucket.second--;//we  decrease the size of the current bucket
	return true;

}

template<typename Key, typename Hash>
void UnorderedSet<Key, Hash>::rehash(size_t newSize)
{
	vector<Key>oldElements;// we put the old elements in vector 
	auto dataBeg = data.begin();
	while (dataBeg != data.end()) {
		oldElements.push_back(*dataBeg);
		dataBeg++;
	}

	data.clear();// restart the hashT and the list of elements and increase the size
	hashT.clear();
	hashT.resize(newSize, make_pair(data.end(), 0));
	elCount = 0;

	// then we put the elemnst back
	auto it = oldElements.begin();

	while (it != oldElements.end()) {
		insert(*it);
		it++;
	}

}

template<typename Key, typename Hash>
bool UnorderedSet<Key, Hash>::empty() const
{
	return elCount = 0;
}

template<typename Key, typename Hash>
size_t UnorderedSet<Key, Hash>::getSize() const
{
	return elCount;
}

template<typename Key, typename Hash>
void UnorderedSet<Key, Hash>::clear()
{
	data.clear();
	hashT.clear();
	elCount = 0;
}
