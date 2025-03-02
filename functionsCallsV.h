#ifndef FUNCTIONSCALLSV_H
#define FUNCTIONSCALLSV_H

// Laikomi funkciju prototipai.

//Prototipai
void readRanka(Stud& stu);
void readName_makeGrade(Stud& stu);
void makeStud(Stud& stu);
void fileRead(vector<Stud>& studentai, string ivestas_vardas);
void randomStudentas(Stud& studentas, bool vyras);
void randomAtsitiktinisPazymys(Stud& stu);
float vidurkis(Stud& studentai);
float mediana(Stud& studentai);
float galutinisVid(Stud& stu);
float galutinisMed(Stud& stu);
void fileOutVid(vector<Stud>& studentai);
void fileOutMed(vector<Stud>& studentai);
bool compareByName(const Stud& a, const Stud& b);
bool compareBySurname(const Stud& a, const Stud& b);
bool compareByFinalGrade(const Stud& a, const Stud& b);
void testas(string ivestas_vardas);

#endif
