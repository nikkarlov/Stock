#pragma once
#include "Product.h"
class Truck {
 public:
	Truck(Package pack, int timeLeft) :
		pack_(pack),
		timeLeft_(timeLeft){}
	Truck(const Truck& other) :
		pack_(other.pack_),
		timeLeft_(other.timeLeft_) {}
	Package pack_;
	int timeLeft_;
};