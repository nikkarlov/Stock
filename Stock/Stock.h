#pragma once
#include "Shelf.h"
#include "Truck.h"
#include "Importer.h"
#include "Shop.h"
#include "Manager.h"

class Stock {
public:
	std::vector<Shop> shops_;
	std::vector<Shelf> shelfs_;
	std::vector<Truck> trucks_;
	Importer importer_;

	std::vector<Request> GetReq() {
		return req_;
	}

	int GetMoney() const {
		return money_;
	}

	int GetDay() const {
		return day_;
	}


	void NextDay();

	void AcceptTrucks(std::vector<Truck> newTrucks_);

	void AcceptOrders(std::vector<Request> newReq);

	void CheckTrucks();

	void CheckShelfs();

	std::vector<Request> FormationOrders();

private:
	std::vector<Request> req_;
	Manager manager_;
	int money_ = 0, day_ = 1;
};