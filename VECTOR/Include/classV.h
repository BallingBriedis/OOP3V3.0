#ifndef STRUCTV_H
#define STRUCTV_H

// Struktura, kurioje laikomi studento duomenys.

#include <string>
#include <vector>

class Stud {
private:
	std::string var;
	std::string pav;
	std::vector<int>uzd{};
	int egz;
	int gal;

public:
	Stud() : egz(0), gal(0) {}

	void setVar(const std::string& v) {var = v;}
	void setPav(const std::string& p) {pav = p;}
	void addUzd(int grade) {uzd.push_back(grade);}
	void setEgz(int e) {egz = e;}
	void setGal(int g) {gal = g;}
	void print() const;

	std::string getVar() const { return var; }
	std::string getPav() const { return pav; }
	std::vector<int> getUzd() const { return uzd; }
	int getEgz() const {return egz;}
	int getGal() const {return gal;}

	~Stud() {
		std::cout << "Destruktorius\n";
	}
};
#endif