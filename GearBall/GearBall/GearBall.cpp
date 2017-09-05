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
		/*left coloum stationary and moving down Faces 0,1,2,3
		are effected and spots 4 5 6 7 8 are replaced with top 
		face and 9 10 11 12 are replaced with back face */
		else if (col == 1 && direction == 0) {
			/*--------update face(0)------------*/
			/*Center side*/
			faces[0][4] = LastState[1][4];
			faces[0][5] = LastState[1][5];
			faces[0][6] = LastState[1][6];
			faces[0][7] = LastState[1][7];
			faces[0][8] = LastState[1][8];

			/*Right side*/
			faces[0][9] = LastState[3][9];
			faces[0][10] = LastState[3][10];
			faces[0][11] = LastState[3][11];
			faces[0][12] = LastState[3][12];

			/*----------update top(1)----------*/
			/*Center side*/
			faces[1][4] = LastState[3][4];
			faces[1][5] = LastState[3][5];
			faces[1][6] = LastState[3][6];
			faces[1][7] = LastState[3][7];
			faces[1][8] = LastState[3][8];

			/*Right side*/
			faces[1][9] = LastState[2][9];
			faces[1][10] = LastState[2][10];
			faces[1][11] = LastState[2][11];
			faces[1][12] = LastState[2][12];

			/*----------update back(3)----------*/
			/*Middle side*/
			faces[3][4] = LastState[2][4];
			faces[3][5] = LastState[2][5];
			faces[3][6] = LastState[2][6];
			faces[3][7] = LastState[2][7];
			faces[3][8] = LastState[2][8];

			/*Right side*/
			faces[3][9] = LastState[0][9];
			faces[3][10] = LastState[0][10];
			faces[3][11] = LastState[0][11];
			faces[3][12] = LastState[0][12];

			/*----------update bottom(2)----------*/
			/*Left side*/
			faces[2][4] = LastState[0][4];
			faces[2][5] = LastState[0][5];
			faces[2][6] = LastState[0][6];
			faces[2][7] = LastState[0][7];
			faces[2][8] = LastState[0][8];

			/*Right side*/
			faces[2][9] = LastState[1][9];
			faces[2][10] = LastState[1][10];
			faces[2][11] = LastState[1][11];
			faces[2][12] = LastState[1][12];

			copyStates();
		}
		/*left coloum stationary and moving up Faces 0,1,2,3
		are effected and spots 4 5 6 7 8 are replaced with bottom 
		face and 9 10 11 12 are replaced with back face */
		else if (col == 1 && direction == 1) {
			/*--------update face(0)------------*/
			/*Center side*/
			faces[0][4] = LastState[2][4];
			faces[0][5] = LastState[2][5];
			faces[0][6] = LastState[2][6];
			faces[0][7] = LastState[2][7];
			faces[0][8] = LastState[2][8];

			/*Right side*/
			faces[0][9] = LastState[3][9];
			faces[0][10] = LastState[3][10];
			faces[0][11] = LastState[3][11];
			faces[0][12] = LastState[3][12];

			/*----------update top(1)----------*/
			/*Center side*/
			faces[1][4] = LastState[0][4];
			faces[1][5] = LastState[0][5];
			faces[1][6] = LastState[0][6];
			faces[1][7] = LastState[0][7];
			faces[1][8] = LastState[0][8];

			/*Right side*/
			faces[1][9] = LastState[2][9];
			faces[1][10] = LastState[2][10];
			faces[1][11] = LastState[2][11];
			faces[1][12] = LastState[2][12];

			/*----------update back(3)----------*/
			/*Middle side*/
			faces[3][4] = LastState[1][4];
			faces[3][5] = LastState[1][5];
			faces[3][6] = LastState[1][6];
			faces[3][7] = LastState[1][7];
			faces[3][8] = LastState[1][8];

			/*Right side*/
			faces[3][9] = LastState[0][9];
			faces[3][10] = LastState[0][10];
			faces[3][11] = LastState[0][11];
			faces[3][12] = LastState[0][12];

			/*----------update bottom(2)----------*/
			/*Left side*/
			faces[2][4] = LastState[3][4];
			faces[2][5] = LastState[3][5];
			faces[2][6] = LastState[3][6];
			faces[2][7] = LastState[3][7];
			faces[2][8] = LastState[3][8];

			/*Right side*/
			faces[2][9] = LastState[1][9];
			faces[2][10] = LastState[1][10];
			faces[2][11] = LastState[1][11];
			faces[2][12] = LastState[1][12];

			copyStates();
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