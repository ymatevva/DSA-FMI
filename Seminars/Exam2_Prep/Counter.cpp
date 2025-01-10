#include<iostream>
#include<unordered_map>
using namespace std;

template<typename T>
class Counter {

	unordered_map<T, int>counter;
public:
	void operator+=(const T& el);
	void operator+(const T& el);

	void operator-=(const T& el);
	void operator-(const T& el);

	int getSize() const;
	int operator[](const T& el) const;
	Counter<T> operator+(const Counter<T>& other);
};

template<typename T>
void Counter<T>::operator+=(const T& el)
{
	auto it = counter.find(el);

	if (it == counter.end()) {
		counter.insert({ el, 1 });
		return;
	}
	(*it).second++;
}

template<typename T>
void Counter<T>::operator+(const T& el)
{
	Counter copy(*this);
	copy += el;
	return copy;
}

template<typename T>
void Counter<T>::operator-=(const T& el)
{
	auto it = counter.find(el);
	if (it == counter.end()) {
		return;
    }
	else {
		(*it).second--;
		if ((*it).second == 0) {
			counter.erase(el);
		}
	}
}

template<typename T>
void Counter<T>::operator-(const T& el)
{
	Counter copy(*this);
	copy -= el;
	return copy;
}

template<typename T>
int Counter<T>::getSize() const
{
	return counter.size();
}

template<typename T>
int Counter<T>::operator[](const T&el) const
{
	auto it = counter.find(el);
	if (it == counter.end()) {
		return 0;
	}
	return (*it).second;
}

template<typename T>
Counter<T> Counter<T>::operator+(const Counter<T>& other)
{
	Counter<T> res = *this;

	for (auto it = other.counter.begin(); it != other.counter.cend(); it++) {

		if (res.counter.find((*it).first) == res.counter.cend()) {
			res.counter.insert({ (*it).first,(*it).second });
		}
		else {
			auto itThis = res.counter.find((*it).first);
			(*itThis).second += (*it).second;
		}
	}

	return res;
}



int main()
{
	Counter<int> c;

	c += 3;
	c += 3;

	c += 5;

	Counter<int> c2 = c;
	Counter<int> c3 = c + c2;

	std::cout << c3[3] << " " << c3[5];

}