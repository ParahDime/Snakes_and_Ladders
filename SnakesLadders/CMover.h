#include "Header.h"
#include "CPlayer.h"

#pragma once
class CMover
{
private:
	int p1; //tile the player lands on
	int p2; //tile the player moves to
	bool pGoUp; //if true, is ladder. if false, is snake
public:
	CMover(int t1, int t2);
	~CMover();

	int GetPosition();
	int GetEnd();

	void MovePlayer(CPlayer*& player, int& order);


};

