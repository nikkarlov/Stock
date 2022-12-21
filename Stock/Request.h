#pragma once
#include "Product.h"

class Request {
 public:
	 Request(const int num, const int count, const Product& prod) :
		num_(num),
		count_(count),
		prod_(prod) {}

	 Request(const Request& req) :
		 num_(req.num_),
		 count_(req.count_),
		 prod_(req.prod_) {}


	 int GetCount() const {
		 return count_;
	 }

	 Product GetProduct() const {
		 return prod_;
	 }

private:
	 int num_, count_;
	 Product prod_;
};