#include "meinelib.h"
#include "studentas.h"
#include "functionsCallsVector.h"

void fileFilter(Vector<Stud>& studentai, const int galutinioPasirinkimas, const int rusiavimoPasirinkimas) {
	Vector<Stud> mokslinciai{};
	Vector<Stud> vargsai{};
	studentuGalutiniuSkaiciavimas(studentai);

	if (rusiavimoPasirinkimas == 1 || rusiavimoPasirinkimas == 2) {
		rusiavimas(studentai, 3);
	}
	else {
		rusiavimas(studentai, rusiavimoPasirinkimas);
	}

	if (rusiavimoPasirinkimas == 3) {
		auto partition_iteratorius = std::partition_point(studentai.begin(), studentai.end(),
			[](const Stud& studentas) {return studentas.getVidurkis() < 5.0f;}
		);
		vargsai.Assign(studentai.begin(), partition_iteratorius);
		mokslinciai.Assign(partition_iteratorius, studentai.end());
	}
	else if (rusiavimoPasirinkimas == 4) {
		auto partition_iteratorius = std::partition_point(studentai.begin(), studentai.end(),
			[](const Stud& studentas) {return studentas.getMediana() < 5.0f;}
		);
		vargsai.Assign(studentai.begin(), partition_iteratorius);
		mokslinciai.Assign(partition_iteratorius, studentai.end());
	}

	try {
		std::ofstream mokslinciai_output("mokslinciai.txt");
		isvestis(mokslinciai, mokslinciai_output, galutinioPasirinkimas);
		mokslinciai_output.close();

		std::ofstream vargsai_output("vargsai.txt");
		isvestis(vargsai, vargsai_output, galutinioPasirinkimas);
		vargsai_output.close();
	}
	catch (std::exception& e) {
		std::cerr << "Ivyko klaida isvedant i failus failus: " << e.what() << "\n";
	}
}