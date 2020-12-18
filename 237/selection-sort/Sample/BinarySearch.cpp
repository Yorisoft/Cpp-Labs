// This program demonstrates the binarySearch function, which performs a
// binary search on an integer array.  (Adapted from Program 8-2)
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
int binarySearch(const int[], int, int);
void printArray(int[], int, int);

int main()
{

	const int SIZE = 20;
	const int COLUMNS = 5;
	const int EMPLOYEE_ID_SENTINEL = -1;    // Special value to end program.

	// Array with employee IDs sorted in ascending order.
	int idNums[SIZE] = { 101, 142, 147, 189, 199, 207, 222,
						234, 289, 296, 310, 319, 388, 394,
						417, 429, 447, 521, 536, 600 };
	int results;   // To hold the search results
	int empID = 0;     // To hold an employee ID

	while (empID != EMPLOYEE_ID_SENTINEL) {
		printArray(idNums, SIZE, COLUMNS);

		// Get an employee ID to search for.
		cout << "Enter employee ID (or -1 to exit): ";
		cin >> empID;
		if (empID == EMPLOYEE_ID_SENTINEL) {
			continue;
		}

		// Search for the ID.
		results = binarySearch(idNums, SIZE, empID);

		// If results contains -1 the ID was not found.
		if (results == -1)
			cout << "That number does not exist in the array.\n";
		else
		{
			// Otherwise the "results" variable contains the 
			// subscript of the specified employee ID in the array.
			cout << "That ID is found at element " << results;
			cout << " in the array.\n";
		}
	}
	return 0;
}

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of size elements,  *
// is searched for the number stored in value. If the number is *
// found, its array subscript is returned. Otherwise, -1 is     *
// returned indicating the value was not in the array.          *
//***************************************************************

int binarySearch(const int array[], int size, int value)
{
	int first = 0,             // First array element
		last = size - 1,       // Last array element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;        // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // Calculate mid point
		cout << "first=" << setw(2) << first
			<< ", middle=" << setw(2) << middle
			<< ", last=" << setw(2) << last << endl;
		if (array[middle] == value)      // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)  // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;           // If value is in upper half
	}
	return position;
} // (end function binarySearch)

/*
*   The printArray function prints the contents of an array,
*   with itemsPerLine items per line.   The function also displays the index
*   of each item.
*
*/
void printArray(int dataArray[], int size, int itemsPerLine) {
	for (int i = 0; i < size; i++) {
		cout << setw(8) << i << ": " << setw(4) << dataArray[i];
		if (i%itemsPerLine == (itemsPerLine - 1)) {
			cout << endl;
		}
	}
	if (size % itemsPerLine != 0) {
		cout << endl;
	}
} // (end function printArray)