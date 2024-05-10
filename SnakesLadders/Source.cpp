#include "Header.h"
#include "CGame.h"
#include "CPlayer.h"
#include "CMover.h"



//control the RNG
int RNG()
{
	//use randomiser function to return a value
	unique_ptr<int> num = make_unique<int>();

	//make random here

	*num = static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6 + 1);

	//if equal to 0, recursive call
	if (*num == 0)
	{
		RNG();
	}

	return *num;
}

bool comparePlayers(CPlayer* a, CPlayer* b) {
	return a->GetPosition() > b->GetPosition(); // Sort in descending order of position
}


//output final positions and place
void LeaderBoard(vector<CPlayer*>& players, unique_ptr<CGame>& game)
{
	unique_ptr<int>pPosition = make_unique<int>();

	//bubble sort
	std::sort(players.begin(), players.end(), comparePlayers);

	for (*pPosition = 0; *pPosition < game->GetPlayers(); ++*pPosition)
	{
		cout << "Position " << *pPosition + 1 << ": Player " << players[*pPosition]->GetName() << "\n";
		cout << "End position: space " << players[*pPosition]->GetPosition() << "\n";
	}
}


//used for playing a round
void GameRound(vector<CPlayer*>& players, unique_ptr<CGame>& game, vector<CMover*> movement, unique_ptr<bool>& pRunning)
{
	unique_ptr<int> pPerson = make_unique<int>();
	unique_ptr<int> pPosition = make_unique<int>();

	//use a for loop
	for (*pPerson = 0; *pPerson < game->GetPlayers(); ++*pPerson)
	{
		
		unique_ptr<int> pAmount = make_unique<int>(0); //stores the combined value for the roll
		
		for (int i = 1; i <= game->GetDie(); i++)
		{
			*pAmount += RNG();//player rolls the die

		}
		
		//player is moved on the board
		players[*pPerson]->AddPosition(*pAmount);
		*pPosition = players[*pPerson]->GetPosition();

		cout << "Player " << players[*pPerson]->GetName() << " rolled a " << *pAmount << "\n";
		cout << "Player is now on space " << *pPosition << "\n";

		//check if they landed on a ladder/snake
		for (int i = 0; i  < movement.size(); i++) {
			if (*pPosition == movement[i]->GetPosition()) {
				//if on a square that is the start
				//move to the end, using class function
				movement[i]->MovePlayer(players[*pPerson], *pPerson);
			}
		}

		//if mode is set to cruel and players position is over 100
		if ((game->GetMode() == true) &&(players[*pPerson]->GetPosition() > game->GetBoard()))
		{
				unique_ptr<int> pOver = make_unique<int>();
				*pOver = *pPosition - 100;
				*pOver = 100 - *pOver;

				players[*pPerson]->SetPosition(*pOver);
				cout << "Player " << *pPerson + 1 << " landed over the board. They were moved back " << (100 - *pOver) * 2 << " spaces\n";
				cout << "Player is now on space " << *pOver << "\n";
		}
		
		if (players[*pPerson]->GetPosition() >= game->GetBoard()) {
			cout << "Player " << *pPerson + 1 << " wins!\n";
			*pRunning = false;
			return;
		}
	}
}




//Read the contents of the file
void ReadBoard(ifstream& file, unique_ptr<CGame>& game, vector<CMover*>& movement, unique_ptr<bool>& debug)
{
	//read in the file as it comes
	unique_ptr<int> pReader = make_unique<int>();
	unique_ptr<int> pSecond = make_unique<int>();

	//read in the board size
	file >> *pReader;
	game->SetBoard(*pReader);
	
	//loop the file while not at the end
	do {
			//read the first value
			file >> *pReader;
			//read the second value
			file >> *pSecond;

			//if mode is set to cruel
			if (game->GetMode() == true)
			{
				//if first value is lower than second (ladder)
				//then convert to snake
				if (*pReader < *pSecond)
				{
					unique_ptr<int> pThird = make_unique<int>();
					*pThird = *pReader;
					*pReader = *pSecond;
					*pSecond = *pThird;
				}

			}
			//push back the movement vector with the value
			movement.push_back(new CMover(*pReader, *pSecond));
	} while (!file.eof());

}



//checks the file can be read
template <class S, class T, class U> bool CheckFile(S& file, T& fileName, U& debug)
{
	if (!file)
	{
		if (debug) {
			cout << "ERROR!\n";
			cout << "File could not be loaded\n";
		}
		return false;
	}
	else
	{
		if (debug) {
			cout << fileName << " loaded successfully\n";
		}
		return true;
	}

}



//main function of the file 
int main() {
	//define variables

	unique_ptr<int> KMaxPlayers = make_unique<int>(4);

	unique_ptr<bool> pDebug = make_unique<bool>(true);
	unique_ptr<bool> pRunning = make_unique<bool>(true);
	
	unique_ptr<CGame> pGame = make_unique<CGame>();
	unique_ptr<string> pFileName = make_unique<string>();

	vector<CPlayer*> pPlayers = {}; //stores individual players
	vector<CMover*> pMovement = {}; //used to hold the snake and ladder

	//set the variables

		//read in the file 
	*pFileName = "Rules.txt";
	ifstream fileName2(*pFileName);

	//if file can be read
	if (CheckFile(fileName2, *pFileName, pDebug))
	{
		//ReadRules(fileName2, pDebug, pGame);
		pGame->SetGame(fileName2);
		bool tBool;
		fileName2 >> tBool;
		pGame->SetMode(tBool);
	}
	else
	{
		return 0;
	}

	fileName2.close();

	//rename the string
	*pFileName = "Board.txt";

	//read in files
	ifstream fileName(*pFileName);

	//if file can be read
	if (CheckFile(fileName, *pFileName, pDebug)) {
		//read the file contents
		ReadBoard(fileName, pGame, pMovement, pDebug);
	}
	else {
		return 0;
	}
	fileName.close();

	

	//for the amount of players set
	for (int i = 1; i <= pGame->GetPlayers(); i++)
	{
		//create a new player
		pPlayers.push_back(new CPlayer(i, 0));
		if (pDebug) {
			cout << "Player " << pPlayers[i - 1]->GetName() << " initialised\n";
		}
	}
	
	//play game
	while (*pRunning) {
		cout << "Round " << pGame->GetRound() << "\n";
		//move to function
		GameRound(pPlayers, pGame, pMovement, pRunning);
		pGame->SetRound();
	}

	LeaderBoard(pPlayers, pGame);
	return 0;
}