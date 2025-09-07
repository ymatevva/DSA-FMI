#include<iostream>
#include"Iterator.hpp"
#include<algorithm>
#include<memory>


constexpr int GROWTH_FACTOR = 2;

template<class T, class Allocator = std::allocator<T>>
class Vector {

	T* data = nullptr;
	size_t size = 0;
	size_t cap = 0;

	void move(Vector&& other);
	void copy(const Vector& other);
	void free();

	Allocator alloc;
	using const_iter = ConstIterator<T>;
	using iter = Iterator<T>;
	using rev_iter = ReverseIterator<T>;

	size_t calculateCap() const;
public:
	Vector() = default;
	explicit Vector(size_t size);
	Vector(size_t size, const T& el);

	Vector(const Vector<T>& other);
	Vector& operator=(const Vector<T>& other);

	Vector(Vector<T>&& other)noexcept;
	Vector& operator=(Vector<T>&& other)noexcept;
	~Vector();

	void push_back(const T& el);
	void push_back(T&& el);
	void pop_back();

	bool empty() const;
	size_t getSize() const;
	size_t getCap() const;

	void resize(size_t n);
	void reserve(size_t n);
	void shrink_to_fit();

	template <class... Args>
	void emplace_back(Args&&...args);

	void erase(const_iter it);
	void erase(const_iter first, const_iter last);

	const T& operator[](size_t ind) const;
	T& operator[](size_t ind);

	const T& back() const;
	T& back();

	void clear();

	const T& front() const;
	T& front();

	ConstIterator<T> cbegin() const;
	ConstIterator<T> cend() const;

	Iterator<T> end();
	Iterator<T> begin();

	ReverseIterator<T> rend();
	ReverseIterator<T> rbegin();
};

template<class T, class Allocator>
inline void Vector<T, Allocator>::move(Vector&& other)
{
	data = other.data;
	alloc = other.alloc;
	other.data = nullptr;
	size = other.size;
	other.size = 0;
	cap = other.cap;
	other.cap = 0;
}

template<class T, class Allocator>
inline void Vector<T, Allocator>::copy(const Vector& other)
{
	cap = other.cap;
	size = other.size;
	data = alloc.allocate(cap);
	for (size_t i = 0; i < size; i++)
	{
		alloc.construct(&data[i], other.data[i]);
	}
}

template<class T, class Allocator>
inline void Vector<T, Allocator>::free()
{
	for (size_t i = 0; i < size; i++)
	{
		alloc.destroy(&data[i]);
	}
	alloc.deallocate(data, cap);
	size = 0;
}

template<class T, class Allocator>
inline size_t Vector<T, Allocator>::calculateCap() const
{
	if (size == 0) {
		return 1;
	}
	return cap * GROWTH_FACTOR;
}

template<class T, class Allocator>
inline Vector<T,Allocator>& Vector<T, Allocator>::operator=(const Vector<T>& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return* this;
}

template<class T, class Allocator>
inline Vector<T,Allocator>& Vector<T, Allocator>::operator=(Vector<T>&& other) noexcept
{
	if (this != &other) {
		free();
		move(std::move(other));
	}
	return* this;
}

template<class T, class Allocator>
inline void Vector<T, Allocator>::push_back(const T& el)
{
	if (size == cap) {
		reserve(calculateCap());
	}
	alloc.construct(&data[size++], el);
}

template<class T, class Allocator>
inline void Vector<T, Allocator>::push_back(T&& el)
{
	if (size == cap) {
		reserve(calculateCap());
	}
	alloc.construct(&data[size++], std::move(el));
}

template<class T, class Allocator>
inline void Vector<T, Allocator>::pop_back()
{
	if (empty()) {
		return;
	}

	const_iter constEnd = --end();
	erase(constEnd);
}

template<class T, class Allocator>
inline bool Vector<T, Allocator>::empty() const
{
	return size==0;
}

template<class T, class Allocator>
inline size_t Vector<T, Allocator>::getSize() const
{
	return size;
}

template<class T, class Allocator>
inline size_t Vector<T, Allocator>::getCap() const
{
	return cap;
}

template<class T, class Allocator>
inline void Vector<T, Allocator>::resize(size_t n)
{
	if (n < size) {
		for (size_t i = n; i < size; i++)
		{
			alloc.destroy(&data[i]);
		}
		size = n;
	}
	else if (n > size) {

		if (n <= cap) {
			for (size_t i = n; i < size; i++)
			{
				alloc.construct(&data[i]);
			}
			size = n;
		}
		else {
			T* tmp = alloc.allocate(n);
			for (size_t i = 0; i < size; i++)
			{
				alloc.construct(&tmp[i], data[i]);
			}for (size_t i = size; i < n; i++)
			{
				alloc.construct(&tmp[i]);
			}
			alloc.deallocate(data, cap);
			data = tmp;
			size = n;
			cap = n; 
		}
	}
}

