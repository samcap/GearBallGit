#ifndef	GEARBALL_H
#define GEARBALL_H
#include <string>
#include "Gear.h"
using namespace std;

class GearBall 
{
public:
	GearBall();
	~GearBall();
	void printBall();
	void rotate(int col, int direction, int turn);
	void randomize(int turns);
	void sideRotate(int rot);
	void copyStates();
	void setGears();
	


private:
	Gear faces[6][13];
	Gear LastState[6][13];
	Gear printFaces[6][13];
	int vertTurn;
	int horizTurn;
};

#endif
