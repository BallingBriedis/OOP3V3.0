#ifndef FUNCTIONSCALLSV_H
#define FUNCTIONSCALLSV_H

#include "studentas.h"
#include "zmogus.h"
#include "meinelib.h"

// Laikomi funkciju prototipai.

// Prototipai

// ivestis.cpp
void readRanka(Stud& stu);
void readName_makeGrade(Stud& stu);
void makeStud(Stud& stu);
void fileRead(Vector<Stud>& studentai, std::string vardas);

// isvestis.cpp
void isvestiesMenu(Vector<Stud>& studentai);
void isvestis(Vector<Stud>& studentai, std::ostream& isvestiesMetodas, const int galutinioPasirinkimas);

// studentuRusiavimas.cpp
void rusiavimas(Vector<Stud>& studentai, int rusiavimoPasirinkimas);

// generators.cpp
void randomStudentas(Stud& studentas, bool vyras);
void randomAtsitiktinisPazymys(Stud& stu);

// fileGenerator.cpp
void failoKurimas(int studentuSk);

// studentuSkirstymas.cpp
void fileFilter(Vector<Stud>& studentai, const int galutinioPasirinkimas, const int rusiavimoPasirinkimas);

// test.cpp
void testMenu();
void nuskaitymoTestas();
void studentuUnitTest();
void programUnitTest();

// ivestisPatikrinimas.cpp
int ivestiesPatikrinimas(const int nuo, const int iki);
int ivestiesPatikrinimas(const int nuo, const int iki, const int sustabdymoSalyga);

// Stud.cpp
// Stud klases Medianos ir Vidurkio funkciju deklaracijos pacioje klaseje
void studentuGalutiniuSkaiciavimas(Vector<Stud>& studentai);


#endif
