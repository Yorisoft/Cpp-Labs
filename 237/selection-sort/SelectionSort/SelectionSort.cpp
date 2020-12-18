//The goal of this lab is to help get familiar with sorting data in an array.
//	Prof.Peter Morgan CSC 237
//	Yelsin S.
//	

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

void selectionSort(vector<string> &array, int size);
void showArray(vector<string> &array, int);
int main() {
	vector<string> names;
	string temp, fileName;
	ifstream inFile;
	int index;

	while (true) {
		cout << "Enter the name of the file to read from: ";
		cin >> fileName;

		inFile.open(fileName);
		while (inFile.fail()) {
			cout << "(line " << __LINE__ << ") Error opening file:  " << fileName << endl
				<< "Enter the name of the file to read from : ";
			cin >> fileName;
			inFile.open(fileName);
		}

		for (int y = 0; !inFile.eof(); y++) {	// .eof to check  that we have not reached end of file.
			string temp;
			getline(inFile, temp);		// input line into string at y index
			names.push_back(temp);
		}

		for (int y = 0; !names[y].empty(); y++) {	// !names[y].empty() to check  that we have reached end of non empty elements.
			//getline(inFile, names[y]);
			cout << "[ " << y << "] "<< names[y] << endl;		// output name out to console.
		}

		selectionSort(names, (names.size() - 1));

		system("PAUSE");
		inFile.close();
	}

	return 0;
}

void selectionSort(vector<string> &array, int size) {
	string minValue;
	int minIndex, startScan;
	int pass = 0;
	int swapCount = 0;
	for (startScan = 0; startScan < size - 1; startScan++)
	{
		pass++;
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		cout << "Pass " << pass << ": swap [" << minIndex << "] "
			<< array[minIndex] << " with [" << startScan << "] "
			<< array[startScan] << "." << endl;
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
		swapCount++;
	}
	cout << "   Modified array: " << endl;
	showArray(array, size);
	cout << "Total passes = " << pass
		<< "    Total swaps = " << swapCount << endl;
}

void showArray(vector<string> &array, int size) {
	for (int count = 0; count < size; count++)
		cout << array[count] << " " << endl;
	cout << endl;
}