template<class T>
class ConstIterator {
	T* ptr;
public:
	ConstIterator<T>(T* ptr) :ptr(ptr) {}

	const T* operator->() const {
		return ptr;
	}

	const T& operator*() const {
		return *(ptr);
	}

	ConstIterator<T> operator++(int) {
		ConstIterator copy(*this);
		++(*this);
		return copy;
	}
	ConstIterator<T> operator--(int) {
		ConstIterator copy(*this);
		--(*this);
		return copy;
	}
	int operator-(ConstIterator<T> other) const
	{
		return ptr - other.ptr;
	}

	ConstIterator<T> operator+(size_t ind) {
		return { ptr + ind };
	}
	ConstIterator<T> operator-(size_t ind) {
		return { ptr - ind };
	}
	bool operator==(const ConstIterator<T>& other) {
		return ptr == other.ptr;
	}
	bool operator!=(const ConstIterator<T>& other) {
		return !(ptr == other.ptr);
	}
};


template<class T>
class Iterator {
	T* ptr;
public:
	Iterator<T>(T* ptr) :ptr(ptr) {}
	T* operator->() {
		return ptr;
	}
	const T* operator->() const {
		return ptr;
	}
	T& operator*() {
		return *(ptr);
	}
	const T& operator*() const {
		return *(ptr);
	}

	operator ConstIterator<T>() const
	{
		return ConstIterator<T>(ptr);
	}

	Iterator<T>& operator++() {
		ptr++;
		return *this;
	}
	Iterator<T>& operator--() {
		ptr--;
		return *this;
	}
	Iterator<T> operator++(int) {
		Iterator copy(*this);
		++(*this);
		return copy;
	}
	Iterator<T> operator--(int) {
		Iterator copy(*this);
		--(*this);
		return copy;
	}
	Iterator<T> operator+(size_t ind) {
		return { ptr + ind };
	}
	Iterator<T> operator-(size_t ind) {
		return { ptr - ind };
	}
	bool operator==(const Iterator<T>& other) {
		return ptr == other.ptr;
	}
	bool operator!=(const Iterator<T>& other) {
		return !(ptr == other.ptr);
	}
};



template<class T>
class ReverseIterator {
	T* ptr;
public:
	ReverseIterator<T>(T* ptr) :ptr(ptr) {}
	T* operator->() {
		return ptr;
	}
	const T* operator->() const {
		return ptr;
	}
	T& operator*() {
		return *(ptr);
	}
	const T& operator*() const {
		return *(ptr);
	}
	ReverseIterator<T>& operator++() {
		ptr--;
		return *this;
	}
	ReverseIterator<T>& operator--() {
		ptr++;
		return *this;
	}
	ReverseIterator<T> operator++(int) {
		ReverseIterator copy(*this);
		--(*this);
		return copy;
	}
	ReverseIterator<T> operator--(int) {
		ReverseIterator copy(*this);
		++(*this);
		return copy;
	}
	ReverseIterator<T> operator+(size_t ind) {
		return { ptr - ind };
	}
	ReverseIterator<T> operator-(size_t ind) {
		return { ptr + ind };
	}
	bool operator==(const ReverseIterator<T>& other) {
		return ptr == other.ptr;
	}
	bool operator!=(const ReverseIterator<T>& other) {
		return !(ptr == other.ptr);
	}

};