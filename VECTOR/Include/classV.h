#ifndef STRUCTV_H
#define STRUCTV_H

// Struktura, kurioje laikomi studento duomenys.

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
	explicit Stud(std::string var = "", std::string pav = "", std::vector<int> pazymys = {}, int egz = {}) : var_(std::move(var)), pav_(std::move(pav)), pazymys_(std::move(pazymys)), egz_(egz) {}

	~Stud() = default;

	/// Copy constructor
	Stud(const Stud& other) :
		var_(other.var_),
		pav_(other.pav_),
		pazymys_(other.pazymys_), 
		egz_(other.egz_),
		galVidurkis_(other.galVidurkis_),
		galMediana_(other.galMediana_) {}

	/// Copy assignment operator
	Stud& operator=(const Stud& other) {
		if (this != &other) {
			var_ = other.var_;
			pav_ = other.pav_;
			pazymys_ = other.pazymys_;
			egz_ = other.egz_;
			galVidurkis_ = other.galVidurkis_;
			galMediana_ = other.galMediana_;
		}
		return *this;
	}

	/// Move constructor
	Stud(Stud&& other) noexcept :
		var_(std::move(other.var_)),
		pav_(std::move(other.pav_)),
		pazymys_(std::move(other.pazymys_)),
		egz_(other.egz_),
		galVidurkis_(other.galVidurkis_),
		galMediana_(other.galMediana_) {
		other.egz_ = 0; // Reset moved-from object's egz
	}

	///  Move assignment operator
	Stud& operator=(Stud&& other) noexcept {
		if (this != &other) {
			var_ = std::move(other.var_);
			pav_ = std::move(other.pav_);
			pazymys_ = std::move(other.pazymys_);
			egz_ = other.egz_;
			galVidurkis_ = other.galVidurkis_;
			galMediana_ = other.galMediana_;
			other.egz_ = 0; // Reset moved-from object's egz
		}
		return *this;
	}

	/// Ivesties operatorius
	friend std::istream& operator>>(std::istream& is, Stud& s) {
		std::string var, pav;
		int egz;
		std::vector<int> pazymiai;
		int paz;

		cout << "Iveskite varda: ";
		is >> var;
		cout << "Iveskite pavarde: ";
		is >> pav;
		cout << "Iveskite egzamino pazymi: ";
		egz = ivestiesPatikrinimas(0, 10);
		cout << "Iveskite pazymius 0 iki 10, norint baigti iveskite -1:\n";
		while(true) {
			paz = ivestiesPatikrinimas(0, 10, -1);
			if (paz == -1) break;
			pazymiai.push_back(paz);
		}

		s.setVar(var);
		s.setPav(pav);
		s.setEgz(egz);
		for (int p : pazymiai) s.addPazymys(p);

		s.calculateGalVidurkis();
		s.calculateGalMediana();
		pazymiai.clear();
		pazymiai.shrink_to_fit();
		return is;
	}

	/// Isvesties operatorius
	friend std::ostream& operator<<(std::ostream& os, const Stud& s) {
		os << s.getVar() << " " << s.getPav() << " Egzaminas: " << s.getEgz() << " Pazymiai: ";
		for (int p : s.getPazymys()) {
			os << p << " ";
		}
		os << " Vidurkis: " << s.getVidurkis() << " Mediana: " << s.getMediana();
		return os;
	}

	/// Setteriai, kurie nustato studento varda, pavarde, uzduotis ir egzamino pazymi.
	void setVar(const std::string& var) { var_ = var; }
	void setPav(const std::string& pav) { pav_ = pav; }
	void setEgz(const int egz)          { egz_ = egz; }

	/// Papildomos funkcijos, kurios prideda ir pasalina uzduociu pazymius
	void addPazymys(const int pazymys)		{pazymys_.push_back(pazymys);}
	void removePazymys()					{pazymys_.pop_back();}

	void calculateGalVidurkis();
	void calculateGalMediana();

	/// Getteriai, kurie grazina studento varda, pavarde, uzduotis, egzamino pazymi ir galutini pazymi.
	std::string getVar() const			{ return var_; }
	std::string getPav() const          { return pav_; }
	std::vector<int> getPazymys() const { return pazymys_; }
	int getEgz() const					{ return egz_; }
	float getVidurkis() const			{ return galVidurkis_; }
	float getMediana() const			{ return galMediana_; }
	
	/// Ivesties patikrinimas
	static int ivestiesPatikrinimas(const int nuo, const int iki) {
		int input{};
		while (true) {
			try {
				cin >> input;
				if (input < nuo || input > iki) {
					cout << "\n\n!!!!Iveskite skaiciu nuo " << nuo << " iki " << iki << ".!!!!\n\n\n";
					continue;
				}
			}
			catch (...) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n\n";
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
				cin >> input;
				if (input == sustabdymoSalyga) {
					return sustabdymoSalyga;
				}

				if (input < nuo || input > iki) {
					cout << "\n\n!!!!Iveskite skaiciu nuo " << nuo << " iki " << iki << ".!!!!\n\n\n";
					continue;
				}
			}
			catch (...) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "\n\n!!!!Ivestis neteisinga. Bandykite isnaujo.!!!!\n\n\n";
				continue;
			}
			break;
		}
		return input;
	}
};
#endif