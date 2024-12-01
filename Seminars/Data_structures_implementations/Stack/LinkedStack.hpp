#pragma once
#include<iostream>
#include<exception>

template<typename T>
class LinkedStack {
	
	struct Node {
		T data;
		Node* next;
		Node(const T& data,  Node* next = nullptr) :data(data), next(next) {}
	};

	size_t count = 0;
	Node* head = nullptr;

	void copyFrom(const LinkedStack& other);
	void moveFrom(LinkedStack&& other);
	void free();
public:
	LinkedStack() = default;
	LinkedStack(const LinkedStack& other);
	LinkedStack& operator=(const LinkedStack& other);
	LinkedStack(LinkedStack&& other)noexcept;
	LinkedStack& operator=(LinkedStack&& other)noexcept;
	~LinkedStack();

	const T& peek()const;//0(1)
	void pop();//O(1)
	void push(const T& el);//0(1)
	void push(T&& el);//0(1)

	bool empty()const;
	size_t getSize() const;
};

template<typename T>
inline void LinkedStack<T>::copyFrom(const LinkedStack& other)
{
	Node* iter = other.head;
	while (iter) {
		push(iter->data);
		iter = iter->next;
	}
	count = other.count;
}

template<typename T>
inline void LinkedStack<T>::moveFrom(LinkedStack&& other)
{
	count = other.count;
	head = other.head;


	other.count = 0;
	other.head = nullptr;
	
}

template<typename T>
inline void LinkedStack<T>::free()
{
	Node* iter = head;
	while (iter) {
		Node* del = iter;
		iter = iter->next;
		delete del;
	}
}

template<typename T>
inline LinkedStack<T>::LinkedStack(const LinkedStack& other)
{
	copyFrom(other);
}

template<typename T>
inline LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline LinkedStack<T>::LinkedStack(LinkedStack&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline LinkedStack<T>::~LinkedStack()
{
	free();
}

template<typename T>
inline const T& LinkedStack<T>::peek() const
{
	if (empty()) {
		throw std::runtime_error("No elements");
	}

	return head->data;
}

template<typename T>
inline void LinkedStack<T>::pop()//pop_front()
{
	if (empty()) {
		throw std::runtime_error("No elements");
	}if (getSize() == 1) {
		delete head;
		head = nullptr;
	}
	else {
		Node* del = head;
		head = head->next;
		delete del;
	}
	count--;
}

template<typename T>
inline void LinkedStack<T>::push(const T& el)//push_front
{
	Node* add = new Node(el);
	if (empty()) {
		head = add;
	}
	else {
		add->next = head;
		head = add;
	}
	count++;
}

template<typename T>
inline void LinkedStack<T>::push(T&& el)
{
	Node* add = new Node(std::move(el));
	if (empty()) {
		head = add;
	}
	else {
		add->next = head;
		head = add;
	}
	count++;
}

template<typename T>
inline bool LinkedStack<T>::empty() const
{
	return count == 0;
}

template<typename T>
inline size_t LinkedStack<T>::getSize() const
{
	return count;
}
