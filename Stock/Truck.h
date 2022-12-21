#pragma once
#include "Package.h"

class Truck {
public:
	Truck(const Package& pack, const int timeLeft) :
		pack_(pack),
		timeLeft_(timeLeft) {}

	Truck(const Truck& other) :
		pack_(other.pack_),
		timeLeft_(other.timeLeft_) {}


	Package GetPackage() const {
		return pack_;
	}

	int GetTime() const {
		return timeLeft_;
	}


	void Drive();

private:
	Package pack_;
	int timeLeft_;
};