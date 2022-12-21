#include <iostream>

#include "Generator.h"

int main() {
	std::srand(std::time(nullptr));
	generator::run();
	for (int i = 0; i < generator::N; i++) {
		generator::stock.NextDay();
		std::cout << "=== Day " << i + 1 << " === " << std::endl;
		std::cout << "Active trucks: " << generator::stock.trucks_.size() << std::endl;
		std::cout << "Money: " << generator::stock.GetMoney() << std::endl << std::endl;
	}
}