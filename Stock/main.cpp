#include <iostream>

#include "Generator.h"

int main() {
	std::srand(std::time(nullptr));
	generator::run();
	for (int i = 0; i < generator::N; i++) {
		generator::stock.NextDay();
	}
	std::cout << generator::stock.GetMoney();
}