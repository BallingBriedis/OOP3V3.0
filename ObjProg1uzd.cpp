#include "meinelib.h"

int main() {
	Stud studentas;
    return 0;
}
void read(Stud stu) {
	cout << "Iveskite studento varda: ";
	cin >> stu.var;
	cout << "Iveskite studento pavarde: ";
	cin >> stu.pav;
	cout << "Iveskite studento egzamino pazymi: ";
	cin >> stu.egz;
	cout << "Iveskite studento namu darbu pazymius. Ivedus visus pazymius, iveskite -1: ";
	while (true) {
		int paz;
		cin >> paz;
		if (paz == -1) {
			break;
		}
		stu.uzd.push_back(paz);
	}
}