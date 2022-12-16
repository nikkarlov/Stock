#pragma once
#include "Product.h"
class Request {
 public:
	 Request(int num, int count, Product prod) :
		num_(num),
		count_(count),
		prod_(prod){}
	 int num_, count_;
	 Product prod_;
};