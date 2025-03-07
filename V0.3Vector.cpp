#include "meinelib.h"
#include "structV.h"
#include "functionsCallsV.h"

int main() {
	cin.exceptions(std::ios::failbit);
	srand(time(NULL));
	vector<Stud> studentai;
	int pasirinkimasV = 0;
	string ivestas_vardas;
	int n = 0;
	while (true) {																											// Meniu ciklas
		int pasirinkimasInt = 0;
		Stud studentas;
		cout << "Pasirinkite norima studento duomenu surasyma irasant skaiciu nuo 1 iki 8.\n";
		cout << "------------------------------------------------------------------------\n";
		cout << "1 - Ivestis ranka\n";
		cout << "2 - Ivestis ranka (Generuojami tik pazymiai)\n";
		cout << "3 - Generuojamas studentas ir pazymiai\n";
		cout << "4 - Failo nuskaitymas\n";
		cout << "5 - Failo kurimas\n";
		cout << "6 - Failo surusiavimas\n";
		cout << "7 - Testinis nuskaitymas laiko matavimui\n";
		cout << "8 - Baigti darba\n";
		cout << "------------------------------------------------------------------------\n";
		try {																												// Teisingo pasirinkimo gaudymas
			cin >> pasirinkimasInt;
			if (pasirinkimasInt < 1 || pasirinkimasInt > 8) {
				cout << "\n\n!!!!Iveskite skaiciu nuo 1 iki 8.!!!!\n\n\n";
				continue;
			}
		}
		catch(...){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n\n";
			continue;
		}
		
		if (pasirinkimasInt == 8) {
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
				cout << "Kiek studentu sugeneruoti?\n";
				cin >> n;
				for (int i = 0; i < n; i++) {
				makeStud(studentas);
				studentai.push_back(studentas);
				}
				break;
			case 4:
				try {
					fileRead(studentai);
				}
				catch (const std::exception& e) {
					std::cerr << e.what() << std::endl;
					continue;
				}
				break;
			case 5:
				failoKurimas();
				break;
			case 6:
				fileFilter();
				break;
			case 7:
					try {
						testas();
					}
					catch (const std::exception& e) {
						std::cerr << e.what() << std::endl;
						break;
					}
				break;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Kaip pateikti rezultata?\n";
	cout << "1 - Vidurkis (ekrane)\n2 - Mediana (ekrane)\n3 - Vidurkis (faile)\n4 - Mediana (faile)\n";
	cout << "------------------------------------------------------------------------\n";
	while (true) {																											// Teisingo pasirinkimo ciklas
		try {																												// Teisingo pasirinkimo gaudymas
			cin >> pasirinkimasV;
			if (pasirinkimasV < 1 || pasirinkimasV > 4) {
				cout << "\n\n!!!!Iveskite skaiciu nuo 1 iki 4.!!!!\n\n\n";
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
	cout << "Wait a tiny bit while the program is calculating...\n";

	for (int i = 0;i < studentai.size();i++) {
		studentai[i].gal = (pasirinkimasV == 1 || pasirinkimasV == 3) ? galutinisVid(studentai[i]) : galutinisMed(studentai[i]);
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Pasirinkite rusiavimo kriteriju:\n";
	cout << "1 - Pagal varda\n2 - Pagal pavarde\n3 - Pagal galutini pazymi\n";
	cout << "------------------------------------------------------------------------\n";
	int sortOption;
	while (true) {																											// Teisingo pasirinkimo ciklas
		try {																												// Teisingo pasirinkimo gaudymas
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
			studentai.clear();																								// Duomenys nebereikalingi, pasalina visus elementus is vektoriaus.
			studentai.shrink_to_fit();																						// Duomenys nebereikalingi, sumazina rezervuota vieta iki tuscio dydzio.
			break;
		case 2:
			cout << "Studentu sarasas: \n";
			cout << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << endl;
			for (Stud studentas : studentai) {
				cout << std::setw(20) << studentas.var << std::setw(20) << studentas.pav << std::setw(20) << fixed << setprecision(0) << studentas.gal << endl;
			}
			studentai.clear();																								// Duomenys nebereikalingi, pasalina visus elementus is vektoriaus.
			studentai.shrink_to_fit();																						// Duomenys nebereikalingi, sumazina rezervuota vieta iki tuscio dydzio.
			break;
		case 3:
			fileOutVid(studentai);
			break;
		case 4:
			fileOutMed(studentai);
			break;
	}
	studentai.clear();																										// Galutinis duomenu pasalinimas, naudojamas isitikinti, kad vektorius tuscias.
	studentai.shrink_to_fit();																								// Galutinis duomenu atlaisvinimas.
	return 0;
}