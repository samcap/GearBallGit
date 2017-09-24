
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <math.h>
#include "GearBall.h"
#include "Gear.h"
#include <queue>

using namespace std;

GearBall::GearBall(){
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 13; j++) {
			//store O at spot zero and keep track of gear pairings
			if (i == 0) {
				if (j == 0){
					faces[i][0].setStates("O","O/B","B/O","B","B/O","O/B");
					//faces[i][0].setForward(horizTurn);
				}
				else if (j == 4) {
					faces[i][4].setStates("O", "O/R", "R/O", "R", "R/O", "O/R");
					//faces[i][4].setForward(vertTurn);
				}
				else if (j == 8) {
					faces[i][8].setStates("O", "O/P", "P/O", "P", "P/O", "O/P");
					//faces[i][8].setForward(vertTurn);
				}
				else if (j == 12) {
					faces[i][12].setStates("O", "O/G", "G/O", "G", "G/O", "O/G");
					//faces[i][12].setForward(horizTurn);
				}
				faces[i][j].setColor("O");

			}
			//store R at spot 1 and keep track of gear pairings
			else if (i == 1) {
				if (j == 0) {
					faces[i][0].setStates("R", "R/B", "B/R", "B", "B/R", "R/B");
					//faces[i][0].setForward(horizTurn);
				}
				else if (j == 4) {
					faces[i][4].setStates("R", "R/Y", "Y/R", "Y", "Y/R", "R/Y");
					//faces[i][4].setForward(vertTurn);
				}
				else if (j == 8) {
					faces[i][8].setStates("R", "R/O", "O/R", "O", "O/R", "R/O");
					//faces[i][8].setForward(vertTurn);
				}
				else if (j == 12) {
					faces[i][12].setStates("R", "R/G", "G/R", "G", "G/R", "R/G");
					//faces[i][12].setForward(horizTurn);
				}
				faces[i][j].setColor("R");
			}
			//store P at spot 2 and keep track of gear pairings
			else if (i == 2) {
				if (j == 0) {
					faces[i][0].setStates("P", "P/B", "B/P", "B", "B/P", "P/B");
					//faces[i][0].setForward(horizTurn);
				}
				else if (j == 4) {
					faces[i][4].setStates("P", "P/O", "O/P", "O", "O/P", "P/O");
					//faces[i][4].setForward(vertTurn);
				}
				else if (j == 8) {
					faces[i][8].setStates("P", "P/Y", "Y/P", "Y", "Y/P", "P/Y");
					//faces[i][8].setForward(vertTurn);
				}
				else if (j == 12) {
					faces[i][12].setStates("P", "P/G", "G/P", "G", "G/P", "P/G");
					//faces[i][12].setForward(horizTurn);
				}
				faces[i][j].setColor("P");
			}
			//store Y at spot 3 and keep track of gear pairings
			else if (i == 3) {
				if (j == 0) {
					faces[i][0].setStates("Y", "Y/G", "G/Y", "G", "G/Y", "Y/G");
					//faces[i][0].setForward(horizTurn);
				}
				else if (j == 4) {
					faces[i][4].setStates("Y", "Y/R", "R/Y", "R", "R/Y", "Y/R");
					//faces[i][4].setForward(vertTurn);
				}
				else if (j == 8) {
					faces[i][8].setStates("Y", "Y/P", "P/Y", "P", "P/Y", "Y/P");
					//faces[i][8].setForward(vertTurn);
				}
				else if (j == 12) {
					faces[i][12].setStates("Y", "Y/B", "B/Y", "B", "B/Y", "Y/B");
					//faces[i][12].setForward(horizTurn);
				}
				faces[i][j].setColor("Y");
			}
			//store B at spot 4 and keep track of gear pairings
			else if (i == 4) {
				if (j == 0) {
					faces[i][0].setStates("B", "B/Y", "Y/B", "Y", "Y/B", "B/Y");
					//faces[i][0].setForward(horizTurn);
				}
				else if (j == 4) {
					faces[i][4].setStates("B", "B/R", "R/B", "R", "R/B", "B/R");
					//faces[i][4].setForward(vertTurn);
				}
				else if (j == 8) {
					faces[i][8].setStates("B", "B/P", "P/B", "P", "P/B", "B/P");
					//faces[i][8].setForward(vertTurn);
				}
				else if (j == 12) {
					faces[i][12].setStates("B", "B/O", "O/B", "O", "O/B", "B/O");
					//faces[i][12].setForward(horizTurn);
				}
				faces[i][j].setColor("B");
			}
			//store G at spot 5 and keep track of gear pairings
			else {
				if (j == 0) {
					faces[i][0].setStates("G", "G/O", "O/G", "O", "O/G", "G/O");
					//faces[i][0].setForward(horizTurn);
				}
				else if (j == 4) {
					faces[i][4].setStates("G", "G/R", "R/G", "R", "R/G", "G/R");
					//faces[i][4].setForward(vertTurn);
				}
				else if (j == 8) {
					faces[i][8].setStates("G", "G/P", "P/G", "P", "P/G", "G/P");
					//faces[i][8].setForward(vertTurn);
				}
				else if (j == 12) {
					faces[i][12].setStates("G", "G/Y", "Y/G", "Y", "Y/G", "G/Y");
					//faces[i][12].setForward(horizTurn);
				}
				faces[i][j].setColor("G");
			}

		}
	}

	copyStates();
	vertTurn = 0;
	horizTurn = 0;
}
GearBall::~GearBall(){
}
void GearBall::setDepth(int n) {
	depth = n;
}
int GearBall::getDepth() {
	return depth;
}
void GearBall::cost(double h) {
	f = double(depth) + h;
}
void GearBall::setFace(Gear state[6][13],int vertical, int horizontal) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 13; j++) {
			faces[i][j] = state[i][j];
		}
	}
	vertTurn = vertical;
	horizTurn = horizontal;

}
void GearBall::getFace(Gear (*array)[6][13], int *vertical, int *horizontal) {
	//setGears();
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 13; j++) {
			(*array)[i][j] = faces[i][j];
		}
	}
	*vertical = vertTurn;
	*horizontal = horizTurn;
}

