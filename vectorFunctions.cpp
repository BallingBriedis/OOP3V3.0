// Laikomi vardu vektoriai ir funkcijos, kurios dirba su vektoriais.

#include "meinelib.h"
#include "structV.h"
#include "functionsCallsV.h"

// Vektoriai su vardais ir pavardemis.

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

void readRanka(Stud& stu) {																									// Vartotojo praso ivesti studento varda, pavarde, pazymius.
	int input;
	cout << "Iveskite studento varda: ";
	cin >> stu.var;
	cout << "Iveskite studento pavarde: ";
	cin >> stu.pav;

	cout << "Iveskite studento egzamino pazymi: ";
	while (true) {																											// Teisingo pasirinkimo ciklas
		try {																												// Teisingo pasirinkimo gaudymas
			cin >> input;
			if (input < 0 || input > 10) {
				cout << "\n\n!!!!Iveskite skaiciu nuo 0 iki 10.!!!!\n\n\n";
				continue;
			}
		}
		catch (...) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n";
			continue;
		}
		break;
	}
	stu.egz = input;
	cout << "\n\n" << "Iveskite studento namu darbu pazymius. Ivedus visus pazymius, iveskite -1.\n";
	cout << "Jeigu darbas neatliktas iveskite 0.\n\n";
	int i = 1;
	while (true) {																											// Teisingo pasirinkimo ciklas
		try {																												// Teisingo pasirinkimo gaudymas
			cout << i << "-asis pazymys: ";
			cin >> input;
			if (input == -1) {
				break;
			}
			if (input < 0 || input > 10) {
				cout << "\n\n!!!!Iveskite sveika skaiciu nuo 0 iki 10 imtinai.!!!!\n!!!!Jeigu norite iseiti iveskite -1:!!!!!\n" << endl;
				continue;
			}
		}
		catch (...) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n";
			continue;
		}
		stu.uzd.push_back(input);
		i++;
	}
}

void readName_makeGrade(Stud& stu) {																						// Vartotojo praso ivesti studento varda ir pavarde, pazymius sugeneruoja.
	cout << "Iveskite studento varda: ";
	cin >> stu.var;
	cout << "Iveskite studento pavarde: ";
	cin >> stu.pav;
	randomAtsitiktinisPazymys(stu);
}

void makeStud(Stud& stu) {																									// Sukuria atsitiktini studenta.
	randomStudentas(stu, rand() % 2);
	randomAtsitiktinisPazymys(stu);
}

void fileRead(vector<Stud>& studentai) {																// Nuskaito duomenis is failo.
	string ivestas_vardas;
	cout << "Iveskite norimo failo pavadinima be kabuciu:\n";
	for (const auto& entry : fs::directory_iterator(".")) {
		if (entry.path().extension() == ".txt") {
			cout << entry.path().filename() << endl;
		}
	}
	cin >> ivestas_vardas;
	std::stringstream buffer;
	std::ifstream duom(ivestas_vardas);
	if (!duom) {																											// Truksta failo, ismeta klaida.
		throw std::runtime_error("\nFailas nerastas.\n\n");
		return;
	}
	buffer << duom.rdbuf();
	duom.close();

	string line;
	getline(buffer, line);																									// Daromas su prielaida, kad pirmoje eiluteje tik pavadinimai zemiau pateiktu duomenu.
	while (getline(buffer, line)) {																							// Nuskaitineja po viena eilute is failo.
		Stud stu;
		std::stringstream ss(line);
		ss >> stu.var >> stu.pav;
		int pazymys;

		while (true) {
			if (ss >> pazymys) {																							// Sekmingai perskaitomas skaicius.
				stu.uzd.push_back(pazymys);
			}
			else if (ss.eof()) {																							// Linija perskaityta iki galo, tad nuskaitymas baigiamas.
				break;
			}
			else {																											// Jei linija nebaigta skaityti, bet elementas neperskaitomas kaip skaicius, tai ismeta klaida.
				ss.clear();
				std::string invalidInput;
				ss >> invalidInput;

				throw std::runtime_error("\n\nError: Netinkamas simbolis pazymiu sarase: " + invalidInput + "\n\n");
			}
		}

		if (stu.uzd.empty()) {																								// Jei studentas neturi pazymiu, ismeta klaida.
			throw std::runtime_error("\n\nError: Studentas neturi pazymiu.\n\n");
		}

		stu.egz = stu.uzd.back();
		stu.uzd.pop_back();
		studentai.push_back(stu);
		stu.uzd.clear();																									// Pasalinami visi elementai is vektoriaus.
		stu.uzd.shrink_to_fit();																							// Rezervuota vieta sulygina su laikomais duomenim, atlaisvina vieta kitiems procesams.
	}
}

