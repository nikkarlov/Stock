#pragma once
#include "Product.h"
#include <vector>
#include <algorithm>
class Shelf {
 public:
	Shelf() {}
	Shelf(Product prod, int maxCount) : 
		prod_(prod),
		maxCount_(maxCount){}
	Shelf(const Shelf& other) :
		prod_(other.prod_),
		pack_(other.pack_),
		count_(other.count_),
		maxCount_(other.maxCount_),
		preliminaryCount_(other.preliminaryCount_){}
	Shelf& operator=(Shelf other) {
		Swap(other);
		return *this;
	}
	void CheckDate(int day) {
		for (int i = 0; i < pack_.size(); i++) {
			if (day - pack_[i].dateManf_ >= pack_[i].prod_.setExpirationDate_()) {
				count_ -= pack_[i].count_;
				preliminaryCount_ -= pack_[i].count_;
				pack_.erase(pack_.begin() + i);
			}
		}
		this->Sort();
	}
	bool Check(Package pack) {
		if (pack.count_ + count_ <= maxCount_) {
			return true;
		}
		else {
			return false;
		}
	}
	void PushPackage(Package pack) {
		if (!Check(pack)) {
			pack.count_ = maxCount_ - count_;
		}
		pack_.push_back(pack);
		count_ += pack.count_;
		this->Sort();
	}
	void Sort() {
		sort(pack_.begin(), pack_.end(), [](Package a, Package b) {
			return a.dateManf_ > b.dateManf_;
			});
	}
	Product prod_;
	std::vector<Package> pack_;
	int count_ = 0, maxCount_, preliminaryCount_ = 0;
 private:
	 void Swap(Shelf& other) {
		std::swap(prod_, other.prod_);
		std::swap(pack_, other.pack_);
		std::swap(count_, other.count_);
		std::swap(maxCount_, other.maxCount_);
		std::swap(preliminaryCount_, other.preliminaryCount_);
	 }
};