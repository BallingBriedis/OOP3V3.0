#include "meinelib.h"
#include "functionsCallsVector.h"

int ivestiesPatikrinimas(const int nuo, const int iki) {
	int input{};
	while (true) {
		try {
			cin >> input;
			if (input < nuo || input > iki) {
				cout << "\n\n!!!!Iveskite skaiciu nuo " << nuo << " iki " << iki << ".!!!!\n\n\n";
				continue;
			}
		}
		catch (...) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n\n";
			continue;
		}
		break;
	}
	return input;
}