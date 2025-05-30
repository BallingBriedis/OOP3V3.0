#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
	int Size;
	int Capacity;
	int* Array;
public:
	Vector();
	~Vector();
	void PushBack(int value);

	bool Empty();
	int Size();
	int Capacity();
};

#endif
