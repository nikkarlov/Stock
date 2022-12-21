#include "Truck.h"

void Truck::Drive() {
	if (timeLeft_ > 0) {
		timeLeft_--;
	}
	return;
}