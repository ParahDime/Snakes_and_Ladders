#include "CMover.h"

CMover::CMover(int t1, int t2)
{
	p1 = t1;
	p2 = t2;
}

CMover::~CMover()
{
}

int CMover::GetPosition()
{
	return p1;
}

int CMover::GetEnd()
{
	return p2;
}

void CMover::MovePlayer(CPlayer*& player, int& order)
{
	//set player position to p2
	player->SetPosition(p2);

	if (p1 > p2) { //if snake
		cout << "Player " << order << " landed on a snake!\n";
		cout << "They moved down to space " << player->GetPosition() << "\n";
	}
	else //else ladder
	{
		cout << "Player " << order << " landed on a ladder!\n";
		cout << "They moved to space " << player->GetPosition() << "\n";
	}

	
}
