#include "Manager.h"

void Manager::Discount(const Importer& importer, std::vector<Shelf>& shelfs, int day) {
	for (int i = 0; i < shelfs.size(); i++) {
		for (int y = 0; y < shelfs[i].GetPackages().size(); y++) {
			if (day - shelfs[i].GetPackages()[y].GetManifuctureDate() >=
				shelfs[i].GetPackages()[y].GetProduct().GetExpirationDate() * 0.5) {
				shelfs[i].GetPackages()[y].SetCost(importer.cost[i]);
			}
		}
	}
}

std::vector<Truck> Manager::FormationTruck(const Importer& importer, std::vector<Shelf>& shelfs, const int day) {
	std::vector<Truck> newTrucks_;

	for (int i = 0; i < shelfs.size(); i++) {
		if (shelfs[i].GetPreliminaryCount() < shelfs[i].GetMaxCount() / 3) {
			int cost = importer.cost[i] * 2;
			Package pac(cost, day, shelfs[i].GetMaxCount() / 3 - shelfs[i].GetPreliminaryCount(), shelfs[i].GetProduct());
			shelfs[i].SetPreliminaryCount(shelfs[i].GetMaxCount() / 3);
			newTrucks_.push_back(Truck(pac, int(std::rand() % 5 + 1)));
		}
	}
	return newTrucks_;
}

std::vector<Request> Manager::FormationOrders(const std::vector<Request>& req, std::vector<Shelf> shelfs) {
	std::vector<Request> newReq;

	for (int i = 0; i < req.size(); i++) {
		int numProd = req[i].GetProduct().GetNumber();
		int countProd = req[i].GetCount();
		for (int y = 0; y < shelfs[numProd].GetPackages().size() && countProd > 0; y++) {
			if (countProd >= shelfs[numProd].GetPackages()[y].GetCount()) {
				countProd -= shelfs[numProd].GetPackages()[y].GetCount();
				std::vector<Package> packages = shelfs[numProd].GetPackages();
				packages.erase(packages.begin() + y);
				shelfs[numProd].SetPackages(packages);
			}
			else {
				shelfs[numProd].GetPackages()[y].SetCount(shelfs[numProd].GetPackages()[y].GetCount() - countProd);
				countProd = 0;
			}
		}
		if (countProd != req[i].GetCount()) {
			newReq.push_back(Request(numProd, req[i].GetCount() - countProd, req[i].GetProduct()));
		}
	}
	return newReq;
}