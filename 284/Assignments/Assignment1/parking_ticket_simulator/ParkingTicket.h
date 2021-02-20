// This is the header file for ParkingTicket class

#ifndef PARKING_TICKET
#define PARKING_TICKET
#include<string>
#include "PoliceOfficer.h"
#include "ParkingMeter.h"
#include "ParkedCar.h"
using namespace std;

class ParkingTicket {
private:
	static int lastTicketNum;

	struct vehicle {
		string maker, model, color, plateNum;
		double minutesPaid, minutesParked;
	};

	double fine, officerNum, ticketNum;
	string officerName;
	vehicle* offenderPtr = new vehicle;

public:
	//constructor
	ParkingTicket(PoliceOfficer* nOfficer, ParkingMeter *nMeter, ParkedCar* offender);

	//setters
	void setOfficer(PoliceOfficer* nOfficer);
	void setOffender(ParkedCar* offender);
	void setFine(vehicle* offenderPtr);
	void setOffenderMaker(vehicle* offenderPtr, string maker);
	void setOffenderModel(vehicle* offenderPtr, string model);
	void setOffenderColor(vehicle* offenderPtr, string color);
	void setOffenderPlateNum(vehicle* offenderPtr, string plateNum);
	void setOffenderMinutesPaid(vehicle* offenderPtr, double minPaid);
	void setOffenderMinutesParked(vehicle* offenderPtr, int minParked);

	//getters
	double getFine();
	double getOfficerNum();
	string getOfficerName();
	double getTicketNum();
	string getOffenderMaker();
	string getOffenderModel();
	string getOffenderColor();
	string getOffenderPlateNum();
	double getOffenderMinutesPaid();
	double getOffenderMinutesParked();
};

#endif