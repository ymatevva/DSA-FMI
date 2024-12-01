#pragma once
#include<exception>
#include<iostream>

template<typename T>
class ArrayStack
{
	T* data;
	size_t count;
	size_t capacity;

	void copyFrom(const ArrayStack& other);
	void moveFrom(ArrayStack&& other);
	void free();
	void resize(size_t cap);
public:
	ArrayStack();
	ArrayStack(const ArrayStack& other);
	ArrayStack& operator=(const ArrayStack& other);
	ArrayStack(ArrayStack&& other)noexcept;
	ArrayStack& operator=(ArrayStack&& other)noexcept;
	~ArrayStack();

	const T& peek()const;
	void pop();//O(1)
	void push(const T& el);//0(1)
	void push(T&& el);//0(1)

	bool empty()const;
	size_t getSize() const;

};

template<typename T>
void ArrayStack<T>::copyFrom(const ArrayStack& other)
{
	count = other.count;
	capacity = other.capacity;
	data = new T[other.capacity];
	for (size_t i = 0; i < other.count; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
void ArrayStack<T>::moveFrom(ArrayStack&& other)
{
	count = other.count;
	capacity = other.capacity;
	data = other.data;
	
	other.count = 0;
	other.capacity = 0;
	other.data = nullptr;
}

template<typename T>
void ArrayStack<T>::free()
{
	delete[] data;
}

template<typename T>
void ArrayStack<T>::resize(size_t cap)
{
	capacity = cap;
	T* tmp = new T[cap];
	for (size_t i = 0; i < count; i++)
	{
		tmp[i] = data[i];
	}
	delete[] data;
	data = tmp;
}

template<typename T>
ArrayStack<T>::ArrayStack()
{
	capacity = 4;
	count = 0;
	data = new T[capacity];
}

template<typename T>
ArrayStack<T>::ArrayStack(const ArrayStack& other)
{
	copyFrom(other);
}

template<typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
ArrayStack<T>::ArrayStack(ArrayStack&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
	free();
}

template<typename T>
const T& ArrayStack<T>::peek() const
{
	if (empty()) {
		throw std::logic_error("no elements");
	}
	return data[count - 1];
}

template<typename T>
void ArrayStack<T>::pop()
{
	if (empty()) {
		throw std::logic_error("no elements");
	}
	count--;
	if (count*2 < capacity && capacity > 1) {
		resize(capacity / 2);
	}
}

template<typename T>
void ArrayStack<T>::push(const T& el)
{
	if (count >= capacity) {
		resize(capacity * 2);
	}
	data[count++] = el;
}

template<typename T>
void ArrayStack<T>::push(T&& el)
{
	if (count >= capacity) {
		resize(capacity * 2);
	}
	data[count++] = std::move(el);
}

template<typename T>
bool ArrayStack<T>::empty() const
{
	return count == 0;
}

template<typename T>
size_t ArrayStack<T>::getSize() const
{
	return count;
}

