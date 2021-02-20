#ifndef PARKING_METER
#define PARKING_METER
#include<string>
using namespace std;

class ParkingMeter {
private:
	double minutesPaid;

public: 
	//constructor 
	ParkingMeter();

	//setter
	void setMinutesPaid();

	//getter
	double getMinutesPaid();
};

#endif
