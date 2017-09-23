#ifndef	MOVESTATE_H
#define MOVESTATE_H
#include <iostream>
#include <string>
#include "GearBall.h"
#include "Gear.h"

class MoveState
{
public:
	MoveState();
	~MoveState();
	void setState(GearBall state);
	void setScore(int g, int h);
	GearBall getState();
	int getScore();
private:
	GearBall myState;
	int score;
	int depth;
};
#endif

