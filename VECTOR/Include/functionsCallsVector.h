#ifndef FUNCTIONSCALLSV_H
#define FUNCTIONSCALLSV_H

// Laikomi funkciju prototipai.

// Prototipai

// ivestis.cpp
void readRanka(Stud& stu);
void readName_makeGrade(Stud& stu);
void makeStud(Stud& stu);
void fileRead(vector<Stud>& studentai, string vardas);

// isvestis.cpp
void isvestiesMenu(vector<Stud>& studentai);
void isvestis(vector<Stud>& studentai, std::ostream& isvestiesMetodas, const int galutinioPasirinkimas);

// studentuRusiavimas.cpp
void rusiavimas(vector<Stud>& studentai, int rusiavimoPasirinkimas);

// generators.cpp
void randomStudentas(Stud& studentas, bool vyras);
void randomAtsitiktinisPazymys(Stud& stu);

// fileGenerator.cpp
void failoKurimas(int studentuSk);

// studentuSkirstymas.cpp
void fileFilter(vector<Stud>& studentai, const int galutinioPasirinkimas, const int rusiavimoPasirinkimas);

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
void studentuGalutiniuSkaiciavimas(vector<Stud>& studentai);


#endif
