#include "meinelib.h"
#include "studentas.h"
#include "functionsCallsVector.h"

Vector<std::string> vyruVardai = { "Jonas", "Mantas", "Tomas", "Lukas", "Dovydas", "Andrius", "Gabrielius", "Erikas", "Vilius", "Domantas",
							   "Augustas", "Mindaugas", "Rokas", "Paulius", "Simas", "Arnas", "Edvinas", "Justas", "Kipras", "Martynas",
							   "Pijus", "Vytis", "Zygimantas", "Tautvydas", "Evaldas", "Eimantas", "Deividas", "Laurynas", "Karolis", "Gytis",
							   "Benas", "Titas", "Ignas", "Nojus", "Vytautas", "Aivaras", "Saulius", "Kristupas", "Orestas", "Armandas",
							   "Jokubas", "Dainius", "Sigitas", "Almantas", "Haroldas", "Julius", "Dziugas", "Gediminas", "Antanas", "Vytenis" };

Vector<std::string> vyruPavardes = { "Jonaitis", "Petraitis", "Kazlauskas", "Baltrunas", "Simkus", "Kairys", "Marcinkevicius", "Zabielskas", "Bagdonas", "Urbonas",
								"Kavaliauskas", "Puidokas", "Bielskis", "Matulevicius", "Sulskis", "Sakalauskas", "Butkus", "Karpavicius", "Zilinskas", "Stankevicius",
								"Vasiliauskas", "Simkevicius", "Daksevic", "Paskevicius", "Bagdonavicius", "Aleknavicius", "Kavolis", "Miezutavicius", "Giedraitis", "Pavardenis",
								"Sviderskis", "Malinauskas", "Gintalas", "Budreckas", "Tamasauskas", "Zimnickas", "Tamulevicius", "Skorupskas", "Gaigalas", "Sadauskas",
								"Janusonis", "Leskevicius", "Mikulenas", "Kairaitis", "Jarmalavicius", "Milkevicus", "Dumcius", "Tamulynas", "Poska", "Savickas" };

Vector<std::string> moteruVardai = { "Austeja", "Gabija", "Egle", "Ieva", "Lina", "Ruta", "Agne", "Laura", "Monika", "Jurgita",
								"Kamile", "Indre", "Viktorija", "Justina", "Karolina", "Evelina", "Ugne", "Neringa", "Dovile", "Raminta",
								"Erika", "Gintare", "Alina", "Simona", "Vaida", "Edita", "Julija", "Renata", "Sandra", "Svetlana",
								"Laima", "Zita", "Gitana", "Greta", "Sigita", "Brigita", "Aleksandra", "Emilija", "Asta", "Ingrida",
								"Joana", "Patricija", "Skaiste", "Vitalija", "Giedre", "Rasa", "Lilija", "Ona", "Aurelija", "Silvija" };

Vector<std::string> moteruPavardes = { "Jonate", "Petraite", "Kazlauskaite", "Baltrunaite", "Simkute", "Kairyte", "Marcinkeviciute", "Zabielskaite", "Bagdonaite", "Urbonaite",
								   "Kavaliauskaite", "Griniute", "Bielskiute", "Matuleviciute", "Sulskite", "Sakalauskaite", "Butkute", "Karpaviciute", "Zilinskaite", "Stankeviciute",
								   "Vasiliauskaite", "Simkeviciute", "Vainyte", "Paskeviciute", "Bagdonaviciute", "Aleknaviciute", "Kavoliute", "Miezutaviciute", "Giedraite", "Pavardenyte",
								   "Sviderskyte", "Malinauskaite", "Gintalaite", "Budreckaite", "Tamasauskaite", "Zimnickaite", "Tamuleviciute", "Skorupskaite", "Gaigalaite", "Sadauskaite",
								   "Janusonyte", "Leskeviciute", "Mikulenaite", "Kairaite", "Jarmalaviciute", "Milkeviciute", "Dumciute", "Tamulynaite", "Poskaite", "Savickaite" };

void randomStudentas(Stud& studentas, bool vyras) {																			// Sukuria atsitiktini studenta.
	if (vyras) {
		studentas.setVar (vyruVardai.At(rand() % vyruVardai.Size()));
		studentas.setPav (vyruPavardes.At(rand() % vyruPavardes.Size()));
	}
	else {
		studentas.setVar (moteruVardai.At(rand() % moteruVardai.Size()));
		studentas.setPav (moteruPavardes.At(rand() % moteruPavardes.Size()));
	}
}

void randomAtsitiktinisPazymys(Stud& stu) {																					// Sugeneruoja atsitiktini pazymi.
	int pazymiai = rand() % 15 + 1;
	stu.setEgz(rand() % 10 + 1);

	for (int i = 0; i < pazymiai; i++) {
		stu.addPazymys(rand() % 10 + 1);
	}
}