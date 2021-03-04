//

#include<string>
#include <vector>
#include <algorithm>
#include<cstdlib>
#include <random>
#include <sstream>

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
	minutesParked = rand() % 720 + 1;
}
void ParkedCar::setMaker() {
	maker = "Tesla";
}
void ParkedCar::setModel() {
	model = "Roadster";
}
void ParkedCar::setColor() {
	unsigned seed = rand() % 6 + 0;
	vector<string> allColors = { "Red", "Blue", "Black", "Yellow", "White", ""};
	
	shuffle(allColors.begin(), allColors.end(), 
		std::default_random_engine(seed));
	color = allColors[0];
}

void ParkedCar::setPlateNum() {
	plateNum = "MA-";
	ostringstream convert;
	int randNum;

	randNum = rand() % 5000 + 4999;
	convert << randNum;
	plateNum = plateNum + convert.str();
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
string ParkedCar::getPlateNum() {
	return plateNum;
}