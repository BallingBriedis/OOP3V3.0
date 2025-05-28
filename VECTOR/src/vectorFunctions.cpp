// Laikomi vardu vektoriai ir funkcijos, kurios dirba su vektoriais.

#include "meinelib.h"
#include "classV.h"
#include "functionsCallsVector.h"

void failoKurimas() {
	int studentuSk;
	string failoVardas = "studList";
	studentuSk = ivestiesPatikrinimas(1,10000000);

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
	auto trukme = std::chrono::duration_cast<sec>(pabaiga - pradzia);
	cout << "Failas sukurtas per " << fixed << setprecision(8) << trukme.count() << " sec.\n";
}

void fileFilter() {
	vector<Stud> studentai, mokslinciai, vargsai;
	std::stringstream outputas;
	int pasirinkimasV, i = 0;

	// Visos programos vykdymo laiko matavimas
	auto programStart = hrClock::now();

	try {
		fileRead(studentai);
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
	
	for (int i = 0; i < studentai.size(); i++) {
		studentai[i].gal = (pasirinkimasV == 1) ? galutinisVid(studentai[i]) : galutinisMed(studentai[i]);
	}

	// Matuoja rusiavima pagal pasirinkta kriteriju
	auto sortStart = hrClock::now();

	sort(studentai.begin(), studentai.end(), compareByFinalGrade);

	auto sortEnd = hrClock::now();
	auto sortDuration = std::chrono::duration_cast<sec>(sortEnd - sortStart).count();
	cout << "Studentu rusiavimas uztruko: " << fixed << setprecision(8) << sortDuration << " sec\n";

	cout << "------------------------------------------------------------------------\n";
	cout << "Kuria strategija naudoti:\n";
	cout << "1 - Pirma\n2 - Antra\n";
	cout << "------------------------------------------------------------------------\n";
	int skirstymoOption;

	while (true) {
		try {
			cin >> skirstymoOption;
			if (skirstymoOption < 1 || skirstymoOption > 2) {
				cout << "\n\n!!!!Iveskite skaiciu nuo 1 iki 2.!!!!\n\n\n";
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

	auto it = std::partition(studentai.begin(), studentai.end(), [](const Stud& s) { return s.gal < 5; });
		// Matuoja studentu skirstyma i vargsus ir mokslincius laika
		auto rikiavimoStart = hrClock::now();
		
		switch (skirstymoOption) {
		case 1:
			std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(vargsai),
				[](const Stud& s) { return s.gal >= 5; });
			std::remove_copy_if(studentai.begin(), studentai.end(), std::back_inserter(mokslinciai),
				[](const Stud& s) { return s.gal < 5; });
			break;
		case 2:
			std::move(studentai.begin(), it, std::back_inserter(vargsai));
			std::move(it, studentai.end(), std::back_inserter(mokslinciai));
			break;
		default:
			cout << "Neteisingas pasirinkimas.\n";
			break;
		}

		auto rikiavimoEnd = hrClock::now();
		auto rikiavimoDuration = std::chrono::duration_cast<sec>(rikiavimoEnd - rikiavimoStart).count();
		cout << "Studentu skirstymas i vargsus ir mokslincius uztruko: " << fixed << setprecision(8) << rikiavimoDuration << " sec\n";

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

	switch (sortOption) {
	case 1:
		sort(studentai.begin(), studentai.end(), compareByName);
		sort(mokslinciai.begin(), mokslinciai.end(), compareByName);
		sort(vargsai.begin(), vargsai.end(), compareByName);
		break;
	case 2:
		sort(studentai.begin(), studentai.end(), compareBySurname);
		sort(mokslinciai.begin(), mokslinciai.end(), compareBySurname);
		sort(vargsai.begin(), vargsai.end(), compareBySurname);
		break;
	case 3:
		sort(studentai.begin(), studentai.end(), compareByFinalGrade);
		sort(mokslinciai.begin(), mokslinciai.end(), compareByFinalGrade);
		sort(vargsai.begin(), vargsai.end(), compareByFinalGrade);
		break;
	default:
		cout << "Neteisingas pasirinkimas. Nerusiavome.\n";
		break;
	}

	// Matuoja isvedimo i faila laika
	auto writeStart = hrClock::now();
	if (skirstymoOption == 1) {
		if (pasirinkimasV == 1) {
			fileOutVid(vargsai, "Vargsai.txt");
			fileOutVid(mokslinciai, "Mokslinciai.txt");
		}
		else {
			fileOutMed(vargsai, "Vargsai.txt");
			fileOutMed(mokslinciai, "Mokslinciai.txt");
		}
	}
	else {
		if (pasirinkimasV == 1) {
			fileOutVid(studentai, "Vargsai.txt");
			fileOutVid(mokslinciai, "Mokslinciai.txt");
		}
		else {
			fileOutMed(studentai, "Vargsai.txt");
			fileOutMed(mokslinciai, "Mokslinciai.txt");
		}
	}

	auto writeEnd = hrClock::now();
	auto writeDuration = std::chrono::duration_cast<sec>(writeEnd - writeStart).count();
	cout << "Failu isvedimas uztruko: " << fixed << setprecision(8) << writeDuration << " sec\n";

	// Skaiciuoja viso programos vykdymo laika
	auto programEnd = hrClock::now();
	auto programDuration = std::chrono::duration_cast<sec>(programEnd - programStart).count();
	cout << "Visos programos veikimo laikas: " << fixed << setprecision(8) << programDuration << " sec\n";

	studentai.clear();
	studentai.shrink_to_fit();
	mokslinciai.clear();
	mokslinciai.shrink_to_fit();
	vargsai.clear();
	vargsai.shrink_to_fit();
}

void testas() {
	int n = 0;
	sec dursum(0.0);
	string ivestas_vardas;

	cout << "Kiek kartu norite nuskaitineti faila?\n";
	cin >> n;
	cout << "Koki faila norite nuskaityti? (Iveskite be kabuciu)\n";

	for (const auto& entry : fs::directory_iterator(".")) {
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
		if (!duom) {
			throw std::runtime_error("Failas nerastas.\n");
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

			if (!ss.eof()) {
				ss.clear();
				string invalidInput;
				ss >> invalidInput;
				throw std::runtime_error("\n\nError: Netinkamas simbolis pazymiu sarase: " + stu.var + " " + stu.pav + " pazymys: " + invalidInput + "\n\n");
			}

			if (stu.uzd.empty()) {
				throw std::runtime_error("\n\nError: Studentas neturi pazymiu.\n\n");
			}

			stu.egz = stu.uzd.back();
			stu.uzd.pop_back();
			studentai.push_back(stu);
		}

		studentai.clear();
		studentai.shrink_to_fit();

		sec duration = hrClock::now() - start;
		cout << "Failas nuskaitytas per " << fixed << setprecision(8) << duration.count() << " sec\n";
		dursum += duration;
	}

	cout << "Viso laiko: " << fixed << setprecision(8) << dursum.count() << " sec\n\n";
}