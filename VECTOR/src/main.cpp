#include "meinelib.h"
#include "studentas.h"
#include "functionsCallsVector.h"

int main() {
	std::cin.exceptions(std::ios::failbit);
	srand(time(NULL));
	Vector<Stud> studentai;
	int n = 0,baigimas = 7;
	while (true) {
		Stud studentas;
		std::cout << "Pasirinkite norima studento duomenu surasyma irasant skaiciu nuo 1 iki "<< baigimas <<".\n";
		std::cout << "------------------------------------------------------------------------\n";
		std::cout << "1 - Ivestis ranka\n";
		std::cout << "2 - Ivestis ranka (Generuojami tik pazymiai)\n";
		std::cout << "3 - Generuojamas studentas ir pazymiai\n";
		std::cout << "4 - Failo nuskaitymas\n";
		std::cout << "5 - Failo kurimas\n";
		std::cout << "6 - Testine aplinka\n";
		std::cout << baigimas << " - Baigti darba\n";
		std::cout << "------------------------------------------------------------------------\n";
		int menuPasirinkimas = ivestiesPatikrinimas(1, baigimas, baigimas);

		if (menuPasirinkimas == baigimas) { break;}

		switch (menuPasirinkimas) {
		case 1:
			readRanka(studentas);
			studentai.PushBack(studentas);
			break;
		case 2:
			readName_makeGrade(studentas);
			studentai.PushBack(studentas);
			break;
		case 3:
			std::cout << "Kiek studentu sugeneruoti?\n";
			std::cin >> n;
			for (int i = 0; i < n; i++) {
				makeStud(studentas);
				studentai.PushBack(studentas);
			}
			break;
		case 4:
			try {
				std::cout << "Iveskite norimo failo pavadinima be kabuciu:\n";
				for (const auto& entry : fs::directory_iterator(".")) {
					if (entry.path().extension() == ".txt") {
						std::cout << entry.path().filename() << endl;
					}
				}
				std::string ivestas_vardas;
				std::cin >> ivestas_vardas;
				fileRead(studentai, ivestas_vardas);
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
				continue;
			}
			break;
		case 5:
			failoKurimas(0);
			break;
		case 6:
			try {
				testMenu();
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
				break;
			}
			break;
		}
	}
	isvestiesMenu(studentai);
}