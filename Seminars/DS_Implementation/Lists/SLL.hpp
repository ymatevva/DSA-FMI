#pragma once
#include<iostream>
#include<exception>

template<typename T>
class SLL {

	struct Node {
		T data;
		Node* next;
		Node(const T& data, Node* next = nullptr) :data(data), next(next) {}
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	size_t count = 0;

	void copyFrom(const SLL& other);
	void moveFrom(SLL&& other);
	void free();
public:
	SLL() = default;
	SLL(const SLL& other);
	SLL& operator=(const SLL& other);
	SLL(SLL&& other)noexcept;
	SLL& operator=(SLL&& other)noexcept;
	~SLL();

	const T& front() const;
	T& front();

	const T& back() const;
	T& back();

	void push_back(const T& el);
	void push_back(T&& el);

	void push_front(const T& el);
	void push_front(T&& el);

	void pop_front();

	bool empty() const;
	size_t getSize() const;

	template <typename U>
	friend SLL<U> concat(SLL<U>& lhs,  SLL<U>& rhs);

	class SLLIterator {
		Node* ptr;
		friend class SLL;
		SLL& list;
	public:
		typedef std::forward_iterator_tag iterator_category;

		SLLIterator(SLL& list, Node* ptr = nullptr) :ptr(ptr), list(list) {}
		T* operator->() {
			return &(ptr)->data;
		}
		T& operator*() {
			return ptr->data;
		}
		SLLIterator& operator++() {
			if (ptr) {
				ptr = ptr->next;
			}
			else {
				ptr = list.tail;
			}
			return *this;
		}
		SLLIterator operator++(int dummy) {
			SLLIterator old(*this);
			++(*this);
			return old;
		}
		SLLIterator& operator+=(size_t offS) {
			while (offS--) {
				++(*this);
			}
			return *this;
		}
		SLLIterator operator+(size_t offS) {
			SLLIterator res(*this);
			return res += offS;
		}
		bool operator==(const SLLIterator& other)const {
			return ptr == other.ptr ;
		}
		bool operator!=(const SLLIterator& other)const {
			return !(this == &other);
		}
		
	};

	class SLLConstIterator {
		Node* ptr;
		friend class SLL;
		const SLL& list;
	public:
		typedef std::forward_iterator_tag iterator_category;

		SLLConstIterator(const SLL& list, Node* ptr = nullptr) :ptr(ptr), list(list) {}
		SLLConstIterator(const SLLIterator& iter) :list(iter.list), ptr(iter.ptr) {}
		const T* operator->()const {
			return &(ptr)->data;
		}
		const T& operator*()const {
			return ptr->data;
		}
		SLLConstIterator& operator++() {
			if (ptr) {
				ptr = ptr->next;
			}
			else {
				ptr = list.tail;
			}
			return *this;
		}
		SLLConstIterator operator++(int dummy) {
			SLLConstIterator old(*this);
			++(*this);
			return old;
		}
		SLLConstIterator& operator+=(size_t offS) {
			while (offS--) {
				++(*this);
			}
			return *this;
		}
		SLLConstIterator operator+(size_t offS) {
			SLLConstIterator res(*this);
			return res += offS;
		}
		bool operator==(const SLLConstIterator& other) const{
			return ptr == other.ptr ;
		}
		bool operator!=(const SLLConstIterator& other) const{
			return !(this == &other);
		}
	};

	SLLConstIterator cbegin() const {
		return SLLConstIterator(*this,head);
	}

	SLLConstIterator cend() const {
		return SLLConstIterator(*this,nullptr);
	}

	SLLIterator begin() {
		return SLLIterator(*this,head);
	}
	SLLIterator end() {
		return SLLIterator(*this,nullptr);
	}

