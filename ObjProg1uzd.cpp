#include "meinelib.h"
#include <iomanip>
#include <sstream>

void read(Stud& stu);
bool isValidInput(const string& input, int& number);
float vidurkis(Stud& studentai);
float mediana(Stud& studentai);


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
	cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Egzaminas" << std::setw(20) << "Galutinis(Vidurkis)" << std::setw(20) << "Galutinis(Mediana)" << endl;
	for (Stud studentas : studentai) {
		cout << std::setw(20) <<studentas.var << std::setw(20) << studentas.pav << std::setw(20) << studentas.egz << std::setw(20) << vidurkis(studentas) << std::setw(20) << mediana(studentas) << endl;
		return 0;
	}

}

void read(Stud& stu) {
	string input;
	int write;
	cout << "Iveskite studento varda: ";
	getline(cin, stu.var);
	cout << "Iveskite studento pavarde: ";
	getline(cin, stu.pav);
	cout << "Iveskite studento egzamino pazymi: ";
	while (true) {
		getline(cin, input);
		if (isValidInput(input, write)) {
			stu.egz = write;
			break;
		}
		else {
			cout << "Neteisingai ivestas egzamino pazymys. Iveskite sveika skaiciu nuo 0 iki 10 imtinai: ";
		}
	}
	cout << "\n\n" << "Iveskite studento namu darbu pazymius. Ivedus visus pazymius, iveskite -1.\n";
	cout << "Jeigu darbas neatliktas iveskite 0.\n\n";
	int i = 1;
	while (true) {
		cout << i << "-asis pazymys: ";
		cin >> input;
		std::stringstream ss(input);
		int paz;
		if (ss >> paz && ss.eof()) {
			if (paz == -1) {
				break;
			}
			stu.uzd.push_back(paz);
			i++;
		}
		else {
			cout << "Neteisingas ivestis. Iveskite sveika skaiciu arba -1: " << endl;
		}
	}
}

bool isValidInput(const string& input, int& number) {
	std::istringstream iss(input);

	if (!(iss >> number) || !(iss.eof())) {
		return false;
	}
	if (number < 0 || number > 10) {
		return false;
	}
	return true;
}

float vidurkis(Stud& studentai) {
	if (studentai.uzd.empty()) return 0.0;
	return accumulate(studentai.uzd.begin(), studentai.uzd.end(), 0) / studentai.uzd.size();
}

float mediana(Stud& studentai) {
	if (studentai.uzd.empty()) return 0.0;

	std::sort(studentai.uzd.begin(), studentai.uzd.end());
	size_t size = studentai.uzd.size();
	if (size % 2 == 0) {
		return (studentai.uzd[size / 2 - 1] + studentai.uzd[size / 2]) / 2.0;
	}
	else {
		return studentai.uzd[size / 2];
	}
}