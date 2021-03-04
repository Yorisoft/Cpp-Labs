// This is the implementation file for ParkingTicket class

#include<iostream>
#include<string>
#include "PoliceOfficer.h"
#include "ParkingTicket.h"
#include "ParkedCar.h"
using namespace std;

int ParkingTicket::lastTicketNum = 0;

ParkingTicket::ParkingTicket(PoliceOfficer *nOfficer, ParkingMeter *nMeter, ParkedCar* offender) {
	lastTicketNum++;	
	ticketNum = lastTicketNum;

	// set values of the officer and offender (standard way)
	this->setOfficer(nOfficer);
	this->setOffender(offender);
	 
	this->setOffenderMinutesPaid(offenderPtr, nMeter->getMinutesPaid());
	this->setFine(offenderPtr);
}

//setters
void ParkingTicket::setOfficer(PoliceOfficer* nOfficer) {
	officerNum = nOfficer->getOfficerNum();
	officerName = nOfficer->getOfficerName();
}
void ParkingTicket::setOffender(ParkedCar* offender) {
	this->setOffenderMaker(offenderPtr, offender->getMaker());
	this->setOffenderModel(offenderPtr, offender->getModel());
	this->setOffenderColor(offenderPtr, offender->getColor());
	this->setOffenderPlateNum(offenderPtr, offender->getPlateNum());
	this->setOffenderMinutesParked(offenderPtr, offender->getMinutesParked());
}
void ParkingTicket::setFine(vehicle* offenderPtr) {
	int timeExceeded;

	timeExceeded = offenderPtr->minutesParked - offenderPtr->minutesPaid;
	//default to 25 since the need for ticket has been met
	fine = 25;

	timeExceeded = timeExceeded - 60;

	for (int y = 0; y < timeExceeded; y+=60) {
		fine = fine + 10;
	}
}
void ParkingTicket::setOffenderMaker(vehicle* offenderPtr, string maker) {
	offenderPtr->maker = maker;
}
void ParkingTicket::setOffenderModel(vehicle* offenderPtr, string model) {
	offenderPtr->model = model;
}
void ParkingTicket::setOffenderColor(vehicle* offenderPtr, string color) {
	offenderPtr->color = color;
}
void ParkingTicket::setOffenderPlateNum(vehicle* offenderPtr, string plateNum) {
	offenderPtr->plateNum = plateNum;
}
void ParkingTicket::setOffenderMinutesPaid(vehicle* offenderPtr, double minPaid) {
	offenderPtr->minutesPaid = minPaid;
}
void ParkingTicket::setOffenderMinutesParked(vehicle* offenderPtr, int minParked) {
	offenderPtr->minutesParked = minParked;
}

//getters
double ParkingTicket::getFine() {
	return this->fine;
}
string ParkingTicket::getOfficerName() {
	return this->officerName;
}
double ParkingTicket::getOfficerNum() {
	return this->officerNum;
}
double ParkingTicket::getTicketNum() {
	return this->ticketNum;
}
string ParkingTicket::getOffenderMaker() {
	return offenderPtr->maker;
}
string ParkingTicket::getOffenderModel() {
	return offenderPtr->model;
}
string ParkingTicket::getOffenderColor() {
	return offenderPtr->color;
}
string ParkingTicket::getOffenderPlateNum() {
	return offenderPtr->plateNum;
}
double ParkingTicket::getOffenderMinutesPaid() {
	return offenderPtr->minutesPaid;
}
double ParkingTicket::getOffenderMinutesParked() {
	return offenderPtr->minutesParked;
}