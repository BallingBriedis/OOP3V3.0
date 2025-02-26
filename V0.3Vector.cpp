#include "meinelib.h"

struct Stud {
	string var;
	string pav;
	vector<int>uzd{};
	int egz = 0;
	int gal = 0;
};

void readRanka(Stud& stu);
void readName_makeGrade(Stud& stu);
void makeStud(Stud& stu);
void fileRead(vector<Stud>& studentai, string ivestas_vardas);
void randomStudentas(Stud& studentas, bool vyras);
void randomAtsitiktinisPazymys(Stud& stu);
float vidurkis(Stud& studentai);
float mediana(Stud& studentai);
float galutinisVid(Stud& stu);
float galutinisMed(Stud& stu);
void fileOutVid(vector<Stud>& studentai);
void fileOutMed(vector<Stud>& studentai);
bool compareByName(const Stud& a, const Stud& b);
bool compareBySurname(const Stud& a, const Stud& b);
bool compareByFinalGrade(const Stud& a, const Stud& b);
void testas(string ivestas_vardas);


int main() {
	srand(time(NULL));
	vector<Stud> studentai;
	int pasirinkimasV = 0;
	string ivestas_vardas, path = ".";
	auto dursum = std::chrono::milliseconds(0);
	int n = 0;
	while (true) {
		int pasirinkimasInt = 0;
		Stud studentas;
		cout << "Pasirinkite norima studento duomenu surasyma irasant skaiciu nuo 1 iki 5.\n";
		cout << "------------------------------------------------------------------------\n";
		cout << "1 - Ivestis ranka\n2 - Ivestis ranka (Generuojami tik pazymiai)\n3 - Generuojamas studentas ir pazymiai\n4 - Nuskaityti is failo\n5 - Baigti darba\n6 - Testinis nuskaitymas laiko matavimui\n";
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
						cout << entry.path().filename() << endl;
					}
				}
				cin >> ivestas_vardas;
				fileRead(studentai, ivestas_vardas);
				break;
			case 6:
				cout << "Kiek kartu norite nuskaitineti faila?\n";
				cin >> n;
				cout << "Koki faila norite nuskaityti? (Iveskite be kabuciu)\n";
				for (const auto& entry : fs::directory_iterator(path)) {
					if (entry.path().extension() == ".txt") {
						cout << entry.path().filename() << endl;
					}
				}
				cin >> ivestas_vardas;
				for (int i = 0; i < n; i++) {
					auto start = hrClock::now();
					testas(ivestas_vardas);
					auto duration = std::chrono::duration_cast<ms>(hrClock::now() - start);
					cout << "Failas nuskaitytas per " << duration.count() << " milisekundziu.\n";
					dursum += duration;
				}
				cout << "Viso laiko: " << dursum.count()/1000 << " s.\n\n";
				break;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Kaip pateikti rezultata?\n";
	cout << "1 - Vidurkis (ekrane)\n2 - Mediana (ekrane)\n3 - Vidurkis (faile)\n4 - Mediana (faile)\n";
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
	cout << "------------------------------------------------------------------------\n";
	cout << "Wait a tiny bit...\n";

	for (int i = 0;i < studentai.size();i++) {
		studentai[i].gal = (pasirinkimasV == 1 || pasirinkimasV == 3) ? galutinisVid(studentai[i]) : galutinisMed(studentai[i]);
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Pasirinkite rusiavimo kriteriju:\n";
	cout << "1 - Pagal varda\n2 - Pagal pavarde\n3 - Pagal galutini pazymi\n";
	cout << "------------------------------------------------------------------------\n";
	int sortOption = isNumber();
	while (true) {
		if (sortValidInput(sortOption)) {
			break;
		}
		else {
			cout << "Neteisingas pasirinkimas. Iveskite skaiciu nuo 1 iki 3: ";
			sortOption = isNumber();
		}
	}

	switch (sortOption) {
	case 1:
		std::sort(studentai.begin(), studentai.end(), compareByName);
		break;
	case 2:
		std::sort(studentai.begin(), studentai.end(), compareBySurname);
		break;
	case 3:
		std::sort(studentai.begin(), studentai.end(), compareByFinalGrade);
		break;
	default:
		cout << "Neteisingas pasirinkimas. Nerusiavome.\n";
		break;
	}


	switch(pasirinkimasV) {
		case 1:
			cout << "Studentu sarasas: \n";
			cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << endl;
			for (Stud studentas : studentai) {
				cout << std::setw(20) << studentas.var << std::setw(20) << studentas.pav << std::setw(20) << fixed << setprecision(0) << studentas.gal << endl;
			}
			break;
		case 2:
			cout << "Studentu sarasas: \n";
			cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << endl;
			for (Stud studentas : studentai) {
				cout << std::setw(20) << studentas.var << std::setw(20) << studentas.pav << std::setw(20) << fixed << setprecision(0) << studentas.gal << endl;
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

float galutinisVid(Stud& stu) {
	return round(0.6 * stu.egz + 0.4 * vidurkis(stu));
}

float galutinisMed(Stud& stu) {
	return round(0.6 * stu.egz + 0.4 * mediana(stu));
}

void fileOutVid(vector<Stud>& studentai) {
	std::stringstream outputas;
	outputas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << endl;
	for (auto& a : studentai) {
		outputas << std::left << std::setw(20) << a.var << std::setw(20) << a.pav << std::setw(20) << fixed << setprecision(0) << a.gal << "\n";
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
		outputas << std::left << std::setw(20) << a.var << std::setw(20) << a.pav << std::setw(20) << fixed << setprecision(0) << a.gal << "\n";
	}
	studentai.clear();

	std::ofstream rez("rezultatas.txt");
	rez << outputas.str();
	rez.close();
}

bool compareByName(const Stud& a, const Stud& b) {
	return a.var < b.var;
}

bool compareBySurname(const Stud& a, const Stud& b) {
	return a.pav < b.pav;
}

bool compareByFinalGrade(const Stud& a, const Stud& b) {
	return a.gal < b.gal;
}

void testas(string ivestas_vardas) {
	vector<Stud> studentai;
	std::stringstream buffer;
	std::ifstream duom(ivestas_vardas);
	if (!duom) {
		cout << "Failas nerastas." << endl;
		return;
	}
	buffer << duom.rdbuf();
	duom.close();

	string line;
	getline(buffer, line);
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
