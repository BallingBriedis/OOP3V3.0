#ifndef MEINELIB_H
#define MEINELIB_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;

//Globalus kintamieji

vector<string> vyruVardai = { "Jonas", "Mantas", "Tomas", "Lukas", "Dovydas", "Andrius", "Gabrielius", "Erikas", "Vilius", "Domantas",
							   "Augustas", "Mindaugas", "Rokas", "Paulius", "Simas", "Arnas", "Edvinas", "Justas", "Kipras", "Martynas",
							   "Pijus", "Vytis", "Zygimantas", "Tautvydas", "Evaldas", "Eimantas", "Deividas", "Laurynas", "Karolis", "Gytis",
							   "Benas", "Titas", "Ignas", "Nojus", "Vytautas", "Aivaras", "Saulius", "Kristupas", "Orestas", "Armandas",
							   "Jokubas", "Dainius", "Sigitas", "Almantas", "Haroldas", "Julius", "Dziugas", "Gediminas", "Antanas", "Vytenis" };

vector<string> vyruPavardes = { "Jonaitis", "Petraitis", "Kazlauskas", "Baltrunas", "Simkus", "Daksevic", "Marcinkevicius", "Zabielskas", "Bagdonas", "Urbonas",
								"Kavaliauskas", "Puidokas", "Bielskis", "Matulevicius", "Sulskis", "Sakalauskas", "Butkus", "Karpavicius", "Zilinskas", "Stankevicius",
								"Vasiliauskas", "Simkevicius", "Vainius", "Paskevicius", "Bagdonavicius", "Aleknavicius", "Kavolis", "Miezutavicius", "Giedraitis", "Pavardenis",
								"Sviderskis", "Malinauskas", "Gintalas", "Budreckas", "Tamasauskas", "Zimnickas", "Tamulevicius", "Skorupskas", "Gaigalas", "Sadauskas",
								"Janusonis", "Leskevicius", "Mikulenas", "Kairaitis", "Jarmalavicius", "Milkevicus", "Dumcius", "Tamulynas", "Poska", "Savickas" };

vector<string> moteruVardai = { "Austeja", "Gabija", "Egle", "Ieva", "Lina", "Ruta", "Agne", "Laura", "Monika", "Jurgita",
								"Kamile", "Indre", "Viktorija", "Justina", "Karolina", "Evelina", "Ugne", "Neringa", "Dovile", "Raminta",
								"Erika", "Gintare", "Alina", "Simona", "Vaida", "Edita", "Julija", "Renata", "Sandra", "Svetlana",
								"Laima", "Zita", "Gitana", "Greta", "Sigita", "Brigita", "Aleksandra", "Emilija", "Asta", "Ingrida",
								"Joana", "Patricija", "Skaiste", "Vitalija", "Giedre", "Rasa", "Lilija", "Ona", "Aurelija", "Silvija" };

vector<string> moteruPavardes = { "Jonate", "Petraite", "Kazlauskaite", "Baltrunaite", "Simkute", "Kairyte", "Marcinkeviciute", "Zabielskaite", "Bagdonaite", "Urbonaite",
								   "Kavaliauskaite", "Griniute", "Bielskiute", "Matuleviciute", "Sulskite", "Sakalauskaite", "Butkute", "Karpaviciute", "Zilinskaite", "Stankeviciute",
								   "Vasiliauskaite", "Simkeviciute", "Vainyte", "Paskeviciute", "Bagdonavičiute", "Aleknavičiute", "Kavoliute", "Miezutavičiute", "Giedraite", "Pavardenyte",
								   "Sviderskyte", "Malinauskaite", "Gintalaite", "Budreckaite", "Tamasauskaite", "Zimnickaite", "Tamuleviciute", "Skorupskaite", "Gaigalaite", "Sadauskaite",
								   "Janusonyte", "Leskevičiute", "Mikulenaite", "Kairaite", "Jarmalavičiute", "Milkevičiute", "Dumciute", "Tamulynaite", "Poskaite", "Savickaite" };

//Prototipai

int isNumber();
bool isValidInput(int input);


struct Stud {
	string var;
	string pav;
	vector<int>uzd{};
	int egz = 0;

	int* mUzd = nullptr;
	int uzdSize = 0;
	int uzd_capacity = 1;

	void addGrades(int grade) {
		if (mUzd == nullptr) {
			mUzd = new int[uzd_capacity];
		}
		if (uzdSize == uzd_capacity) {
			int newCapacity = uzd_capacity + 1;
			int* newMuzd = new int[newCapacity];

			std::copy(mUzd, mUzd + uzdSize, newMuzd);

			delete[] mUzd;

			mUzd = newMuzd;
			uzd_capacity = newCapacity;
		}
		mUzd[uzdSize] = grade;
		uzdSize++;
	}
};


inline int isNumber() {
	int input;
	while (true) {
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Neteisinga ivestis. Iveskite sveika skaiciu: ";
		}
		else {
			return input;
		}
	}
}

inline bool isValidInput(int input) {
	if (input == -1) {
		return true;
	}
	if (input < 0 || input > 10) {
		return false;
	}
	return true;
}
inline bool menuValidInput(int input) {
	if (input < 1 || input > 4) {
		return false;
	}
	return true;
}
#endif