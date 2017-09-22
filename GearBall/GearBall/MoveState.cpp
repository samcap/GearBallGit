#include "MoveState.h"
#include <iostream>



MoveState::MoveState()
{
}


MoveState::~MoveState()
{
}

void MoveState::setID(int id) {
	moveID = id;
}
void MoveState::setScore(int num) {
	score = num;
}
 int MoveState::getID() {
	 return moveID;
}
double MoveState::getScore() {
	return score;
}