void randomStudentas(Stud& studentas, bool vyras) {																			// Sukuria atsitiktini studenta.
	if (vyras) {
		studentas.var = vyruVardai.at(rand() % vyruVardai.size());
		studentas.pav = vyruPavardes.at(rand() % vyruPavardes.size());
	}
	else {
		studentas.var = moteruVardai.at(rand() % moteruVardai.size());
		studentas.pav = moteruPavardes.at(rand() % moteruPavardes.size());
	}
}

void randomAtsitiktinisPazymys(Stud& stu) {																					// Sugeneruoja atsitiktini pazymi.
	int pazymiai = rand() % 15 + 1;
	stu.egz = rand() % 10 + 1;

	for (int i = 0; i < pazymiai; i++) {
		stu.uzd.push_back(rand() % 10 + 1);
	}
}

void failoKurimas() {
	int studentuSk;
	string failoVardas = "studList";
	while (true) {
		cout << "Iveskite studentu skaiciu: ";
		try {
			cin >> studentuSk;
			if (studentuSk < 1) {
				cout << "\n\nIveskite skaiciu didesni uz 0.\n\n";
				continue;
			}
			else {
				break;
			}
		}
		catch (...) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n";
			continue;
		}
	}

	auto pradzia = hrClock::now();
	cout << "\n\nPalaukite, kuriamas failas...\n\n";
	failoVardas += std::to_string(studentuSk) + ".txt";

	std::stringstream outputas;
	int pazymiuSk = 7;

	outputas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20);

	for (int i = 0; i < pazymiuSk; i++) {
		outputas << std::left << std::setw(6) << "ND" + std::to_string(i + 1);

	}
	outputas << std::left << std::setw(6) << "Egz." << endl;

	for (int i = 0; i < studentuSk; i++) {
		outputas << std::left << std::setw(20) << "Vardas" + std::to_string(i + 1) << std::setw(20) << "Pavarde" + std::to_string(i + 1);

		for (int j = 0; j < pazymiuSk; j++) {
			outputas << std::setw(6) << rand() % 10 + 1;

		}
		outputas << std::setw(6) << rand() % 10 + 1 << endl;

	}
	std::ofstream rez(failoVardas);
	rez << outputas.str();
	rez.close();
	auto pabaiga = hrClock::now();
	auto trukme = std::chrono::duration_cast<ms>(pabaiga - pradzia);
	cout << "Failas sukurtas per " << trukme.count() << " milisekundziu.\n";
}

