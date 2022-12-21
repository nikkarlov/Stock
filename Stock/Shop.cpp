#include "Shop.h"

Request Shop::CreateRequest() const {
	return Request(num_, std::rand() % 4 + 2, prod_[std::rand() % prod_.size()]);
}