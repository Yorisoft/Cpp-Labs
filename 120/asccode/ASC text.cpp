#include <iostream>
#include<string>

using namespace std;

int main(){

	int number ;

	cin >> number ;

	cout << " The ASCII value of the" << number << "th letter is " << static_cast<char>(number);

	system("PAUSE");

}