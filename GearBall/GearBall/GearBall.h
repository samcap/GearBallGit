#ifndef	GEARBALL_H
#define GEARBALL_H

class GearBall
{
public:
	GearBall();
	~GearBall();
	void printBall();
	void rotate(int col, int direction, int turn);
	void randomize(int turns);
	void sideRotate(int direction);
	void copyStates();


private:
	char faces[6][13];
	char LastState[6][13];
};

#endif
