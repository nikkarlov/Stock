#pragma once
#include "Importer.h"
#include "Shelf.h"
#include "Truck.h"
class Manager {
public:
	void Discount(const Importer& importer, std::vector<Shelf>& shelfs, int day) {
		for (int i = 0; i < shelfs.size(); i++) {
			for (int y = 0; y < shelfs[i].pack_.size(); y++) {
				if (day - shelfs[i].pack_[y].dateManf_ >= shelfs[i].pack_[y].prod_.setExpirationDate_() * 0.5) {
					shelfs[i].pack_[y].cost_ = importer.cost_[i];
				}
			}
		}
	}
	std::vector<Truck> FormationTruck(const Importer& importer, std::vector<Shelf>& shelfs,
		int& money, std::vector<Truck>& trucks, int day) {
		std::vector<Truck> newTrucks_;
		for (int i = 0; i < shelfs.size(); i++) {
			if (shelfs[i].preliminaryCount_ < shelfs[i].maxCount_ / 3) {
				int cost = importer.cost_[i] * 2;
				Package pac = { cost, day, shelfs[i].maxCount_ / 3 - shelfs[i].preliminaryCount_, shelfs[i].prod_ };
				shelfs[i].preliminaryCount_ = shelfs[i].maxCount_ / 3;
				newTrucks_.push_back({ pac, int(rnd() % 5) });
			}
		}
		return newTrucks_;
	}
	std::vector<Request> FormationOrders(std::vector<Request>& req, std::vector<Shelf>& shelfs, int& money) {
		std::vector<Request> newReq;
		std::vector<Shelf> copyShelfs(shelfs.size());
		copy(shelfs.begin(), shelfs.end(), copyShelfs.begin());
		for (int i = 0; i < req.size(); i++) {
			int numProd = req[i].prod_.setNumber();
			int countProd = req[i].count_;
			for (int y = 0; y < copyShelfs[numProd].pack_.size() && countProd > 0; y++) {
				if (countProd >= copyShelfs[numProd].pack_[y].count_) {
					countProd -= copyShelfs[numProd].pack_[y].count_;
					copyShelfs[numProd].pack_.erase(copyShelfs[numProd].pack_.begin() + y);
				}
				else {
					copyShelfs[numProd].pack_[y].count_ -= countProd;
					countProd = 0;
				}
			}
			if (countProd != req[i].count_) {
				newReq.push_back({ numProd, req[i].count_ - countProd, req[i].prod_ });
			}
		}
		return newReq;
	}
};