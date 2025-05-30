#include "meinelib.h"
#include "studentas.h"
#include "functionsCallsVector.h"

void testMenu() {
	while (true) {
	cout << "Pasirinkite norima testavimo buda: \n";
	cout << "1 - Nuskaitymo testas\n";
	cout << "2 - Programos unit testas\n";
	cout << "3 - Studentu unit testas\n";
	cout << "4 - Baigti testavima\n";
	int testPasirinkimas = ivestiesPatikrinimas(1, 4, 4);

	if (testPasirinkimas == 4) return;

		switch (testPasirinkimas) {
		case 1:
			nuskaitymoTestas();
			break;
		case 2:
			programUnitTest();
			break;
		case 3:
			studentuUnitTest();
			break;
		}
	}
}
void nuskaitymoTestas() {
	int n = 0;
	sec dursum(0.0);
	string ivestas_vardas;
	vector<Stud> studentai;

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
			Stud tempStu;
			std::istringstream iss(line);
			string vardas{}, pavarde{};
			iss >> vardas >> pavarde;
			tempStu.setVar(vardas);
			tempStu.setPav(pavarde);
			int pazymys{};

			while (iss >> pazymys) {
				tempStu.addPazymys(pazymys);
			}
			tempStu.setEgz(tempStu.getPazymys().back());
			tempStu.removePazymys();
			studentai.push_back(tempStu);
		}

		sec duration = hrClock::now() - start;
		cout << "Failas nuskaitytas per " << fixed << setprecision(8) << duration.count() << " sec\n";
		dursum += duration;
	}
	studentai.clear();
	studentai.shrink_to_fit();
	cout << "Viso laiko: " << fixed << setprecision(8) << dursum.count() << " sec\n";
	cout << "Avg: " << fixed << setprecision(8) << dursum.count() / n << " sec\n\n";
}

void programUnitTest() {
	vector<Stud> studentai;
	Stud studentas;

	// Test 1: Manual input
	readRanka(studentas);
	studentai.push_back(studentas);

	if (studentai.size() == 1)
		cout << "[PASS] Added one student\n\n";
	else
		cout << "[FAIL] studentai size: " << studentai.size() << ", expected 1\n\n";

	if (studentai[0].getVar() == studentas.getVar())
		cout << "[PASS] Name matches\n\n";
	else
		cout << "[FAIL] Name mismatch\n\n";

	if (studentai[0].getPav() == studentas.getPav())
		cout << "[PASS] Surname matches\n\n";
	else
		cout << "[FAIL] Surname mismatch\n\n";

	// Test 2: Generate random grades
	readName_makeGrade(studentas);
	if (!studentas.getPazymys().empty())
		cout << "[PASS] Random grades generated\n\n";
	else
		cout << "[FAIL] Random grades missing\n\n";

	// Test 3: Create a random student
	makeStud(studentas);
	if (!studentas.getPazymys().empty())
		cout << "[PASS] Random student created\n\n";
	else
		cout << "[FAIL] Random student creation failed\n\n";

	// Test 4: File reading
	try {
		fileRead(studentai, "test.txt");
		if (!studentai.empty())
			cout << "[PASS] File reading successful\n\n";
		else
			cout << "[FAIL] File read but no students loaded\n\n";
	}
	catch (const std::exception& e) {
		cout << "[FAIL] File reading exception: " << e.what() << '\n\n';
	}

	// Test 5: File creation
	failoKurimas(100);
	if (fs::exists("studList100.txt"))
		cout << "[PASS] File creation successful\n\n";
	else
		cout << "[FAIL] File not created\n\n";

	// Test 6: Output filtering
	isvestiesMenu(studentai);

	// Test 7: Sorting
	rusiavimas(studentai, 1);
	cout << "[INFO] Sorting completed\n\n";
}

void studentuUnitTest() {
	vector<Stud> studentai;
	vector<int> pazymiai = { 5, 6, 7 };


	/// Konstruktoriaus testas
	Stud studentas1("Jonas", "Jonaitis", pazymiai, 8);
	studentas1.calculateGalVidurkis();
	studentas1.calculateGalMediana();
	if (studentas1.getVar() == "Jonas" &&
		studentas1.getPav() == "Jonaitis" &&
		studentas1.getPazymys() == pazymiai) {
		cout << "[PASS] Constructor test passed\n\n";
	}
	else {
		cout << "[FAIL] Constructor test failed\n\n";
	}
	/// Tuscio konstruktoriaus testas
	Stud studentas7;
	if (studentas7.getVar().empty() &&
		studentas7.getPav().empty() &&
		studentas7.getPazymys().empty()) {
		cout << "[PASS] Empty Constructor test passed\n\n";
	}
	else {
		cout << "[FAIL] Empty Constructor test failed\n\n";
	}

	// Copy constructor testas
	Stud studentas2(studentas1);
	if (studentas1.getVar() == studentas2.getVar() &&
		studentas1.getPav() == studentas2.getPav() &&
		studentas1.getPazymys() == studentas2.getPazymys() &&
		studentas1.getVidurkis() == studentas2.getVidurkis() &&
		studentas1.getMediana() == studentas2.getMediana()) {
		cout << "[PASS] Copy constructor test passed\n\n";
	}
	else {
		cout << "[FAIL] Copy constructor test failed\n\n";
	}

	// Copy assignment operator testas
	Stud studentas3;
	studentas3 = studentas1;
	if (studentas3.getVar() == studentas1.getVar() &&
		studentas3.getPav() == studentas1.getPav() &&
		studentas3.getPazymys() == studentas1.getPazymys() &&
		studentas3.getVidurkis() == studentas1.getVidurkis() &&
		studentas3.getMediana() == studentas1.getMediana()) {
		cout << "[PASS] Copy assignment operator test passed\n\n";
	}
	else {
		cout << "[FAIL] Copy assignment operator test failed\n\n";
	}

	// Move constructor testas
	Stud studentas4(std::move(studentas1));
	if (studentas4.getVar() == "Jonas" &&
		studentas4.getPav() == "Jonaitis" &&
		studentas4.getPazymys() == pazymiai &&
		studentas1.getVar() != "Jonas" &&
		studentas1.getPav() != "Jonaitis" &&
		studentas1.getPazymys() != pazymiai) {
		cout << "[PASS] Move constructor test passed\n\n";
	}
	else {
		cout << "[FAIL] Move constructor test failed\n\n";
	}

	// Move assignment operator testas
	Stud studentas5;
	studentas5 = std::move(studentas4);
	if (studentas5.getVar() == "Jonas" &&
		studentas5.getPav() == "Jonaitis" &&
		studentas5.getPazymys() == pazymiai &&
		studentas4.getVar() != "Jonas" &&
		studentas4.getPav() != "Jonaitis" &&
		studentas4.getPazymys() != pazymiai) {
		cout << "[PASS] Move assignment operator test passed\n\n";
	}
	else {
		cout << "[FAIL] Move assignment operator test failed\n\n";
	}

	cout << "\n";

	// Ivesties operatorius testas
	cout << "Input operator testas:\n";
	Stud studentas6;
	cin >> studentas6;

	cout << "\n";

	// Isveties operatorius testas
	cout << "Ivestas studentas: \n" << studentas6;

	cout << "\n\n";
}