template<class T, class Allocator>
inline void Vector<T, Allocator>::reserve(size_t n)
{
	if (n <= cap) {
		return;
	}
	T* tmp = alloc.allocate(n);
	for (size_t i = 0; i < n; i++)
	{
		alloc.construct(&tmp[i], std::move(data[i]));
	}
	alloc.deallocate(data, cap);
	data = tmp;
	cap = n;

}

template<class T, class Allocator>
inline void Vector<T, Allocator>::shrink_to_fit()
{
	if (size >= cap) {
		return;
	}

	T* tmp = alloc.allocate(size);
	for (size_t i = 0; i < size; i++)
	{
		alloc.construct(&tmp[i], std::move(data[i]));
	}
	alloc.deallocate(data, cap);
	data = tmp;
	cap = size;
}

template <class T, class Allocator>
template <class... Args>
inline void Vector<T, Allocator>::emplace_back(Args&&...args)
{
	if (getSize() == cap) {
		reserve(calculateCap());
	}
	alloc.construct(&data[size++], std::forward<Args>(args)...);
		
}

template<class T, class Allocator>
inline void Vector<T, Allocator>::erase(const_iter it)
{
	erase(it, it + 1);
}

template<class T, class Allocator>
inline void Vector<T, Allocator>::erase(const_iter first, const_iter last)
{
	int deletedCount = last - first;

	if (deletedCount <= 0)
		return;

	int beginOffset = first - begin();
	int endOffset = last - begin();

	if (last != cend())
	{
		size_t construct_idx = beginOffset;
		for (size_t i = endOffset; i < getSize(); i++)
		{
			alloc.construct(&data[construct_idx], std::move(data[i]));
			++construct_idx;
		}
	}

	for (size_t i = endOffset; i < getSize(); i++)
		alloc.destroy(&data[i]);

	size -= deletedCount;
}

template<class T, class Allocator>
inline const T& Vector<T, Allocator>::operator[](size_t ind) const
{
	return data[ind];
}

template<class T, class Allocator>
inline T& Vector<T, Allocator>::operator[](size_t ind)
{
	return data[ind];
}

template<class T, class Allocator>
inline const T& Vector<T, Allocator>::back() const
{
	return data[size - 1];
}

template<class T, class Allocator>
inline T& Vector<T, Allocator>::back()
{
	return data[size - 1];
}

template<class T, class Allocator>
inline void Vector<T, Allocator>::clear()
{
	for (size_t i = 0; i < size; i++)
	{
		alloc.destroy(&data[i]);
	}
	size = 0;
}

template<class T, class Allocator>
inline const T& Vector<T, Allocator>::front() const
{
	return data[0];
}

template<class T, class Allocator>
inline T& Vector<T, Allocator>::front()
{
	return data[0];
}

template<class T, class Allocator>
inline ConstIterator<T> Vector<T, Allocator>::cbegin() const
{
	return ConstIterator<T>(&data[0]);
}

template<class T, class Allocator>
inline ConstIterator<T> Vector<T, Allocator>::cend() const
{
	return ConstIterator<T>(&data[size-1]);
}

template<class T, class Allocator>
inline Iterator<T> Vector<T, Allocator>::end()
{
	return Iterator<T>(&data[size -1 ]);
}

template<class T, class Allocator>
typename Iterator<T> Vector<T, Allocator>::begin()
{
	return Iterator<T>(&data[0]);
}

template<class T, class Allocator>
typename ReverseIterator<T> Vector<T, Allocator>::rend()
{
	return ReverseIterator<T>(&data[getSize()-1]);
}

template<class T, class Allocator>
inline ReverseIterator<T> Vector<T, Allocator>::rbegin()
{
	return ReverseIterator<T>(data - 1);
}

template<class T, class Allocator>
inline Vector<T, Allocator>::Vector(size_t size):size(size),cap(size),data(alloc.allocate(cap))
{
	for (size_t i = 0; i < size; i++)
	{
		alloc.construct(&data[i]);
	}
}

template<class T, class Allocator>
inline Vector<T, Allocator>::Vector(size_t size, const T& el) :size(size), cap(size), data(alloc.allocate(cap))
{
	for (size_t i = 0; i < size; i++)
	{
		alloc.construct(&data[i],el);
	}
}

template<class T, class Allocator>
inline Vector<T, Allocator>::Vector(const Vector<T>& other)
{
	copy(other);
}

template<class T, class Allocator>
inline Vector<T, Allocator>::Vector(Vector<T>&& other) noexcept
{
	move(std::move(other));
}

template<class T, class Allocator>
inline Vector<T, Allocator>::~Vector()
{
	free();
}
