// This lab ask users for personal info and calculates the data to determine the persons club eligibility. 
// If Statement Lab - Club Admission Lab.
// Developer: Yelsin Sepulveda.
// Last modified: 06/26/2017

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	system("title  If Statement Lab - Club Admission Lab.  by Yelsin S.");
	system("color 70");
	
	const int 
		MINIMUM_AGE = 21,
		MAX_AGE = 40;
	double age;
	string name;

	// banner
	cout << endl
		<< "\t              The \"club admission\" lab                 \n"
		<< "\t              note that age is a double                  \n" 
		<< "\t                needs an if ... else                     \n" 
		<< "\t           Loops for ever for easy testing               \n" 
		<< "\t          used names const for easy updates              \n" 
		<< "\t  ONLY customurs with age in [" << MINIMUM_AGE << ',' << MAX_AGE << ") are allowed in    \n"
		<< "\t                    by Yelsin S.                         " << endl;

	while (true) {
		cout << "\nWhat is your FULL name? "; // Ask user for name
		getline(cin >> ws, name);

		cout << "How old are you \"" << name << "\"? "; // Ask user for age.
		cin >> age; cin.ignore(100, '\n');

		if (age >= MINIMUM_AGE && age < MAX_AGE) {
			cout << "\t Welcome to the club " << name << "!" << "\nNext Customer please! \n";
		}
		else {
			cout << "\t Sorry, you need to be between " << MINIMUM_AGE << " (INclusive) and " << MAX_AGE << " (EXclusive)\n\t to be eligible to enter this establishment! \n" 
				<< "\nNext Customer please! \n";
		}

		system("pause");
		cout << endl << endl; // Space for rerunning the program.
	}
	return 0;
}