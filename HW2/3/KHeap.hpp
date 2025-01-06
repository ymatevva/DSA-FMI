#include<iostream>
#include<vector>
#include<exception>

//Used materials: https://github.com/Angeld55/Data_structures_and_algorithms_FMI/blob/main/PriorityQueue/priorityQueue.hpp
template<class T>
class KHeap {

	 size_t getParentInd(size_t ind)const;
	 size_t getNthChildInd(size_t ind, size_t N)const;

	 std::vector<T> data;
	 size_t dimensions = 0;

	void heapify(size_t ind);
public:
	KHeap(const std::vector<T>& vec,size_t k);

	void push(const T& el);
	void push(T&& el);

	const T& peek() const;
	void pop();

	bool empty() const;
	size_t getSize() const;
};



template<class T>
inline size_t KHeap<T>::getParentInd(size_t ind)const
{
	return (ind - 1)/dimensions;
}

template<class T>
inline size_t KHeap<T>::getNthChildInd(size_t ind, size_t N)const
{
	return ind*dimensions + N;
}

template<class T>
inline void KHeap<T>::heapify(size_t ind)
{
	while (true) {
		size_t currInd = ind;
		size_t largestChildInd = currInd;

		for (size_t i = 1; i <= dimensions; i++) {
			size_t childInd = getNthChildInd(currInd, i);
			if (childInd < data.size() && data[childInd] > data[largestChildInd]) {
				largestChildInd = childInd;
			}
		}

		if (largestChildInd != currInd) {
			std::swap(data[currInd], data[largestChildInd]);
			ind = largestChildInd;
		}
		else {
			break;
		}
	}
}


template<class T>
inline KHeap<T>::KHeap(const std::vector<T>& vec, size_t k):dimensions(k),data(vec)
{

	for (int i = vec.size() / dimensions - 1; i >= 0; i--)
	{
		heapify(i);
	}
}

template<class T>
inline void KHeap<T>::push(const T& el)
{
	data.push_back(el);
	size_t currInd = data.size() - 1;
	size_t parentInd = getParentInd(currInd);

	while (currInd > 0 && data[currInd] > data[parentInd]) {
		std::swap(data[currInd], data[parentInd]);
		currInd = parentInd;
		parentInd = getParentInd(currInd);
	}
}

template<class T>
inline void KHeap<T>::push(T&& el)
{
	data.push_back(std::move(el));
	size_t currInd = data.size() - 1;
	size_t parentInd = getParentInd(currInd);

	while (currInd > 0 && data[currInd] > data[parentInd]) {
		std::swap(data[currInd], data[parentInd]);
		currInd = parentInd;
		parentInd = getParentInd(currInd);
	}
}

template<class T>
inline const T& KHeap<T>::peek() const
{
	if (empty()) {
		throw std::runtime_error("Empty heap.");
	}
	return data[0];
}

template<class T>
inline void KHeap<T>::pop()
{
	if (empty()) {
		throw std::runtime_error("Empty heap.");
	}

	std::swap(data[0], data[data.size() - 1]);
	data.pop_back();
	if (!empty()) {
		heapify(0);
	}
}

template<class T>
inline bool KHeap<T>::empty() const
{
	return data.size() == 0;
}

template<class T>
inline size_t KHeap<T>::getSize() const
{
	return data.size();
}
