#include "meinelib.h"

void readRanka(Stud& stu);
void randomAtsitiktinisPazymys(Stud& stu);
float vidurkis(Stud& studentai);
float mediana(Stud& studentai);

int main() {
	srand(time(NULL));
	vector<Stud> studentai;
	char pasirinkimasS = 'Y';
	char pasirinkimasV = 'V';
	while (pasirinkimasS != 'N') {
		Stud studentas;
		readRanka(studentas);
		studentai.push_back(studentas);
		cout << "Ar norite ivesti dar viena studenta? (Y/N): ";
		while (true) {
			cin >> pasirinkimasS;
			if (pasirinkimasS == 'Y' || pasirinkimasS == 'N') {
				break;
			}
			else {
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Neteisingas pasirinkimas. Iveskite Y arba N: ";
			}
		}
	}

	cout << "Ar galutini rezultata skaiciuosite vidurkiu ar mediana? (V/M): ";

	while (true) {
		cin >> pasirinkimasV;
		if (pasirinkimasV == 'V') {
			cout << "Studentu sarasas: \n";
			cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << endl;
			for (Stud studentas : studentai) {
				cout << std::setw(20) << studentas.var << std::setw(20) << studentas.pav << std::setw(20) << fixed << setprecision(0) << round(0.6 * studentas.egz + 0.4 * vidurkis(studentas)) << endl;
			}
			break;
		}
		else if (pasirinkimasV == 'M') {
			cout << "Studentu sarasas: \n";
			cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << endl;
			for (Stud studentas : studentai) {
				cout << std::setw(20) << studentas.var << std::setw(20) << studentas.pav << std::setw(20) << fixed << setprecision(0) << round(0.6 * studentas.egz + 0.4 * mediana(studentas)) << endl;
			}
			break;
		}
		else {
			cout << "Neteisingas pasirinkimas. Iveskite V arba M: ";
		}
	}
	return 0;
}

void readRanka(Stud& stu) {
	int input;
	char pasirinkimas = 'R';
	cout << "Iveskite studento varda: ";
	cin >> stu.var;
	cout << "Iveskite studento pavarde: ";
	cin >> stu.pav;
	cout << "Ar pazymius norite ranka vesti, ar juos generuoti automatiskai. Iveskite (R/A) atitinkamai ranka arba auto: ";
	while (true) {
		cin >> pasirinkimas;
		if (pasirinkimas == 'R') {
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
			break;
		}
		else if (pasirinkimas == 'A') {
			randomAtsitiktinisPazymys(stu);
			break;
		}
		else {
			cout << "Neteisingas pasirinkimas. Iveskite R arba A: ";
		}
	}
	
}

void randomAtsitiktinisPazymys(Stud& stu) {
	stu.egz = rand() % 10 + 1;
	cout << "Kiek pazymiu sugeneruoti? ";
	int pazymiai = isNumber();
	
	for (int i = 0; i < pazymiai; i++) {
		stu.uzd.push_back(rand() % 10 + 1);
	}
	for (int i = 0; i < pazymiai; i++) {
		cout << stu.uzd[i] << " ";
	}
}

float vidurkis(Stud& studentai) {
	if (studentai.uzd.empty()) return 0.0;
	return accumulate(studentai.uzd.begin(), studentai.uzd.end(), 0) / studentai.uzd.size();
}

float mediana(Stud& studentai) {
	if (studentai.uzd.empty()) return 0.0;

	std::sort(studentai.uzd.begin(), studentai.uzd.end());
	int size = studentai.uzd.size();
	if (size % 2 == 0) {
		return (studentai.uzd[size / 2 - 1] + studentai.uzd[size / 2]) / 2.0;
	}
	else {
		return studentai.uzd[size / 2];
	}
}