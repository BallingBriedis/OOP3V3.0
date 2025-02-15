#include "meinelib.h"

void read(Stud &stu);

int main() {
	vector<Stud> studentai;
	char pasirinkimas = 'Y';
	while (pasirinkimas != 'N') {
		Stud studentas;
		read(studentas);
		studentai.push_back(studentas);
		cout << "Ar norite ivesti dar viena studenta? (Y/N): ";
		cin >> pasirinkimas;
	}
	cout << "Studentu sarasas: " << endl;
	cout << "Vardas\tPavarde\tEgzaminas\tGalutinis (Vidurkis)\tGalutinis (Mediana)" << endl;
	for (Stud studentas : studentai) {
		cout << studentas.var << "\t" << studentas.pav << "\t" << studentas.egz << "\t" << "Galutinis (Vidurkis)\tGalutinis (Mediana)" << endl;
		return 0;
	}

}

void read(Stud &stu) {
	cout << "Iveskite studento varda: ";
	cin >> stu.var;
	cout << "Iveskite studento pavarde: ";
	cin >> stu.pav;
	cout << "Iveskite studento egzamino pazymi: ";
	cin >> stu.egz;
	cout << "Iveskite studento namu darbu pazymius. Ivedus visus pazymius, iveskite -1: ";
	int i = 1;
	while (true) {
		int paz;
		cout << i << "-asis pazymys: ";
		cin >> paz;
		if (paz == -1) {
			break;
		}
		stu.uzd.push_back(paz);
		i++;
	}
}
float vidurkis(Stud &studentai) {
	return accumulate(studentai.uzd.begin(), studentai.uzd.end(), 0) / studentai.uzd.size();
}