double GearBall::FindOutOfPlace() {
	//setGears();
	double outOfPlace = 0;
	double gearOutOfPlace = 0;
	int correctPlace = 0;
	int wholeSide = 0;
	double sum = 0;

	// Loops through every face
	int len = faces[0][4].getColor().size();
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 13; j++) {
			if (j != 6) {
				//findes piece colors that dont match the center peice
				if (faces[i][j].getColor() != faces[i][6].getColor()) {
					outOfPlace++;
				}
				//finds all the matching pieces
				if(faces[i][j].getColor() == faces[i][6].getColor() && j != 6){
					correctPlace++;
				}
				//finds the gears that are not in the correct rotation
				if (faces[i][j].getColor().size() == 3) {
					gearOutOfPlace++;
				}
				
			}
		}
		//if 12 psieces wehre correct then the whole side was correct
		if (correctPlace == 12) {
			wholeSide++;
			correctPlace = 0;
		}
		else {
			correctPlace = 0;
		}

	}
	//if two sides are correct adjust the heuristic score
	if (wholeSide == 2 ) {
		sum = (double((gearOutOfPlace / 8)) + double((outOfPlace / 40)));
		if (sum != 0) {
			sum = sum - 2.5;
		}

	}
	// if not then calcualte normally
	else {
		sum = (double((gearOutOfPlace / 8)) + double((outOfPlace / 40)));
	}
	
	
	return sum;
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

			faces[0][4].setForward(-1);
			faces[0][8].setForward(-1);


			/*----------update top(1)----------*/
			/*Left side*/
			faces[1][0] = LastState[0][0];
			faces[1][1] = LastState[0][1];
			faces[1][2] = LastState[0][2];
			faces[1][3] = LastState[0][3];

			/*Right side*/
			faces[1][9] = LastState[3][3];
			faces[1][10] = LastState[3][2];
			faces[1][11] = LastState[3][1];
			faces[1][12] = LastState[3][0];

			faces[1][4].setForward(-1);
			faces[1][8].setForward(-1);

			/*----------update back(3)----------*/
			/*Left side*/
			faces[3][0] = LastState[2][12];
			faces[3][1] = LastState[2][11];
			faces[3][2] = LastState[2][10];
			faces[3][3] = LastState[2][9];

			/*Right side*/
			faces[3][9] = LastState[1][3];
			faces[3][10] = LastState[1][2];
			faces[3][11] = LastState[1][1];
			faces[3][12] = LastState[1][0];

			faces[3][4].setForward(-1);
			faces[3][8].setForward(-1);
			/*----------update bottom(2)----------*/
			/*Left side*/
			faces[2][0] = LastState[3][12];
			faces[2][1] = LastState[3][11];
			faces[2][2] = LastState[3][10];
			faces[2][3] = LastState[3][9];


			/*Right side*/
			faces[2][9] = LastState[0][9];
			faces[2][10] = LastState[0][10];
			faces[2][11] = LastState[0][11];
			faces[2][12] = LastState[0][12];

			faces[2][4].setForward(-1);
			faces[2][8].setForward(-1);
	
		
			copyStates();
			sideRotate(0);


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

			faces[0][4].setForward(1);
			faces[0][8].setForward(1);


			/*----------update top(1)----------*/
			/*Left side*/
			faces[1][0] = LastState[3][12];
			faces[1][1] = LastState[3][11];
			faces[1][2] = LastState[3][10];
			faces[1][3] = LastState[3][9];

			/*Right side*/
			faces[1][9] = LastState[0][9];
			faces[1][10] = LastState[0][10];
			faces[1][11] = LastState[0][11];
			faces[1][12] = LastState[0][12];

			faces[1][4].setForward(1);
			faces[1][8].setForward(1);

			/*----------update back(3)----------*/
			/*Left side*/
			faces[3][0] = LastState[1][12];
			faces[3][1] = LastState[1][11];
			faces[3][2] = LastState[1][10];
			faces[3][3] = LastState[1][9];

			/*Right side*/
			faces[3][9] = LastState[2][3];
			faces[3][10] = LastState[2][2];
			faces[3][11] = LastState[2][1];
			faces[3][12] = LastState[2][0];

			faces[3][4].setForward(1);
			faces[3][8].setForward(1);

			/*----------update bottom(2)----------*/
			/*Left side*/
			faces[2][0] = LastState[0][0];
			faces[2][1] = LastState[0][1];
			faces[2][2] = LastState[0][2];
			faces[2][3] = LastState[0][3];

			/*Right side*/
			faces[2][9] = LastState[3][3];
			faces[2][10] = LastState[3][2];
			faces[2][11] = LastState[3][1];
			faces[2][12] = LastState[3][0];

			faces[2][4].setForward(1);
			faces[2][8].setForward(1);

			
			copyStates();
			sideRotate(1);

		}
		/*Center coloum stationary and moving left, Faces 0 4 5 3 are effected
		The top slice 1 4 5 9 are changed with left face and spots 3 7 11 8 are
		switched with the right face*/
		else if (col == 0 && direction == 2) {
			/*--------update face(0)------------*/
			/*Top side*/
			faces[0][1] = LastState[5][1];
			faces[0][4] = LastState[5][4];
			faces[0][5] = LastState[5][5];
			faces[0][9] = LastState[5][9];

			/*Bottom Side*/
			faces[0][3] = LastState[4][3];
			faces[0][7] = LastState[4][7];
			faces[0][8] = LastState[4][8];
			faces[0][11] = LastState[4][11];

			faces[0][0].setForward(1);
			faces[0][12].setForward(1);

			/*--------update face(4)------------*/
			/*Top side*/
			faces[4][1] = LastState[0][1];
			faces[4][4] = LastState[0][4];
			faces[4][5] = LastState[0][5];
			faces[4][9] = LastState[0][9];

			/*Bottom Side*/
			faces[4][3] = LastState[3][3];
			faces[4][7] = LastState[3][7];
			faces[4][8] = LastState[3][8];
			faces[4][11] = LastState[3][11];

			faces[4][0].setForward(1);
			faces[4][12].setForward(1);
			/*--------update face(5)------------*/
			/*Top side*/
			faces[5][1] = LastState[3][1];
			faces[5][4] = LastState[3][4];
			faces[5][5] = LastState[3][5];
			faces[5][9] = LastState[3][9];

			/*Bottom Side*/
			faces[5][3] = LastState[0][3];
			faces[5][7] = LastState[0][7];
			faces[5][8] = LastState[0][8];
			faces[5][11] = LastState[0][11];

			faces[5][0].setForward(1);
			faces[5][12].setForward(1);

			/*--------update face(3)------------*/
			/*Top side*/
			faces[3][1] = LastState[4][1];
			faces[3][4] = LastState[4][4];
			faces[3][5] = LastState[4][5];
			faces[3][9] = LastState[4][9];

			/*Bottom Side*/
			faces[3][3] = LastState[5][3];
			faces[3][7] = LastState[5][7];
			faces[3][8] = LastState[5][8];
			faces[3][11] = LastState[5][11];

			faces[3][0].setForward(1);
			faces[3][12].setForward(1);

			
			copyStates();
			sideRotate(4);

		}
		/*Center coloum stationary and moving right Faces 0 4 5 3 are effected
		The top slice 1 4 5 9 are changed with right face and spots 3 7 11 8 are
		switched with the left face*/
		else if (col == 0 && direction == 3) {
			/*--------update face(0)------------*/
			/*Top side*/
			faces[0][1] = LastState[4][1];
			faces[0][4] = LastState[4][4];
			faces[0][5] = LastState[4][5];
			faces[0][9] = LastState[4][9];

			/*Bottom Side*/
			faces[0][3] = LastState[5][3];
			faces[0][7] = LastState[5][7];
			faces[0][8] = LastState[5][8];
			faces[0][11] = LastState[5][11];

			faces[0][0].setForward(-1);
			faces[0][12].setForward(-1);

			/*--------update face(4)------------*/
			/*Top side*/
			faces[4][1] = LastState[3][1];
			faces[4][4] = LastState[3][4];
			faces[4][5] = LastState[3][5];
			faces[4][9] = LastState[3][9];

			/*Bottom Side*/
			faces[4][3] = LastState[0][3];
			faces[4][7] = LastState[0][7];
			faces[4][8] = LastState[0][8];
			faces[4][11] = LastState[0][11];

			faces[4][0].setForward(-1);
			faces[4][12].setForward(-1);

			/*--------update face(5)------------*/
			/*Top side*/
			faces[5][1] = LastState[0][1];
			faces[5][4] = LastState[0][4];
			faces[5][5] = LastState[0][5];
			faces[5][9] = LastState[0][9];

			/*Bottom Side*/
			faces[5][3] = LastState[3][3];
			faces[5][7] = LastState[3][7];
			faces[5][8] = LastState[3][8];
			faces[5][11] = LastState[3][11];

			faces[5][0].setForward(-1);
			faces[5][12].setForward(-1);

			/*--------update face(3)------------*/
			/*Top side*/
			faces[3][1] = LastState[5][1];
			faces[3][4] = LastState[5][4];
			faces[3][5] = LastState[5][5];
			faces[3][9] = LastState[5][9];

			/*Bottom Side*/
			faces[3][3] = LastState[4][3];
			faces[3][7] = LastState[4][7];
			faces[3][8] = LastState[4][8];
			faces[3][11] = LastState[4][11];

			faces[3][0].setForward(-1);
			faces[3][12].setForward(-1);

			
			copyStates();
			sideRotate(5);
	
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
			faces[0][9] = LastState[3][3];
			faces[0][10] = LastState[3][2];
			faces[0][11] = LastState[3][1];
			faces[0][12] = LastState[3][0];

			/*----------update top(1)----------*/
			/*Center side*/
			faces[1][4] = LastState[3][8];
			faces[1][5] = LastState[3][7];
			faces[1][6] = LastState[3][6];
			faces[1][7] = LastState[3][5];
			faces[1][8] = LastState[3][4];

			/*Right side*/
			faces[1][9] = LastState[2][9];
			faces[1][10] = LastState[2][10];
			faces[1][11] = LastState[2][11];
			faces[1][12] = LastState[2][12];

			/*----------update back(3)----------*/
			/*Middle side*/
			faces[3][4] = LastState[2][8];
			faces[3][5] = LastState[2][7];
			faces[3][6] = LastState[2][6];
			faces[3][7] = LastState[2][5];
			faces[3][8] = LastState[2][4];

			/*left side*/
			faces[3][0] = LastState[0][12];
			faces[3][1] = LastState[0][11];
			faces[3][2] = LastState[0][10];
			faces[3][3] = LastState[0][9];

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
			sideRotate(2);
			vertTurn--;
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
			faces[0][9] = LastState[3][3];
			faces[0][10] = LastState[3][2];
			faces[0][11] = LastState[3][1];
			faces[0][12] = LastState[3][0];

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
			/*Center side*/
			faces[3][4] = LastState[1][8];
			faces[3][5] = LastState[1][7];
			faces[3][6] = LastState[1][6];
			faces[3][7] = LastState[1][5];
			faces[3][8] = LastState[1][4];

			/*Left side*/
			faces[3][0] = LastState[0][12];
			faces[3][1] = LastState[0][11];
			faces[3][2] = LastState[0][10];
			faces[3][3] = LastState[0][9];

			/*----------update bottom(2)----------*/
			/*Center side*/
			faces[2][4] = LastState[3][8];
			faces[2][5] = LastState[3][7];
			faces[2][6] = LastState[3][6];
			faces[2][7] = LastState[3][5];
			faces[2][8] = LastState[3][4];

			/*Right side*/
			faces[2][9] = LastState[1][9];
			faces[2][10] = LastState[1][10];
			faces[2][11] = LastState[1][11];
			faces[2][12] = LastState[1][12];

		
			copyStates();
			sideRotate(2);
			vertTurn++;
		}
		/*right coloum stationary and moving down Faces 0 1 2 3 are
		effected and spots 4 5 6 7 8 are replaced with top face and spots
		0 1 2 3 are replaced with back face Faces 0 1 2 3 are */
		else if (col == 2 && direction == 0) {
			/*----------update front(0)----------*/
			/*center side*/
			faces[0][4] = LastState[1][4];
			faces[0][5] = LastState[1][5];
			faces[0][6] = LastState[1][6];
			faces[0][7] = LastState[1][7];
			faces[0][8] = LastState[1][8];

			/*Left side*/
			faces[0][0] = LastState[3][12];
			faces[0][1] = LastState[3][11];
			faces[0][2] = LastState[3][10];
			faces[0][3] = LastState[3][9];

			/*----------update top(1)----------*/
			/*center side*/
			faces[1][4] = LastState[3][8];
			faces[1][5] = LastState[3][7];
			faces[1][6] = LastState[3][6];
			faces[1][7] = LastState[3][5];
			faces[1][8] = LastState[3][4];

			/*Left side*/
			faces[1][0] = LastState[2][0];
			faces[1][1] = LastState[2][1];
			faces[1][2] = LastState[2][2];
			faces[1][3] = LastState[2][3];

			/*----------update Back(3)----------*/
			/*center side*/
			faces[3][4] = LastState[2][8];
			faces[3][5] = LastState[2][7];
			faces[3][6] = LastState[2][6];
			faces[3][7] = LastState[2][5];
			faces[3][8] = LastState[2][4];

			/*right side*/
			faces[3][9] = LastState[0][3];
			faces[3][10] = LastState[0][2];
			faces[3][11] = LastState[0][1];
			faces[3][12] = LastState[0][0];

			/*----------update Bottom(2)----------*/
			/*center side*/
			faces[2][4] = LastState[0][4];
			faces[2][5] = LastState[0][5];
			faces[2][6] = LastState[0][6];
			faces[2][7] = LastState[0][7];
			faces[2][8] = LastState[0][8];

			/*Left side*/
			faces[2][0] = LastState[1][0];
			faces[2][1] = LastState[1][1];
			faces[2][2] = LastState[1][2];
			faces[2][3] = LastState[1][3];

			
			copyStates();
			sideRotate(3);
			vertTurn--;
		}
		/*right coloum stationary and moving up Faces 0 1 2 3 are
		effected and spots 4 5 6 7 8 are replaced with Bottom face and spots
		0 1 2 3 are replaced with back face*/
		else if (col == 2 && direction == 1) {
			/*----------update front(0)----------*/
			/*center side*/
			faces[0][4] = LastState[2][4];
			faces[0][5] = LastState[2][5];
			faces[0][6] = LastState[2][6];
			faces[0][7] = LastState[2][7];
			faces[0][8] = LastState[2][8];

			/*Left side*/
			faces[0][0] = LastState[3][12];
			faces[0][1] = LastState[3][11];
			faces[0][2] = LastState[3][10];
			faces[0][3] = LastState[3][9];

			/*----------update top(1)----------*/
			/*center side*/
			faces[1][4] = LastState[0][4];
			faces[1][5] = LastState[0][5];
			faces[1][6] = LastState[0][6];
			faces[1][7] = LastState[0][7];
			faces[1][8] = LastState[0][8];

			/*Left side*/
			faces[1][0] = LastState[2][0];
			faces[1][1] = LastState[2][1];
			faces[1][2] = LastState[2][2];
			faces[1][3] = LastState[2][3];

			/*----------update Back(3)----------*/
			/*center side*/
			faces[3][4] = LastState[1][8];
			faces[3][5] = LastState[1][7];
			faces[3][6] = LastState[1][6];
			faces[3][7] = LastState[1][5];
			faces[3][8] = LastState[1][4];

			/*Left side*/
			faces[3][9] = LastState[0][3];
			faces[3][10] = LastState[0][2];
			faces[3][11] = LastState[0][1];
			faces[3][12] = LastState[0][0];

			/*----------update Bottom(2)----------*/
			/*center side*/
			faces[2][4] = LastState[3][8];
			faces[2][5] = LastState[3][7];
			faces[2][6] = LastState[3][6];
			faces[2][7] = LastState[3][5];
			faces[2][8] = LastState[3][4];

			/*Left side*/
			faces[2][0] = LastState[1][0];
			faces[2][1] = LastState[1][1];
			faces[2][2] = LastState[1][2];
			faces[2][3] = LastState[1][3];

			
			copyStates();
			sideRotate(3);
			vertTurn++;
		}
		/*top row stationary and moving left faces 0 3 4 5 are effected
		and spots 0 2 6 10 12 are replaced with the right face and spots
		3 7 11 8 are replaced with the back face*/
		else if (col == 3 && direction == 0) {
			/*----------update Front(0)----------*/
			/*Center*/
			faces[0][0] = LastState[5][0];
			faces[0][2] = LastState[5][2];
			faces[0][6] = LastState[5][6];
			faces[0][10] = LastState[5][10];
			faces[0][12] = LastState[5][12];

			/*Bottom*/
			faces[0][3] = LastState[3][3];
			faces[0][7] = LastState[3][7];
			faces[0][11] = LastState[3][11];
			faces[0][8] = LastState[3][8];

			/*----------update Left(4)----------*/
			/*Center*/
			faces[4][0] = LastState[0][0];
			faces[4][2] = LastState[0][2];
			faces[4][6] = LastState[0][6];
			faces[4][10] = LastState[0][10];
			faces[4][12] = LastState[0][12];

			/*Bottom*/
			faces[4][3] = LastState[5][3];
			faces[4][7] = LastState[5][7];
			faces[4][11] = LastState[5][11];
			faces[4][8] = LastState[5][8];

			/*----------update Back(3)----------*/
			/*Center*/
			faces[3][0] = LastState[4][0];
			faces[3][2] = LastState[4][2];
			faces[3][6] = LastState[4][6];
			faces[3][10] = LastState[4][10];
			faces[3][12] = LastState[4][12];

			/*Bottom*/
			faces[3][3] = LastState[0][3];
			faces[3][7] = LastState[0][7];
			faces[3][11] = LastState[0][11];
			faces[3][8] = LastState[0][8];

			/*----------update Right(5)----------*/
			/*Center*/
			faces[5][0] = LastState[3][0];
			faces[5][2] = LastState[3][2];
			faces[5][6] = LastState[3][6];
			faces[5][10] = LastState[3][10];
			faces[5][12] = LastState[3][12];

			/*Bottom*/
			faces[5][3] = LastState[4][3];
			faces[5][7] = LastState[4][7];
			faces[5][11] = LastState[4][11];
			faces[5][8] = LastState[4][8];


			copyStates();
			sideRotate(6);
			horizTurn++;
		}
		/*top row stationary and moving right faces 0 3 4 5 are effected
		and spots 0 2 6 10 12 are replaced with the left face and spots
		3 7 11 8 are replaced with the back face*/
		else if (col == 3 && direction == 1) {
			/*----------update Front(0)----------*/
			/*Center*/
			faces[0][0] = LastState[4][0];
			faces[0][2] = LastState[4][2];
			faces[0][6] = LastState[4][6];
			faces[0][10] = LastState[4][10];
			faces[0][12] = LastState[4][12];

			/*Bottom*/
			faces[0][3] = LastState[3][3];
			faces[0][7] = LastState[3][7];
			faces[0][11] = LastState[3][11];
			faces[0][8] = LastState[3][8];

			/*----------update Left(4)----------*/
			/*Center*/
			faces[4][0] = LastState[3][0];
			faces[4][2] = LastState[3][2];
			faces[4][6] = LastState[3][6];
			faces[4][10] = LastState[3][10];
			faces[4][12] = LastState[3][12];

			/*Bottom*/
			faces[4][3] = LastState[5][3];
			faces[4][7] = LastState[5][7];
			faces[4][11] = LastState[5][11];
			faces[4][8] = LastState[5][8];

			/*----------update Back(3)----------*/
			/*Center*/
			faces[3][0] = LastState[5][0];
			faces[3][2] = LastState[5][2];
			faces[3][6] = LastState[5][6];
			faces[3][10] = LastState[5][10];
			faces[3][12] = LastState[5][12];

			/*Bottom*/
			faces[3][3] = LastState[0][3];
			faces[3][7] = LastState[0][7];
			faces[3][11] = LastState[0][11];
			faces[3][8] = LastState[0][8];

			/*----------update Right(5)----------*/
			/*Center*/
			faces[5][0] = LastState[0][0];
			faces[5][2] = LastState[0][2];
			faces[5][6] = LastState[0][6];
			faces[5][10] = LastState[0][10];
			faces[5][12] = LastState[0][12];

			/*Bottom*/
			faces[5][3] = LastState[4][3];
			faces[5][7] = LastState[4][7];
			faces[5][11] = LastState[4][11];
			faces[5][8] = LastState[4][8];

			
			copyStates();
			sideRotate(6);
			horizTurn--;
		}
		/*bottom row stationary and moving left, faces 0 3 4 5 are effected
		abd soits 0 2 6 10 12 are replaced wutg the right face and spots
		1 4 5 9 are replaced with the back face*/
		else if (col == 4 && direction == 0) {
			/*----------update Front(0)----------*/
			/*Center*/
			faces[0][0] = LastState[5][0];
			faces[0][2] = LastState[5][2];
			faces[0][6] = LastState[5][6];
			faces[0][10] = LastState[5][10];
			faces[0][12] = LastState[5][12];

			/*Top*/
			faces[0][1] = LastState[3][1];
			faces[0][4] = LastState[3][4];
			faces[0][5] = LastState[3][5];
			faces[0][9] = LastState[3][9];

			/*----------update Left(4)----------*/
			/*Center*/
			faces[4][0] = LastState[0][0];
			faces[4][2] = LastState[0][2];
			faces[4][6] = LastState[0][6];
			faces[4][10] = LastState[0][10];
			faces[4][12] = LastState[0][12];

			/*Top*/
			faces[4][1] = LastState[5][1];
			faces[4][4] = LastState[5][4];
			faces[4][5] = LastState[5][5];
			faces[4][9] = LastState[5][9];

			/*----------update Back(3)----------*/
			/*Center*/
			faces[3][0] = LastState[4][0];
			faces[3][2] = LastState[4][2];
			faces[3][6] = LastState[4][6];
			faces[3][10] = LastState[4][10];
			faces[3][12] = LastState[4][12];

			/*Top*/
			faces[3][1] = LastState[0][1];
			faces[3][4] = LastState[0][4];
			faces[3][5] = LastState[0][5];
			faces[3][9] = LastState[0][9];

			/*----------update Right(5)----------*/
			/*Center*/
			faces[5][0] = LastState[3][0];
			faces[5][2] = LastState[3][2];
			faces[5][6] = LastState[3][6];
			faces[5][10] = LastState[3][10];
			faces[5][12] = LastState[3][12];

			/*Top*/
			faces[5][1] = LastState[4][1];
			faces[5][4] = LastState[4][4];
			faces[5][5] = LastState[4][5];
			faces[5][9] = LastState[4][9];

			
			copyStates();
			sideRotate(7);
			horizTurn++;
		}
		/*bottom row stationary and moving right faces 0 3 4 5 are effected
		abd soits 0 2 6 10 12 are replaced wutg the left face and spots
		1 4 5 9 are replaced with the back face*/
		else if (col == 4 && direction == 1) {
			/*----------update Front(0)----------*/
			/*Center*/
			faces[0][0] = LastState[4][0];
			faces[0][2] = LastState[4][2];
			faces[0][6] = LastState[4][6];
			faces[0][10] = LastState[4][10];
			faces[0][12] = LastState[4][12];

			/*Top*/
			faces[0][1] = LastState[3][1];
			faces[0][4] = LastState[3][4];
			faces[0][5] = LastState[3][5];
			faces[0][9] = LastState[3][9];

			/*----------update Left(4)----------*/
			/*Center*/
			faces[4][0] = LastState[3][0];
			faces[4][2] = LastState[3][2];
			faces[4][6] = LastState[3][6];
			faces[4][10] = LastState[3][10];
			faces[4][12] = LastState[3][12];

			/*Top*/
			faces[4][1] = LastState[5][1];
			faces[4][4] = LastState[5][4];
			faces[4][5] = LastState[5][5];
			faces[4][9] = LastState[5][9];

			/*----------update Back(3)----------*/
			/*Center*/
			faces[3][0] = LastState[5][0];
			faces[3][2] = LastState[5][2];
			faces[3][6] = LastState[5][6];
			faces[3][10] = LastState[5][10];
			faces[3][12] = LastState[5][12];

			/*Top*/
			faces[3][1] = LastState[0][1];
			faces[3][4] = LastState[0][4];
			faces[3][5] = LastState[0][5];
			faces[3][9] = LastState[0][9];

			/*----------update Right(5)----------*/
			/*Center*/
			faces[5][0] = LastState[0][0];
			faces[5][2] = LastState[0][2];
			faces[5][6] = LastState[0][6];
			faces[5][10] = LastState[0][10];
			faces[5][12] = LastState[0][12];

			/*Top*/
			faces[5][1] = LastState[4][1];
			faces[5][4] = LastState[4][4];
			faces[5][5] = LastState[4][5];
			faces[5][9] = LastState[4][9];

			
			copyStates();
			sideRotate(7);
			horizTurn--;
		}

	/*	if (vertTurn == 6 || vertTurn == -6) {
			vertTurn = 0;
		}
		if (horizTurn == 6 || horizTurn == -6) {
			horizTurn = 0;
		}
		//setGears();
		*/
	}


}
void GearBall::randomize(int turns) {

	int counter = 0;
	int Turn = 0;
	int Rotation = 0;
	int Num = 0;
	bool valid;

	previousMove[0] = 99;
	previousMove[1] = 99;
	previousMove[2] = 99;

	//generates the seed for the mersen twist
	generator.seed(time(0));

	//creates 4 types of random numbers for each valid case
	uniform_int_distribution<uint32_t> typeTurn(0, 0);
	uniform_int_distribution<uint32_t> typeRotationCenter(0, 3);
	uniform_int_distribution<uint32_t> typeRotationOther(0, 1);
	uniform_int_distribution<uint32_t> numTurns(1, 11);

	//create random moves based on the users desired number of turns
	while (counter != turns) {

		Turn = typeTurn(generator);
		Move[0] = Turn;
		//having the center column stationary can have 4 diffrent possible numbers while everything else has 2 turns 
		if (Turn == 0) {
			Rotation = typeRotationCenter(generator);
			Move[1] = Rotation;
		}
		else {
			Rotation = typeRotationOther(generator);
			Move[1] = Rotation;
		}
		Num = numTurns(generator);
		Move[2] = Num;
		//make sure the number of turns dosent exceed the users desired rotations
		if ((Num + counter) > turns) {
			valid = false;
		}
		else {
			//make sure the moves do not reverse on the previous move
			if (Move[0] == previousMove[0] && Move[0] != 0) {
				if ((Move[1] == 0 && previousMove[1] == 1) || (Move[1] == 1 && previousMove[1] == 0)) {
					valid = false;
				}
				else {
					valid = true;
				}
			}
			//make sure the moves do not reverse on the previous move
			else if (Move[0] == previousMove[0] && Move[0] == 0) {
				if ((Move[1] == 0 && previousMove[1] == 1) || (Move[1] == 1 && previousMove[1] == 0)) {
					valid = false;
				}
				else if ((Move[1] == 2 && previousMove[1] == 3) || (Move[1] == 3 && previousMove[1] == 2)) {
					valid = false;
				}
				// if the move passed all the tests than it is a valid move
				else {
					valid = true;
				}
			}
			// if the move passed all the tests than it is a valid move
			else {
				valid = true;
			}

		}
		// if there was a valid move save it in the previous move array

		if (valid == true) {
			previousMove[0] = Move[0];
			previousMove[1] = Move[1];
			previousMove[2] = Move[2];
			counter += Num;
			cout << "This move was preformed: "<< Move[0]<< "," << Move[1] << "," << Move[2] << endl;
			rotate(Move[0], Move[1], Move[2]);

		}
		
	}
}
void GearBall::sideRotate(int rot){
	/*if the rotation was downward update face 4 and 5*/
	if (rot == 0) {

		faces[4][0] = LastState[4][4];
		faces[4][1] = LastState[4][9];
		faces[4][2] = LastState[4][5];
		faces[4][3] = LastState[4][1];
		faces[4][4] = LastState[4][12];
		faces[4][5] = LastState[4][10];
		faces[4][7] = LastState[4][2];
		faces[4][8] = LastState[4][0];
		faces[4][9] = LastState[4][11];
		faces[4][10] = LastState[4][7];
		faces[4][11] = LastState[4][3];
		faces[4][12] = LastState[4][8];

		faces[5][0] = LastState[5][4];
		faces[5][1] = LastState[5][9];
		faces[5][2] = LastState[5][5];
		faces[5][3] = LastState[5][1];
		faces[5][4] = LastState[5][12];
		faces[5][5] = LastState[5][10];
		faces[5][7] = LastState[5][2];
		faces[5][8] = LastState[5][0];
		faces[5][9] = LastState[5][11];
		faces[5][10] = LastState[5][7];
		faces[5][11] = LastState[5][3];
		faces[5][12] = LastState[5][8];
		
		copyStates();
		
	}
	/*If rotation was up rotate face 4 and 5*/
	else if (rot == 1) {

		faces[4][0] = LastState[4][8];
		faces[4][1] = LastState[4][3];
		faces[4][2] = LastState[4][7];
		faces[4][3] = LastState[4][11];
		faces[4][4] = LastState[4][0];
		faces[4][5] = LastState[4][2];
		faces[4][7] = LastState[4][10];
		faces[4][8] = LastState[4][12];
		faces[4][9] = LastState[4][1];
		faces[4][10] = LastState[4][5];
		faces[4][11] = LastState[4][9];
		faces[4][12] = LastState[4][4];

		faces[5][0] = LastState[5][8];
		faces[5][1] = LastState[5][3];
		faces[5][2] = LastState[5][7];
		faces[5][3] = LastState[5][11];
		faces[5][4] = LastState[5][0];
		faces[5][5] = LastState[5][2];
		faces[5][7] = LastState[5][10];
		faces[5][8] = LastState[5][12];
		faces[5][9] = LastState[5][1]; 
		faces[5][10] = LastState[5][5];
		faces[5][11] = LastState[5][9];
		faces[5][12] = LastState[5][4];

		copyStates();
	}
	/*rotate one side with left stationary  up and down*/
	else if (rot == 2) {
		faces[5][0] = LastState[5][12];
		faces[5][1] = LastState[5][11];
		faces[5][2] = LastState[5][10];
		faces[5][3] = LastState[5][9];
		faces[5][4] = LastState[5][8];
		faces[5][5] = LastState[5][7];
		faces[5][7] = LastState[5][5];
		faces[5][8] = LastState[5][4];
		faces[5][9] = LastState[5][3];
		faces[5][10] = LastState[5][2];
		faces[5][11] = LastState[5][1];
		faces[5][12] = LastState[5][0];

		copyStates();
	}
	/*rotate one side with right stationary up and down*/
	else if (rot == 3) {
		faces[4][0] = LastState[4][12];
		faces[4][1] = LastState[4][11];
		faces[4][2] = LastState[4][10];
		faces[4][3] = LastState[4][9];
		faces[4][4] = LastState[4][8];
		faces[4][5] = LastState[4][7];
		faces[4][7] = LastState[4][5];
		faces[4][8] = LastState[4][4];
		faces[4][9] = LastState[4][3];
		faces[4][10] = LastState[4][2];
		faces[4][11] = LastState[4][1];
		faces[4][12] = LastState[4][0];

		copyStates();
	}
	/*rotate left update faces 1 and 2*/
	else if (rot == 4) {

		faces[1][0] = LastState[1][8];
		faces[1][1] = LastState[1][3];
		faces[1][2] = LastState[1][7];
		faces[1][3] = LastState[1][11];
		faces[1][4] = LastState[1][0];
		faces[1][5] = LastState[1][2];
		faces[1][7] = LastState[1][10];
		faces[1][8] = LastState[1][12];
		faces[1][9] = LastState[1][1];
		faces[1][10] = LastState[1][5];
		faces[1][11] = LastState[1][9];
		faces[1][12] = LastState[1][4];

		faces[2][0] = LastState[2][8];
		faces[2][1] = LastState[2][3];
		faces[2][2] = LastState[2][7];
		faces[2][3] = LastState[2][11];
		faces[2][4] = LastState[2][0];
		faces[2][5] = LastState[2][2];
		faces[2][7] = LastState[2][10];
		faces[2][8] = LastState[2][12];
		faces[2][9] = LastState[2][1];
		faces[2][10] = LastState[2][5];
		faces[2][11] = LastState[2][9];
		faces[2][12] = LastState[2][4];

		copyStates();
	}
	/*rotate right update faces 1 and 2*/
	else if (rot == 5) {

		faces[1][0] = LastState[1][4];
		faces[1][1] = LastState[1][9];
		faces[1][2] = LastState[1][5];
		faces[1][3] = LastState[1][1];
		faces[1][4] = LastState[1][12];
		faces[1][5] = LastState[1][10];
		faces[1][7] = LastState[1][2];
		faces[1][8] = LastState[1][0];
		faces[1][9] = LastState[1][11];
		faces[1][10] = LastState[1][7];
		faces[1][11] = LastState[1][3];
		faces[1][12] = LastState[1][8];

		faces[2][0] = LastState[2][4];
		faces[2][1] = LastState[2][9];
		faces[2][2] = LastState[2][5];
		faces[2][3] = LastState[2][1];
		faces[2][4] = LastState[2][12];
		faces[2][5] = LastState[2][10];
		faces[2][7] = LastState[2][2];
		faces[2][8] = LastState[2][0];
		faces[2][9] = LastState[2][11];
		faces[2][10] = LastState[2][7];
		faces[2][11] = LastState[2][3];
		faces[2][12] = LastState[2][8];

		copyStates();
	}
	/*keep top slice sill and rotate lef and right up date face 2*/
	else if (rot == 6) {
		faces[2][0] = LastState[2][12];
		faces[2][1] = LastState[2][11];
		faces[2][2] = LastState[2][10];
		faces[2][3] = LastState[2][9];
		faces[2][4] = LastState[2][8];
		faces[2][5] = LastState[2][7];
		faces[2][7] = LastState[2][5];
		faces[2][8] = LastState[2][4];
		faces[2][9] = LastState[2][3];
		faces[2][10] = LastState[2][2];
		faces[2][11] = LastState[2][1];
		faces[2][12] = LastState[2][0];

		copyStates();
	}
	/*keep bottom slice sitll and rotate left and right update face 1*/
	else if (rot == 7) {
		faces[1][0] = LastState[1][12];
		faces[1][1] = LastState[1][11];
		faces[1][2] = LastState[1][10];
		faces[1][3] = LastState[1][9];
		faces[1][4] = LastState[1][8];
		faces[1][5] = LastState[1][7];
		faces[1][7] = LastState[1][5];
		faces[1][8] = LastState[1][4];
		faces[1][9] = LastState[1][3];
		faces[1][10] = LastState[1][2];
		faces[1][11] = LastState[1][1];
		faces[1][12] = LastState[1][0];

		copyStates();
	}
}
void GearBall::copyStates() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 13; j++) {
			LastState[i][j] = faces[i][j];
		}
	}

}
void GearBall::setGears() {
	//For every edge piece correctly orient them
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 13; j++) {
			//if there was a horizontal move make sure not to change the states of the edges on faces 1 and 2 and only the horizontal edges
			if (i != 1) {
				if (i != 2) {
					if (j == 0 || j == 12) {
						faces[i][j].setForward(horizTurn);
						faces[i][j].setColor(faces[i][j].getForward());
					}
				}
			}
			//if there was a vertical move make sure not to change the states of the edges on faces 4 and 5 and only the vertical edges
			if (i != 4) {
				if (i != 5) {
					if (j == 4 || j == 8) {
						faces[i][j].setForward(vertTurn);
						faces[i][j].setColor(faces[i][j].getForward());
					}
				}
			}
		}
	}
	copyStates();
}
void GearBall::printBall() {
	//setGears();
	cout << endl;
	for (int i = 0; i <= 5; i++) {
		if (i == 0) {
			cout << "++++--FACE--++++++++++++" << endl;
			cout << "-------" << faces[i][4].getColor() << "----------------" << endl;
			cout << "----" << faces[i][1].getColor() << "--" << faces[i][5].getColor() << "--" << faces[i][9].getColor() << "-------------" << endl;
			cout << "-" <<faces[i][0].getColor() << "--" << faces[i][2].getColor() << "--" << faces[i][6].getColor() << "--" << faces[i][10].getColor() << "--" << faces[i][12].getColor() << "--------" << endl;
			cout << "----" << faces[i][3].getColor() << "--" << faces[i][7].getColor() << "--" << faces[i][11].getColor() << "-------------" << endl;
			cout << "-------" << faces[i][8].getColor() << "----------------" << endl;
			cout << "++++++++++++++++++++++++" << endl;
		}
		else if (i == 1) {
			cout << "+++++++--TOP--++++++++++" << endl;
			cout << "-------" << faces[i][4].getColor() << "----------------" << endl;
			cout << "----" << faces[i][1].getColor() << "--" << faces[i][5].getColor() << "--" << faces[i][9].getColor() << "-------------" << endl;
			cout << "-" << faces[i][0].getColor() << "--" << faces[i][2].getColor() << "--" << faces[i][6].getColor() << "--" << faces[i][10].getColor() << "--" << faces[i][12].getColor() << "--------" << endl;
			cout << "----" << faces[i][3].getColor() << "--" << faces[i][7].getColor() << "--" << faces[i][11].getColor() << "-------------" << endl;
			cout << "-------" << faces[i][8].getColor() << "----------------" << endl;
			cout << "++++++++++++++++++++++++" << endl;
		}
		else if (i == 2) {
			cout << "+++++++--BOTTOM--+++++++" << endl;
			cout << "-------" << faces[i][4].getColor() << "----------------" << endl;
			cout << "----" << faces[i][1].getColor() << "--" << faces[i][5].getColor() << "--" << faces[i][9].getColor() << "-------------" << endl;
			cout << "-" << faces[i][0].getColor() << "--" << faces[i][2].getColor() << "--" << faces[i][6].getColor() << "--" << faces[i][10].getColor() << "--" << faces[i][12].getColor() << "--------" << endl;
			cout << "----" << faces[i][3].getColor() << "--" << faces[i][7].getColor() << "--" << faces[i][11].getColor() << "-------------" << endl;
			cout << "-------" << faces[i][8].getColor() << "----------------" << endl;
			cout << "++++++++++++++++++++++++" << endl;
		}
		else if (i == 3) {
			cout << "++++++--BACK--++++++++++" << endl;
			cout << "-------" << faces[i][4].getColor() << "----------------" << endl;
			cout << "----" << faces[i][1].getColor() << "--" << faces[i][5].getColor() << "--" << faces[i][9].getColor() << "-------------" << endl;
			cout << "-" << faces[i][0].getColor() << "--" << faces[i][2].getColor() << "--" << faces[i][6].getColor() << "--" << faces[i][10].getColor() << "--" << faces[i][12].getColor() << "--------" << endl;
			cout << "----" << faces[i][3].getColor() << "--" << faces[i][7].getColor() << "--" << faces[i][11].getColor() << "-------------" << endl;
			cout << "-------" << faces[i][8].getColor() << "----------------" << endl;
			cout << "++++++++++++++++++++++++" << endl;
		}
		else if (i == 4) {
			cout << "++++++--LEFT--+++++++++" << endl;
			cout << "-------" << faces[i][4].getColor() << "----------------" << endl;
			cout << "----" << faces[i][1].getColor() << "--" << faces[i][5].getColor() << "--" << faces[i][9].getColor() << "-------------" << endl;
			cout << "-" << faces[i][0].getColor() << "--" << faces[i][2].getColor() << "--" << faces[i][6].getColor() << "--" << faces[i][10].getColor() << "--" << faces[i][12].getColor() << "--------" << endl;
			cout << "----" << faces[i][3].getColor() << "--" << faces[i][7].getColor() << "--" << faces[i][11].getColor() << "-------------" << endl;
			cout << "-------" << faces[i][8].getColor() << "----------------" << endl;
			cout << "++++++++++++++++++++++++" << endl;
		}
		else if (i == 5) {
			cout << "+++++++--RIGHT--++++++++" << endl;
			cout << "-------" << faces[i][4].getColor() << "----------------" << endl;
			cout << "----" << faces[i][1].getColor() << "--" << faces[i][5].getColor() << "--" << faces[i][9].getColor() << "-------------" << endl;
			cout << "-" << faces[i][0].getColor() << "--" << faces[i][2].getColor() << "--" << faces[i][6].getColor() << "--" << faces[i][10].getColor() << "--" << faces[i][12].getColor() << "--------" << endl;
			cout << "----" << faces[i][3].getColor() << "--" << faces[i][7].getColor() << "--" << faces[i][11].getColor() << "-------------" << endl;
			cout << "-------" << faces[i][8].getColor() << "----------------" << endl;
			cout << "++++++++++++++++++++++++" << endl;
		}
		//cout << "The number of gears out of place is " << FindOutOfPlace() << endl;
	}
}


