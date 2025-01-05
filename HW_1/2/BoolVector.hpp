#pragma once
#include"Iterators.hpp"
#include"Constants.h"

//Used materials:
// https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2006/Bitsets/DynamicSet/DynamicSet.h
// https://github.com/stoychoX/Data-structures-and-algorithms/blob/main/Seminar03/src/dynamic-array/iterator/iterator.hpp
// https://github.com/stoychoX/Data-structures-and-algorithms/blob/main/Seminar03/src/dynamic-array/vector/vector.hpp
//https://cplusplus.com/reference/vector/vector/operator[]/
//https://stackoverflow.com/questions/10144945/how-to-write-bool-operatorint-index-which-returns-reference-to-single-bit


template<typename Allocator = std::allocator<uint8_t>>
class BoolVector {
private:
	uint8_t* buckets = nullptr;
	unsigned countValues = 0;
	unsigned bucketsCount = 0;
	unsigned capacity = 0;
private:
	Allocator myAlloc;
	unsigned getElementIndex(unsigned count)const;
	unsigned getBucketIndex(unsigned count)const;
	unsigned createMask(unsigned pos)const;
private:
	void resize();
	void free();
	void copyFrom(const BoolVector& other);
	void moveFrom(BoolVector&& other);
public:
	BoolVector();
	BoolVector(const BoolVector& other);
	BoolVector& operator=(const BoolVector& other);
	BoolVector& operator=(BoolVector&& other)noexcept;
	BoolVector(BoolVector&& other)noexcept;
	~BoolVector();

	BitRef operator[](unsigned ind);
	bool operator[](unsigned ind)const;

	void push_back(bool value);
	void pop_back();
	void pop_front();

	size_t size()const;

	void insert(const Iterator& iter, bool value);
	void insert(const ConstIterator& iter, bool value);

	void remove(const Iterator& iter);
	void remove(const ConstIterator& iter);


	ConstIterator cbegin()const;
	ConstIterator cend()const;
	Iterator end();
	Iterator begin();
	ReverseIterator rbegin();
	ReverseIterator rend();
};

template<typename Allocator>
unsigned BoolVector<Allocator>::createMask(unsigned pos) const
{
	return 1 << pos;
}

template<typename Allocator>
void BoolVector<Allocator>::free()
{
	if (buckets) {
		myAlloc.deallocate(buckets, bucketsCount); 
	}
	buckets = nullptr;
	bucketsCount = 0;
	countValues = 0;
}

template<typename Allocator>
void BoolVector<Allocator>::copyFrom(const BoolVector& other)
{
	countValues = other.countValues;
	capacity = other.capacity;
	bucketsCount = other.bucketsCount;
	buckets = myAlloc.allocate(bucketsCount);

	for (size_t i = 0; i < bucketsCount; i++) {
		buckets[i] = other.buckets[i];
	}
}

template<typename Allocator>
void BoolVector<Allocator>::moveFrom(BoolVector&& other)
{
	buckets = other.buckets;
	countValues = other.countValues;
	capacity = other.capacity;
	bucketsCount = other.bucketsCount;

	other.buckets = nullptr;
	other.countValues = 0;
	other.capacity = 0;
	other.bucketsCount = 0;
}

template<typename Allocator>
void BoolVector<Allocator>::resize()
{
	size_t newCapacity = capacity * 2;
	capacity = newCapacity;
	unsigned newBucketsCount = capacity / ELEMENTS_IN_BUCKET + 1;

	uint8_t* newData = myAlloc.allocate(newBucketsCount);
	std::fill_n(newData, newBucketsCount, 0);

	for (size_t i = 0; i < bucketsCount; i++) {
		newData[i] = buckets[i];
	}


	myAlloc.deallocate(buckets, bucketsCount);
	bucketsCount = newBucketsCount;
	buckets = newData;
}

template<typename Allocator>
unsigned BoolVector<Allocator>::getElementIndex(unsigned count) const
{
	return count % ELEMENTS_IN_BUCKET;
}

template<typename Allocator>
unsigned BoolVector<Allocator>::getBucketIndex(unsigned count) const
{
	return count / ELEMENTS_IN_BUCKET;
}

template<typename Allocator>
BoolVector<Allocator>::BoolVector()
{
	capacity = 16;
	bucketsCount = capacity / ELEMENTS_IN_BUCKET + 1;
	buckets = myAlloc.allocate(bucketsCount);
	std::fill_n(buckets, bucketsCount, 0);
}

template<typename Allocator>
BoolVector<Allocator>::BoolVector(const BoolVector& other)
{
	copyFrom(other);
}

