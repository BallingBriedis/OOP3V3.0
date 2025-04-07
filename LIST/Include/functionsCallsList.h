#ifndef FUNCTIONSCALLSLIST_H
#define FUNCTIONSCALLSList_H

// Laikomi funkciju prototipai.

//Prototipai
void readRanka(Stud& stu);
void readName_makeGrade(Stud& stu);
void makeStud(Stud& stu);
void fileRead(list<Stud>& studentai);
void randomStudentas(Stud& studentas, bool vyras);
void randomAtsitiktinisPazymys(Stud& stu);
void failoKurimas();
void fileFilter();
float vidurkis(Stud& studentai);
float mediana(Stud& studentai);
void fileOutVid(list<Stud>& studentai, string ivestas_vardas);
void fileOutMed(list<Stud>& studentai, string ivestas_vardas);
float galutinisVid(Stud& stu);
float galutinisMed(Stud& stu);
void fileOutVid(list<Stud>& studentai);
void fileOutMed(list<Stud>& studentai);
bool compareByName(const Stud& a, const Stud& b);
bool compareBySurname(const Stud& a, const Stud& b);
bool compareByFinalGrade(const Stud& a, const Stud& b);
void testas();

#endif
