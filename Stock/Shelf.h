#pragma once
#include <vector>
#include <algorithm>

#include "Product.h"
#include "Package.h"

class Shelf {
 public:
	Shelf(const Product& prod, const int maxCount) : 
		prod_(prod),
		maxCount_(maxCount) {}

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


	Product GetProduct() const {
		return prod_;
	}

	std::vector<Package> GetPackages() const {
		return pack_;
	}

	int GetCount() const {
		return count_;
	}

	int GetMaxCount() const {
		return maxCount_;
	}

	int GetPreliminaryCount() const {
		return preliminaryCount_;
	}

	void SetPackages(const std::vector<Package>& packages) {
		pack_ = packages;
		return;
	}

	void SetCount(const int count) {
		count_ = count;
		return;
	}

	void SetPreliminaryCount(const int count) {
		preliminaryCount_ = count;
		return;
	}


	void CheckDate(const int day);

	bool Check(const Package& pack);

	void PushPackage(Package pack);

	void Sort();

 private:
	 Product prod_;
	 std::vector<Package> pack_;
	 int count_ = 0, maxCount_, preliminaryCount_ = 0;

	 void Swap(Shelf& other);
};