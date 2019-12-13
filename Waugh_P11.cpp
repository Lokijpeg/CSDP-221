#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Dice_Fish//Class Dice Fish will roll 2 six-sided dice and assign the object/fish to which total number of dices you rolled
{
	int Total_D_Roll;
	int Score=0;
	string Obj;
public:
	Dice_Fish();
	string getFish() { return Obj; }
	int getScore() { return Score; }
	void RollDice();
	void CheckScore();//Looks at Total_D_Roll and assign the name to Obj and add the score in the respective total dice rolls.
};

void Dice_Fish::CheckScore()
{
	switch(Total_D_Roll)
	{
	case 2:
		Obj = "Sea Snake";
		Score -= 12;
		break;
	case 3:
		Obj = "Old Shoe";
		Score -= 1;
		break;
	case 4:
		Obj = "goldfish";
		Score += 1;
		break;
	case 5:
		Obj = "Tin Can";
		Score -= 2;
		break;
	case 6:
		Obj = "Koi";
		Score += 2;
		break;
	case 7:
		Obj = "Clown Fish";
		Score += 3;
		break;
	case 8:
		Obj = "Octopus";
		Score += 4;
		break;
	case 9:
		Obj = "Alaska Salmon";
		Score += 5;
		break;
	case 10:
		Obj = "Jellyfish";
		Score += 6;
		break;
	case 11:
		Obj = "Blue Crab";
		Score += 7;
		break;
	case 12:
		Obj = "Pufferfish";
		Score += 12;
		break;
	}
}

void Dice_Fish::RollDice()//roll the dice and add up both side up dice to total dice 
{
	int D1, D2;
	srand(time(0));
	D1 = rand() % 6 + 1;
	D2 = rand() % 6 + 1;
	Total_D_Roll = D1 + D2;
}
Dice_Fish::Dice_Fish()//This will give total D roll a initilization
{
	int D1, D2;
	srand(time(0));
	D1 = rand()
		% 6 + 1;
	D2 = rand() % 6 + 1;
	Total_D_Roll = D1 + D2;
}
int main()
{
	Dice_Fish Game;//create the dices and objects
	int round=0;//count the rounds that has been looped in the game
	string fishes;//add up to the words of fishes or objects to this variable
	char confirm;//confirmation of the players response on whether the user wants to quit fishing
	cout << "Welcome to Rod n' Reel the game." << endl;
	cout << "---Points you earn---"<<endl;
	cout << "Goldfish= 1\nKoi= 2\nClown Fish= 3\nOctopus= 4\nAlaska Salmon= 5\nJellyfish= 6\nBlue Crab= 7\nPuffer Fish= 12" << endl;
	cout << "---Points you lose---" << endl;
	cout << "Old shoe= -1\nTin can= -2\nSea snake= -12" << endl;
	do {
		cout<<"Round "<<(round+1)<<endl;
		cout << "Press enter to roll the dice" << endl;
		system("pause");
		Game.RollDice();
		Game.CheckScore();
		fishes += Game.getFish() + "\n";
		cout << "Do you wish to continue to fish(y/n) " << endl;
		cout << "confirm: ";
		cin >> confirm;
		confirm = tolower(confirm);
		if (confirm == 'y')//if the user wants to do it again then add another round
			round++;
		system("cls");
	} while (confirm == 'y');

	if (Game.getScore() < 0)//if score less than 0 you lose if greater than zero
		cout << "Too bad ";//get your score
	else
		cout << "Congradulations ";

	cout<<"your score is " << Game.getScore() << endl;
	if (round > 1)
		cout << "After " << (round + 1) << " Rounds ";
	else
		cout << "After " << (round + 1) << " Round ";
	cout <<"This is how many fishes you collected\n"<<fishes<<endl;//display the fishes
	system("pause");
	return 0;
}