#include "meinelib.h"
#include "classV.h"
#include "functionsCallsVector.h"

void Stud::calculateGalVidurkis() {
	int pazymiuSuma{};
	if (this->getPazymys().empty()) {
		this->galVidurkis_ = 0.0f;
		throw std::runtime_error("Studentas neturi pazymiu.\n");
		return;
	}
	for (const auto& pazymys : this->getPazymys()) {
		pazymiuSuma += pazymys;
	}
	this->galVidurkis_ = pazymiuSuma / this->getPazymys().size() * 0.4f + this->egz_ * 0.6f;
}

void Stud::calculateGalMediana() {
	if (this->getPazymys().empty()) {
		throw std::runtime_error("Studentas neturi pazymiu.\n");
	}
	std::vector<int> sortedPazymiai = this->getPazymys();
	std::sort(sortedPazymiai.begin(), sortedPazymiai.end());

	if (sortedPazymiai.size() % 2 == 0) {
		galMediana_ = (sortedPazymiai[size / 2 - 1] + sortedPazymiai[size / 2]) / 2.0f;
	}
	else {
		stu.galMediana_ = sortedPazymiai[size / 2];
	}
}