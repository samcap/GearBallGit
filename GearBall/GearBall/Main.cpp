#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stdlib.h>

#include "GearBall.h"
#include "Gear.h"
#include "MoveState.h"


using namespace std;

bool operator<(const GearBall &n1, const GearBall &n2) {
	return n1.f > n2.f;
}
int main() {

double depth = 1;
Gear stuff[6][13];
Gear(*temp)[6][13] = &stuff;
int vert = 0;
int horiz = 0;
bool finished = false;
string num = "";


cout << "Enter the number of states you would like to randomize: ";
getline(cin, num);

vector<GearBall> ball;
vector<GearBall> states;
int n = 0;
ball.resize(1);

for (int it = 0; it < 5; it++) {
	
	ball.resize(1);
	n = ball.size();
	//randomize the first gearball state based on the users input
	ball[0].randomize(stoi(num));
	//ball[0].printBall();


	//make sure the ball is not finished already
	if (ball[0].FindOutOfPlace() == 0) {
		cout << "state was already solved by randomizer. " << endl;
		ball.clear();
		finished = false;
	}
	else {
		//set a temp array to the state of the random gearball
		ball[0].getFace(temp, &vert, &horiz);
		ball[0].setDepth(0);

		priority_queue<GearBall> q;
		//create 4 more gearballs representing the 4 moves that can be preformed
		ball.resize(n + 4);
		//apply the random state to the balls
		ball[n].setFace(stuff, vert, horiz);
		ball[n + 1].setFace(stuff, vert, horiz);
		ball[n + 2].setFace(stuff, vert, horiz);
		ball[n + 3].setFace(stuff, vert, horiz);

		ball[n].copyStates();
		ball[n + 1].copyStates();
		ball[n + 2].copyStates();
		ball[n + 3].copyStates();

		//apply the move to each ball and record what type of movement it was
		ball[n].rotate(0, 0, 1);
		ball[n].typeOfMove = "Down ";
		ball[n + 1].rotate(0, 1, 1);
		ball[n + 1].typeOfMove = "Up ";
		ball[n + 2].rotate(0, 2, 1);
		ball[n + 2].typeOfMove = "Left ";
		ball[n + 3].rotate(0, 3, 1);
		ball[n + 3].typeOfMove = "Right ";

		//set the depth of the moves
		ball[n].setDepth(depth);
		ball[n + 1].setDepth(depth);
		ball[n + 2].setDepth(depth);
		ball[n + 3].setDepth(depth);

		//callculate the h(n) value for the heuristc and then calcualte the cost f(n)
		ball[n].cost(ball[n].FindOutOfPlace());
		ball[n + 1].cost(ball[n + 1].FindOutOfPlace());
		ball[n + 2].cost(ball[n + 2].FindOutOfPlace());
		ball[n + 3].cost(ball[n + 3].FindOutOfPlace());

		//push the states onto the priority queue
		q.push(ball[n]);
		q.push(ball[n + 1]);
		q.push(ball[n + 2]);
		q.push(ball[n + 3]);

		//push the state thats on top of the queue on to the states visited vector
		states.push_back(q.top());
		//pop of the top of the queue
		q.pop();

		//check to see if the ball is solved
		if (states.back().FindOutOfPlace() == 0) {
			finished = true;
		}
		//if net reset the temporary array to the state that was chosen
		else {
			states.back().getFace(temp, &vert, &horiz);
		}
		//rest the depth if we decide to back track
		if (states.back().getDepth() < depth) {
			depth = states.back().getDepth();
		}
		depth++;

		//loop through what we just did until we find the completed state
		while (finished == false) {
			//These moves are now restriced since we dont wnat to do the move that could reverse the previous
			//since this could cause cycling.
			if (states.back().typeOfMove == "Down ") {
				ball.resize(n + 3);
				ball[n].setFace(stuff, vert, horiz);
				ball[n + 1].setFace(stuff, vert, horiz);
				ball[n + 2].setFace(stuff, vert, horiz);

				ball[n].copyStates();
				ball[n + 1].copyStates();
				ball[n + 2].copyStates();



				ball[n].rotate(0, 0, 1);
				ball[n].typeOfMove = "Down ";
				ball[n + 1].rotate(0, 2, 1);
				ball[n + 1].typeOfMove = "Left ";
				ball[n + 2].rotate(0, 3, 1);
				ball[n + 2].typeOfMove = "Right ";


				ball[n].setDepth(depth);
				ball[n + 1].setDepth(depth);
				ball[n + 2].setDepth(depth);


				ball[n].cost(ball[n].FindOutOfPlace());
				ball[n + 1].cost(ball[n + 1].FindOutOfPlace());
				ball[n + 2].cost(ball[n + 2].FindOutOfPlace());


				q.push(ball[n]);
				q.push(ball[n + 1]);
				q.push(ball[n + 2]);

			}
			else if (states.back().typeOfMove == "Up ") {
				ball.resize(n + 3);
				ball[n].setFace(stuff, vert, horiz);
				ball[n + 1].setFace(stuff, vert, horiz);
				ball[n + 2].setFace(stuff, vert, horiz);


				ball[n].copyStates();
				ball[n + 1].copyStates();
				ball[n + 2].copyStates();



				ball[n].rotate(0, 1, 1);
				ball[n].typeOfMove = "Up ";
				ball[n + 1].rotate(0, 2, 1);
				ball[n + 1].typeOfMove = "Left ";
				ball[n + 2].rotate(0, 3, 1);
				ball[n + 2].typeOfMove = "Right ";


				ball[n].setDepth(depth);
				ball[n + 1].setDepth(depth);
				ball[n + 2].setDepth(depth);


				ball[n].cost(ball[n].FindOutOfPlace());
				ball[n + 1].cost(ball[n + 1].FindOutOfPlace());
				ball[n + 2].cost(ball[n + 2].FindOutOfPlace());


				q.push(ball[n]);
				q.push(ball[n + 1]);
				q.push(ball[n + 2]);
			}
			else if (states.back().typeOfMove == "Left ") {
				ball.resize(n + 3);
				ball[n].setFace(stuff, vert, horiz);
				ball[n + 1].setFace(stuff, vert, horiz);
				ball[n + 2].setFace(stuff, vert, horiz);


				ball[n].copyStates();
				ball[n + 1].copyStates();
				ball[n + 2].copyStates();



				ball[n].rotate(0, 1, 1);
				ball[n].typeOfMove = "Up ";
				ball[n + 1].rotate(0, 0, 1);
				ball[n + 1].typeOfMove = "Down ";
				ball[n + 2].rotate(0, 2, 1);
				ball[n + 2].typeOfMove = "Left ";


				ball[n].setDepth(depth);
				ball[n + 1].setDepth(depth);
				ball[n + 2].setDepth(depth);


				ball[n].cost(ball[n].FindOutOfPlace());
				ball[n + 1].cost(ball[n + 1].FindOutOfPlace());
				ball[n + 2].cost(ball[n + 2].FindOutOfPlace());


				q.push(ball[n]);
				q.push(ball[n + 1]);
				q.push(ball[n + 2]);
			}
			else if (states.back().typeOfMove == "Right ") {
				ball.resize(n + 3);
				ball[n].setFace(stuff, vert, horiz);
				ball[n + 1].setFace(stuff, vert, horiz);
				ball[n + 2].setFace(stuff, vert, horiz);


				ball[n].copyStates();
				ball[n + 1].copyStates();
				ball[n + 2].copyStates();



				ball[n].rotate(0, 1, 1);
				ball[n].typeOfMove = "Up ";
				ball[n + 1].rotate(0, 0, 1);
				ball[n + 1].typeOfMove = "Down ";
				ball[n + 2].rotate(0, 3, 1);
				ball[n + 2].typeOfMove = "Right ";


				ball[n].setDepth(depth);
				ball[n + 1].setDepth(depth);
				ball[n + 2].setDepth(depth);


				ball[n].cost(ball[n].FindOutOfPlace());
				ball[n + 1].cost(ball[n + 1].FindOutOfPlace());
				ball[n + 2].cost(ball[n + 2].FindOutOfPlace());


				q.push(ball[n]);
				q.push(ball[n + 1]);
				q.push(ball[n + 2]);
			}


			states.push_back(q.top());
			q.pop();

			if (states.back().FindOutOfPlace() == 0) {
				finished = true;
			}
			else {
				states.back().getFace(temp, &vert, &horiz);
			}
			if (states.back().getDepth() < depth) {
				depth = states.back().getDepth();
			}
			depth++;
		}



		//print the number of states in the states vector and what the final depth of the solution was
		cout << "Visited: " << states.size()<< " Nodes in order to find a solution." << "The final depth was "<< states.back().getDepth()<< endl;
		/*for (int i = 0; i < states.size(); i++) {
			cout << states[i].typeOfMove << endl;
		}*/
		//reset all the variables to start solving the next states.
		ball.resize(1);
		ball.clear();
		states.resize(1);
		states.clear();
		depth = 0;
		finished = false;
	}
	

}
cout << "PROGRAM DONE PRESS ENTER TO QUIT!!" << endl;
cin.ignore();


}
