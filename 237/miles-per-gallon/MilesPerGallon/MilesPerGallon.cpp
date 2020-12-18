// This program calculates the users miles per gallon

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	while (true) {
		double latest_ODM_reading, 
			previous_ODM_reading, gallons_purchased;

		cout << "\t\t\t\t This program calculates the users miles per gallon \n\n";

		cout << "Enter Odometer at PREVIOUS fill-up: ";
		cin >> previous_ODM_reading; cin.ignore(100, '\n');
		cout << "Enter Odometer at LATEST fill-up: ";
		cin >> latest_ODM_reading; cin.ignore(100, '\n');

		cout << "Distance travelled = " << fixed << setprecision(1)
			<< latest_ODM_reading - previous_ODM_reading << " miles. \n";

		cout << "Enter gallons purchased at LATEST fill-up: ";
		cin >> gallons_purchased; cin.ignore(100, '\n');
		
		cout << "Your fuel economy is: " << (latest_ODM_reading - previous_ODM_reading) / gallons_purchased << " MPG. \n\n";	

		system("PAUSE");
	}
}
