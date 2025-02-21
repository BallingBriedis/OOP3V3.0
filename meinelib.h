#ifndef MEINELIB_H
#define MEINELIB_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct Stud {
	string var;
	string pav;
	vector<int>uzd{};
	int egz = 0;

	int* mUzd = nullptr;
	size_t uzdSize = 0;
	~Stud() {
		delete[] mUzd;
	}
};
#endif