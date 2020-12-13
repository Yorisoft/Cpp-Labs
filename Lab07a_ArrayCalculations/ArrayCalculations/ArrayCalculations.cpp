// Sample Program to Demonstrate Two-dimensional Arrays:
//    This program inputs numbers from a text file, 
//    places them in a 4x3 two dimensional array, and
//    displays the array contents.
//
//	Prof.Peter Morgan CSC 237
//	Yelsin S.
//	

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//  Global Constants:

// Status codes returned by several functions:
const int SUCCESS = 0;	// return code for SUCCESS
const int FAILURE = 1;  // return code for FAILURE
const int WRAP_AROUND = 2;  // Array "wrap-around"

double sumOfAllRows, sumOfAllColumns;

//   Two-dimensional array dimensions:
const int NUMBER_OF_COLUMNS = 4;
const int NUMBER_OF_ROWS = 3;

//  Function Prototypes:
void processFile();
int readNumbers(ifstream&, double[][NUMBER_OF_COLUMNS], int);
int printArrayContent(ostream&, double[][NUMBER_OF_COLUMNS], int, int);
double sumOfRows(ostream&, double[][NUMBER_OF_COLUMNS], int, int);
double sumOfColums(ostream&, double[][NUMBER_OF_COLUMNS], int, int);
int insertToArray(double[][NUMBER_OF_COLUMNS], int, int&, int&, double);

