#pragma once
#include <algorithm>

class Product {
 public:
	 Product(const int number, const int expirationDate, const bool type) :
		number_(number),
		expirationDate_(expirationDate),
		type_(type) {}

	 Product(const Product& other) :
		 number_(other.number_),
		 expirationDate_(other.expirationDate_),
		 type_(other.type_) {}


	 int GetExpirationDate() const {
		 return expirationDate_;
	 }

	 int GetNumber() const {
		 return number_;
	 }

	 bool GetType() const {
		 return type_;
	 }

 private:
	 int expirationDate_, number_;
	 bool type_;
};