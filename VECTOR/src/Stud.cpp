#include "meinelib.h"
#include "studentas.h"
#include "functionsCallsVector.h"

void Stud::calculateGalVidurkis() {
	int pazymiuSuma{};
	if (this->getPazymys().Empty()) {
		this->galVidurkis_ = 0.0f;
		return;
	}
	for (const auto& pazymys : this->getPazymys()) {
		pazymiuSuma += pazymys;
	}
	this->galVidurkis_ = pazymiuSuma / this->getPazymys().Size() * 0.4f + this->egz_ * 0.6f;
}

void Stud::calculateGalMediana() {
	float galMediana{};
	if (this->getPazymys().Empty()) {
		this->galMediana_ = 0.0f;
		return;
	}
	Vector<int> sortedPazymiai = this->getPazymys();
	std::sort(sortedPazymiai.begin(), sortedPazymiai.end());

	if (sortedPazymiai.Size() % 2 == 0) {
		galMediana = (sortedPazymiai[sortedPazymiai.Size() / 2 - 1] + sortedPazymiai[sortedPazymiai.Size() / 2]) / 2.0f;
	}
	else {
		galMediana = sortedPazymiai[sortedPazymiai.Size() / 2];
	}
	this->galMediana_ = galMediana * 0.4f + this->egz_ * 0.6f;
}

void studentuGalutiniuSkaiciavimas(Vector<Stud>& studentai) {
	if (studentai.Back().getVidurkis() == 0 || studentai.Back().getMediana() == 0) {
		for (auto& studentas : studentai) {
			studentas.calculateGalVidurkis();
			studentas.calculateGalMediana();
		}
	}
}