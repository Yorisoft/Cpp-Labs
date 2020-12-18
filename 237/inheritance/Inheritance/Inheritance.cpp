// Your code for this lab exercise must use the Employee class, 
// but you may not modify the Employee class for this lab exercise.
// Write a class named ProductionWorker that is a sub-class of the Employee class

#include<string>
#include<iostream>
#include<vector>
#include "ProductionWorker.h"
using namespace std;

void printSupportedCommands();
ProductionWorker* createProducitonWorker();

int main() {
	system("color 70");

	char runCommand = ' ';
	ProductionWorker* prodWrokerPtr = NULL;
	vector<ProductionWorker*> workerList;

	while (runCommand != 'q') {
		cout << "Enter command (or 'h' for help): ";
		cin >> runCommand; cin.ignore(100, '\n');

		switch (runCommand) {
		case 'c': 
			prodWrokerPtr = createProducitonWorker();	// Does not work when using arguments ??
			workerList.push_back(prodWrokerPtr);
			break;
		case 'h':
			printSupportedCommands();
			break;
		case 'p':
			cout << prodWrokerPtr << endl;
			prodWrokerPtr->displayInfo(prodWrokerPtr);
			break;
		case 'q':
			for (int y = 0; y < workerList.size(); y++) {
				cout << "Deleting ProductinWorker class: " << workerList[y] << endl;
				delete workerList[y];
			}
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

void printSupportedCommands() {
	cout << "Supported Commands: \n"
		<< "\tc" << "\t\tcreate a new ProductionWorker object." << endl
		<< "\th" << "\t\tprint help text." << endl
		<< "\tp" << "\t\tprint Production Worker information." << endl
		<< "\tq" << "\t\tquit (end the program)." << endl << endl;
}

ProductionWorker* createProducitonWorker() {
	ProductionWorker* worker;

	worker = ProductionWorker::createNewProductionWorker();
	return worker;
}