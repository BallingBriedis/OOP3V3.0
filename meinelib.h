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

vector<string> vyruPavardes = { "Jonaitis", "Petraitis", "Kazlauskas", "Baltrunas", "Simkus", "Kairys", "Marcinkevicius", "Zabielskas", "Bagdonas", "Urbonas",
								"Kavaliauskas", "Grinius", "Bielskis", "Matulevicius", "Sulskis", "Sakalauskas", "Butkus", "Karpavicius", "Zilinskas", "Stankevicius",
								"Vasiliauskas", "Simkevicius", "Vainius", "Paskevicius", "Bagdonavicius", "Aleknavicius", "Kavolis", "Miezutavicius", "Giedraitis", "Pavardenis",
								"Sviderskis", "Malinauskas", "Gintalas", "Budreckas", "Tamasauskas", "Zimnickas", "Tamulevicius", "Skorupskas", "Gaigalas", "Sadauskas",
								"Janusonis", "Leskevicius", "Mikulenas", "Kairaitis", "Jarmalavicius", "Milkevicus", "Dumcius", "Tamulynas", "Poska", "Savickas" };

vector<string> moteruVardai = { "Austeja", "Gabija", "Egle", "Ieva", "Lina", "Ruta", "Agne", "Laura", "Monika", "Jurgita",
								"Kamile", "Indre", "Viktorija", "Justina", "Karolina", "Evelina", "Ugne", "Neringa", "Dovile", "Raminta",
								"Erika", "Gintare", "Alina", "Simona", "Vaida", "Edita", "Julija", "Renata", "Sandra", "Svetlana",
								"Laima", "Zita", "Gitana", "Greta", "Sigita", "Brigita", "Aleksandra", "Emilija", "Asta", "Ingrida",
								"Joana", "Patricija", "Skaiste", "Vitalija", "Giedre", "Rasa", "Lilija", "Ona", "Aurelija", "Silvija" };

vector<string> moteruPavardes = { "Jonate", "Petraite", "KazlauskAite", "Baltrunaite", "Simkute", "Kairyte", "Marcinkeviciute", "Zabielskaite", "Bagdonaite", "UrbonAite",
								   "KavaliauskAite", "Griniute", "Bielskiute", "Matuleviciute", "Sulskite", "SakalauskAite", "Butkute", "Karpaviciute", "Zilinskaite", "Stankeviciute",
								   "VasiliauskAite", "Simkevičiute", "Vainyte", "Paskeviciute", "Bagdonavičiute", "Aleknavičiute", "Kavoliute", "Miezutavičiute", "Giedraite", "Pavardenyte",
								   "SviderskytE", "MalinauskAite", "GintalAite", "BudreckAite", "TamasAuskAite", "ZimnickAite", "Tamuleviciute", "SkorupskAite", "GaigalAite", "SadauskAite",
								   "Janusonyte", "Leskevičiute", "MikulenAite", "KairAite", "Jarmalavičiute", "Milkevičiute", "DumčiutE", "TamulynAite", "PoškAite", "SavickAite" };



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
		cout <<"\n"<< grade << "\n";
		cout <<"\n"<< "Veikia" << "\n";
        mUzd[uzdSize] = grade;
		cout << "\n" << "Veikia po muzd idejimo" << "\n";
		uzdSize++;
		for(int i=0;i<uzdSize;i++)
		cout << "\nTestas meinelib.h " << mUzd[i] << " Testas meinelib.h\n";
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