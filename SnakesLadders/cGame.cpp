#include "cGame.h"

CGame::CGame()
{
	mRound = 1;
}

CGame::~CGame()
{
}

void CGame::SetRound()
{
	mRound++;
}

int CGame::GetRound()
{
	return mRound;
}

int CGame::GetDie()
{
	return mDice;
}

void CGame::SetBoard(int& tBoard)
{
	mBoardSize = tBoard;
}

int CGame::GetBoard()
{
	return mBoardSize;
}

void CGame::SetPlayers(int& tPlayers)
{
	mPlayers = tPlayers;
}

int CGame::GetPlayers()
{
	return mPlayers;
}

void CGame::SetGame(istream& inputstream)
{
	mRound = 1;
	inputstream >> *this;
	
}

bool CGame::GetMode()
{
	return mMode;
}

void CGame::SetMode(bool& tMode)
{
	mMode = tMode;
}


istream& operator>>(istream& inputstream, CGame& cGame)
{
	// TODO: insert return statement here
	//players dice rules

	inputstream >> cGame.mPlayers >> cGame.mDice;
	return inputstream;
}
