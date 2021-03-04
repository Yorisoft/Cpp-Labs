// Restaurant Selector Excersice 1 
// Create a program that filters restaurant based on the diatary restrictions of the users.
// Prof Carmelito Moreno - CSC 284-H1
// Yelsin Sepulveda

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

struct Restaurant {
	string name;
	bool isVegetarian, isVegan, isGFree;
};

void pupulateRestaurantArray(Restaurant *allRestPtr);
void printAvilableRes(Restaurant *allResPtr, const int ARRAY_SIZE);
void printCompatibleRes(vector<string> compatibleRest);

int main() {
	const int MAX_NUM_OF_RESTAURANTS = 5;

	string answer;
	vector<string> compatibleRest;
	bool isVegan, isVeg, isGFree;
	Restaurant* allRestPtr = new Restaurant[MAX_NUM_OF_RESTAURANTS];

	pupulateRestaurantArray(allRestPtr);
	//printAvilableRes(allRestPtr, MAX_NUM_OF_RESTAURANTS);

	while (true) {
		cout << "Is anyone in your party a vergetarian? ";
		cin >> answer;
		isVeg = (answer == "yes" ? true : false);

		cout << "Is anyone in your party a vegan? ";
		cin >> answer;
		isVegan = (answer == "yes" ? true : false);

		cout << "Is anyone in your party a gluten-free? ";
		cin >> answer;
		isGFree = (answer == "yes" ? true : false);

		for (int y = 0; y < MAX_NUM_OF_RESTAURANTS; y++) {
			if ((isVegan == false && isVeg == false) && isGFree == false) { // no conditions needs to be met
				// add current restaurant to array
				compatibleRest.push_back((allRestPtr + y)->name);
				continue;
			}
			else if (isVegan == true && (allRestPtr + y)->isVegan != true) {	// continue to next restaurant if current one does not meet condition
				continue;
			}
			else if (isVeg == true && (allRestPtr + y)->isVegetarian != true) {
				continue;
			}
			else if (isGFree == true && (allRestPtr + y)->isGFree != true) {
				continue;
			}
			compatibleRest.push_back((allRestPtr + y)->name);
		}

		printCompatibleRes(compatibleRest);

		system("pause");
		delete[] allRestPtr;
	}
	return 0;
}

void pupulateRestaurantArray(Restaurant *allRestPtr) {

		allRestPtr->name = "Joe's Goermet Burgers";
		allRestPtr->isVegetarian = false;
		allRestPtr->isVegan = false;
		allRestPtr->isGFree = false;

		allRestPtr++;

		allRestPtr->name = "Main Street Pizza Company";
		allRestPtr->isVegetarian = true;
		allRestPtr->isVegan = false;
		allRestPtr->isGFree = true;

		allRestPtr++;

		allRestPtr->name = "Corner Cafe";
		allRestPtr->isVegetarian = true;
		allRestPtr->isVegan = true;
		allRestPtr->isGFree = true;

		allRestPtr++;

		allRestPtr->name = "Mama's Fine Italian";
		allRestPtr->isVegetarian = true;
		allRestPtr->isVegan = false;
		allRestPtr->isGFree = false;

		allRestPtr++;

		allRestPtr->name = "The Chef's Kitchen";
		allRestPtr->isVegetarian = true;
		allRestPtr->isVegan = true;
		allRestPtr->isGFree = true;
}

void printAvilableRes(Restaurant *allResPtr, const int ARRAY_SIZE) {
	string yes = "Yes", no = "No";

	cout << "List of available Restaurants.. \n";
	for (int y = 0; y < ARRAY_SIZE; y++) {
		cout << (allResPtr + y)->name
			<< " - Vegetarian: " << ((allResPtr + y)->isVegetarian == 0 ? "No" : "Yes")
			<< ", Vegan: " << ((allResPtr + y)->isVegan == 0 ? "No" : "Yes")
			<< ", Gluten-Free: " << ((allResPtr + y)->isGFree == 0 ? "No" : "Yes")
			<< endl << endl;
	}
}

void printCompatibleRes(vector<string> compatibleRest) {
	cout << "Here are your restaurant choirces: " << endl;
	for (int y = 0; y < compatibleRest.size(); y++) {
		cout << "\t" << compatibleRest[y] << endl;
	}
}