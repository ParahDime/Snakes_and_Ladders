#pragma once
class CPlayer
{
private:
	int mName;
	int mPosition;
public:
	CPlayer(int tName, int tPosition);
	~CPlayer();

	void SetName(int& tName);
	int GetName();

	void SetPosition(int& tPosition);
	void AddPosition(int& tPosition);
	int GetPosition();
};

