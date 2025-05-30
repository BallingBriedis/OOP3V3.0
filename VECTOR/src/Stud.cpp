#include "meinelib.h"
#include "studentas.h"
#include "functionsCallsVector.h"

void Stud::calculateGalVidurkis() {
	int pazymiuSuma{};
	if (this->getPazymys().empty()) {
		this->galVidurkis_ = 0.0f;
		return;
	}
	for (const auto& pazymys : this->getPazymys()) {
		pazymiuSuma += pazymys;
	}
	this->galVidurkis_ = pazymiuSuma / this->getPazymys().size() * 0.4f + this->egz_ * 0.6f;
}

void Stud::calculateGalMediana() {
	float galMediana{};
	if (this->getPazymys().empty()) {
		this->galMediana_ = 0.0f;
		return;
	}
	std::vector<int> sortedPazymiai = this->getPazymys();
	std::sort(sortedPazymiai.begin(), sortedPazymiai.end());

	if (sortedPazymiai.size() % 2 == 0) {
		galMediana = (sortedPazymiai[sortedPazymiai.size() / 2 - 1] + sortedPazymiai[sortedPazymiai.size() / 2]) / 2.0f;
	}
	else {
		galMediana = sortedPazymiai[sortedPazymiai.size() / 2];
	}
	this->galMediana_ = galMediana * 0.4f + this->egz_ * 0.6f;
}

void studentuGalutiniuSkaiciavimas(vector<Stud>& studentai) {
	if (studentai.back().getVidurkis() == 0 || studentai.back().getMediana() == 0) {
		for (auto& studentas : studentai) {
			studentas.calculateGalVidurkis();
			studentas.calculateGalMediana();
		}
	}
}