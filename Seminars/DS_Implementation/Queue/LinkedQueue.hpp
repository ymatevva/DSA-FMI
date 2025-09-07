#pragma once
#include <iostream>
#include<exception>

template <typename T>
class LinkedQueue
{
	struct Node
	{
		Node(T data)
		{
			this->data = data;
			next = nullptr;
		}
		T data;
		Node* next;
	};

	Node* head;
	Node* tail;

	void free();
	void copyFrom(const LinkedQueue& other);
	void moveFrom(LinkedQueue&& other);
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue& other);
	LinkedQueue(LinkedQueue&& other)noexcept;
	LinkedQueue operator=(const LinkedQueue& other);
	LinkedQueue operator=(LinkedQueue&& other)noexcept;
	~LinkedQueue();

	void push(const T&el); // O(1)
	void push(T&& el); // O(1)
	void pop(); //O(1)
	const T& peek() const; //O(1)

	bool empty() const;
};

template<typename T>
inline void LinkedQueue<T>::free()
{
	Node* iter = head;
	while (iter) {
		Node* del = iter;
		iter = iter->next;
		delete del;
	}
	head = tail = nullptr;
}

template<typename T>
inline void LinkedQueue<T>::copyFrom(const LinkedQueue& other)
{

	Node* otherIter = other.head;
	while (otherIter) {
		push(otherIter.data);
		otherIter = otherIter->next;
	}
}

template<typename T>
inline void LinkedQueue<T>::moveFrom(LinkedQueue&& other)
{
	head = other.head;
	tail = other.tail;
	
	other.head = nullptr;
	other.tail = nullptr;
}

template<typename T>
inline LinkedQueue<T>::LinkedQueue()
{
	tail = nullptr;
	head = nullptr;
}

template<typename T>
inline LinkedQueue<T>::LinkedQueue(const LinkedQueue& other)
{
	copyFrom(other);

}

template<typename T>
inline LinkedQueue<T>::LinkedQueue(LinkedQueue&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline LinkedQueue<T> LinkedQueue<T>::operator=(const LinkedQueue& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline LinkedQueue<T> LinkedQueue<T>::operator=(LinkedQueue&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline LinkedQueue<T>::~LinkedQueue()
{
	free();
}

template<typename T>
inline void LinkedQueue<T>::push(const T& el)
{
	Node* add = new Node(el);
	if (empty()) {
		head = tail = add;
	}
	else {
		tail->next = add;
		tail = add;
	}
}

template<typename T>
inline void LinkedQueue<T>::push(T&& el)//push_back()
{
	Node* add = new Node(std::move(el));
	if (empty()) {
		head = tail = add;
	}
	else {
		tail->next = add;
		tail = add;
	}
}

template<typename T>
inline void LinkedQueue<T>::pop()//pop_front()
{
	if (empty()) {
		throw std::runtime_error("empty queue");
	}if (head == tail) {
		delete head;
		head = tail = nullptr;
	}
	else {
		Node* toDel = head;
		head = head->next;
		delete toDel;
	}
}

template<typename T>
inline const T& LinkedQueue<T>::peek() const
{
	if (empty()) {
		throw std::runtime_error("empty queue");
	}
	return head->data;
}


template<typename T>
inline bool LinkedQueue<T>::empty() const
{
	return !head && !tail;
}