void fileFilter() {
	vector<Stud> studentai, vargsai, mokslinciai;
	std::stringstream outputas;
	int pasirinkimasV, i = 0;

	// Visos programos vykdymo laiko matavimas
	auto programStart = hrClock::now();

	try {
		// Matuoja kiek laiko uztrunka failo nuskaitymas
		auto readStart = hrClock::now();
		fileRead(studentai);
		auto readEnd = hrClock::now();
		auto readDuration = std::chrono::duration_cast<ms>(readEnd - readStart).count();
		cout << "Ivestis is failo uztruko: " << readDuration << " ms\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return;
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Kaip pateikti rezultata?\n";
	cout << "1 - Vidurkiu\n2 - Mediana\n";
	cout << "------------------------------------------------------------------------\n";

	while (true) {
		try {
			cin >> pasirinkimasV;
			if (pasirinkimasV < 1 || pasirinkimasV > 2) {
				cout << "\n\n!!!!Iveskite skaiciu 1 arba 2.!!!!\n\n\n";
				continue;
			}
		}
		catch (...) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n\n";
			continue;
		}
		break;
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Palaukite kol programa skaiciuoja...\n";

	// Matuoja studentu galutinio skaiciavimo ilgi
	auto calcStart = hrClock::now();
	for (int i = 0; i < studentai.size(); i++) {
		studentai[i].gal = (pasirinkimasV == 1) ? galutinisVid(studentai[i]) : galutinisMed(studentai[i]);
	}
	auto calcEnd = hrClock::now();
	auto calcDuration = std::chrono::duration_cast<ms>(calcEnd - calcStart).count();
	cout << "Vidurkio skaiciavimai uztruko: " << calcDuration << " ms\n";

	cout << "------------------------------------------------------------------------\n";
	cout << "Pasirinkite rusiavimo kriteriju:\n";
	cout << "1 - Pagal varda\n2 - Pagal pavarde\n3 - Pagal galutini pazymi\n";
	cout << "------------------------------------------------------------------------\n";
	int sortOption;
	while (true) {
		try {
			cin >> sortOption;
			if (sortOption < 1 || sortOption > 3) {
				cout << "\n\n!!!!Iveskite skaiciu nuo 1 iki 3.!!!!\n\n\n";
				continue;
			}
		}
		catch (...) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n\n";
			continue;
		}
		break;
	}

	// Matuoja rusiavimo laika
	auto sortStart = hrClock::now();
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
	auto sortEnd = hrClock::now();
	auto sortDuration = std::chrono::duration_cast<ms >(sortEnd - sortStart).count();
	cout << "Studentu rusiavimas uztruko: " << sortDuration << " ms\n";

	// Matuoja studentu rusiavima
	auto rusiavimoStart = hrClock::now();
	for (auto it = studentai.begin(); it != studentai.end();) {
		if (it->gal < 5) {
			vargsai.push_back(*it);
			it = studentai.erase(it);
		}
		else {
			mokslinciai.push_back(*it);
			++it;
		}
	}
	studentai.clear();
	studentai.shrink_to_fit();
	auto rusiavimoEnd = hrClock::now();
	auto rusiavimoDuration = std::chrono::duration_cast<ms>(rusiavimoEnd - rusiavimoStart).count();
	cout << "Studentu rusiavimas uztruko: " << rusiavimoDuration << " ms\n";

	// Matuoja isvedimo i faila laika
	auto writeStart = hrClock::now();
	if (pasirinkimasV == 1) {
		fileCreateOutVid(vargsai, "Vargsai.txt");
		fileCreateOutVid(mokslinciai, "Mokslinciai.txt");
	}
	else {
		fileCreateOutMed(vargsai, "Vargsai.txt");
		fileCreateOutMed(mokslinciai, "Mokslinciai.txt");
	}
	auto writeEnd = hrClock::now();
	auto writeDuration = std::chrono::duration_cast<ms>(writeEnd - writeStart).count();
	cout << "Failu isvedimas uztruko: " << writeDuration << " ms\n";

	// Skaiciuoja viso programos vykdymo laika
	auto programEnd = hrClock::now();
	auto programDuration = std::chrono::duration_cast<ms>(programEnd - programStart).count();
	cout << "Visos programos veikimo laikas: " << programDuration << " ms\n";

	vargsai.clear();
	vargsai.shrink_to_fit();
	mokslinciai.clear();
	mokslinciai.shrink_to_fit();
}

void fileCreateOutVid(vector<Stud>& studentai, string ivestas_vardas) {																					// Isveda i faila pagal vidurki.
	std::stringstream outputas;
	outputas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << endl;
	for (auto& a : studentai) {
		outputas << std::left << std::setw(20) << a.var << std::setw(20) << a.pav << std::setw(20) << fixed << setprecision(0) << a.gal << "\n";
	}
	studentai.clear();																										// Duomenys nebereikalingi, pasalina visus elementus is vektoriaus.
	studentai.shrink_to_fit();																								// Duomenys nebereikalingi, sumazina rezervuota vieta iki tuscio dydzio.

	std::ofstream rez(ivestas_vardas);
	rez << outputas.str();
	rez.close();
}

