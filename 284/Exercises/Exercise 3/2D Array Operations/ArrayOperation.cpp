#include<iomanip>
#include<iostream>
#include<math.h>
#include "ArrayOperation.h"
using namespace std;

void ArrayOperation::populateArray() {
	twoDArray = new double[5][10] {
		1,  6,  7,  8,  9, 10, 11, 12, 13, 14,
		2, 16, 17, 18, 19, 20, 21, 22, 23, 24,
		3, 25, 26, 27, 28, 29, 30, 31, 32, 33,
 		4, 34, 35, 36, 37, 38, 39, 40, 41, 42,
		5, 43, 44, 45, 46, 47, 48, 49, 51, 55
	};
}
double ArrayOperation::getTotal() {
	double total = 0;

	for (int y = 0; y < 5; y++) {
		for (int e = 0; e < 10; e++) {
			total = (total + twoDArray[y][e]);
		}
	}
	return total;
}
double ArrayOperation::getAverage() {
	double sum = this->getTotal();
	return (sum / 50);
}
double ArrayOperation::getRowTotal(int row) {
	double rowTotal = 0;

	for (int y = 0; y < 10; y++) {
		rowTotal = (rowTotal + twoDArray[row-1][y]);
	}
	return rowTotal;
}
double ArrayOperation::getColumnTotal(int col) {
	double colTotal = 0;

	for (int y = 0; y < 5; y++) {
		colTotal = (colTotal + twoDArray[y][col - 1]);
	}
	return colTotal;
}
double ArrayOperation::getHighestInRow(int row) {
	double highestInRow;
	highestInRow = twoDArray[row-1][0];

	for (int y = 0; y < 10; y++) {
		if (twoDArray[row - 1][y] > highestInRow) {
			highestInRow = twoDArray[row - 1][y];
		}
	}
	return highestInRow;
}
double ArrayOperation::getLowestInRow(int row) {
	double lowestInRow;
	lowestInRow = twoDArray[row - 1][0];

	for (int y = 0; y < 10; y++) {
		if (twoDArray[row - 1][y] < lowestInRow) {
			lowestInRow = twoDArray[row - 1][y];
		}
	}
	return lowestInRow;
}