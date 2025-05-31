#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"
#include "Vector.h"
// Struktura, kurioje laikomi studento duomenys.

class Stud : public Zmogus {
private:
	Vector<int>pazymys_{};
	int egz_{};
	float galVidurkis_{};
	float galMediana_{};

public:
	/// Konstruktorius ir desktrutorius
	explicit Stud(std::string var = "", std::string pav = "", Vector<int> pazymys = {}, int egz = {}) :
		Zmogus(std::move(var), std::move(pav)), pazymys_(std::move(pazymys)), egz_(egz) {}

	~Stud() = default;

	/// Copy constructor
	Stud(const Stud& other) :
		Zmogus(other.var_, other.pav_),
		pazymys_(other.pazymys_), 
		egz_(other.egz_),
		galVidurkis_(other.galVidurkis_),
		galMediana_(other.galMediana_) {}

	/// Copy assignment operator
	Stud& operator=(const Stud& other) {
		if (this != &other) {
			Zmogus::operator=(other);
			pazymys_ = other.pazymys_;
			egz_ = other.egz_;
			galVidurkis_ = other.galVidurkis_;
			galMediana_ = other.galMediana_;
		}
		return *this;
	}

	/// Move constructor
	Stud(Stud&& other) noexcept :
		Zmogus(std::move(other)),
		pazymys_(std::move(other.pazymys_)),
		egz_(other.egz_),
		galVidurkis_(other.galVidurkis_),
		galMediana_(other.galMediana_) {
		other.pazymys_.Clear();
		other.egz_ = 0;
		other.galVidurkis_ = 0.0f;
		other.galMediana_ = 0.0f;
	}

	///  Move assignment operator
	Stud& operator=(Stud&& other) noexcept {
		if (this != &other) {
			Zmogus::operator=(std::move(other));
			pazymys_ = std::move(other.pazymys_);
			egz_ = other.egz_;
			galVidurkis_ = other.galVidurkis_;
			galMediana_ = other.galMediana_;

			other.pazymys_.Clear();
			other.egz_ = 0;
			other.galVidurkis_ = 0.0f;
			other.galMediana_ = 0.0f;
		}
		return *this;
	}

	/// Ivesties operatorius
	friend std::istream& operator>>(std::istream& is, Stud& s) {
		is >> static_cast<Zmogus&>(s);

		int egz;
		Vector<int> pazymiai;
		int paz;

		std::cout << "Iveskite egzamino pazymi: ";
		egz = ivestiesPatikrinimas(0, 10);

		std::cout << "Iveskite pazymius 0 iki 10, norint baigti iveskite -1:\n";
		while(true) {
			paz = ivestiesPatikrinimas(0, 10, -1);
			if (paz == -1) break;
			pazymiai.PushBack(paz);
		}

		s.setEgz(egz);
		for (int p : pazymiai) s.addPazymys(p);

		s.calculateGalVidurkis();
		s.calculateGalMediana();
		return is;
	}

	/// Isvesties operatorius
	friend std::ostream& operator<<(std::ostream& os, const Stud& s) {
		os << static_cast<const Zmogus&>(s);
		os << " Egzaminas: " << s.getEgz() << " Pazymiai: ";
		for (int p : s.getPazymys()) {
			os << p << " ";
		}
		os << "Vidurkis: " << s.getVidurkis() << " Mediana: " << s.getMediana();
		return os;
	}

	/// Setteriai, kurie nustato studento varda, pavarde, uzduotis ir egzamino pazymi.
	void setVar(const std::string& var) override { var_ = var; }
	void setPav(const std::string& pav) override { pav_ = pav; }
	void setEgz(const int egz)					 { egz_ = egz; }

	/// Papildomos funkcijos, kurios prideda ir pasalina uzduociu pazymius
	void addPazymys(const int pazymys)		{pazymys_.PushBack(pazymys);}
	void removePazymys()					{pazymys_.PopBack();}

	void calculateGalVidurkis();
	void calculateGalMediana();

	/// Getteriai, kurie grazina studento varda, pavarde, uzduotis, egzamino pazymi ir galutini pazymi.
	std::string getVar() const override { return var_; }
	std::string getPav() const override { return pav_; }
	Vector<int> getPazymys() const { return pazymys_; }
	int getEgz() const					{ return egz_; }
	float getVidurkis() const			{ return galVidurkis_; }
	float getMediana() const			{ return galMediana_; }
	
	/// Ivesties patikrinimas
	static int ivestiesPatikrinimas(const int nuo, const int iki) {
		int input{};
		while (true) {
			try {
				std::cin >> input;
				if (input < nuo || input > iki) {
					std::cout << "\n\n!!!!Iveskite skaiciu nuo " << nuo << " iki " << iki << ".!!!!\n\n\n";
					continue;
				}
			}
			catch (...) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n\n";
				continue;
			}
			break;
		}
		return input;
	}

	static int ivestiesPatikrinimas(const int nuo, const int iki, const int sustabdymoSalyga) {
		int input{};
		while (true) {
			try {
				std::cin >> input;
				if (input == sustabdymoSalyga) {
					return sustabdymoSalyga;
				}

				if (input < nuo || input > iki) {
					std::cout << "\n\n!!!!Iveskite skaiciu nuo " << nuo << " iki " << iki << ".!!!!\n\n\n";
					continue;
				}
			}
			catch (...) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n\n";
				continue;
			}
			break;
		}
		return input;
	}
};

#endif