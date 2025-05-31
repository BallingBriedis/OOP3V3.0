#include "meinelib.h"
#include "studentas.h"
#include "functionsCallsVector.h"

void testMenu() {
	while (true) {
	std::cout << "Pasirinkite norima testavimo buda: \n";
	std::cout << "1 - Nuskaitymo testas\n";
	std::cout << "2 - Programos unit testas\n";
	std::cout << "3 - Studentu unit testas\n";
	std::cout << "4 - Baigti testavima\n";
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
	std::string ivestas_vardas;
	Vector<Stud> studentai;

	std::cout << "Kiek kartu norite nuskaitineti faila?\n";
	std::cin >> n;
	std::cout << "Koki faila norite nuskaityti? (Iveskite be kabuciu)\n";

	for (const auto& entry : fs::directory_iterator(".")) {
		if (entry.path().extension() == ".txt") {
			std::cout << entry.path().filename() << endl;
		}
	}
	std::cin >> ivestas_vardas;

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

		std::string line;
		getline(buffer, line);
		while (getline(buffer, line)) {
			Stud tempStu;
			std::istringstream iss(line);
			std::string vardas{}, pavarde{};
			iss >> vardas >> pavarde;
			tempStu.setVar(vardas);
			tempStu.setPav(pavarde);
			int pazymys{};

			while (iss >> pazymys) {
				tempStu.addPazymys(pazymys);
			}
			tempStu.setEgz(tempStu.getPazymys().Back());
			tempStu.removePazymys();
			studentai.PushBack(tempStu);
		}

		sec duration = hrClock::now() - start;
		std::cout << "Failas nuskaitytas per " << fixed << setprecision(8) << duration.count() << " sec\n";
		dursum += duration;
	}
	studentai.Clear();
	studentai.ShrinkToFit();
	std::cout << "Viso laiko: " << fixed << setprecision(8) << dursum.count() << " sec\n";
	std::cout << "Avg: " << fixed << setprecision(8) << dursum.count() / n << " sec\n\n";
}

void programUnitTest() {
	Vector<Stud> studentai;
	Stud studentas;

	// Test 1: Manual input
	readRanka(studentas);
	studentai.PushBack(studentas);

	if (studentai.Size() == 1)
		std::cout << "[PASS] Added one student\n\n";
	else
		std::cout << "[FAIL] studentai size: " << studentai.Size() << ", expected 1\n\n";

	if (studentai[0].getVar() == studentas.getVar())
		std::cout << "[PASS] Name matches\n\n";
	else
		std::cout << "[FAIL] Name mismatch\n\n";

	if (studentai[0].getPav() == studentas.getPav())
		std::cout << "[PASS] Surname matches\n\n";
	else
		std::cout << "[FAIL] Surname mismatch\n\n";

	// Test 2: Generate random grades
	readName_makeGrade(studentas);
	if (!studentas.getPazymys().Empty())
		std::cout << "[PASS] Random grades generated\n\n";
	else
		std::cout << "[FAIL] Random grades missing\n\n";

	// Test 3: Create a random student
	makeStud(studentas);
	if (!studentas.getPazymys().Empty())
		std::cout << "[PASS] Random student created\n\n";
	else
		std::cout << "[FAIL] Random student creation failed\n\n";

	// Test 4: File reading
	try {
		fileRead(studentai, "test.txt");
		if (!studentai.Empty())
			std::cout << "[PASS] File reading successful\n\n";
		else
			std::cout << "[FAIL] File read but no students loaded\n\n";
	}
	catch (const std::exception& e) {
		std::cout << "[FAIL] File reading exception: " << e.what() << '\n\n';
	}

	// Test 5: File creation
	failoKurimas(100);
	if (fs::exists("studList100.txt"))
		std::cout << "[PASS] File creation successful\n\n";
	else
		std::cout << "[FAIL] File not created\n\n";

	// Test 6: Output filtering
	isvestiesMenu(studentai);

	// Test 7: Sorting
	rusiavimas(studentai, 1);
	std::cout << "[INFO] Sorting completed\n\n";
}

void studentuUnitTest() {
	Vector<Stud> studentai;
	Vector<int> pazymiai = { 5, 6, 7 };


	/// Konstruktoriaus testas
	Stud studentas1("Jonas", "Jonaitis", pazymiai, 8);
	studentas1.calculateGalVidurkis();
	studentas1.calculateGalMediana();
	if (studentas1.getVar() == "Jonas" &&
		studentas1.getPav() == "Jonaitis" &&
		studentas1.getPazymys() == pazymiai) {
		std::cout << "[PASS] Constructor test passed\n\n";
	}
	else {
		std::cout << "[FAIL] Constructor test failed\n\n";
	}

	/// Tuscio konstruktoriaus testas
	Stud studentas7;
	if (studentas7.getVar().empty() &&
		studentas7.getPav().empty() &&
		studentas7.getPazymys().Empty()) {
		std::cout << "[PASS] Empty Constructor test passed\n\n";
	}
	else {
		std::cout << "[FAIL] Empty Constructor test failed\n\n";
	}

	// Copy constructor testas
	Stud studentas2(studentas1);
	if (studentas1.getVar() == studentas2.getVar() &&
		studentas1.getPav() == studentas2.getPav() &&
		studentas1.getPazymys() == studentas2.getPazymys() &&
		studentas1.getVidurkis() == studentas2.getVidurkis() &&
		studentas1.getMediana() == studentas2.getMediana()) {
		std::cout << "[PASS] Copy constructor test passed\n\n";
	}
	else {
		std::cout << "[FAIL] Copy constructor test failed\n\n";
	}

	// Copy assignment operator testas
	Stud studentas3;
	studentas3 = studentas1;
	if (studentas3.getVar() == studentas1.getVar() &&
		studentas3.getPav() == studentas1.getPav() &&
		studentas3.getPazymys() == studentas1.getPazymys() &&
		studentas3.getVidurkis() == studentas1.getVidurkis() &&
		studentas3.getMediana() == studentas1.getMediana()) {
		std::cout << "[PASS] Copy assignment operator test passed\n\n";
	}
	else {
		std::cout << "[FAIL] Copy assignment operator test failed\n\n";
	}

	// Move constructor testas
	Stud studentas4(std::move(studentas1));
	if (studentas4.getVar() != studentas1.getVar() &&
		studentas4.getPav() != studentas1.getPav() &&
		studentas4.getPazymys() != studentas1.getPazymys()) {
		std::cout << "[PASS] Move constructor test passed\n\n";
	}
	else {
		std::cout << "[FAIL] Move constructor test failed\n\n";
	}

	// Move assignment operator testas
	Stud studentas5;
	studentas5 = std::move(studentas4);
	if (studentas5.getVar() != studentas4.getVar() &&
		studentas5.getPav() != studentas4.getPav() &&
		studentas5.getPazymys() != studentas4.getPazymys()) {
		std::cout << "[PASS] Move assignment operator test passed\n\n";
	}
	else {
		std::cout << "[FAIL] Move assignment operator test failed\n\n";
	}

	std::cout << "\n";

	// Ivesties operatorius testas
	std::cout << "Input operator testas:\n";
	Stud studentas6;
	std::cin >> studentas6;

	std::cout << "\n";

	// Isveties operatorius testas
	std::cout << "Ivestas studentas: \n" << studentas6;

	std::cout << "\n\n";
}