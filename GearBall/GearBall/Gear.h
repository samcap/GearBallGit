#ifndef	GEAR_H
#define GEAR_H
//#include "GearBall.h"
#include <string> 
class Gear
{
public:
	Gear();
	~Gear();
	void setColor(std::string colr);
	void setStates(std::string st0, std::string st1, std::string st2, std::string st3, std::string st4, std::string st5);
	void setForward(int count);
	std::string getColor();
	std::string getForward();

private:
	std::string color;
	std::string forward;
	std::string states[6];
	
	
};
#endif

