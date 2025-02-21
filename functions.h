#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "meinelib.h"

int isNumber();
bool isValidInput(int input);

inline int isNumber() {
	int input;
	while (true) {
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Neteisinga ivestis. Iveskite sveika skaiciu: ";
		}
		else {
			return input;
		}
	}
}

inline bool isValidInput(int input) {
	if (input == -1) {
		return true;
	}
	if (input < 0 || input > 10) {
		return false;
	}
	return true;
}
#endif