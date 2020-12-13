#include <iostream>
#include <string>
using namespace std;
//   C++ "Bad Pointer" Demonstration: 
//                       Demonstration of WHY a function should never 
//                       return a pointer to a local variable. 

// Function Prototypes
int product ();
int *badSumPtr(int param1, int param2);
int *dynamicSumPtr(int param1, int param2);

int main()
{
	int number1 = 4;
	int number2 = 5;
	int *resultPtr;

	resultPtr = badSumPtr(number1, number2);
	cout << "(line "<<__LINE__<<"):  FIRST resultPtr=" << resultPtr 
		<< ", result value is " << *resultPtr << endl<< endl;
	cout << "(line " << __LINE__ << "):  'product' function returns " << product() << endl<<endl;
	cout << "(line " << __LINE__ << "):  SECOND resultPtr=" << resultPtr
		<< ", result value is " << *resultPtr << endl << endl;

	system("pause");
//_______________________________________________________
	cout << "______________________________________________" << endl;

	resultPtr = dynamicSumPtr(number1, number2);
	cout << "(line " << __LINE__ << "):  THIRD resultPtr=" << resultPtr 
		<< ", result value is " << *resultPtr << endl<< endl;
	cout << "(line " << __LINE__ << "):  'product' function returns " << product() << endl<<endl;
	cout << "(line " << __LINE__ << "):  FOURTH resultPtr=" << resultPtr 
		<< ", result value is " << *resultPtr << endl << endl;

	
} // (end main)

// Simple function which uses local variables
int product ()
{
	int data1 = 5;
	int data2 = 8;
	int outputValue;
	outputValue = data1 * data2;
	cout << "(line " << __LINE__ << "):  &data1=" << &data1 << ", ";
	cout << "&data2=" << &data2 << ", ";
	cout << "&outputValue=" << &outputValue << endl;
	return outputValue;
}

// Function which returns a pointer to a local variable (BAD idea).
int *badSumPtr(int param1, int param2)
{
	int sum;
	sum = param1 + param2;
	cout << "(line " << __LINE__ << "):  Address of sum variable=" <<&sum<< ", Value of sum variable="<<sum<<endl;
	return &sum;
}

// Function which returns a pointer to dynamically allocated variable.
int *dynamicSumPtr(int param1, int param2)   
{
	int *sumPtr;
	sumPtr = new int;
	*sumPtr = param1 + param2;
	cout << "(line " << __LINE__ << "):  sumPtr="<<sumPtr<<", Value that sumPtr points to=" <<*sumPtr<<endl;
	return sumPtr;
}     