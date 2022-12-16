#pragma once
#include "Product.h"
#include "Request.h"
#include <vector>
#include <random>
#include <chrono>
std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
class Shop {
 public:
	 Shop(int num, int type, std::vector<Product> prod) :
		num_(num),
		type_(type),
		prod_(prod){}
	 Request Req() {
		 Request req = { num_, rnd() % 4 + 2, prod_[rnd() % prod_.size()] };
		 return req;
	 }
 private:
	 int num_, type_;
	 std::vector<Product> prod_;
};
