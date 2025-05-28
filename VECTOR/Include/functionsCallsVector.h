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

// rusiavimas.cpp
void rusiavimas(vector<Stud>& studentai, int rusiavimoPasirinkimas);

// generators.cpp
void randomStudentas(Stud& studentas, bool vyras);
void randomAtsitiktinisPazymys(Stud& stu);


int ivestiesPatikrinimas(const int nuo, const int iki);
int ivestiesPatikrinimas(const int nuo, const int iki, const int sustabdymoSalyga);
void studentuGalutiniuSkaiciavimas(vector<Stud>& studentai);
#endif
