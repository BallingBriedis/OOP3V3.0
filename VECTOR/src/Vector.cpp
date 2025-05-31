#include "meinelib.h"
#include "studentas.h"
#include "functionsCallsVector.h"

template <typename T>
template <typename InputIt>
void Vector<T>::Assign(InputIt first, InputIt last) {
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