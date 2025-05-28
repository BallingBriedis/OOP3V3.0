#include "meinelib.h"
#include "classV.h"
#include "functionsCallsVector.h"

void rusiavimas(vector<Stud>& studentai, int rusiavimoPasirinkimas) {
	auto compareByName = [](const Stud& a, const Stud& b) {
		return a.getVar() < b.getVar();
		};
	auto compareBySurname = [](const Stud& a, const Stud& b) {
		return a.getPav() < b.getPav();
		};
	auto compareByFinalGradeVid = [](const Stud& a, const Stud& b) {
		return a.getVidurkis() < b.getVidurkis();
		};
	auto compareByFinalGradeMed = [](const Stud& a, const Stud& b) {
		return a.getMediana() < b.getMediana();
		};

	switch (rusiavimoPasirinkimas) {
	case 1:
		sort(studentai.begin(), studentai.end(), compareByName);
		break;
	case 2:
		sort(studentai.begin(), studentai.end(), compareBySurname);
		break;
	case 3:
		sort(studentai.begin(), studentai.end(), compareByFinalGradeVid);
		break;
	case 4:
		sort(studentai.begin(), studentai.end(), compareByFinalGradeMed);
		break;
	default:
		cout << "Neteisingas pasirinkimas. Nerusiavome.\n";
		break;
	}
}