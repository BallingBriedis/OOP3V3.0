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
	int uzdSize = 0;
	int uzd_capacity = 1;

    void addGrades(int grade) {
		if (mUzd == nullptr) {
			mUzd = new int[uzd_capacity];
		}
        if (uzdSize == uzd_capacity) {
            int newCapacity = uzd_capacity + 1;
            int* newMuzd = new int[newCapacity];

            std::copy(mUzd, mUzd + uzdSize, newMuzd);

            delete[] mUzd;

            mUzd = newMuzd;
            uzd_capacity = newCapacity;
        }
		cout <<"\n"<< grade << "\n";
		cout <<"\n"<< "Veikia" << "\n";
        mUzd[uzdSize] = grade;
		cout << "\n" << "Veikia po muzd idejimo" << "\n";
		uzdSize++;
		for(int i=0;i<uzdSize;i++)
		cout << "\nTestas meinelib.h " << mUzd[i] << " Testas meinelib.h\n";
    }
};
#endif