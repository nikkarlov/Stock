#pragma once
#include "Importer.h"
#include "Shelf.h"
#include "Truck.h"
#include "Request.h"

class Manager {
public:
	void Discount(const Importer& importer, std::vector<Shelf>& shelfs, const int day);

	std::vector<Truck> FormationTruck(const Importer& importer, std::vector<Shelf>& shelfs, const int day);

	std::vector<Request> FormationOrders(const std::vector<Request>& req, std::vector<Shelf> shelfs);
};