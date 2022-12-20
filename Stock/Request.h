#pragma once
#include "Product.h"
class Request {
 public:
	 Request(int num, int count, Product prod) :
		num_(num),
		count_(count),
		prod_(prod){}
	 Request(const Request& req) :
		 num_(req.num_),
		 count_(req.count_),
		 prod_(req.prod_){}
	 int num_, count_;
	 Product prod_;
};