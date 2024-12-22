#include<iostream>
#include<exception>
#include<vector>

using namespace std;

template<class T>
class TernaryHeap {

	static size_t getLeftChild(size_t ind);
	static size_t getMiddleChild(size_t ind);
	static size_t getRightChild(size_t ind);
	static size_t getParent(size_t ind);

	void heapify(size_t ind);
	vector<T>vec;
public:
	TernaryHeap() = default;
	explicit TernaryHeap(const vector<T>& vec);

	void insert(const T& el);
	void remove();
	const T& peek() const;

	void print()const;
};

template<class T>
inline size_t  TernaryHeap<T>::getLeftChild(size_t ind)
{
	return ind * 3 + 1;
}

template<class T>
inline size_t TernaryHeap<T>::getMiddleChild(size_t ind)
{
	return ind * 3 + 2;
}

template<class T>
inline size_t TernaryHeap<T>::getRightChild(size_t ind)
{
	return ind * 3 + 3;
}

template<class T>
inline size_t TernaryHeap<T>::getParent(size_t ind)
{
	return (ind - 1) / 3;
}

template<class T>
inline void TernaryHeap<T>::heapify(size_t ind)
{

	while (true) {
		size_t currInd = ind;

		size_t leftInd = getLeftChild(currInd);
		size_t midInd = getMiddleChild(currInd);
		size_t rightInd = getRightChild(currInd);

		if (leftInd < vec.size() && vec[leftInd] > vec[currInd])
			currInd = leftInd;

		if (rightInd < vec.size() && vec[rightInd] > vec[currInd])
			currInd = rightInd;

		if (midInd < vec.size() && vec[midInd] > vec[currInd])
			currInd = midInd;
		
		if (currInd != ind) {
			std::swap(vec[ind], vec[currInd]);
			ind = currInd;
		}
		else {
			break;
		}
	}
}

template<class T>
inline TernaryHeap<T>::TernaryHeap(const vector<T>& vec)
{
	this->vec = vec;
	for (int i = vec.size() / 3 - 1; i >= 0; i--)
	{
		heapify(i);
	}

}

template<class T>
inline void TernaryHeap<T>::insert(const T& el)
{
	vec.push_back(el);
	size_t ind = vec.size() - 1;
	size_t parInd = getParent(ind);

	while (ind > 0 && vec[ind] > vec[parInd]) {
		std::swap(vec[ind], vec[parInd]);
		ind = parInd;
		parInd = getParent(ind);
	}
}

template<class T>
inline void TernaryHeap<T>::remove()
{
	if (vec.empty()) {
		throw std::out_of_range("The vector is already empty.,");
	}

	swap(vec[0], vec[vec.size() - 1]);
	vec.pop_back();

	if (!vec.empty())
		heapify(0);
}

template<class T>
inline const T& TernaryHeap<T>::peek() const
{
	if (!vec.empty()) {
		return vec[0];
	}
	else {
		throw std::out_of_range("There is no elements.");
	}
}

template<class T>
inline void TernaryHeap<T>::print() const
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
}