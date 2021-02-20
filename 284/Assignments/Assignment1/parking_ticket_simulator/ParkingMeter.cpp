#include<cstdlib>

#include "ParkingMeter.h"
using namespace std;

ParkingMeter::ParkingMeter() {
	this->setMinutesPaid();
}

void ParkingMeter::setMinutesPaid() {
	minutesPaid = (rand() % 1*1.0 + 240);
}

double ParkingMeter::getMinutesPaid() {
	return minutesPaid;
}