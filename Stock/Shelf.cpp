#include "Shelf.h"

void Shelf::CheckDate(const int day) {
	for (int i = 0; i < pack_.size(); i++) {
		if (day - pack_[i].GetManifuctureDate() >= pack_[i].GetProduct().GetExpirationDate()) {
			count_ -= pack_[i].GetCount();
			preliminaryCount_ -= pack_[i].GetCount();
			pack_.erase(pack_.begin() + i);
		}
	}
	this->Sort();
}

bool Shelf::Check(const Package& pack) {
	if (pack.GetCount() + count_ <= maxCount_) {
		return true;
	}
	return false;
}

void Shelf::PushPackage(Package pack) {
	if (!Check(pack)) {
		pack.SetCount(maxCount_ - count_);
	}
	pack_.push_back(pack);
	count_ += pack.GetCount();
	this->Sort();
}

void Shelf::Sort() {
	sort(pack_.begin(), pack_.end(), [](const Package& a, const Package& b) {
		return a.GetManifuctureDate() > b.GetManifuctureDate();
	});
}


void Shelf::Swap(Shelf& other) {
	std::swap(prod_, other.prod_);
	std::swap(pack_, other.pack_);
	std::swap(count_, other.count_);
	std::swap(maxCount_, other.maxCount_);
	std::swap(preliminaryCount_, other.preliminaryCount_);
}