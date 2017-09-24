#ifndef	GEARBALL_H
#define GEARBALL_H
#include <string>
#include "Gear.h"

#include <random>
#include <ctime>
using namespace std;

class GearBall 
{
public:

	GearBall();
	~GearBall();
	//Print the current ball state
	void printBall();
	//rotate the cube based on a stationary colomn, rotation direction, and the amount of turns
	void rotate(int col, int direction, int turn);
	//randomzie the gear ball
	void randomize(int turns);
	//rotate the correspondings sides after a move
	void sideRotate(int rot);
	//create a copy of the current state
	void copyStates();
	//orient the edge gear pices
	void setGears();
	//Find the number of out of place gears realtive to center.
	double FindOutOfPlace();
	//set the faces of a diffrent gearball
	void setFace(Gear state[6][13], int vertical, int horizontal);
	//grab the face of the gearball
	void getFace(Gear (*temp)[6][13],int *vertical, int *horizontal);
	//set the depth of a gearball state
	void setDepth(int n);
	//retrive the depth of the gearball state
	int getDepth();
	//calcualte the heuristic cost
	void cost(double h);
	double f = 0;
	string typeOfMove = "";
	
private:
	Gear faces[6][13];
	Gear LastState[6][13];
	Gear printFaces[6][13];
	int depth;
	int vertTurn = 0;
	int horizTurn = 0;
	mt19937 generator;
	int previousMove[3];
	int Move[3];
	bool isSolved = false;
};

#endif
