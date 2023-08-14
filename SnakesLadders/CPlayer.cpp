#include "CPlayer.h"

CPlayer::CPlayer(int tName, int tPosition)
{
	mName = tName;
	mPosition = tPosition;
}

CPlayer::~CPlayer()
{
}

void CPlayer::SetName(int& tName)
{
	mName = tName;
}

int CPlayer::GetName()
{
	return mName;
}

void CPlayer::SetPosition(int& tPosition)
{
	mPosition = tPosition;
}

void CPlayer::AddPosition(int& tPosition)
{
	mPosition += tPosition;
}

int CPlayer::GetPosition()
{
	return mPosition;
}
