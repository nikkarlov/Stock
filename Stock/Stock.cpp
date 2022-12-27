#include "Stock.h"

void Stock::NextDay() {
	CheckShelfs();
	CheckTrucks();
	manager_.Discount(importer_, shelfs_, day_);
	req_ = FormationOrders();
	reqManager_ = manager_.FormationOrders(req_, shelfs_);
	AcceptOrders(reqManager_);
	AcceptTrucks(manager_.FormationTruck(importer_, shelfs_, day_));
	day_++;
}

void Stock::AcceptTrucks(const std::vector<Truck>& newTrucks_) {
	for (int i = 0; i < newTrucks_.size(); i++) {
		money_ -= newTrucks_[i].GetPackage().GetCount() * importer_.cost[newTrucks_[i].GetPackage().GetProduct().GetNumber()];
		trucks_.push_back(newTrucks_[i]);
	}
}

void Stock::AcceptOrders(const std::vector<Request>& newReq) {
	for (int i = 0; i < newReq.size(); i++) {
		int numProd = newReq[i].GetProduct().GetNumber();
		int countProd = newReq[i].GetCount();
		for (int y = 0; y < shelfs_[numProd].GetPackages().size() && countProd > 0; y++) {
			if (countProd >= shelfs_[numProd].GetPackages()[y].GetCount()) {
				countProd -= shelfs_[numProd].GetPackages()[y].GetCount();
				money_ += shelfs_[numProd].GetPackages()[y].GetCost() * shelfs_[numProd].GetPackages()[y].GetCount();
				std::vector<Package> packages = shelfs_[numProd].GetPackages();
				shelfs_[numProd].SetCount(shelfs_[numProd].GetCount() - packages[y].GetCount());
				shelfs_[numProd].SetPreliminaryCount(shelfs_[numProd].GetPreliminaryCount() - packages[y].GetCount());
				packages.erase(packages.begin() + y);
				shelfs_[numProd].SetPackages(packages);
			}
			else {
				money_ += countProd * shelfs_[numProd].GetPackages()[y].GetCount();
				shelfs_[numProd].SetCount(shelfs_[numProd].GetCount() - countProd);
				shelfs_[numProd].SetPreliminaryCount(shelfs_[numProd].GetPreliminaryCount() - countProd);
				std::vector<Package> packages = shelfs_[numProd].GetPackages();
				packages[y].SetCount(packages[y].GetCount() - countProd);
				shelfs_[numProd].SetPackages(packages);
				countProd = 0;
			}
		}
	}
}

void Stock::CheckTrucks() {
	for (int i = 0; i < trucks_.size(); i++) {
		trucks_[i].Drive();
		if (trucks_[i].GetTime() <= 0) {
			int numProd = trucks_[i].GetPackage().GetProduct().GetNumber();
			shelfs_[numProd].PushPackage(trucks_[i].GetPackage());
			trucks_.erase(trucks_.begin() + i);
		}
	}
}

void Stock::CheckShelfs() {
	for (int i = 0; i < shelfs_.size(); i++) {
		shelfs_[i].CheckDate(day_);
	}
}

std::vector<Request> Stock::FormationOrders() {
	std::vector<Request> req;
	for (int i = 0; i < shops_.size(); i++) {
		req.push_back(shops_[i].CreateRequest());
	}
	return req;
}