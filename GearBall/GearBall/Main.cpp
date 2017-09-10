#include <iostream>
#include <string>
#include "GearBall.h"
#include "Gear.h"


using namespace std;

int main() {

	GearBall ball;
	string input = "";
	cout << " Enter How many rotations would you like to randomize the gear ball: ";
	getline(cin, input);
	cout << endl;
	

	ball.randomize(stoi(input));
	ball.printBall();

	cin.ignore();


}
