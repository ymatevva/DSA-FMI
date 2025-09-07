#pragma once
#include<iostream>
#include<vector>
#include<exception>


template<typename T>
class PQ {
	 
	std::vector<T> data;
private:
	static size_t getLeftChild(size_t ind);
	static size_t getRightChild(size_t ind);
	static int getParentInd(size_t ind);
	void heapify(size_t ind);
public:
	PQ() = default;
	PQ(const std::vector<int>& vec);

	bool empty() const;
	size_t getSize() const;

	const T& peek() const;
	void pop();
	void push(const T& el);
};

template<typename T>
inline size_t PQ<T>::getLeftChild(size_t ind)
{
	return ind * 2 + 1;
}

template<typename T>
inline size_t PQ<T>::getRightChild(size_t ind)
{
	return ind * 2 + 2;
}

template<typename T>
inline int PQ<T>::getParentInd(size_t ind)
{
	return (ind - 1)/2;
}

template<typename T>
inline void PQ<T>::heapify(size_t ind)
{
	int curInd = ind;

	while (true) {

		int leftInd = getLeftChild(ind);
		int rightInd = getRightChild(ind);

		bool goLeft = leftInd < data.size() && data[curInd] < data[leftInd];
		bool goRight = rightInd < data.size() && data[curInd] < data[rightInd];


		if (goLeft && goRight) {

			if (data[leftInd] > data[rightInd]) {
				std::swap(data[curInd], data[leftInd]);
				curInd = leftInd;
			}
			else {
				std::swap(data[curInd], data[rightInd]);
				curInd = rightInd;
			}
		}
		else if (goLeft) {
			std::swap(data[curInd], data[leftInd]);
			curInd = leftInd;
		}
		else if (goRight) {
			std::swap(data[curInd], data[rightInd]);
			curInd = rightInd;
		}
		else {
			break;
		}
	}
}

template<typename T>
inline PQ<T>::PQ(const std::vector<int>& vec)
{
	data = vec;
	for (int i = vec.size()/2-1; i >= 0; i--)
	{
		heapify(i);
	}
}

template<typename T>
inline bool PQ<T>::empty() const
{
	return data.size() == 0;
}

template<typename T>
inline size_t PQ<T>::getSize() const
{
	return data.size();
}

template<typename T>
inline const T& PQ<T>::peek() const
{
	if (empty()) {
		throw std::runtime_error("There are no elements.");
	}
	return data[0];
}

template<typename T>
inline void PQ<T>::pop()
{
	if (empty()) {
		throw std::runtime_error("There are no elements.");
	}

	data[0] = data[data.size() - 1];
	data.pop_back();
	if (!empty()) {
		heapify(0);
	}
}

template<typename T>
inline void PQ<T>::push(const T& el)
{
	data.push_back(el);
	int ind = data.size() - 1;
	int parentInd = getParentInd(ind);

	while (ind > 0 && data[ind] > data[parentInd]) {
		std::swap(data[ind], data[parentInd]);
		ind = parentInd;
		parentInd = getParentInd(ind);
	}
}
