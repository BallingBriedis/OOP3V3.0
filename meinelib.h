#ifndef MEINELIB_H
#define MEINELIB_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;

struct Stud {
	string var;
	string pav;
	vector<int>uzd{};
	int egz = 0;

	int* mUzd = nullptr;
	size_t uzdSize = 0;
	size_t uzd_capacity = 1;

    Stud() { mUzd = new int[1], uzdSize = 0, uzd_capacity = 1; }

	~Stud() {
		delete[] mUzd;
	}
    void addGrades(int grade) {
        if (mUzd == nullptr) {
            uzd_capacity = 1;
            mUzd = new int[uzd_capacity];
        }

        if (uzdSize == uzd_capacity) {
            size_t newCapacity = uzd_capacity * 2;
            int* newMuzd = new int[newCapacity];

            std::copy(mUzd, mUzd + uzdSize, newMuzd);

            delete[] mUzd;

            mUzd = newMuzd;
            uzd_capacity = newCapacity;
        }
		cout <<"\n\n\n"<< grade << "\n\n\n";
        mUzd[uzdSize] = grade;
		uzdSize++;
		for(int i=0;i<uzdSize;i++)
		cout << "\nABFDAFG" << mUzd[i] << "\nABFDAFG";
    }
};
#endif