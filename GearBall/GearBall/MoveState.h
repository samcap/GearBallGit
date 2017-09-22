#ifndef	MOVESTATE_H
#define MOVESTATE_H
class MoveState
{
public:
	MoveState();
	~MoveState();
	void setID(int id);
	void setScore(int num);
	int getID();
	double getScore();
private:
	int moveID;
	double score;
};
#endif

