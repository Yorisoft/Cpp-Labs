#include<cstdlib>
#include <random>
#include<string>

#include "ParkingMeter.h"
using namespace std;

ParkingMeter::ParkingMeter() {
	this->setMinutesPaid();
}

void ParkingMeter::setMinutesPaid() {
	minutesPaid = rand() % 240 + 30;
}

long int ParkingMeter::getMinutesPaid() {
	return minutesPaid;
}