int main()
{
	cout << fixed << setprecision(1);
	processFile();           // Call function to process data.

	// Try to test the FAILIRE error case for insertToArray function:
	double testArray[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = { 0 };
	cout << endl;
	// Deliberately attempt to insert a number beyond the bounds of the array:
	int row = NUMBER_OF_ROWS + 1;
	int col = 0;
	double testData = 12.345;
	int testStatus = insertToArray(testArray, NUMBER_OF_ROWS, row, col, testData);
	if (testStatus == FAILURE) {
		cout << "(line " << __LINE__ << ")  TEST SUCCESSFUL:  Unable to insert data value "
			<< testData << " at position row=" << row << ", col=" << col << " in the array." << endl;
	}
	else {
		cout << "(line " << __LINE__ << ")  TEST FAILURE:  insertToArray returned unexpected status = "
			<< testStatus << " when attempting to insert data to an invalid location." << endl;
	}
	exit(SUCCESS);

}  // (end function 'main')



/*=============================================================================
*	Function:	processFile  -	 read and process file
*   Description:   Read numbers from input file into two-dimensional array.
*                  Display the array contents.
*---------------------------------------------------------------------------*/
void processFile()
{

	string inputFileName;
	int numberOfValuesInserted = 0;

	int fieldWidth = 12;     // Number of columns to display each number.

	// Input file stream object
	ifstream inFile;

	// Array to hold the numbers

	double numbers[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];

	// Input file:  prompt for filename, open file for input.
	cout << "Enter name of input file: ";
	cin >> inputFileName;
	inFile.open(inputFileName);

	// Check for file open error.
	if (inFile.fail())
	{
		cout << "(line " << __LINE__ << ") Error opening file:  " << inputFileName << endl;
		exit(FAILURE);
	}

	// Read the numbers into the array.
	numberOfValuesInserted = readNumbers(inFile, numbers, NUMBER_OF_ROWS);

	cout << numberOfValuesInserted << " numbers inserted into array from file " << inputFileName << endl;

	cout << endl << "Contents of array:" << endl;
	printArrayContent(cout, numbers, NUMBER_OF_ROWS, fieldWidth);


// ---------------------------------------------------------------------------------------------------------------------------------
	sumOfAllRows = sumOfRows(cout, numbers, NUMBER_OF_ROWS, fieldWidth);
	sumOfAllColumns = sumOfColums(cout, numbers, NUMBER_OF_ROWS, fieldWidth);

	cout << "SumOfAllRows = " << sumOfAllRows << endl
		<< "sumOfAllColumns = " << sumOfAllColumns << endl;


// -----------------------------------------------------------------------------------------------------------------------------------
	// Close the file.
	inFile.close();

	system("PAUSE");

}// (end function 'processFile')


// ********************************************************
// The readNumbers function reads numbers from inFile and 
// stores them in the numbers array.        
// The return value is the number of values actually INSERTED 
// into the array.
// ********************************************************
int readNumbers(ifstream& inFile, double numbers[][NUMBER_OF_COLUMNS], int numberOfRows)
{

	// Initialize the array to all zeroes
	for (int row = 0; row < numberOfRows; row++) {
		for (int col = 0; col < NUMBER_OF_COLUMNS; col++) {
			numbers[row][col] = 0.0;
		}
	}

	// Read data from file into array
	int row = 0, col = 0;
	int inputCount = 0;    // count of numbers that were read from the ifstream.
	int insertCount = 0;   // count of numbers that were inserted into the array.
	int insertStatus = SUCCESS;
	double temp;                // temporary variable for input data

	//   Continue reading from the input until "end-of-file".
	//   Insert the data into the array until the insertToArray 
	//              function returns any non-SUCCESS status.
	while (inFile >> temp) {
		inputCount++;
		if (insertStatus == SUCCESS) {
			insertStatus = insertToArray(numbers, numberOfRows, row, col, temp);
			if (insertStatus == FAILURE) {
				cout << "(line " << __LINE__ << ")  "
					<< "Unable to insert data value " << temp << " into array." << endl;
			}
			else {
				insertCount++;
			}
		}
		else {
			cout << "Data value " << temp << " was NOT inserted into array " << endl
				<< "because previous insert resulted in insertStatus=" << insertStatus << "." << endl;
		}

	} // end while
	if (inputCount != insertCount) {
		cout << endl << "Some data lost: inputCount=" << inputCount << ", insertCount=" << insertCount << endl;
	}

	return insertCount;
}// (end function 'readNumbers')

//_______________________________________________________________________
// Function:   insertToArray -- insert one data value into array.
// Inputs:     row, col = the position in the array to store inputValue.
// Outputs:    row, col = advanced to the position for the NEXT insert.
// Return status:    FAILURE if the input row or col values are illegal.
//                           The insert has NOT occurred.
//                   SUCCESS if insert occurred and row, col are advanced
//                            to the next valid position in the array.
//                   WRAP_AROUND if insert occurred and the row, col values 
//                            have "wrapped around" to the beginning of the array.
//
int insertToArray(double numbers[][NUMBER_OF_COLUMNS], int numberOfRows,
	int& row, int& col, double inputValue) {

	int insertStatus;
	if ((row >= numberOfRows) || (col >= NUMBER_OF_COLUMNS)
		|| (row < 0) || (col < 0)) {
		cout << "(line " << __LINE__ << ")  "
			<< "Cannot insert data value " << inputValue
			<< " into array at row=" << row << ", col=" << col << endl;
		insertStatus = FAILURE;
	}
	else {
		numbers[row][col] = inputValue;
		insertStatus = SUCCESS;
		// Attempt to advance to next column
		col++;
		if (col >= NUMBER_OF_COLUMNS) {
			// Wrap-around to beginning of next row.
			col = 0;
			row++;

			if (row >= numberOfRows) {
				row = 0;
				cout << "(line " << __LINE__ << ")  "
					<< "Wrap-around to beginning of array: "
					<< "row=" << row << ", col=" << col << endl;
				insertStatus = WRAP_AROUND;
			}
		}
	}
	return insertStatus;
} // (end function 'insertToArray')

// ********************************************************
// The printArray function outputs the contents of a 
// two-dimensional array to an ofstream object. 

// ********************************************************


// _______________________________________________________________________________________________________________________________________
int printArrayContent(ostream& output, double numbers[][NUMBER_OF_COLUMNS], int numberOfRows,
	int fieldWidth)
{
	int row, col, inputCount = 0;

	// Output the array contents to the ofstream object
	for (row = 0; row < numberOfRows; row++) {
		for (col = 0; col < NUMBER_OF_COLUMNS; col++) {
			output << setw(fieldWidth) << numbers[row][col];
		}
		output << endl;
	}

	return SUCCESS;
} // (end function 'printArray')

double sumOfRows(ostream& output, double numbers[][NUMBER_OF_COLUMNS], int numberOfRows,
	int fieldWidth)
{
	int row, col, inputCount= 0;
	double sum = 0, value = 0;

	// Output the array contents to the ofstream object
	for (row = 0; row < numberOfRows; row++) {
		for (col = 0; col < NUMBER_OF_COLUMNS; col++) {
			value = value + numbers[row][col];
		}
		output << "Sum of row " << row << " is " << value << endl;
		sum = sum + value;
		value = 0;
	}
	return sum;
}

double sumOfColums(ostream& output, double numbers[][NUMBER_OF_COLUMNS], int numberOfRows,
	int fieldWidth)
{
	int row, cols, inputCount = 0;
	double sum = 0, value = 0;

	// Output the array contents to the ofstream object
	for (row = 0; row < NUMBER_OF_COLUMNS; row++) {
		for (cols = 0; cols < numberOfRows; cols++) {
			value = value + numbers[cols][row];
		}
		output << "Sum of column " << row << " is " << value << endl;
		sum = sum + value;
		value = 0;
	}
	return sum; 
}