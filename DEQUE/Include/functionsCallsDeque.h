#ifndef FUNCTIONSCALLSDEQUE_H
#define FUNCTIONSCALLSDEQUE_H

// Laikomi funkciju prototipai.

//Prototipai
void readRanka(Stud& stu);
void readName_makeGrade(Stud& stu);
void makeStud(Stud& stu);
void fileRead(deque<Stud>& studentai);
void randomStudentas(Stud& studentas, bool vyras);
void randomAtsitiktinisPazymys(Stud& stu);
void failoKurimas();
void fileFilter();
float vidurkis(Stud& studentai);
float mediana(Stud& studentai);
void fileOutVid(deque<Stud>& studentai);
void fileOutMed(deque<Stud>& studentai);
void fileOutVid(deque<Stud>& studentai, string ivestas_vardas);
void fileOutMed(deque<Stud>& studentai, string ivestas_vardas);
float galutinisVid(Stud& stu);
float galutinisMed(Stud& stu);
bool compareByName(const Stud& a, const Stud& b);
bool compareBySurname(const Stud& a, const Stud& b);
bool compareByFinalGrade(const Stud& a, const Stud& b);
void testas();

#endif
