// Parking Ticket Similator - Assignment 1 
// This program uses four classes to emulate an officer issuing parking tickets. 
// Prof Carmelito Moreno - CSC 284-H1
// Yelsin Sepulveda

#include<chrono>
#include<iostream>
#include<string>

#include "PoliceOfficer.h"
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
using namespace std;

void printBanner();
void printParkingTicket(ParkingTicket* nParkingTicketPtr);

int main() {
	string choice = "yes", nOfficerName;
	double officeBadgeNum;
	PoliceOfficer* nOfficerPtr = NULL;
	ParkedCar* nParkedCarPtr = NULL;
	ParkingMeter* nParkingMeterPtr = NULL;
	ParkingTicket* nParkingTicketPtr = NULL;

	printBanner();
	cout << "Please enter a name for the officer: ";
	getline(cin, nOfficerName);

	// Create new instance of PoliceOfficer
	nOfficerPtr = new PoliceOfficer(nOfficerName);

	cout << " Officer: " << nOfficerPtr->getOfficerName() << endl
		<< " Badge Number:  " << nOfficerPtr->getOfficerNum() << endl << endl;
		

	while (choice[0] == 'y' || choice[0] == 'Y') {
		cout << "Starting Meter inspections.." << endl;

		// Create new instace of ParkedCar
		nParkedCarPtr = new ParkedCar;
		cout << "Vehicle: " << endl
			<< "\t" << "Make: " << nParkedCarPtr->getMaker() << endl
			<< "\t" << "Model: " << nParkedCarPtr->getModel() << endl
			<< "\t" << "Color: " << nParkedCarPtr->getColor() << endl
			<< "\t" << "Plate Number: " << nParkedCarPtr->getPlateNum() << endl
			<< "\t" << "Minutes Parked: " << nParkedCarPtr->getMinutesParked() << endl;

		// Create new instace of ParkingMeter
		nParkingMeterPtr = new ParkingMeter;
		cout << "Parking Meter: " << endl
			<< "\t" << "Minutes Paid: " << nParkingMeterPtr->getMinutesPaid() << endl << endl;

		if (nOfficerPtr->isInViolation(nParkingMeterPtr, nParkedCarPtr)) {
			cout << "The parking meter has expired.. Issuing the vehicle a ticket.." << endl << endl;
			cin.get();

			nParkingTicketPtr = new ParkingTicket(nOfficerPtr, nParkingMeterPtr, nParkedCarPtr);
			cout << "Printing parking ticket.." << endl << endl;
			cin.get();

			printParkingTicket(nParkingTicketPtr);
		}

		cout << "Should officer " << nOfficerPtr->getOfficerName() << " continue inspecting meters ? [Y/n]";
		getline(cin, choice); 
	}
	cout << "Stopping meter inspection..";
	delete nOfficerPtr;
	delete nParkedCarPtr;
	delete nParkingMeterPtr;
	delete nParkingTicketPtr;
	system("pause");
	return 0;

}
void printBanner() {
	cout << "\t\t     This program simiulates an officer inspecting parking meeters     " << endl
		 << "\t\t and issuing parking tickets to vehicles that have exceeded their time " << endl << endl;
}
void printParkingTicket(ParkingTicket* nParkingTicketPtr) {
	cout << '\t' << "  Parking Ticket: " << nParkingTicketPtr->getTicketNum() << endl
		 << '\t' << "  Officer: " << nParkingTicketPtr->getOfficerName() 
		 << " #" << nParkingTicketPtr->getOfficerNum() << endl;

	cout << "Vehicle: " << endl
		<< '\t' << "  Make: " << nParkingTicketPtr->getOffenderMaker() << endl
		<< '\t' << "  Model: " << nParkingTicketPtr->getOffenderModel() << endl
		<< '\t' << "  Color: " << nParkingTicketPtr->getOffenderColor() << endl
		<< '\t' << "  License plate number: " << nParkingTicketPtr->getOffenderPlateNum() << endl;

	cout << "Fine: " << endl
		<< '\t' << "  Paid for: " << nParkingTicketPtr->getOffenderMinutesPaid() << endl
		<< '\t' << "  Time parked: " << nParkingTicketPtr->getOffenderMinutesParked() << endl
		<< '\t' << "  Fine total: " << nParkingTicketPtr->getFine() << endl << endl;
		
}