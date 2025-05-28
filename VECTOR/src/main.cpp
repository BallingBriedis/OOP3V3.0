#include "meinelib.h"
#include "classV.h"
#include "functionsCallsVector.h"

int main() {
	cin.exceptions(std::ios::failbit);
	srand(time(NULL));
	vector<Stud> studentai;
	int pasirinkimasV = 0;
	int n = 0;
	while (true) {
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
		int menuPasirinkimas = ivestiesPatikrinimas(1, 8, 8);

		if (menuPasirinkimas == 8) { break;}

		switch (menuPasirinkimas) {
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
				cout << "Iveskite norimo failo pavadinima be kabuciu:\n";
				for (const auto& entry : fs::directory_iterator(".")) {
					if (entry.path().extension() == ".txt") {
						cout << entry.path().filename() << endl;
					}
				}
				string ivestas_vardas;
				cin >> ivestas_vardas;
				fileRead(studentai, ivestas_vardas);
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
	isvestiesMenu(studentai);
}