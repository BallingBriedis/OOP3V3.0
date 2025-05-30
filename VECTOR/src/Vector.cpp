#include "vector.h"


Vector::Vector() :
	Size(0),
	Capacity(5),
	Array(new int[Capacity]) {}

Vector::~Vector(){
	delete[] Array;
	Size = 0;
	Capacity = 0;
	Array = nullptr;
}

void Vector::PushBack(int value) {
	Array[Size] = value;
	++Size;
}