void fileCreateOutMed(vector<Stud>& studentai, string ivestas_vardas) {																					// Isveda i faila pagal mediana.
	std::stringstream outputas;
	outputas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << endl;
	for (auto& a : studentai) {
		outputas << std::left << std::setw(20) << a.var << std::setw(20) << a.pav << std::setw(20) << fixed << setprecision(0) << a.gal << "\n";
	}
	studentai.clear();																										// Duomenys nebereikalingi, pasalina visus elementus is vektoriaus.
	studentai.shrink_to_fit();																								// Duomenys nebereikalingi, sumazina rezervuota vieta iki tuscio dydzio.

	std::ofstream rez(ivestas_vardas);
	rez << outputas.str();
	rez.close();
}

void fileCreateOutVid(vector<Stud>& studentai) {																					// Isveda i faila pagal vidurki.
	std::stringstream outputas;
	outputas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << endl;
	for (auto& a : studentai) {
		outputas << std::left << std::setw(20) << a.var << std::setw(20) << a.pav << std::setw(20) << fixed << setprecision(0) << a.gal << "\n";
	}
	studentai.clear();																										// Duomenys nebereikalingi, pasalina visus elementus is vektoriaus.
	studentai.shrink_to_fit();																								// Duomenys nebereikalingi, sumazina rezervuota vieta iki tuscio dydzio.

	std::ofstream rez("rezultatas.txt");
	rez << outputas.str();
	rez.close();
}

void fileCreateOutMed(vector<Stud>& studentai) {																					// Isveda i faila pagal mediana.
	std::stringstream outputas;
	outputas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << endl;
	for (auto& a : studentai) {
		outputas << std::left << std::setw(20) << a.var << std::setw(20) << a.pav << std::setw(20) << fixed << setprecision(0) << a.gal << "\n";
	}
	studentai.clear();																										// Duomenys nebereikalingi, pasalina visus elementus is vektoriaus.
	studentai.shrink_to_fit();																								// Duomenys nebereikalingi, sumazina rezervuota vieta iki tuscio dydzio.

	std::ofstream rez("rezultatas.txt");
	rez << outputas.str();
	rez.close();
}

float vidurkis(Stud& studentai) {																							// Suskaiciuoja vidurki.
	if (studentai.uzd.empty()) return 0.0;
	return accumulate(studentai.uzd.begin(), studentai.uzd.end(), 0) / studentai.uzd.size();
}

