#pragma once
#include"Constants.h"

template<typename Allocator> 
class BoolVector;

class Iterator {
private:
    uint8_t* bucketPtr; 
    unsigned posInBucket; 

    template<typename Allocator>
    friend class BoolVector;
public:
    Iterator(uint8_t* bucketPtr, unsigned posInBucket)
        : bucketPtr(bucketPtr), posInBucket(posInBucket) {}

    BitRef operator*() {
        return BitRef(*bucketPtr, posInBucket);
    }

    Iterator& operator++() { 
        if (++posInBucket == ELEMENTS_IN_BUCKET) {
            ++bucketPtr;
            posInBucket = 0;
        }
        return *this;
    }

    Iterator operator++(int dummy) {
        Iterator temp = *this;
        ++(*this);
        return temp;
    }

    Iterator& operator--() { 
        if (posInBucket == 0) {
            --bucketPtr;
            posInBucket = ELEMENTS_IN_BUCKET - 1;
        }
        else {
            --posInBucket;
        }
        return *this;
    }

    Iterator operator--(int dummy) {
        Iterator temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const Iterator& other) const {
        return bucketPtr == other.bucketPtr && posInBucket == other.posInBucket;
    }

    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }
};

class ConstIterator {
private:
    const uint8_t* bucketPtr; 
    unsigned posInBucket;

    template<typename Allocator>
    friend class BoolVector;
public:
    ConstIterator(const uint8_t* bucketPtr, unsigned posInBucket)
        : bucketPtr(bucketPtr), posInBucket(posInBucket) {}

    bool operator*() const { 
        return (*bucketPtr & (1 << posInBucket)) != 0;
    }

    ConstIterator& operator++() { 
        if (++posInBucket == ELEMENTS_IN_BUCKET) {
            ++bucketPtr;
            posInBucket = 0;
        }
        return *this;
    }

    ConstIterator operator++(int dummy) {
        ConstIterator temp = *this;
        ++(*this);
        return temp;
    }

    ConstIterator& operator--() { 
        if (posInBucket == 0) {
            --bucketPtr;
            posInBucket = ELEMENTS_IN_BUCKET - 1;
        }
        else {
            --posInBucket;
        }
        return *this;
    }

    ConstIterator operator--(int dummy) {
        ConstIterator temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const ConstIterator& other) const {
        return bucketPtr == other.bucketPtr && posInBucket == other.posInBucket;
    }

    bool operator!=(const ConstIterator& other) const {
        return !(*this == other);
    }
};

class ReverseIterator {
private:
    uint8_t* bucketPtr; 
    unsigned posInBucket;

    template<typename Allocator>
    friend class BoolVector;
public:
    ReverseIterator(uint8_t* bucketPtr, unsigned posInBucket)
        : bucketPtr(bucketPtr), posInBucket(posInBucket) {}

    BitRef operator*() {
        return BitRef(*bucketPtr, posInBucket);
    }

    ReverseIterator& operator++() { 
        if (posInBucket == 0) {
            --bucketPtr;
            posInBucket = ELEMENTS_IN_BUCKET - 1;
        }
        else {
            --posInBucket;
        }
        return *this;
    }

    ReverseIterator operator++(int dummy) { 
        ReverseIterator temp = *this;
        ++(*this);
        return temp;
    }

    ReverseIterator& operator--() { 
        if (++posInBucket == ELEMENTS_IN_BUCKET) {
            ++bucketPtr;
            posInBucket = 0;
        }
        return *this;
    }

    ReverseIterator operator--(int dummy) { 
        ReverseIterator temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const ReverseIterator& other) const {
        return bucketPtr == other.bucketPtr && posInBucket == other.posInBucket;
    }

    bool operator!=(const ReverseIterator& other) const {
        return !(*this == other);
    }
};
