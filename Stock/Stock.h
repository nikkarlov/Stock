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
		 AcceptOrders(FormationOrders());
		 AcceptTrucks(manager_.FormationTruck(importer_, shelfs_, money_, trucks_, day_));
		 day_++;
	 }
	 void AcceptTrucks(std::vector<Truck> newTrucks_) {
		 for (int i = 0; i < newTrucks_.size(); i++) {
			 money_ -= newTrucks_[i].pack_.count_ * importer_.cost_[newTrucks_[i].pack_.prod_.setNumber()];
			 trucks_.push_back(newTrucks_[i]);
		 }
	 }
	 void AcceptOrders(std::vector<Request> newReq) {
		 for (int i = 0; i < newReq.size(); i++) {
			 int numProd = newReq[i].prod_.setNumber();
			 int countProd = newReq[i].count_;
			 for (int y = 0; y < shelfs_[numProd].pack_.size() && countProd > 0; y++) {
				 if (countProd >= shelfs_[numProd].pack_[y].count_) {
					 countProd -= shelfs_[numProd].pack_[y].count_;
					 money_ += shelfs_[numProd].pack_[y].cost_ * shelfs_[numProd].pack_[y].count_;
					 shelfs_[numProd].pack_.erase(shelfs_[numProd].pack_.begin() + y);
				 }
				 else {
					 money_ += countProd * shelfs_[numProd].pack_[y].count_;
					 shelfs_[numProd].pack_[y].count_ -= countProd;
					 countProd = 0;
				 }
			 }
		 }
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
	 std::vector<Request> FormationOrders() {
		 std::vector<Request> req;
		 for (int i = 0; i < shops_.size(); i++) {
			 req.push_back(shops_[i].Req());
		 }
		 return manager_.FormationOrders(req, shelfs_, money_);
	 }
	 std::vector<Shop> shops_;
	 std::vector<Shelf> shelfs_;
	 std::vector<Truck> trucks_;
	 Importer importer_;
	 Manager manager_;
	 int money_ = 0, day_ = 1;
};