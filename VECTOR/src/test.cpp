#include "meinelib.h"
#include "classV.h"
#include "functionsCallsVector.h"

void testas() {
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