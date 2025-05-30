#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
	int size;
	int capacity;
	int* array;
public:
	Vector();
	Vector(const Vector& rhs);
	Vector(int elements, int value = 0);

	~Vector();


	void PushBack(int value);

	bool Empty() const;
	int Size() const;
	int Capacity() const;

	bool operator==(const Vector& rhs) const;
	bool operator!=(const Vector& rhs) const;

	friend std::ostream& operator<<(std::ostream& ostr, const Vector& rhs);
};

#endif
