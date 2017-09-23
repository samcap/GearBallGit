#include "MoveState.h"
#include <iostream>
#include <string>
#include "GearBall.h"
#include "Gear.h"



MoveState::MoveState()
{
}
MoveState::~MoveState()
{
}
void MoveState::setState(GearBall state) {
	myState = state;
}
void MoveState::setScore(int g, int h) {
	depth = g;
	score = g+h;
}
 GearBall MoveState::getState() {
	 return myState;
}
int MoveState::getScore() {
	return score;
}