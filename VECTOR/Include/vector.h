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
	Vector() :
		size(0),
		capacity(5),
		array(new int[capacity]) {}

	Vector(const Vector& rhs) :
		size(rhs.size),
		capacity(rhs.capacity),
		array(new int[capacity])
	{
		for (int i = 0; i < rhs.Size(); ++i) {
			array[i] = rhs.array[i];
		}
	}

	Vector(int elements, int value) :
		size(elements),
		capacity(elements + 5),
		array(new int[capacity])
	{
		for (int i = 0; i < size; ++i) {
			array[i] = value;
		}
	}

	Vector(const std::initializer_list<int>& list) :
		size(0),
		capacity(list.size() + 5),
		array(new int[capacity])
	{
		for (int i : list) {
			PushBack(i);
		}
	}

	~Vector() {
		delete[] array;
		size = 0;
		capacity = 0;
		array = nullptr;
	}

	void PushBack(int value) {
		if (size < capacity) {
			array[size] = value;
			++size;
		}
		else {
			capacity *= 2;
			int* newarray = new int[capacity];

			for (int i = 0; i < size; ++i) {
				newarray[i] = array[i];
			}

			newarray[size] = value;
			++size;
			delete[] array;
			array = newarray;
		}
	}

	void PopBack() {
		if (size == 0) {
			throw std::exception("Pop back on empty vector!");
		}
		--size;
	}

	bool Empty() const {
		return size == 0;;
	}

	int Size() const {
		return size;
	}

	int Capacity() const {
		return capacity;
	}

	bool operator==(const Vector& rhs) const {
		if (Size() != rhs.Size()) {
			return false;
		}

		for (int i = 0; i < Size(); ++i) {
			if (array[i] != rhs.array[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator!=(const Vector& rhs) const
	{
		return !(*this == rhs);
	}

	friend std::ostream& operator<<(std::ostream& ostr, const Vector& rhs)
	{
		for (int i = 0; i < rhs.size; ++i) {
			ostr << rhs.array[i] << " ";
		}
		ostr << " || ";

		for (int i = rhs.size; i < rhs.capacity; ++i) {
			ostr << rhs.array[i] << " ";
		}

		ostr << std::endl;

		return ostr;
	}

	Vector& operator=(const Vector& rhs) {
		if (rhs.size > size) {
			delete[] array;
			capacity = rhs.size + 5;
			array = new int[capacity];
		}
		for (int i = 0; i < rhs.Size(); ++i) {
			array[i] = rhs.array[i];
		}

		size = rhs.size;
		return *this;
	}

	int& operator[](int index) {
		return array[index];
	}

	int& At(int index) {
		if ((index < 0) || (index >= size))
		{
			throw std::exception("At - Index out of range");
		}
		return array[index];
	}

	int& Front() {
		return array[0];
	}

	int& Back() {
		return array[size - 1];
	}

	void Insert(int index, int value) {
		if ((index < 0) || (index > size)) {
			throw std::exception("Insert - Index out of range");
		}

		if (size != capacity) {
			for (int i = size - 1; i >= index; --i) {
				array[i + 1] = array[i];
			}
			array[index] = value;
			++size;
		}
		else {
			capacity *= 2;
			int* newarray = new int[capacity];
			for (int i = 0; i < size; ++i) {
				newarray[i] = array[i];
			}
			delete[] array;
			array = newarray;
			Insert(index, value);
		}
	}

	void Erase(int index) {
		if ((index < 0) || (index >= size)) {
			throw std::exception("Erase - Index out of range");
		}

		for (int i = index; i < size - 1; ++i) {
			array[i] = array[i + 1];
		}
		--size;
	}

	void Clear() {
		size = 0;
	}

};

#endif
