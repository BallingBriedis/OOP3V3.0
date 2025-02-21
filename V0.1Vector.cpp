#include "meinelib.h"

void readRanka(Stud& stu);
int isNumber();
bool isValidInput(int input);
float vidurkis(Stud& studentai);
float mediana(Stud& studentai);


int main() {
	vector<Stud> studentai;
	char pasirinkimasS = 'Y';
	char pasirinkimasV = 'V';
	while (pasirinkimasS != 'N') {
		Stud studentas;
		readRanka(studentas);
		studentai.push_back(studentas);
		cout << "Ar norite ivesti dar viena studenta? (Y/N): ";
		cin >> pasirinkimasS;
		if (pasirinkimasS == 'Y' || pasirinkimasS == 'N') {
		}
		else {
			bool kaasciadarau = true;
			while (kaasciadarau) {
				cout << "Neteisingas pasirinkimas. Iveskite Y arba N: ";
				cin >> pasirinkimasS;
				if (pasirinkimasS == 'Y' || pasirinkimasS == 'N') {
					kaasciadarau = false;
				}
			}
		}
	}

	cout << "Ar namu darbu pazymi skaiciuosite vidurkiu ar mediana? (V/M): ";
	cin >> pasirinkimasV;
	if (pasirinkimasV == 'V' || pasirinkimasV == 'M') {
	}
	else {
		bool kaasciadarau = true;
		while (kaasciadarau) {
			cout << "Neteisingas pasirinkimas. Iveskite V arba M: ";
			cin >> pasirinkimasV;
			if (pasirinkimasV == 'V' || pasirinkimasV == 'M') {
				kaasciadarau = false;
			}
		}
	}
	cout << "Studentu sarasas: \n";

	if (pasirinkimasV == 'V') {
		cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << endl;
		for (Stud studentas : studentai) {
			cout << std::setw(20) << studentas.var << std::setw(20) << studentas.pav << std::setw(20) << 0.6 * studentas.egz + 0.4 * vidurkis(studentas) << endl;
		}
	}
	else {
		cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << endl;
		for (Stud studentas : studentai) {
			cout << std::setw(20) << studentas.var << std::setw(20) << studentas.pav << std::setw(20) << 0.6 * studentas.egz + 0.4 * mediana(studentas) << endl;
		}
	}
	return 0;
}

void readRanka(Stud& stu) {
	int input;
	cout << "Iveskite studento varda: ";
	cin >> stu.var;
	cout << "Iveskite studento pavarde: ";
	cin >> stu.pav;
	cout << "Iveskite studento egzamino pazymi: ";
	while (true) {
		input = isNumber();
		if (isValidInput(input) && input != -1) {
			stu.egz = input;
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
		input = isNumber();
		if (isValidInput(input)) {
			if (input == -1) {
				break;
			}
			stu.uzd.push_back(input);
			i++;
		}
		else {
			cout << "Neteisinga ivestis. Iveskite sveika skaiciu nuo 0 iki 10 imtinai.\nJeigu norite iseiti iveskite -1: \n" << endl;
		}
	}
}
int isNumber() {
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

bool isValidInput(int input) {
	if (input == -1) {
		return true;
	}
	if (input < 0 || input > 10) {
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