#ifndef PRODUCTOIN_WORKER_H
#define	PRODUCTOIN_WORKER_H
#include<iostream>
#include<iomanip>
#include<string>
#include "Employee.h"
using namespace std;

class ProductionWorker : public Employee {
private:
	int shift; // The worker's shift
	double payRate; // The worker's hourly pay rate

public:
	// Default constructor
	ProductionWorker();			//ProductionWorker() : Employee(); <- THIS WOULD NOT WORK AS DEFAULT CONSTRUCTOR ?
	// Constructor
	ProductionWorker(string aName, string aDate, int aShift, double aPayRate);

	// Mutators
	void setShift(int s);
	void setPayRate(double r);
	static ProductionWorker* createNewProductionWorker();

	// Accessors
	int getShiftNumber() const;
	string getShiftName() const;
	double getPayRate() const;

	//******************************************************
	// The displayInfo function displays a production *
	// worker's employment information. *
	//******************************************************
	void displayInfo(ProductionWorker* e);
};
#endif