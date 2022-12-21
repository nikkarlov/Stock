#pragma once
#include "Importer.h"
#include "Product.h"
#include "Stock.h"

namespace generator {
	int N = std::rand() % 24 + 7;
	int M = std::rand() % 7 + 3;
	int K = std::rand() % 8 + 10;
	std::vector<Product> products, farmProducts, supmarketProducts;
	Stock stock;

	void run() {
		std::srand(std::time(nullptr));

		N = std::rand() % 24 + 7;
		M = std::rand() % 7 + 3;
		K = std::rand() % 8 + 10;

		for (int i = 0; i < K; i++) {
			products.push_back(Product(i, std::rand() % 20 + 5, bool(std::rand() % 2)));
			if (products[i].GetType()) {
				farmProducts.push_back(products[i]);
			}
			else {
				supmarketProducts.push_back(products[i]);
			}
		}
		stock.importer_.cost.resize(K);
		for (int i = 0; i < K; i++) {
			stock.importer_.cost[i] = std::rand() % 100 + 10;
		}
		for (int i = 0; i < K; i++) {
			if (std::rand() % 2) {
				stock.shops_.push_back(Shop(i, 1, farmProducts));
			}
			else {
				stock.shops_.push_back(Shop(i, 2, supmarketProducts));
			}
		}
		for (int i = 0; i < K; i++) {
			stock.shelfs_.push_back(Shelf(products[i], std::rand() % 10 + 4));
		}
	}
}