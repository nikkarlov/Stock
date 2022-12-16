#pragma once
#include "Importer.h"
#include "Product.h"
#include "Stock.h"
int N = rnd() % 24 + 7, M = rnd() % 7 + 3, K = rnd() % 8 + 10;
std::vector<Product> products, farmProducts, supmarketProducts;
Stock stock;
void gener() {
	for (int i = 0; i < K; i++) {
		products.push_back({ i, rnd() % 20 + 5, bool(rnd() % 2) });
		if (products[i].setType()) {
			farmProducts.push_back(products[i]);
		}
		else {
			supmarketProducts.push_back(products[i]);
		}
	}
	stock.importer_.cost_.resize(K);
	for (int i = 0; i < K; i++) {
		stock.importer_.cost_[i] = rnd() % 100 + 10;
	}
	for (int i = 0; i < K; i++) {
		if (rnd() % 2) {
			stock.shops_.push_back({i, 1, farmProducts});
		}
		else {
			stock.shops_.push_back({ i, 2, supmarketProducts });
		}
	}
	for (int i = 0; i < K; i++) {
		stock.shelfs_.push_back({ products[i], rnd() % 10 + 4 });
	}
}