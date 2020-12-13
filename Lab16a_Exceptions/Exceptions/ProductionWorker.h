#ifndef PRODUCTOIN_WORKER_H
#define	PRODUCTOIN_WORKER_H
#include<iostream>
#include<iomanip>
#include<string>
#include "Employee.h"
using namespace std;

class ProductionWorker : public Employee {
private:
	double shift; // The worker's shift
	double payRate; // The worker's hourly pay rate

public:
	// Default constructor
	ProductionWorker();			//ProductionWorker() : Employee(); <- THIS WOULD NOT WORK AS DEFAULT CONSTRUCTOR ?
	// Constructor
	ProductionWorker(string aName, string aDate, int aShift, double aPayRate);

	// Mutators
	void setShift(double s);
	void setPayRate(double r);
	static ProductionWorker* createNewProductionWorker();

	// Accessors
	double getShiftNumber() const;
	string getShiftName() const;
	double getPayRate() const;

	//******************************************************
	// The displayInfo function displays a production *
	// worker's employment information. *
	//******************************************************
	void displayInfo(ProductionWorker* e);
};
#endif