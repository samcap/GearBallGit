#include <iostream>
#include <string>
#include <queue>
#include <vector>

#include "GearBall.h"
#include "Gear.h"
#include "MoveState.h"


using namespace std;

bool operator<(const GearBall &n1, const GearBall &n2) {
	return n1.f > n2.f;
}
int main() {

	//GearBall ball;
	//ball.rotate(0, 0, 1);
	//ball.rotate(0, 1, 1);
	//ball.rotate(0, 2, 1);
	//ball.rotate(0, 3, 1);
	//ball.printBall();
	int siz;
	double depth = 1;
	Gear stuff[6][13];
	Gear (*temp)[6][13] = &stuff;
	int vert = 0;
	int horiz = 0;
	bool finished = false;
	
	vector<GearBall> ball;
	vector<GearBall> states;
	ball.resize(1);
	int n = ball.size();
	ball[0].rotate(0, 0, 1);
	ball[0].rotate(0, 2, 1);
	ball[0].rotate(0, 0, 1);
	ball[0].rotate(0, 3, 1);
	ball[0].rotate(0, 1, 1);
	ball[0].rotate(0, 2, 1);
	//ball[0].rotate(0, 1, 1);
	

	ball[0].printBall();


	ball[0].getFace(temp, &vert, &horiz);
	ball[0].setDepth(0);

	priority_queue<GearBall> q;

	while (finished == false) {
		ball.resize(n + 4);
		ball[n].setFace(stuff, vert, horiz);
		ball[n + 1].setFace(stuff, vert, horiz);
		ball[n + 2].setFace(stuff, vert, horiz);
		ball[n + 3].setFace(stuff, vert, horiz);

		ball[n].copyStates();
		ball[n + 1].copyStates();
		ball[n + 2].copyStates();
		ball[n + 3].copyStates();


		ball[n].rotate(0, 0, 1);
		ball[n + 1].rotate(0, 1, 1);
		ball[n + 2].rotate(0, 2, 1);
		ball[n + 3].rotate(0, 3, 1);

		ball[n].setDepth(depth);
		ball[n+1].setDepth(depth);
		ball[n+2].setDepth(depth);
		ball[n+3].setDepth(depth);

		ball[n].cost(ball[n].FindOutOfPlace());
		ball[n+1].cost(ball[n+1].FindOutOfPlace());
		ball[n+2].cost(ball[n+2].FindOutOfPlace());
		ball[n+3].cost(ball[n+3].FindOutOfPlace());

		q.push(ball[n]);
		q.push(ball[n+1]);
		q.push(ball[n+2]);
		q.push(ball[n+3]);

		states.push_back(q.top());
		q.pop();
		siz = states.size();
		if (states.back().FindOutOfPlace() == 0) {
			finished = true;
		}
		else {
			states.back().getFace(temp, &vert, &horiz);
		}

		n = ball.size();
		if (states.back().getDepth() < depth) {
			depth = states.back().getDepth();
		}
		depth++;
		//finished = true;
	}
	
	

	/*cout << "Heuristic score for move 1: " << 1 + ball[n].FindOutOfPlace() << endl;
	cout << "Heuristic score for move 2: " << 1 + ball[n+1].FindOutOfPlace() << endl;
	cout << "Heuristic score for move 3: " << 1 + ball[n+2].FindOutOfPlace() << endl;
	cout << "Heuristic score for move 4: " << 1 + ball[n+3].FindOutOfPlace() << endl;*/
	

	//ball.resize(n+6);
	cout << "Found a Solution in: " << states.size() << endl;
	
	cin.ignore();


}
