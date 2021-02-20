#ifndef PARKING_METER
#define PARKING_METER

using namespace std;

class ParkingMeter {
private:
	long int minutesPaid;

public: 
	//constructor 
	ParkingMeter();

	//setter
	void setMinutesPaid();

	//getter
	long int getMinutesPaid();
};

#endif
