#pragma once
#include <iostream>

// Implementation without a sentinel node and without circular linkage.

template <typename T>
class DLL
{
    
    struct Node
    {
        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
        T data;
        Node* next;
        Node* prev;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    size_t count = 0;
    void copyFrom(const DLL& other);
    void moveFrom(DLL&& other);
    void free();

public:
    DLL()=default;
    DLL(const DLL<T>& other);
    DLL(DLL<T>&& other);

    DLL<T>& operator=(const DLL<T>& other);
    DLL<T>& operator=(DLL<T>&& other);
    ~DLL();

    void push_back(const T& el); 
    void push_back(T&& el); 
    void push_front(const T& el);
    void push_front(T&& el);
    void pop_back();
    void pop_front();

    const T& front() const;
    const T& back() const;

    T& front();
    T& back();

    void print() const;
    size_t getSize() const;

    bool empty() const;

    void clear();

    class DllIterator;
    class ConstDllIterator;

    DllIterator insertBefore(const T& element, const ConstDllIterator& it);
    DllIterator removeAt(const ConstDllIterator& it);

    DllIterator begin() { return DllIterator(*this, head); }
    DllIterator end() { return DllIterator(*this, nullptr); }
    ConstDllIterator cbegin() const { return ConstDllIterator(*this, head); }
    ConstDllIterator cend() const { return ConstDllIterator(*this, nullptr); }

    class DllIterator
    {
        friend class DLL;
        Node* currentElementPtr;
        DLL& list;

    public:
      
        DllIterator(DLL& list, Node* currentElementPtr = nullptr) : list(list), currentElementPtr(currentElementPtr) {}

        T& operator*() { return currentElementPtr->data; }
        T* operator->() { return &currentElementPtr->data; }

        DllIterator& operator++() {
            if (currentElementPtr)
                currentElementPtr = currentElementPtr->next;
            return *this;
        }

        DllIterator operator++(int) {
            DllIterator copy(*this);
            ++(*this);
            return copy;
        }

        DllIterator& operator--() {
            if (currentElementPtr)
                currentElementPtr = currentElementPtr->prev;
            else
                currentElementPtr = list.tail;
            return *this;
        }

        DllIterator operator--(int) {
            DllIterator copy(*this);
            --(*this);
            return copy;
        }

        bool operator==(const DllIterator& rhs) const { return currentElementPtr == rhs.currentElementPtr; }
        bool operator!=(const DllIterator& rhs) const { return !(rhs == *this); }
    };

    class ConstDllIterator
    {
        Node* currentElementPtr;
        const DLL& list; 
        friend class DLL;
    public:
      
        ConstDllIterator(const DLL& list, Node* currentElementPtr = nullptr) : list(list), currentElementPtr(currentElementPtr) {}
        ConstDllIterator(const DllIterator& iter) : list(iter.list), currentElementPtr(iter.currentElementPtr) {} //convert constructor

        const T& operator*() const { return currentElementPtr->data; }
        const T* operator->() const { return &currentElementPtr->data; }

        ConstDllIterator& operator++() {
            if (currentElementPtr)
                currentElementPtr = currentElementPtr->next;
            return *this;
        }

        ConstDllIterator operator++(int) {
            ConstDllIterator copy(*this);
            ++(*this);
            return copy;
        }

        ConstDllIterator& operator--() {
            if (currentElementPtr)
                currentElementPtr = currentElementPtr->prev;
            else
                currentElementPtr = list.tail;
            return *this;
        }

        ConstDllIterator operator--(int) {
            ConstDllIterator copy(*this);
            --(*this);
            return copy;
        }