float mediana(Stud& studentai) {																							// Suskaiciuoja mediana.
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

float galutinisVid(Stud& stu) {																								// Suskaiciuoja galutini pagal vidurki.
	return round(0.6 * stu.egz + 0.4 * vidurkis(stu));
}

float galutinisMed(Stud& stu) {																								// Suskaiciuoja galutini pagal mediana.
	return round(0.6 * stu.egz + 0.4 * mediana(stu));
}

void fileOutVid(vector<Stud>& studentai) {																					// Isveda i faila pagal vidurki.
	std::stringstream outputas;
	outputas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << endl;
	for (auto& a : studentai) {
		outputas << std::left << std::setw(20) << a.var << std::setw(20) << a.pav << std::setw(20) << fixed << setprecision(0) << a.gal << "\n";
	}
	studentai.clear();																										// Duomenys nebereikalingi, pasalina visus elementus is vektoriaus.
	studentai.shrink_to_fit();																								// Duomenys nebereikalingi, sumazina rezervuota vieta iki tuscio dydzio.

	std::ofstream rez("rezultatas.txt");
	rez << outputas.str();
	rez.close();
}

void fileOutMed(vector<Stud>& studentai) {																					// Isveda i faila pagal mediana.
	std::stringstream outputas;
	outputas << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << endl;
	for (auto& a : studentai) {
		outputas << std::left << std::setw(20) << a.var << std::setw(20) << a.pav << std::setw(20) << fixed << setprecision(0) << a.gal << "\n";
	}
	studentai.clear();																										// Duomenys nebereikalingi, pasalina visus elementus is vektoriaus.
	studentai.shrink_to_fit();																								// Duomenys nebereikalingi, sumazina rezervuota vieta iki tuscio dydzio.

	std::ofstream rez("rezultatas.txt");
	rez << outputas.str();
	rez.close();
}

bool compareByName(const Stud& a, const Stud& b) {																			// Rusiavimo funkcijos dalis kuri tikrina vardus.
	return a.var < b.var;
}

bool compareBySurname(const Stud& a, const Stud& b) {																		// Rusiavimo funkcijos dalis kuri tikrina pavardes.
	return a.pav < b.pav;
}

bool compareByFinalGrade(const Stud& a, const Stud& b) {																	// Rusiavimo funkcijos dalis kuri tikrina galutinius pazymi.
	return a.gal < b.gal;
}

void testas() {																						// Testavimo funkcija.
	int n = 0;
	auto dursum = std::chrono::milliseconds(0);
	string ivestas_vardas;
	cout << "Kiek kartu norite nuskaitineti faila?\n";
	cin >> n;
	cout << "Koki faila norite nuskaityti? (Iveskite be kabuciu)\n";
	for (const auto& entry : fs::directory_iterator(".")) {													// Iteruoja per direktorija, iesko failu su .txt pabaiga.
		if (entry.path().extension() == ".txt") {
			cout << entry.path().filename() << endl;
		}
	}
	cin >> ivestas_vardas;

	for (int i = 0; i < n; i++) {
		auto start = hrClock::now();

	vector<Stud> studentai;
	std::stringstream buffer;
	std::ifstream duom(ivestas_vardas);
	if (!duom) {																											// Truksta failo, ismeta klaida.
		throw std::runtime_error("Failas nerastas.\n");
		return;
	}
	buffer << duom.rdbuf();
	duom.close();

	string line;
	getline(buffer, line);																									// Daromas su prielaida, kad pirmoje eiluteje tik pavadinimai zemiau pateiktu duomenu.
	while (getline(buffer, line)) {																							// Nuskaitineja po viena eilute is failo.
		Stud stu;
		std::stringstream ss(line);
		ss >> stu.var >> stu.pav;
		int pazymys;

		while (true) {																										// Pazymiu nuskaitymo ciklas.
			if (ss >> pazymys) {																							// Sekmingai perskaitomas skaicius
				stu.uzd.push_back(pazymys);
			}
			else if (ss.eof()) {																							// Linija perskaityta iki galo
				break;
			}
			else {																											// Jei linija nebaigta skaityti, bet elementas neperskaitomas kaip skaicius, tai ismeta klaida.
				ss.clear();
				std::string invalidInput;
				ss >> invalidInput;

				throw std::runtime_error("\n\nError: Netinkamas simbolis pazymiu sarase: " + stu.var + " " + stu.pav + " pazymys: " + invalidInput + "\n\n");
			}
		}

		if (stu.uzd.empty()) {																								// Jei studentas neturi pazymiu, ismeta klaida.
			throw std::runtime_error("\n\nError: Studentas neturi pazymiu.\n\n");
		}

		stu.egz = stu.uzd.back();
		stu.uzd.pop_back();
		studentai.push_back(stu);
		stu.uzd.clear();																									// Pasalinami visi elementai is vektoriaus.
		stu.uzd.shrink_to_fit();																							// Rezervuota vieta sulygina su laikomais duomenim, atlaisvina vieta kitiems procesams.
	}
	studentai.clear();																										// Testinis nuskaitymas, nereikia saugoti duomenu, pasalina visus elementus is vektoriaus.
	studentai.shrink_to_fit();																								// Rezervuota vieta sulygina su laikomais duomenim, atlaisvina vieta kitiems procesams.

	auto duration = std::chrono::duration_cast<ms>(hrClock::now() - start);
	cout << "Failas nuskaitytas per " << duration.count() << " milisekundziu.\n";
	dursum += duration;
}
cout << "Viso laiko: " << dursum.count() / 1000 << " s.\n\n";
}