template<typename Allocator>
BoolVector<Allocator>& BoolVector<Allocator>::operator=(const BoolVector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename Allocator>
BoolVector<Allocator>& BoolVector<Allocator>::operator=(BoolVector&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename Allocator>
BoolVector<Allocator>::BoolVector(BoolVector&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename Allocator>
BoolVector<Allocator>::~BoolVector()
{
	free();
}

template<typename Allocator>
BitRef BoolVector<Allocator>::operator[](unsigned ind)
{
	unsigned posInd = getElementIndex(ind);
	unsigned bucketInd = getBucketIndex(ind);

	return BitRef(buckets[bucketInd], posInd);
}

template<typename Allocator>
bool BoolVector<Allocator>::operator[](unsigned ind) const
{
	unsigned posIndex = getElementIndex(ind);
	unsigned bucketInd = getBucketIndex(ind);

	return buckets[bucketInd] & createMask(posIndex);

}

template<typename Allocator>
void BoolVector<Allocator>::push_back(bool value)
{
	if (countValues >= capacity) {
		resize();
	}

	unsigned posIndex = getElementIndex(countValues);
	unsigned bucketIndex = getBucketIndex(countValues);

	if (value) {
		buckets[bucketIndex] |= createMask(posIndex);
	}
	countValues++;
}

template<typename Allocator>
void BoolVector<Allocator>::pop_back()
{
	if (countValues == 0) {
		return;
	}

	unsigned posIndex = getElementIndex(countValues);
	unsigned bucketIndex = getBucketIndex(countValues);

	buckets[bucketIndex] &= ~createMask(posIndex);
	countValues--;
}

template<typename Allocator>
void BoolVector<Allocator>::pop_front()
{
	if (countValues == 0) {
		return;
	}

	for (size_t i = 0; i < countValues; i++) {
		size_t buckInd = getBucketIndex(i);
		size_t buckPos = getElementIndex(i);

		size_t nextBucketInd = getBucketIndex(i + 1);
		size_t nextBucketPos = getElementIndex(i + 1);


		if (buckets[nextBucketInd] & createMask(nextBucketPos)) {
			buckets[buckInd] |= createMask(buckPos); 
		}
		else {
			buckets[buckInd] &= ~createMask(buckPos); 
		}
	}
	countValues--;
}

template<typename Allocator>
size_t BoolVector<Allocator>::size()const
{
	return countValues;
}

template<typename Allocator>
void BoolVector<Allocator>::insert(const Iterator& iter, bool value)
{
	unsigned indToInsert = (iter.bucketPtr - buckets) * ELEMENTS_IN_BUCKET + iter.posInBucket;
	if (countValues == capacity) {
		resize();
	}
	for (int i = countValues; i > indToInsert; i--)
	{
		bool prevVal = (*this)[i - 1];

		(*this)[i] = prevVal;
	}

	(*this)[indToInsert] = value;
	++countValues;
}


template<typename Allocator>
void BoolVector<Allocator>::insert(const ConstIterator& iter, bool value)
{
	unsigned indToInsert = (iter.bucketPtr - buckets) * ELEMENTS_IN_BUCKET + iter.posInBucket;
	if (countValues == capacity) {
		resize();
	}
	for (int i = countValues; i > indToInsert; i--)
	{
		bool prevVal = (*this)[i - 1];

		(*this)[i] = prevVal;
	}

	(*this)[indToInsert] = value;
	++countValues;
}

template<typename Allocator>
void BoolVector<Allocator>::remove(const Iterator& iter)
{
	unsigned indToRemove = (iter.bucketPtr - buckets) * ELEMENTS_IN_BUCKET + iter.posInBucket;

	for (int i = indToRemove; i < countValues; i++)
	{
		bool nextVal = (*this)[i + 1];

		(*this)[i] = nextVal;
	}
	--countValues;
}


template<typename Allocator>
void BoolVector<Allocator>::remove(const ConstIterator& iter)
{
	unsigned indToRemove = (iter.bucketPtr - buckets) * ELEMENTS_IN_BUCKET + iter.posInBucket;

	for (int i = indToRemove; i < countValues; i++)
	{
		bool nextVal = (*this)[i + 1];

		(*this)[i] = nextVal;
	}
	--countValues;
}



template<typename Allocator>
typename ConstIterator BoolVector<Allocator>::cbegin() const
{
	unsigned startBucket = getBucketIndex(0);
	unsigned startBucketPos = getElementIndex(0);
	return ConstIterator(&buckets[startBucket], startBucketPos);
}

template<typename Allocator>
typename ConstIterator BoolVector<Allocator> :: cend() const
{
	unsigned endBucket = getBucketIndex(countValues-1);
	unsigned endBitPosition = getElementIndex(countValues-1);


	return ConstIterator(&buckets[endBucket], endBitPosition);
}

template<typename Allocator>
typename  Iterator BoolVector<Allocator>::end()
{
	unsigned endBucket = getBucketIndex(countValues-1);
	unsigned endBitPosition = getElementIndex(countValues-1);
	return Iterator(&buckets[endBucket], endBitPosition);
}

template<typename Allocator>
typename  Iterator BoolVector<Allocator>::begin()
{
	unsigned startBucket = getBucketIndex(0);
	unsigned startBucketPos = getElementIndex(0);
	return Iterator(&buckets[startBucket], startBucketPos);
}

template<typename Allocator>
typename ReverseIterator BoolVector<Allocator>::rbegin()
{
	unsigned endBucket = getBucketIndex(countValues-1);
	unsigned endBitPosition = getElementIndex(countValues-1);


	return ReverseIterator(&buckets[endBucket], endBitPosition);
}

template<typename Allocator>
typename ReverseIterator BoolVector<Allocator>::rend()
{
	unsigned startBucket = getBucketIndex(0);
	unsigned startBucketPos = getElementIndex(0);
	return ReverseIterator(&buckets[startBucket], startBucketPos);
}
