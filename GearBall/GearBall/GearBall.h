#ifndef	GEARBALL_H
#define GEARBALL_H
#include <string>

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
	void gearFormat(); 


private:
	std::string faces[6][13];
	std::string LastState[6][13];
	std::string printFaces[6][13];
	int vertTurn;
	int horizTurn;
};

#endif
