#pragma once
#include "Product.h"

class Package {
public:
	Package(const int cost, const int dateManf, const int count, const Product& prod) :
		cost_(cost),
		dateManf_(dateManf),
		count_(count),
		prod_(prod) {}


	Product GetProduct() const {
		return prod_;
	}

	int GetCost() const {
		return cost_;
	}

	int GetManifuctureDate() const {
		return dateManf_;
	}

	int GetCount() const {
		return count_;
	}


	void SetCost(const int cost) {
		cost_ = cost;
		return;
	}

	void SetCount(const int count) {
		count_ = count;
		return;
	}

private:
	Product prod_;
	int cost_, dateManf_, count_;
};