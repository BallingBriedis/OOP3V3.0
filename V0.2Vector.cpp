#include "meinelib.h"

struct Stud {
	string var;
	string pav;
	vector<int>uzd{};
	int egz = 0;
};

void readRanka(Stud& stu);
void readName_makeGrade(Stud& stu);
void makeStud(Stud& stu);
void fileRead(vector<Stud>& studentai, string ivestas_vardas);
void randomStudentas(Stud& studentas, bool vyras);
void randomAtsitiktinisPazymys(Stud& stu);
float vidurkis(Stud& studentai);
float mediana(Stud& studentai);
void fileOutVid(vector<Stud>& studentai);
void fileOutMed(vector<Stud>& studentai);

namespace fs = std::filesystem;
int main() {
	srand(time(NULL));
	vector<Stud> studentai;
	int pasirinkimasV = 0;
	string ivestas_vardas, path = ".";
	int n = 0;
	while (true) {
		int pasirinkimasInt = 0;
		Stud studentas;
		cout << "Pasirinkite norima studento duomenu surasyma irasant skaiciu nuo 1 iki 5.\n";
		cout << "------------------------------------------------------------------------\n";
		cout << "1 - Ivestis ranka\n2 - Generuojami tik pazymiai\n3 - Generuojamas studentas ir pazymiai\n4 - Nuskaityti is failo\n5 - Baigti darba\n";
		cout << "------------------------------------------------------------------------\n";
		pasirinkimasInt = isNumber();
		while (true) {
			if (menuValidInput(pasirinkimasInt)) {
				break;
			}
			else {
				cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki 5: ";
				pasirinkimasInt = isNumber();
			}
		}
		if (pasirinkimasInt == 5) {
			break;
		}
		switch (pasirinkimasInt) {
			case 1:
				readRanka(studentas);
				studentai.push_back(studentas);
				break;
			case 2:
				readName_makeGrade(studentas);
				studentai.push_back(studentas);
				break;
			case 3:
				cout << "Kiek studentu sugeneruoti? ";
				cin >> n;
				for (int i = 0; i < n; i++) {
				makeStud(studentas);
				studentai.push_back(studentas);
				}
				break;
			case 4:
				cout << "Iveskite norimo failo pavadinima be kabuciu:\n";
				for (const auto& entry : fs::directory_iterator(path)) {
					if (entry.path().extension() == ".txt") {
						std::cout << entry.path().filename() << std::endl;
					}
				}
				cin >> ivestas_vardas;
				fileRead(studentai, ivestas_vardas);
				break;
		}
	}

	cout << "Kaip pateikti rezultata?\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "1 - Vidurkiu ekrane\n2 - Mediana ekrane\n3 - Vidurkiu faile\n4 - Mediana faile\n";
	cout << "------------------------------------------------------------------------\n";
	pasirinkimasV = isNumber();
	while (true) {
		if (endValidInput(pasirinkimasV)) {
			break;
		}
		else {
			cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki 4: ";
			pasirinkimasV = isNumber();
		}
	}
		switch(pasirinkimasV) {
			case 1:
				cout << "Studentu sarasas: \n";
				cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << endl;
				for (Stud studentas : studentai) {
					cout << std::setw(20) << studentas.var << std::setw(20) << studentas.pav << std::setw(20) << fixed << setprecision(0) << round(0.6 * studentas.egz + 0.4 * vidurkis(studentas)) << endl;
				}
				break;
			case 2:
				cout << "Studentu sarasas: \n";
				cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << endl;
				for (Stud studentas : studentai) {
					cout << std::setw(20) << studentas.var << std::setw(20) << studentas.pav << std::setw(20) << fixed << setprecision(0) << round(0.6 * studentas.egz + 0.4 * mediana(studentas)) << endl;
				}
				break;
			case 3:
				fileOutVid(studentai);
				break;
			case 4:
				fileOutMed(studentai);
				break;
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

void readName_makeGrade(Stud& stu) {
	cout << "Iveskite studento varda: ";
	cin >> stu.var;
	cout << "Iveskite studento pavarde: ";
	cin >> stu.pav;
	randomAtsitiktinisPazymys(stu);
}

void makeStud(Stud& stu) {
	randomStudentas(stu, rand() % 2);
	randomAtsitiktinisPazymys(stu);
}

void fileRead(vector<Stud>& studentai, string ivestas_vardas) {
	std::stringstream buffer;
	std::ifstream duom(ivestas_vardas);
	if (!duom) {
		cout << "Failas nerastas." << endl;
		return;
	}
	buffer << duom.rdbuf();
	duom.close();

	string line;
	getline(buffer,line);
	while (getline(buffer, line)) {
		Stud stu;
		std::stringstream ss(line);
		ss >> stu.var >> stu.pav;
		int pazymys;
		while (ss >> pazymys) {
			stu.uzd.push_back(pazymys);
		}
		stu.egz = stu.uzd.back();
		stu.uzd.pop_back();
		studentai.push_back(stu);
	}
}

void randomStudentas (Stud& studentas, bool vyras) {
	if (vyras) {
		studentas.var = vyruVardai[rand() % vyruVardai.size()];
		studentas.pav = vyruPavardes[rand() % vyruPavardes.size()];
	}
	else {
		studentas.var = moteruVardai[rand() % moteruVardai.size()];
		studentas.pav = moteruPavardes[rand() % moteruPavardes.size()];
	}
}

void randomAtsitiktinisPazymys(Stud& stu) {
	stu.egz = rand() % 10 + 1;
	cout << "Kiek pazymiu sugeneruoti? ";
	int pazymiai = isNumber();
	
	for (int i = 0; i < pazymiai; i++) {
		stu.uzd.push_back(rand() % 10 + 1);
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

void fileOutVid(vector<Stud>& studentai) {
	std::stringstream outputas;
	outputas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << endl;
	for (auto& a : studentai) {
		outputas << std::left << std::setw(20) << a.var << std::setw(20) << a.pav << std::setw(20) << round(0.6 * a.egz + 0.4 * vidurkis(a)) << "\n";
	}
	studentai.clear();

	std::ofstream rez("rezultatas.txt");
	rez << outputas.str();
	rez.close();
}

void fileOutMed(vector<Stud>& studentai) {
	std::stringstream outputas;
	outputas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << endl;
	for (auto& a : studentai) {
		outputas << std::left << std::setw(20) << a.var << std::setw(20) << a.pav << std::setw(20) << round(0.6 * a.egz + 0.4 * mediana(a)) << "\n";
	}
	studentai.clear();

	std::ofstream rez("rezultatas.txt");
	rez << outputas.str();
	rez.close();
}
