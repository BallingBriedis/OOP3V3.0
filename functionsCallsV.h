#ifndef FUNCTIONSCALLSV_H
#define FUNCTIONSCALLSV_H


//Prototipai
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

void randomStudentas(Stud& studentas, bool vyras) {
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
		throw std::runtime_error("Failas nerastas.");
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

		if (stu.uzd.empty()) {
			throw std::runtime_error("Error: Studentas neturi pazymiu.");
		}

		stu.egz = stu.uzd.back();
		stu.uzd.pop_back();
		studentai.push_back(stu);
	}
}
#endif
