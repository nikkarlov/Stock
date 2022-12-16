#pragma once
#include "Shelf.h"
#include "Truck.h"
#include "Importer.h"
#include "Shop.h"
#include "Manager.h"
class Stock {
 public:
	 void Day() {
		 ChackShelfs();
		 CheckTrucks();
		 manager_.Discount(importer_, shelfs_, day_);
		 FormationOrders();
		 manager_.FormationTruck(importer_, shelfs_, money_, trucks_, day_);
		 day_++;
	 }
	 void CheckTrucks() {
		 for (int i = 0; i < trucks_.size(); i++) {
			 trucks_[i].timeLeft_--;
			 if (!trucks_[i].timeLeft_) {
				 int numProd = trucks_[i].pack_.prod_.setNumber();
				 shelfs_[numProd].PushPackage(trucks_[i].pack_);
				 trucks_.erase(trucks_.begin() + i);
			 }
		 }
	 }
	 void ChackShelfs() {
		 for (int i = 0; i < shelfs_.size(); i++) {
			 shelfs_[i].CheckDate(day_);
		 }
	 }
	 void FormationOrders() {
		 std::vector<Request> req;
		 for (int i = 0; i < shops_.size(); i++) {
			 req.push_back(shops_[i].Req());
		 }
		 manager_.FormationOrders(req, shelfs_, money_);
	 }
	 std::vector<Shop> shops_;
	 std::vector<Shelf> shelfs_;
	 std::vector<Truck> trucks_;
	 Importer importer_;
	 Manager manager_;
	 int money_ = 0, day_ = 1;
};