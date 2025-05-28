#include "meinelib.h"
#include "classV.h"
#include "functionsCallsVector.h"

bool compareByName(const Stud& a, const Stud& b) {																			// Rusiavimo funkcijos dalis kuri tikrina vardus.
	return a.getVar() < b.getVar();
}

bool compareBySurname(const Stud& a, const Stud& b) {																		// Rusiavimo funkcijos dalis kuri tikrina pavardes.
	return a.getPav() < b.getPav();
}

bool compareByFinalGrade(const Stud& a, const Stud& b) {																	// Rusiavimo funkcijos dalis kuri tikrina galutinius pazymi.
	return a.getGal() < b.getGal();
}

void Stud::addUzd(int grade) {
	uzd.push_back(grade);
}

void Stud::print() const {
	cout << std::left << "\nVardas: " << std::setw(20) << var << "\nPavarde: " << std::setw(20) << pav << endl;
	cout << "Namų darbai: ";
	for (int i = 0; i < uzd.size(); i++) {
		cout << std::setw(3) << uzd[i];
	}
	cout << "\n";
	cout << "Egzaminas: " << std::setw(3) << egz << "\n";
	cout << "Galutinis: " << std::setw(3) << gal << "\n\n";
}