#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template<typename T>
class Vector {
private:
	size_t size;
	size_t capacity;
	T* array = nullptr;
public:
	// Constructors
	Vector() :
		size(0),
		capacity(5),
		array(new T[capacity]) {}

	Vector(const Vector& rhs) :
		size(rhs.size),
		capacity(rhs.capacity),
		array(new T[capacity])
	{
		for (size_t i = 0; i < size; ++i) {
			array[i] = rhs.array[i];
		}
	}

	Vector(int elements, const T& value = T()) :
		size(elements),
		capacity(elements + 5),
		array(new T[capacity])
	{
		for (size_t i = 0; i < size; ++i) {
			array[i] = value;
		}
	}

	Vector(const std::initializer_list<T>& list) :
		size(0),
		capacity(list.size() + 5),
		array(new T[capacity])
	{
		for (const T& value : list) {
			PushBack(value);
		}
	}


	//Destructor
	~Vector() {
		delete[] array;
		array = nullptr;
		size = 0;
		capacity = 0;
	}


	// Operator=
	Vector& operator=(const Vector& rhs) {
		if (this != &rhs) {
			if (rhs.size > capacity) {
				delete[] array;
				capacity = rhs.size + 5;
				array = new T[capacity];
			}
			for (size_t i = 0; i < rhs.size; ++i) {
				array[i] = rhs.array[i];
			}
			size = rhs.size;
		}
		return *this;
	}


	// Assign
	void Assign(size_t count, const T& value) {
		if (count > capacity) {
			delete[] array;
			capacity = count + 5;
			array = new T[capacity];
		}
		for (size_t i = 0; i < count; ++i) {
			array[i] = value;
		}
		size = count;
	}

	template <typename InputIt>
	void Assign(InputIt first, InputIt last) {
		size_t count = std::distance(first, last);

		if (count > capacity) {
			delete[] array;
			capacity = count + 5;
			array = new T[capacity];
		}

		size_t i = 0;
		for (InputIt it = first; it != last; ++it, ++i) {
			array[i] = *it;
		}

		size = count;
	}


	// Element access
	T& At(size_t index) {
		if ((index < 0) || (index >= size))
		{
			throw std::exception("At - Index out of range");
		}
		return array[index];
	}

	const T& At(size_t index) const {
		if ((index < 0) || (index >= size)) {
			throw std::exception("At - Index out of range");
		}
		return array[index];
	}
	
	T& operator[](size_t index) {
		return array[index];
	}

	T& Front() {
		return At(0);
	}

	const T& Front() const {
		return At(0);
	}

	T& Back() {
		return At(size - 1);
	}

	const T& Back() const {
		return At(size - 1);
	}


	// Iterators
	T* begin() {
		return array;
	}

	T* end() {
		return array + size;
	}


	// Capacity
	bool Empty() const {
		return size == 0;;
	}

	size_t Size() const {
		return size;
	}

	size_t MaxSize() const {
		return static_cast<size_t>(-1) / sizeof(T);
	}

	void Reserve(size_t newCapacity) {
		if (newCapacity <= capacity) return;

		T* newArray = new T[newCapacity];

		for (size_t i = 0; i < size; ++i) {
			newArray[i] = array[i];
		}

		delete[] array;
		array = newArray;
		capacity = newCapacity;
	}

	size_t Capacity() const {
		return capacity;
	}

	void ShrinkToFit() {
		if (capacity == size) return;

		T* newArray = new T[size];

		for (size_t i = 0; i < size; ++i) {
			newArray[i] = array[i];
		}

		delete[] array;
		array = newArray;
		capacity = size;
	}


	// Modifiers
	void Clear() {
		size = 0;
	}

	void Insert(size_t index, const T& value) {
		if ((index < 0) || (index > size)) {
			throw std::exception("Insert - Index out of range");
		}

		if (size >= capacity) {
			capacity *= 2;
			T* newarray = new T[capacity];
			for (size_t i = 0; i < index; ++i) {
				newarray[i] = array[i];
			}
			newarray[index] = value;
			for (size_t i = index; i < size; ++i) {
				newarray[i + 1] = array[i];
			}
			delete[] array;
			array = newarray;
		}
		else {
			for (size_t i = size; i > index; --i) {
				array[i] = array[i - 1];
			}
			array[index] = value;
		}
		++size;
	}

	void Erase(size_t index) {
		if ((index < 0) || (index >= size)) {
			throw std::exception("Erase - Index out of range");
		}

		for (size_t i = index; i < size - 1; ++i) {
			array[i] = array[i + 1];
		}
		--size;
	}

	void PushBack(const T& value) {
		if (size >= capacity) {
			capacity *= 2;
			T* newarray = new T[capacity];
			for (size_t i = 0; i < size; ++i) {
				newarray[i] = array[i];
			}
			delete[] array;
			array = newarray;
		}
		array[size++] = value;
	}

	void PopBack() {
		if (size == 0) {
			throw std::exception("Pop back on empty vector!");
		}
		--size;
	}

	void Swap(Vector& other) {
		size_t tempSize = size;
		size = other.size;
		other.size = tempSize;

		size_t tempCapacity = capacity;
		capacity = other.capacity;
		other.capacity = tempCapacity;

		T* tempArray = array;
		array = other.array;
		other.array = tempArray;
	}


	// Non-member functions
	bool operator==(const Vector& rhs) const {
		if (Size() != rhs.Size()) return false;

		for (size_t i = 0; i < Size(); ++i) {
			if (array[i] != rhs.array[i]) return false;
		}
		return true;
	}

	bool operator!=(const Vector& rhs) const
	{
		return !(*this == rhs);
	}


	// Operator<<
	friend std::ostream& operator<<(std::ostream& ostr, const Vector& rhs)
	{
		for (size_t i = 0; i < rhs.size; ++i) {
			ostr << rhs.array[i] << " ";
		}
		/*ostr << " || ";

		for (int i = rhs.size; i < rhs.capacity; ++i) {
			ostr << rhs.array[i] << " ";
		}

		ostr << std::endl;*/

		return ostr;
	}


};

#endif