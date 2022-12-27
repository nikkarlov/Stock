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

	std::vector<Request> GetRequests() const {
		return req_;
	}

	std::vector<Request> GetManagerRequests() const {
		return reqManager_;
	}

	int GetMoney() const {
		return money_;
	}

	int GetDay() const {
		return day_;
	}


	void NextDay();

	void AcceptTrucks(const std::vector<Truck>& newTrucks_);

	void AcceptOrders(const std::vector<Request>& newReq);

	void CheckTrucks();

	void CheckShelfs();

	std::vector<Request> FormationOrders();

private:
	std::vector<Request> req_;
	std::vector<Request> reqManager_;
	Manager manager_;
	int money_ = 0, day_ = 1;
};