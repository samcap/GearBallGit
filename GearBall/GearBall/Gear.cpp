#include "Gear.h"
//#include "GearBall.h"
#include <string>
#include <iostream>


Gear::Gear()
{
}
Gear::~Gear()
{
}
void Gear::setColor(std::string colr) {
	color = colr;
}
void Gear::setStates(std::string st0, std::string st1, std::string st2, std::string st3, std::string st4, std::string st5) {

	states[0] = st0;
	states[1] = st1;
	states[2] = st2;
	states[3] = st3;
	states[4] = st4;
	states[5] = st5;
}

void Gear::setForward(int turn) {
	count+=turn;
	if (count == 0) {
		forward = states[0];
	}

	else if (count == 1) {
		forward = states[1];
	}
	else if (count == 2) {
		forward = states[2];
	}
	else if (count == 3) {
		forward = states[3];
	}
	else if (count == 4) {
		forward = states[4];
	}
	else if (count == 5) {
		forward = states[5];
	}
	else if (count == 6) {
		forward = states[0];
	}
	else if (count == -1) {
		forward = states[1];
	}
	else if (count == -2) {
		forward = states[2];
	}
	else if (count == -3) {
		forward = states[3];
	}
	else if (count == -4) {
		forward = states[4];
	}
	else if (count == -5) {
		forward = states[5];
	}
	else if (count == -6) {
		forward = states[0];
	}
	color = forward;
	if (count >= 6 || count <= -6) {
		count = 0;
	}
}
std::string Gear::getColor() {
	return(color);
}
std::string Gear::getForward() {
	return(forward);
}

