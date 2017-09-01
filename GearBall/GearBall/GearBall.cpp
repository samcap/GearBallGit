#include <iostream>
#include "GearBall.h"

using namespace std;
GearBall::GearBall()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 13; j++) {
			if (i == 0) {
				faces[i][j] = 'O';
			}
			else if (i == 1) {
				faces[i][j] = 'R';
			}
			else if (i == 2) {
				faces[i][j] = 'P';
			}
			else if (i == 3) {
				faces[i][j] = 'Y';
			}
			else if (i == 4) {
				faces[i][j] = 'B';
			}
			else {
				faces[i][j] = 'G';
			}
			
		}
	}
	copyStates();
}


GearBall::~GearBall()
{
}
void GearBall::rotate(int col, int direction, int turn) {
	
	for(int i = 0; i < turn; i++){

		/*Center coloum stationary and moving down 
		Faces 0,1,2,3 are effected and spots 0 1 2 3 
		are changed from bottom and spots 9 10 11 12 are
		changed from top*/
		if (col == 0 && direction == 0) {
			/*--------update face(0)------------*/
			/*Left side*/
			faces[0][0] = LastState[2][0];
			faces[0][1] = LastState[2][1];
			faces[0][2] = LastState[2][2];
			faces[0][3] = LastState[2][3];

			/*Right side*/
			faces[0][9] = LastState[1][9];
			faces[0][10] = LastState[1][10];
			faces[0][11] = LastState[1][11];
			faces[0][12] = LastState[1][12];

			/*----------update top(1)----------*/
			/*Left side*/
			faces[1][0] = LastState[0][0];
			faces[1][1] = LastState[0][1];
			faces[1][2] = LastState[0][2];
			faces[1][3] = LastState[0][3];

			/*Right side*/
			faces[1][9] = LastState[3][9];
			faces[1][10] = LastState[3][10];
			faces[1][11] = LastState[3][11];
			faces[1][12] = LastState[3][12];

			/*----------update back(3)----------*/
			/*Left side*/
			faces[3][0] = LastState[1][0];
			faces[3][1] = LastState[1][1];
			faces[3][2] = LastState[1][2];
			faces[3][3] = LastState[1][3];

			/*Right side*/
			faces[3][9] = LastState[2][9];
			faces[3][10] = LastState[2][10];
			faces[3][11] = LastState[2][11];
			faces[3][12] = LastState[2][12];

			/*----------update bottom(2)----------*/
			/*Left side*/
			faces[2][0] = LastState[3][0];
			faces[2][1] = LastState[3][1];
			faces[2][2] = LastState[3][2];
			faces[2][3] = LastState[3][3];

			/*Right side*/
			faces[2][9] = LastState[0][9];
			faces[2][10] = LastState[0][10];
			faces[2][11] = LastState[0][11];
			faces[2][12] = LastState[0][12];

			copyStates();
		}
		/*Center coloum stationary and moving up
		Faces 0 1 2 3 are are effected and spots 0 1 2 3 
		are changed from top and spots 9 10 11 12 are
		changed from bottom*/ 
		else if (col == 0 && direction == 1) {
			/*--------update face(0)------------*/
			/*Left side*/
			faces[0][0] = LastState[1][0];
			faces[0][1] = LastState[1][1];
			faces[0][2] = LastState[1][2];
			faces[0][3] = LastState[1][3];

			/*Right side*/
			faces[0][9] = LastState[2][9];
			faces[0][10] = LastState[2][10];
			faces[0][11] = LastState[2][11];
			faces[0][12] = LastState[2][12];

			/*----------update top(1)----------*/
			/*Left side*/
			faces[1][0] = LastState[3][0];
			faces[1][1] = LastState[3][1];
			faces[1][2] = LastState[3][2];
			faces[1][3] = LastState[3][3];

			/*Right side*/
			faces[1][9] = LastState[0][9];
			faces[1][10] = LastState[0][10];
			faces[1][11] = LastState[0][11];
			faces[1][12] = LastState[0][12];

			/*----------update back(3)----------*/
			/*Left side*/
			faces[3][0] = LastState[2][0];
			faces[3][1] = LastState[2][1];
			faces[3][2] = LastState[2][2];
			faces[3][3] = LastState[2][3];

			/*Right side*/
			faces[3][9] = LastState[1][9];
			faces[3][10] = LastState[1][10];
			faces[3][11] = LastState[1][11];
			faces[3][12] = LastState[1][12];

			/*----------update bottom(2)----------*/
			/*Left side*/
			faces[2][0] = LastState[0][0];
			faces[2][1] = LastState[0][1];
			faces[2][2] = LastState[0][2];
			faces[2][3] = LastState[0][3];

			/*Right side*/
			faces[2][9] = LastState[3][9];
			faces[2][10] = LastState[3][10];
			faces[2][11] = LastState[3][11];
			faces[2][12] = LastState[3][12];

			copyStates();
		}
		/*Center coloum stationary and moving left */
		else if (col == 0 && direction == 2) {

		}
		/*Center coloum stationary and moving right */
		else if (col == 0 && direction == 3) {

		}
		/*left coloum stationary and moving down */
		else if (col == 1 && direction == 0) {

		}
		/*left coloum stationary and moving up */
		else if (col == 1 && direction == 1) {

		}
		/*right coloum stationary and moving down */
		else if (col == 2 && direction == 0) {

		}
		/*right coloum stationary and moving up */
		else if (col == 2 && direction == 0) {

		}
		/*top row stationary and moving left */
		else if (col == 3 && direction == 2) {

		}
		/*top row stationary and moving right */
		else if (col == 3 && direction == 3) {

		}
		/*bottom row stationary and moving left */
		else if (col == 4 && direction == 2) {

		}
		/*bottom row stationary and moving right */
		else if (col == 4 && direction == 3) {

		}
		else {

		}




	}

	

}
void GearBall::randomize(int turns) {

}
void GearBall::copyStates() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 13; j++) {
			LastState[i][j] = faces[i][j];
		}
	}
}
void GearBall::printBall() {
	copyStates();
	for (int i = 0; i <= 5; i++) {
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "--" << faces[i][4] << "--" << endl;
		cout << "-" << faces[i][1] << faces[i][5] << faces[i][9] << "-" << endl;
		cout << faces[i][0] << faces[i][2] << faces[i][6] << faces[i][10] << faces[i][12] << endl;
		cout << "-" << faces[i][3] << faces[i][7] << faces[i][11] << "-" << endl;
		cout << "--" << faces[i][8] << "--" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	}
}