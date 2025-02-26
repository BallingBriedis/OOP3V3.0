#include "meinelib.h"
#include "structV.h"
#include "functionsCallsV.h"

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