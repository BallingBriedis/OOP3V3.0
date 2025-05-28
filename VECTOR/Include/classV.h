#ifndef STRUCTV_H
#define STRUCTV_H

// Struktura, kurioje laikomi studento duomenys.

#include <string>
#include <vector>
#include "meinelib.h"

class Stud {
private:
	std::string var_{}, pav_{};
	std::vector<int>pazymys_{};
	int egz_{};
	float galVidurkis_{};
	float galMediana_{};

public:
	/// <summary>
	/// Konstruktorius ir desktrutorius
	/// </summary>
	Stud(string var, string pav, vector<int> pazymys, int egz) : var_(std::move(var)), pav_(std::move(pav)), pazymys_(std::move(pazymys)), egz_(std::move(egz)) {}
	Stud() = default;
	~Stud() {
		pazymys_.clear();
	}


	/// <summary>
	/// Setteriai, kurie nustato studento varda, pavarde, uzduotis ir egzamino pazymi.
	/// </summary>
	/// <param name="v"></param>
	void setVar(const std::string& var) {var_ = var;}
	void setPav(const std::string& pav) {pav_ = pav;}
	void setEgz(const int egz) { egz_ = egz; }

	/// <summary>
	/// Papildomos funkcijos, kurios prideda ir pasalina uzduociu pazymius
	/// </summary>
	/// <param name="uzd"></param>
	void addUzd(const int pazymys) {pazymys_.push_back(pazymys);}
	void removeUzd() {pazymys_.pop_back();}

	void calculateGalVidurkis();
	void calculateGalMediana();
	/// <summary>
	/// Getteriai, kurie grazina studento varda, pavarde, uzduotis, egzamino pazymi ir galutini pazymi.
	/// </summary>
	/// <returns></returns>
	std::string getVar() const { return var_; }
	std::string getPav() const { return pav_; }
	std::vector<int> getPazymys() const { return pazymys_; }
	int getEgz() const {return egz_;}
	int getVidurkis() const {return galVidurkis_;}
	int getMediana() const {return galMediana_;}
	
};
#endif