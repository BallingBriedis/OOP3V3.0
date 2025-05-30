#ifndef ZMOGUS_H
#define ZMOGUS_H
class Zmogus {
protected:
	std::string var_{}, pav_{};

public:
	/// Konstruktorius ir desktrutorius
	explicit Zmogus(std::string var = "", std::string pav = "") :
		var_(std::move(var)), pav_(std::move(pav)) {}

	~Zmogus() = default;

	/// Copy constructor
	Zmogus(const Zmogus& other) :
		var_(other.var_),
		pav_(other.pav_){}

	/// Copy assignment operator
	Zmogus& operator=(const Zmogus& other) {
		if (this != &other) {
			var_ = other.var_;
			pav_ = other.pav_;
		}
		return *this;
	}

	/// Move constructor
	Zmogus(Zmogus&& other) noexcept :
		var_(std::move(other.var_)),
		pav_(std::move(other.pav_)){}

	///  Move assignment operator
	Zmogus& operator=(Zmogus&& other) noexcept {
		if (this != &other) {
			var_ = std::move(other.var_);
			pav_ = std::move(other.pav_);
		}
		return *this;
	}

	/// Ivesties operatorius
	friend std::istream& operator>>(std::istream& is, Zmogus& s) {
		std::string var, pav;

		cout << "Iveskite varda: ";
		is >> var;
		cout << "Iveskite pavarde: ";
		is >> pav;

		s.setVar(var);
		s.setPav(pav);
		return is;
	}

	/// Isvesties operatorius
	friend std::ostream& operator<<(std::ostream& os, const Zmogus& s) {
		os << "Vardas: " << s.getVar() << " Pavarde: " << s.getPav();
		return os;
	}

	/// Setteriai, kurie nustato zmogaus varda ir pavarde
	virtual void setVar(const std::string& var) = 0;
	virtual void setPav(const std::string& pav) = 0;

	/// Getteriai, kurie grazina zmogaus varda ir pavarde
	virtual std::string getVar() const { return var_; }
	virtual std::string getPav() const { return pav_; }
};
#endif