#include "meinelib.h"
#include "structV.h"
#include "functionsCallsV.h"

vector<string> vyruVardai = { "Jonas", "Mantas", "Tomas", "Lukas", "Dovydas", "Andrius", "Gabrielius", "Erikas", "Vilius", "Domantas",
							   "Augustas", "Mindaugas", "Rokas", "Paulius", "Simas", "Arnas", "Edvinas", "Justas", "Kipras", "Martynas",
							   "Pijus", "Vytis", "Zygimantas", "Tautvydas", "Evaldas", "Eimantas", "Deividas", "Laurynas", "Karolis", "Gytis",
							   "Benas", "Titas", "Ignas", "Nojus", "Vytautas", "Aivaras", "Saulius", "Kristupas", "Orestas", "Armandas",
							   "Jokubas", "Dainius", "Sigitas", "Almantas", "Haroldas", "Julius", "Dziugas", "Gediminas", "Antanas", "Vytenis" };

vector<string> vyruPavardes = { "Jonaitis", "Petraitis", "Kazlauskas", "Baltrunas", "Simkus", "Kairys", "Marcinkevicius", "Zabielskas", "Bagdonas", "Urbonas",
								"Kavaliauskas", "Puidokas", "Bielskis", "Matulevicius", "Sulskis", "Sakalauskas", "Butkus", "Karpavicius", "Zilinskas", "Stankevicius",
								"Vasiliauskas", "Simkevicius", "Daksevic", "Paskevicius", "Bagdonavicius", "Aleknavicius", "Kavolis", "Miezutavicius", "Giedraitis", "Pavardenis",
								"Sviderskis", "Malinauskas", "Gintalas", "Budreckas", "Tamasauskas", "Zimnickas", "Tamulevicius", "Skorupskas", "Gaigalas", "Sadauskas",
								"Janusonis", "Leskevicius", "Mikulenas", "Kairaitis", "Jarmalavicius", "Milkevicus", "Dumcius", "Tamulynas", "Poska", "Savickas" };

vector<string> moteruVardai = { "Austeja", "Gabija", "Egle", "Ieva", "Lina", "Ruta", "Agne", "Laura", "Monika", "Jurgita",
								"Kamile", "Indre", "Viktorija", "Justina", "Karolina", "Evelina", "Ugne", "Neringa", "Dovile", "Raminta",
								"Erika", "Gintare", "Alina", "Simona", "Vaida", "Edita", "Julija", "Renata", "Sandra", "Svetlana",
								"Laima", "Zita", "Gitana", "Greta", "Sigita", "Brigita", "Aleksandra", "Emilija", "Asta", "Ingrida",
								"Joana", "Patricija", "Skaiste", "Vitalija", "Giedre", "Rasa", "Lilija", "Ona", "Aurelija", "Silvija" };

vector<string> moteruPavardes = { "Jonate", "Petraite", "Kazlauskaite", "Baltrunaite", "Simkute", "Kairyte", "Marcinkeviciute", "Zabielskaite", "Bagdonaite", "Urbonaite",
								   "Kavaliauskaite", "Griniute", "Bielskiute", "Matuleviciute", "Sulskite", "Sakalauskaite", "Butkute", "Karpaviciute", "Zilinskaite", "Stankeviciute",
								   "Vasiliauskaite", "Simkeviciute", "Vainyte", "Paskeviciute", "Bagdonaviciute", "Aleknaviciute", "Kavoliute", "Miezutaviciute", "Giedraite", "Pavardenyte",
								   "Sviderskyte", "Malinauskaite", "Gintalaite", "Budreckaite", "Tamasauskaite", "Zimnickaite", "Tamuleviciute", "Skorupskaite", "Gaigalaite", "Sadauskaite",
								   "Janusonyte", "Leskeviciute", "Mikulenaite", "Kairaite", "Jarmalaviciute", "Milkeviciute", "Dumciute", "Tamulynaite", "Poskaite", "Savickaite" };

void readRanka(Stud& stu) {
	int input;
	cout << "Iveskite studento varda: ";
	cin >> stu.var;
	cout << "Iveskite studento pavarde: ";
	cin >> stu.pav;

	cout << "Iveskite studento egzamino pazymi: ";
	while (true) {
		try {
			cin >> input;
			if (input < 0 || input > 10) {
				cout << "!!!!Iveskite skaiciu nuo 0 iki 10.!!!!\n\n\n";
				continue;
			}
		}
		catch (...) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!";
			continue;
		}
		break;
	}
	stu.egz = input;
	cout << "\n\n" << "Iveskite studento namu darbu pazymius. Ivedus visus pazymius, iveskite -1.\n";
	cout << "Jeigu darbas neatliktas iveskite 0.\n\n";
	int i = 1;
	while (true) {
		try {
			cout << i << "-asis pazymys: ";
			cin >> input;
			if (input == -1) {
				break;
			}
			if (input < 0 || input > 10) {
				cout << "!!!!Iveskite sveika skaiciu nuo 0 iki 10 imtinai.!!!!\n!!!!Jeigu norite iseiti iveskite -1:!!!!!\n" << endl;
				continue;
			}
		}
		catch (...) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!";
			continue;
		}
		stu.uzd.push_back(input);
		i++;
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
		throw std::runtime_error("\nFailas nerastas.\n\n");
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
		studentas.var = vyruVardai.at(rand() % vyruVardai.size());
		studentas.pav = vyruPavardes.at(rand() % vyruPavardes.size());
	}
	else {
		studentas.var = moteruVardai.at(rand() % moteruVardai.size());
		studentas.pav = moteruPavardes.at(rand() % moteruPavardes.size());
	}
}

void randomAtsitiktinisPazymys(Stud& stu) {
	int pazymiai;
	stu.egz = rand() % 10 + 1;
	cout << "Kiek pazymiu sugeneruoti? ";
	while (true) {
		try {
			cin >> pazymiai;
		}
		catch (...) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!";
			continue;
		}
		break;
	}

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
		throw std::runtime_error("Failas nerastas.\n");
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

		try {
			while (ss >> pazymys) {
				stu.uzd.push_back(pazymys);
			}
		}
		catch (...) {
			cout << "!!!!Pazymiuose ivesta raide.!!!!\n\n\n";
			continue;
		}

		if (stu.uzd.empty()) {
			throw std::runtime_error("Error: Studentas neturi pazymiu.");
		}

		stu.egz = stu.uzd.back();
		stu.uzd.pop_back();
		studentai.push_back(stu);
	}
}