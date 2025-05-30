#include "vector.h"


Vector::Vector() :
	size(0),
	capacity(5),
	array(new int[capacity]) {}

Vector::Vector(const Vector& rhs) :
	size(rhs.size),
	capacity(rhs.capacity),
	array(new int[capacity])
{
	for (int i = 0; i < rhs.Size(); ++i) {
		array[i] = rhs.array[i];
	}
}

Vector::Vector(int elements, int value) :
	size(elements),
	capacity(elements + 5),
	array(new int[capacity])
{
	for (int i = 0; i < size; ++i) {
		array[i] = value;
	}
}

Vector::~Vector(){
	delete[] array;
	size = 0;
	capacity = 0;
	array = nullptr;
}

void Vector::PushBack(int value) {
	array[size] = value;
	++size;
}

bool Vector::Empty() const {
	return size == 0;;
}

int Vector::Size() const {
	return size;
}

int Vector::Capacity() const {
	return capacity;
}

bool Vector::operator==(const Vector& rhs) const {
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

bool Vector::operator!=(const Vector& rhs) const
{
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& ostr, const Vector& rhs)
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
