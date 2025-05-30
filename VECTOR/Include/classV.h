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
	/// <summary>
	/// Setteriai, kurie nustato studento varda, pavarde, uzduotis ir egzamino pazymi.
	/// </summary>
	/// <param name="v"></param>
	void setVar(const std::string& var) { var_ = var; }
	void setPav(const std::string& pav) { pav_ = pav; }
	void setEgz(const int egz)          { egz_ = egz; }

	/// <summary>
	/// Papildomos funkcijos, kurios prideda ir pasalina uzduociu pazymius
	/// </summary>
	/// <param name="uzd"></param>
	void addPazymys(const int pazymys)		{pazymys_.push_back(pazymys);}
	void removePazymys()					{pazymys_.pop_back();}

	void calculateGalVidurkis();
	void calculateGalMediana();
	/// <summary>
	/// Getteriai, kurie grazina studento varda, pavarde, uzduotis, egzamino pazymi ir galutini pazymi.
	/// </summary>
	/// <returns></returns>
	std::string getVar() const			{ return var_; }
	std::string getPav() const          { return pav_; }
	std::vector<int> getPazymys() const { return pazymys_; }
	int getEgz() const					{ return egz_; }
	float getVidurkis() const			{ return galVidurkis_; }
	float getMediana() const			{ return galMediana_; }
	
};
#endif