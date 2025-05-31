#include "meinelib.h"
#include "studentas.h"
#include "functionsCallsVector.h"

void readRanka(Stud& stu) {																									// Vartotojo praso ivesti studento varda, pavarde, pazymius.
	int input, i = 1;
	string a;
	cout << "Iveskite studento varda: ";
	cin >> a;
	stu.setVar(a);
	cout << "Iveskite studento pavarde: ";
	cin >> a;
	stu.setPav(a);

	cout << "Iveskite studento egzamino pazymi: ";
	input = ivestiesPatikrinimas(0, 10);
	stu.setEgz(input);
	cout << "\n\n" << "Iveskite studento namu darbu pazymius. Ivedus visus pazymius, iveskite -1.\n";
	cout << "Jeigu darbas neatliktas iveskite 0.\n\n";

	while (true) {
		cout << i << "-asis pazymys: ";
		input = ivestiesPatikrinimas(0, 10, -1);
		if (input == -1) {
			break;
		}
		stu.addPazymys(input);
		i++;
	}
}

void readName_makeGrade(Stud& stu) {
	string a;
	cout << "Iveskite studento varda: ";
	cin >> a;
	stu.setVar(a);
	cout << "Iveskite studento pavarde: ";
	cin >> a;
	stu.setPav(a);
	randomAtsitiktinisPazymys(stu);
}

void makeStud(Stud& stu) {																									// Sukuria atsitiktini studenta.
	randomStudentas(stu, rand() % 2);
	randomAtsitiktinisPazymys(stu);
}

void fileRead(Vector<Stud>& studentai, string ivestas_vardas) {
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
		tempStu.setEgz(tempStu.getPazymys().Back());
		tempStu.removePazymys();
		studentai.PushBack(tempStu);
	}
}
