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
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;
using hrClock = std::chrono::high_resolution_clock;
using ms = std::chrono::milliseconds;

vector<string> vyruVardai = { "Jonas", "Mantas", "Tomas", "Lukas", "Dovydas", "Andrius", "Gabrielius", "Erikas", "Vilius", "Domantas",
							   "Augustas", "Mindaugas", "Rokas", "Paulius", "Simas", "Arnas", "Edvinas", "Justas", "Kipras", "Martynas",
							   "Pijus", "Vytis", "Zygimantas", "Tautvydas", "Evaldas", "Eimantas", "Deividas", "Laurynas", "Karolis", "Gytis",
							   "Benas", "Titas", "Ignas", "Nojus", "Vytautas", "Aivaras", "Saulius", "Kristupas", "Orestas", "Armandas",
							   "Jokubas", "Dainius", "Sigitas", "Almantas", "Haroldas", "Julius", "Dziugas", "Gediminas", "Antanas", "Vytenis" };

vector<string> vyruPavardes = { "Jonaitis", "Petraitis", "Kazlauskas", "Baltrunas", "Simkus", "Kairys", "Marcinkevicius", "Zabielskas", "Bagdonas", "Urbonas",
								"Kavaliauskas", "Puidokas", "Bielskis", "Matulevicius", "Sulskis", "Sakalauskas", "Butkus", "Karpavicius", "Zilinskas", "Stankevicius",
								"Vasiliauskas", "Simkevicius", "Daksevic", "Paskevicius", "Bagdonavicius", "Aleknavicius", "Kavolis", "Miezutavicius", "Giedraitis", "Pavardenis",
								"Sviderskis", "Malinauskas", "Gintalas", "Budreckas", "Tamasauskas", "Zimnickas", "Tamulevicius", "Skorupskas", "Gaigalas", "Sadauskas",
								"Janusonis", "Leskevicius", "Mikulenas", "Kairaitis", "Jarmalavicius", "Milkevicus", "Dumcius", "Tamulynas", "Poska", "Savickas" };

vector<string> moteruVardai = { "Austeja", "Gabija", "Egle", "Ieva", "Lina", "Ruta", "Agne", "Laura", "Monika", "Jurgita",
								"Kamile", "Indre", "Viktorija", "Justina", "Karolina", "Evelina", "Ugne", "Neringa", "Dovile", "Raminta",
								"Erika", "Gintare", "Alina", "Simona", "Vaida", "Edita", "Julija", "Renata", "Sandra", "Svetlana",
								"Laima", "Zita", "Gitana", "Greta", "Sigita", "Brigita", "Aleksandra", "Emilija", "Asta", "Ingrida",
								"Joana", "Patricija", "Skaiste", "Vitalija", "Giedre", "Rasa", "Lilija", "Ona", "Aurelija", "Silvija" };

vector<string> moteruPavardes = { "Jonate", "Petraite", "Kazlauskaite", "Baltrunaite", "Simkute", "Kairyte", "Marcinkeviciute", "Zabielskaite", "Bagdonaite", "Urbonaite",
								   "Kavaliauskaite", "Griniute", "Bielskiute", "Matuleviciute", "Sulskite", "Sakalauskaite", "Butkute", "Karpaviciute", "Zilinskaite", "Stankeviciute",
								   "Vasiliauskaite", "Simkeviciute", "Vainyte", "Paskeviciute", "Bagdonaviciute", "Aleknaviciute", "Kavoliute", "Miezutaviciute", "Giedraite", "Pavardenyte",
								   "Sviderskyte", "Malinauskaite", "Gintalaite", "Budreckaite", "Tamasauskaite", "Zimnickaite", "Tamuleviciute", "Skorupskaite", "Gaigalaite", "Sadauskaite",
								   "Janusonyte", "Leskeviciute", "Mikulenaite", "Kairaite", "Jarmalaviciute", "Milkeviciute", "Dumciute", "Tamulynaite", "Poskaite", "Savickaite" };

#endif