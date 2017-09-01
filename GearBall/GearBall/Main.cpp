#include <iostream>
#include "GearBall.h"


using namespace std;

int main() {
	GearBall ball;
	//ball.printBall();
	ball.rotate(0, 0, 1);
	ball.rotate(0, 1, 1);
	ball.printBall();
	cin.ignore();


}
