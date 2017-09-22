#ifndef	GEARBALL_H
#define GEARBALL_H
#include <string>
#include "Gear.h"
#include "MoveState.h"
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
	int FindOutOfPlace();
	//soldve the ball using a*
	void SolveBall();
	void previousState();
	void reset();
	double futureMove(int move);
	
private:
	Gear faces[6][13];
	Gear LastState[6][13];
	Gear hState[6][13];
	Gear printFaces[6][13];
	int vertTurn;
	int horizTurn;
	int pvertTurn;
	int phorizTurn;
	int fverTurn;
	int fhorizTurn;
	mt19937 generator;
	int previousMove[3];
	int Move[3];
	bool isSolved = false;
};

#endif
