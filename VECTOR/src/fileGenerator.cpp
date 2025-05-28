#include "meinelib.h"
#include "classV.h"
#include "functionsCallsVector.h"

void failoKurimas() {
	int studentuSk;
	string failoVardas = "studList";
	studentuSk = ivestiesPatikrinimas(1, 10000000);

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