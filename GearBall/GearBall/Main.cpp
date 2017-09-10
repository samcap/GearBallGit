#include <iostream>
#include <string>
#include "GearBall.h"


using namespace std;

int main() {
	GearBall ball;
	//ball.rotate(0, 0, 12); //down
	ball.rotate(0, 1, 1); //up
	ball.rotate(0, 2, 1); //left
	//ball.rotate(0, 3, 12); //right
	//ball.rotate(1, 0, 12); // left stationary down
	//ball.rotate(1, 1, 12); // left stationary up
	//ball.rotate(2, 0, 12); // right stationary down
	//ball.rotate(2, 1, 12); // right stationary up
	//ball.rotate(3, 0, 12); // top stationary left
	//ball.rotate(3, 1, 12); //top stationary right
	//ball.rotate(4, 0, 12); // bottom stationary left
	//ball.rotate(4, 1, 12); // bottom stationary right
	

	ball.printBall();

	cin.ignore();


}
