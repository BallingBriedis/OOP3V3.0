#include "meinelib.h"
#include "studentas.h"
#include "functionsCallsVector.h"

void isvestiesMenu(Vector<Stud>& studentai) {
	std::cout << "Pasirinkite norima studentu isvedimo buda: \n";
	std::cout << "1 - Isvesti i terminala\n";
	std::cout << "2 - Isvesti i faila\n";
	std::cout << "3 - Isvesti i du failus, suskirsto\n";
	int isvestiesPasirinkimas = ivestiesPatikrinimas(1, 3);

	std::cout << "Pasirinkite koki galutini norite matyti: \n";
	std::cout << "1 - Vidurki \n";
	std::cout << "2 - Mediana \n";
	std::cout << "3 - Abu \n";
	int galutinioPasirinkimas = ivestiesPatikrinimas(1, 3);

	std::cout << "Pasirinkite studentu rusiavima:\n";
	std::cout << "1 - Pagal varda\n";
	std::cout << "2 - Pagal pavarde\n";
	std::cout << "3 - Pagal galutini pazymi pagal vidurki \n";
	std::cout << "4 - Pagal galutini pazymi pagal mediana \n";
	int rusiavimoPasirinkimas = ivestiesPatikrinimas(1, 4);


	if (isvestiesPasirinkimas == 1) {
		studentuGalutiniuSkaiciavimas(studentai);
		rusiavimas(studentai, rusiavimoPasirinkimas);
		isvestis(studentai, std::cout, galutinioPasirinkimas);
	}

	else if (isvestiesPasirinkimas == 2){
		std::ofstream output("rezultatai.txt");
		studentuGalutiniuSkaiciavimas(studentai);
		rusiavimas(studentai, rusiavimoPasirinkimas);
		isvestis(studentai, output, galutinioPasirinkimas);
	}
	else if (isvestiesPasirinkimas == 3) {
		fileFilter(studentai, galutinioPasirinkimas, rusiavimoPasirinkimas);
	}
}

void isvestis(Vector<Stud>& studentai, std::ostream& isvestiesMetodas, const int galutinioPasirinkimas) {
	int longest_name{};
	int longest_surname{};
	for (auto& studentas : studentai) {
		if (studentas.getVar().length() > longest_name) {
			longest_name = static_cast<int>(studentas.getVar().length());
		}
		if (studentas.getPav().length() > longest_surname) {
			longest_surname = static_cast<int>(studentas.getPav().length());
		}
	}
	int isvesties_pavardes_ilgis{ ((longest_surname > 7 ? longest_surname + 2 : 8)) };
	int isvesties_vardo_ilgis{ ((longest_name > 6 ? longest_name + 2 : 8)) };

	std::stringstream isvestis{};

	isvestis << std::left << std::setw(isvesties_vardo_ilgis) << "Vardas" << std::setw(isvesties_pavardes_ilgis) << "Pavarde";

	if (galutinioPasirinkimas == 1 || galutinioPasirinkimas == 3) {
		isvestis << std::setw(17) << "Galutinis (Vid.)";
	}
	if (galutinioPasirinkimas == 2 || galutinioPasirinkimas == 3) {
		isvestis << std::setw(17) << "Galutinis (Med.)";
	}

	isvestis << "\n";

	if (galutinioPasirinkimas == 1) {
		for (auto& i : studentai) {
			isvestis << std::setw(isvesties_pavardes_ilgis) << i.getVar()
				<< std::setw(isvesties_vardo_ilgis) << i.getPav()
				<< std::setw(20) << std::left << i.getVidurkis() << "\n";
		}
	}
	else if (galutinioPasirinkimas == 2) {
		for (auto& i : studentai) {
			isvestis << std::setw(isvesties_pavardes_ilgis) << i.getVar()
				<< std::setw(isvesties_vardo_ilgis) << i.getPav()
				<< std::setw(20) << std::left << i.getMediana() << "\n";
		}
	}
	else if (galutinioPasirinkimas == 3) {
		for (auto& i : studentai) {
			isvestis << std::setw(isvesties_pavardes_ilgis) << i.getVar()
				<< std::setw(isvesties_vardo_ilgis) << i.getPav()
				<< std::setw(20) << std::left << i.getVidurkis() << "   "
				<< std::setw(20) << std::left << i.getMediana() << "\n";
		}
	}

	isvestiesMetodas << isvestis.str();
}