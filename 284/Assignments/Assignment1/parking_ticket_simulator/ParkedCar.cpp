//

#include<string>
#include <vector>
#include <algorithm>
#include "ParkedCar.h"
using namespace std;

//constructor
ParkedCar::ParkedCar() {
	//initializing private vars
	//set random value for minutesParked
	this->setMinutesParked();
	this->setMaker();
	this->setModel();
	this->setColor();
	this->setPlateNum();
}

//setters
void ParkedCar::setMinutesParked() {
	minutesParked = (1.0 * (rand() % 1 + 720));
}
void ParkedCar::setMaker() {
	maker = "Tesla";
}
void ParkedCar::setModel() {
	model = "Roadster";
}
void ParkedCar::setColor() {
	unsigned seed = 0;
	vector<string> allColors = { "Red", "Blue", "Black", "Yellow", "white"};
	
	shuffle(allColors.begin(), allColors.end(), seed);
	color = allColors[0];
}
void ParkedCar::setPlateNum() {
	plateNum = ((rand() % 10000 + 99999));
}

//getters
int ParkedCar::getMinutesParked() {
	return minutesParked;
}
string ParkedCar::getMaker() {
	return maker;
}
string ParkedCar::getModel() {
	return model;
}
string ParkedCar::getColor() {
	return color;
}
long int ParkedCar::getPlateNum() {
	return plateNum;
}