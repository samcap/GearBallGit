#include <iostream>
#include "GearBall.h"


using namespace std;

int main() {
	GearBall ball;
	ball.rotate(0, 1, 2);
	ball.rotate(0, 3, 1);
	ball.rotate(0, 2, 1);
	ball.rotate(0, 0, 2);


	ball.printBall();

	cin.ignore();


}
