#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;


class coin//coin is defined as whether when it's tossed and which side of the coin is flipped face up
{
	string SideUp;
public:
	coin();
	void toss();
	string getSideUp() { return SideUp; }
};

coin::coin()//A default constructor that randomly determines the side of the coin that is facing up (“heads” or “tails”) and initializes the sideUp member accordingly. 
{
	int side;
	srand(time(0));//set srand to the seed time(0) so the program can actuallly randomize the numbers
	side = rand() % 2;// randomize the number between 1 and 0
	if (side == 0)
		SideUp = "Heads";
	else if (side == 1)
		SideUp = "Tails";
}
void coin::toss()
{
	/*A void member function named toss that simulates the tossing of the coin.
	When the toss member function is called, it randomly determines the side
	of the coin that is facing up (“heads” or “tails”) and sets the sideUp
	member variable accordingly.*/
	int side;
	srand(time(0));
	side = rand() % 2;
	if (side == 0)
		SideUp = "Heads";
	else if (side == 1)
		SideUp = "Tails";
}

int main()
{
	int heads = 0, tails = 0, total = 0;
	coin side;
	//display the face up side of the coin and will warn the user that the coin tosses will be flipped 1000 times and let the user press enter to start the coin flips  
	cout << "The coin is faced on : " << side.getSideUp() << endl;
	cout << "**Warning This program will flip a coin 1000 times don't worry you will have 1/2 a second to see the result of each." << endl;
	cout << "The screen will refresh every time a coin is flipped face up.**"<<endl;
	cout << "If your ready, Press enter to begin";
	cin.get();
	for (int i = 0; i < 1000; i++)//Will toss the coin and if the side up is either heads or tails then count the  respectable side the coin is face up
	{
		//
		system("cls");
		side.toss();
		if (side.getSideUp() == "Heads")
			heads++;
		else if (side.getSideUp() == "Tails")
			tails++;
		cout << (i+1)<<".) Result: " << side.getSideUp()<<endl;
		//Sleep(500);//delay for half a second
		total++;
	}
	system("cls");//Screen will print heads, tails, and missed of the perfect score
	cout << "Heads: " << heads << endl;
	cout << "Tails: " << tails << endl;
	/*double havg = (abs((total / 2) - heads) / static_cast<double>(total / 2)) * 100; <- This assignmet is equivalent to this equation
	                         |    |    |   
							 V    V    V
	*/
	double havg = (abs((total / 2) - heads) / static_cast<double>(total / 2)) * 100;
	double Tavg = (abs((total / 2) - tails) / static_cast<double>(total / 2)) * 100;
	double tavg = (abs(heads-tails) / static_cast<double>(total)) * 100;//take the average from the difference between the number of heads and tails find the percentage of how off from a perfect coin tosses
	cout << "'How off from a perfect coin toss' Percentage: ";
	cout << fixed << setprecision(2) << tavg << "%" << endl;//print 
	cout << fixed << setprecision(2) << havg << "%" << endl;
	cout << fixed << setprecision(2) << Tavg << "%" << endl;
	system("pause");
	return 0;
}