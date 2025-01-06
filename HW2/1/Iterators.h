#pragma once
#include<vector>
#include"Traversal.h"

class ConstIterator {
	const Traversal* collectionIter;
public:
	ConstIterator(const Traversal* iter) :collectionIter(iter) {}
	const Traversal& operator*() const {
		return *collectionIter;
	}
	const Traversal* operator->() const {
		return &(*collectionIter);
	}
	ConstIterator& operator++() {
		collectionIter++;
		return (*this);
	}
	ConstIterator operator++(int dummy) {
		ConstIterator copy(*this);
		++(*this);
		return copy;
	}
	bool operator==(const ConstIterator& other) {
		return collectionIter == other.collectionIter;
	}
	bool operator!=(const ConstIterator& other) {
		return !(*this == other);
	}
};


class Iterator {
	Traversal* collectionIter;
public:
	Iterator(Traversal* iter) :collectionIter(iter) {}
	Traversal& operator*() {
		return *collectionIter;
	}
	Traversal* operator->() {
		return &(*collectionIter);
	}

	Iterator& operator++() {
		collectionIter++;
		return (*this);
	}
	Iterator operator++(int dummy) {
		Iterator copy(*this);
		++(*this);
		return copy;
	}

	bool operator==(const Iterator& other) {
		return collectionIter == other.collectionIter;
	}
	bool operator!=(const Iterator& other) {
		return !(*this == other);
	}
};