        bool operator==(const ConstDllIterator& rhs) const { return currentElementPtr == rhs.currentElementPtr; }
        bool operator!=(const ConstDllIterator& rhs) const { return !(rhs == *this); }
    };
};


template <typename T>
bool DLL<T>::empty() const
{
    return !head;
}

template <typename T>
void DLL<T>::push_back(const T& el)
{
    Node* added = new Node(el);
    count++;
    if (empty()) {
        head = tail = added;
    }
    else
    {
        tail->next = added;
        added->prev = tail;
        tail = added;
    }
}
template<typename T>
inline void DLL<T>::push_back(T&& el)
{
    Node* add = new Node(std::move(el));
    if (empty()) {
        head = tail = add;
    }
    else {
        add->prev = tail;
        tail->next = add;
        tail = add;
    }
    count++;
}
template <typename T>
void DLL<T>::push_front(const T& el)
{
    Node* added = new Node(el);
    if (empty())
    {
        head = tail = added;
    }
    else
    {
        added->next = head;
        head->prev = added;
        head = added;
    }
    count++;
}

template<typename T>
inline void DLL<T>::push_front(T&& el)
{
    Node* added = new Node(std::move(el));
    if (empty())
    {
        head = tail = added;
    }
    else
    {
        added->next = head;
        head->prev = added;
        head = added;
    }
    count++;
}

template<typename T>
void DLL<T>::pop_back()
{
    if (empty())
        throw std::runtime_error("The list is empty!");

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        tail->prev->next = nullptr;

        Node* toDelete = tail;
        tail = tail->prev;

        delete toDelete;

    }

    count--;
}

template<typename T>
void DLL<T>::pop_front()
{
    if (empty())
        throw std::runtime_error("The list is empty!");


    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        head->next->prev = nullptr;

        Node* toDelete = head;
        head = head->next;

        delete toDelete;
    }

    count--;
}

template <typename T>
typename DLL<T>::DllIterator DLL<T>::insertBefore(const T& element, const ConstDllIterator& it)
{
    if (it == cbegin())
    {
        push_front(element);
        return begin();
    }
    else if (it == cend())
    {
        push_back(element);
        return DllIterator(*this, tail);
    }
    else
    {
        Node* current = it.currentElementPtr;
        Node* newNode = new Node(element);

        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        count++;

        return DllIterator(*this, newNode);
    }
}

template <typename T>
typename DLL<T>::DllIterator DLL<T>::removeAt(const ConstDllIterator& it)
{
    Node* toDelete = it.currentElementPtr;
    if (!toDelete)
        throw std::runtime_error("Cannot remove end iterator");

    if (toDelete == head)
    {
        pop_front();
        return begin();
    }
    else if (toDelete == tail)
    {
        pop_back();
        return end();
    }
    else
    {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        Node* nextNode = toDelete->next;

        delete toDelete;
        count--;

        return DllIterator(*this, nextNode);
    }
}

template<typename T>
const T& DLL<T>::front() const
{
    if (empty())
        throw std::runtime_error("The list is empty!");

    return head->data;
}

template<typename T>
const T& DLL<T>::back() const
{
    if (empty())
        throw std::runtime_error("The list is empty!");

    return tail->data;
}


template<typename T>
T& DLL<T>::front()
{
    if (empty())
        throw std::runtime_error("The list is empty!");

    return head->data;
}

template<typename T>
T& DLL<T>::back()
{
    if (empty())
        throw std::runtime_error("The list is empty!");

    return tail->data;
}

template<typename T>
void DLL<T>::print() const
{
    Node* iter = head;
    while (iter != nullptr)
    {
        std::cout << iter->data;
        if (iter != tail)
            std::cout << "<->";
        iter = iter->next;
    }
    std::cout << std::endl;
}
template<typename T>
size_t DLL<T>::getSize() const
{
    return count;
}

template<typename T>
void DLL<T>::clear()
{
    free();
}

template <typename T>
DLL<T>::DLL(const DLL<T>& other) : head(nullptr), tail(nullptr)
{
    copyFrom(other);
}

template <typename T>
DLL<T>& DLL<T>::operator=(const DLL<T>& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
DLL<T>::DLL(DLL<T>&& other)
{
    moveFrom(std::move(other));
}

template <typename T>
DLL<T>& DLL<T>::operator=(DLL<T>&& other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template <typename T>
DLL<T>::~DLL()
{
    free();
}

template <typename T>
void DLL<T>::copyFrom(const DLL<T>& other)
{
    Node* otherIter = other.head;
    while (otherIter != nullptr)
    {
        push_back(otherIter->data);
        otherIter = otherIter->next;
    }
}

template <typename T>
void DLL<T>::moveFrom(DLL<T>&& other)
{
    head = other.head;
    tail = other.tail;
    count = other.count;
    other.head = other.tail = nullptr;
    other.count = 0;
}


template<typename T>
void DLL<T>::free()
{
    Node* iter = head;
    while (iter != nullptr)
    {
        Node* toDelete = iter;
        iter = iter->next;
        delete toDelete;
    }

    head = tail = nullptr;
    count = 0;
}