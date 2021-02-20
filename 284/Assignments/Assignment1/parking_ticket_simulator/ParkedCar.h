#ifndef PARKED_CAR
#define PARKED_CAR

using namespace std;

class ParkedCar {
private:
	int minutesParked;
	string maker, model, color, plateNum;

public:
	ParkedCar();

	void setMinutesParked();
	void setMaker();
	void setModel();
	void setColor();
	void setPlateNum();

	int getMinutesParked();
	string getMaker();
	string getModel();
	string getColor();
	string getPlateNum();
};

#endif