	SLLIterator insertAfter(const T& el, const SLLConstIterator& iter);
	SLLIterator removeAfter(const SLLConstIterator& iter);
};

template<typename T>
inline void SLL<T>::copyFrom(const SLL& other)
{
	Node* iter = other.head;
	while (iter) {
		push_back(iter->data);
		iter = iter->next;
	}
}

template<typename T>
inline void SLL<T>::moveFrom(SLL&& other)
{
	head = other.head;
	other.head = nullptr;

	tail = other.tail;
	other.tail = nullptr;

	count = other.count;
	other.count = 0;
}

template<typename T>
inline void SLL<T>::free()
{
	Node* iter = head;
	while (iter) {
		Node* del = iter;
		iter = iter->next;
		delete del;
	}
}

template<typename T>
inline SLL<T>::SLL(const SLL& other)
{
	copyFrom(other);
}

template<typename T>
inline SLL<T>& SLL<T>::operator=(const SLL& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline SLL<T>::~SLL()
{
	free();
}

template<typename T>
inline const T& SLL<T>::front() const
{
	if (empty()) {
		throw std::runtime_error("No elements");
	}
	return head->data;
}

template<typename T>
inline T& SLL<T>::front()
{
	if (empty()) {
		throw std::runtime_error("No elements");
	}
	return head->data;
}

template<typename T>
inline const T& SLL<T>::back() const
{
	if (empty()) {
		throw std::runtime_error("No elements");
	}
	return tail->data;
}

template<typename T>
inline T& SLL<T>::back()
{
	if (empty()) {
		throw std::runtime_error("No elements");
	}
	return tail->data;
}

template<typename T>
inline void SLL<T>::push_back(const T& el)
{
	Node* add = new Node(el);
	if (empty()) {
		head = tail = add;
	}
	else {
		tail->next = add;
		tail = add;
	}
	count++;
}

template<typename T>
inline void SLL<T>::push_back(T&& el)
{
	Node* add = new Node(std::move(el));
	if (empty()) {
		head = tail = add;
	}
	else {
		tail->next = add;
		tail = add;
	}
	count++;
}

template<typename T>
inline void SLL<T>::push_front(const T& el)
{
	Node* add = new Node(el);
	if (empty()) {
		head = tail = add;
	}
	else {
		add->next = head;
		head = add;
	}
	count++;
}

template<typename T>
inline void SLL<T>::push_front(T&& el)
{
	Node* add = new Node(std::move(el));
	if (empty()) {
		head = tail = add;
	}
	else {
		add->next = head;
		head = add;
	}
	count++;
}

template<typename T>
inline void SLL<T>::pop_front()
{
	if (empty()) {
		throw std::runtime_error("no elements");
	}

	if (getSize() == 1) {
		delete head;
		head = tail = nullptr;
	}
	else {
		Node* del = head;
		head = head->next;
		delete del;
	}
	count--;
}

template<typename T>
inline bool SLL<T>::empty() const
{
	return count == 0;
}

template<typename T>
inline size_t SLL<T>::getSize() const
{
	return count;
}

template<typename T>
typename SLL<T>::SLLIterator SLL<T>::insertAfter(const T& el, const SLLConstIterator& iter)
{
	Node* add = new Node(el);

	if (iter == cend()) {
		return end();
	}
	else {
		Node* curr = iter.ptr;
		add->next = curr->next;
		curr->next = add;
	}
	count++;
	return SLL<T>::SLLIterator(*this,add);
}

template<typename T>
typename SLL<T>::SLLIterator SLL<T>::removeAfter(const SLLConstIterator& iter)
{
	if (iter == cend() || getSize()==1) {
		return end();
	}
	Node* curr = iter.ptr;
	Node* next = curr->next;
	Node* newNext = curr->next->next;
	curr->next = newNext;
	if (!curr->next) {
		tail = curr->next;
	}
	count--;
	return SLL<T>::SLLIterator(*this,newNext);
}



template<typename T>
inline SLL<T>::SLL(SLL&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline SLL<T>& SLL<T>::operator=(SLL&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename U>
inline SLL<U> concat(SLL<U>& lhs,SLL<U>& rhs)
{
	SLL<U> res;

	if (!lhs.head) {
		res.head = rhs.head;
		res.tail = rhs.tail;
	}else if (!rhs.head) {
		res.head = lhs.head;
		res.tail = lhs.tail;
	}
	else {
		res.head = lhs.head;
		res.tail = rhs.head;
		lhs.tail->next = rhs.head;
	}

	res.count = lhs.count + rhs.count;
	lhs.head = rhs.head = lhs.tail = rhs.tail = nullptr;

	lhs.count = rhs.count = 0;
	return res;
}
