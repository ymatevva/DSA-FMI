#pragma once
#include<iostream>
#include<exception>

template<typename T>
class CircularQueue {

	T* data;
	size_t cap;
	size_t size;
	size_t get;
	size_t put;

	void moveFrom(CircularQueue&& other);
	void copyFrom(const CircularQueue& other);
	void free();
	void resize(size_t newCap);
public:
	CircularQueue();
	CircularQueue(const CircularQueue& other);
	CircularQueue& operator=(const CircularQueue& other);
	CircularQueue(CircularQueue&& other)noexcept;
	CircularQueue& operator=(CircularQueue&& other)noexcept;
	~CircularQueue();

	const T& peek() const;//O(1) return first in
	void push(const T& el);//O(1) 
	void push(T&& el);//O(1) push_back
	void pop();//O(1) pop_front

	bool empty() const;
	size_t getSize() const;
};

template<typename T>
 void CircularQueue<T>::moveFrom(CircularQueue&& other)
{
	cap = other.cap;
	size = other.size;
	get = other.get;
	put = other.put;
	data = other.data;

	other.cap = 0;
	other.size = 0;
	other.get = 0;
	other.put = 0;
	other.data = nullptr;

}

template<typename T>
 void CircularQueue<T>::copyFrom(const CircularQueue& other)
{
	cap = other.cap;
	size = other.size;
	get = other.get;
	put = other.put;
	data = new T[other.cap];
	for (size_t i = 0; i < other.size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
 void CircularQueue<T>::free()
{
	delete[] data;
}

template<typename T>
 void CircularQueue<T>::resize(size_t newCap)
{
	T* tmp = new T[newCap];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = data[get];
		(++get) %= cap;
	}

	cap = newCap;
	delete[] data;
	data = tmp;
	get = 0;//!!!
	put = size;//!!!
}

template<typename T>
 CircularQueue<T>::CircularQueue()
{
	cap = 4;
	size = 0;
	get = 0;
	put = 0;
	data = new T[cap];
}

template<typename T>
 CircularQueue<T>::CircularQueue(const CircularQueue& other)
{
	copyFrom(other);
}

template<typename T>
 CircularQueue<T>& CircularQueue<T>::operator=(const CircularQueue& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
 CircularQueue<T>::CircularQueue(CircularQueue&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
 CircularQueue<T>& CircularQueue<T>::operator=(CircularQueue&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
 CircularQueue<T>::~CircularQueue()
{
	free();
}

template<typename T>
 const T& CircularQueue<T>::peek() const
{
	if (empty()) {
		throw std::runtime_error("no elements");
	}
	return data[get];
}

template<typename T>
 void CircularQueue<T>::push(const T& el)
{
	 if (size >= cap) {
		 resize(cap * 2);
     }
	 data[put] = el;
	 size++;
	 (++put) %= cap;
}

template<typename T>
 void CircularQueue<T>::push(T&& el)
{
	 if (size >= cap) {
		 resize(cap * 2);
	 }
	 data[put] = std::move(el);
	 size++;
	 (++put) %= cap;
}

template<typename T>
 void CircularQueue<T>::pop()
{
	if (empty()) {
		throw std::runtime_error("No elements.");
    }
	size--;
	(++get) %= cap;
}

template<typename T>
 bool CircularQueue<T>::empty() const
{
	return size == 0;
}

template<typename T>
 size_t CircularQueue<T>::getSize() const
{
	return size;
}
