// This is the header file for PoliceOfficer class
#ifndef POLICE_OFFICER
#define POLICE_OFFICER

#include<string>

#include "ParkedCar.h"
#include "ParkingMeter.h"

using namespace std;

class PoliceOfficer {
private:
	string officerName;
	double officerNum;

public:
	//constructors
	PoliceOfficer();
	PoliceOfficer(string name);

	//setters
	void setOfficerNum();
	void setOfficerName(string name);

	//getters
	double getOfficerNum();
	string getOfficerName();

	//extra
	bool isInViolation(ParkingMeter* nMeter, ParkedCar* nCar);
};
#endif