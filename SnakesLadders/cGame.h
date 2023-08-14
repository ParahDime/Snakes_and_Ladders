#include "Header.h"
#pragma once
class CGame
{
private:
	int mRound;
	int mPlayers;
	int mDice;
	int mBoardSize;
	bool mMode; //if false, normal. if true, cruel mode

	//enum mMode { Normal, Cruel, Wildcard };//difficulty
	//mMode mDifficulty;

public:
	CGame();
	~CGame();

	void SetRound();
	int GetRound();

	int GetDie();

	void SetBoard(int& tBoard);
	int GetBoard();

	void SetPlayers(int& tPlayers);
	int GetPlayers();
	void SetGame(istream& inputstream);

	bool GetMode();
	void SetMode(bool& tMode);

	friend istream& operator >> (istream& inputstream, CGame& cGame);

};

