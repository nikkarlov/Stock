#pragma once
#include <vector>

#include "Product.h"
#include "Request.h"

class Shop {
 public:
	 Shop(const int num, const int type, const std::vector<Product>& prod) :
		num_(num),
		type_(type),
		prod_(prod) {}

	 Request CreateRequest() const;

 private:
	 int num_, type_;
	 std::vector<Product> prod_;
};
