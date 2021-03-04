#ifndef ARRAY_OPERATION
#define ARRAY_OPERATION
#include<string>
using namespace std;

class ArrayOperation {
	private:
		double (*twoDArray)[10];

	public:
		void populateArray();
		double getTotal();
		double getAverage();
		double getRowTotal(int row);
		double getColumnTotal(int col);
		double getHighestInRow(int row);
		double getLowestInRow(int row);
};

#endif