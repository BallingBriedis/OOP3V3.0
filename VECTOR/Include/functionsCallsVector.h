#ifndef FUNCTIONSCALLSV_H
#define FUNCTIONSCALLSV_H

// Laikomi funkciju prototipai.

//Prototipai
void readRanka(Stud& stu);
void readName_makeGrade(Stud& stu);
void makeStud(Stud& stu);
void fileRead(vector<Stud>& studentai);
void randomStudentas(Stud& studentas, bool vyras);
void randomAtsitiktinisPazymys(Stud& stu);
void failoKurimas();
void fileFilter();
float vidurkis(Stud& studentai);
float mediana(Stud& studentai);
void fileOutVid(vector<Stud>& studentai, string ivestas_vardas);
void fileOutMed(vector<Stud>& studentai, string ivestas_vardas);
float galutinisVid(Stud& stu);
float galutinisMed(Stud& stu);
void fileOutVid(vector<Stud>& studentai);
void fileOutMed(vector<Stud>& studentai);
bool compareByName(const Stud&, const Stud&);
bool compareBySurname(const Stud&, const Stud&);
bool compareByFinalGrade(const Stud&, const Stud&);
void testas();

#endif
