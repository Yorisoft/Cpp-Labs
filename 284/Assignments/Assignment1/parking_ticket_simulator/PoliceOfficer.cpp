/// This is the implementation file for PoliceOfficer class

#include<string>
#include "ParkedCar.h"
#include "PoliceOfficer.h"
#include "ParkingMeter.h";

using namespace std;

//constructor
PoliceOfficer::PoliceOfficer() {
	this->setOfficerNum();
	this->setOfficerName("Jhon Doe");
}
PoliceOfficer::PoliceOfficer(string name) {
	this->setOfficerNum();
	this->setOfficerName(name);
}

//setters
void PoliceOfficer::setOfficerNum() {
	officerNum =  (rand() % 1000*1.0 + 9999);
}
void PoliceOfficer::setOfficerName(string name) {
	officerName = name;
}

//getters
double PoliceOfficer::getOfficerNum() {
	return officerNum;
}
string PoliceOfficer::getOfficerName() {
	return officerName;
}

bool PoliceOfficer::parkingMeterInspection(ParkingMeter* nMeter, ParkedCar* nCar) {
	if (nCar->getMinutesParked() > nMeter->getMinutesPaid()) {
		return true;
	}
	return false;
}