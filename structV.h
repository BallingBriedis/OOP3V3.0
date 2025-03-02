#ifndef STRUCTV_H
#define STRUCTV_H

// Struktura, kurioje laikomi studento duomenys.

#include <string>
#include <vector>

struct Stud {
	std::string var;
	std::string pav;
	std::vector<int>uzd{};
	int egz = 0;
	int gal = 0;
};
#endif