#pragma once
#include <algorithm>
class Product {
 public:
	 Product() {}
	 Product(int number, int expirationDate, bool type) :
		number_(number),
		expirationDate_(expirationDate),
		type_(type){}
	 Product(const Product& other) :
		 number_(other.number_),
		 expirationDate_(other.expirationDate_),
		 type_(other.type_) {}
	 int setExpirationDate_() {
		 return expirationDate_;
	 }
	 int setNumber() {
		 return number_;
	 }
	 bool setType() {
		 return type_;
	 }
 private:
	 int expirationDate_, number_;
	 bool type_;
};
class Package {
 public:
	 Package(int cost, int dateManf, int count, Product prod) :
		 cost_(cost),
		 dateManf_(dateManf),
		 count_(count),
		 prod_(prod){}
	Product prod_;
	int cost_, dateManf_, count_;
};