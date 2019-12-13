#include <iostream>
#include <string>
using namespace std;

class FeetInches
{
	//store feet, inches, and simplify() function in privated
	int feet;
	int inches;
	void simplify();
public:
	FeetInches() :feet(0), inches(0) { simplify(); }//initialize feet and inches to zero and keep inches simplified
	FeetInches(FeetInches& Obj);
	void setFeet(int f) { feet = f; }// manipulate feet
	void setInches(int i) { inches = i; simplify(); }//manipulate and simplify feet
	int getFeet() { return feet; }//returns feet
	int getInches() { return inches; }//returns inches
	FeetInches operator * (const FeetInches&);
};

FeetInches::FeetInches(FeetInches &obj)//copy constructor
{
	feet = obj.feet;
	inches = obj.inches;
}

FeetInches FeetInches::operator * (const FeetInches &Obj)//multiply operator for classes
{
	FeetInches temp;
	temp.feet = feet * Obj.feet;
	temp.inches = inches * Obj.inches;
	temp.simplify();

	return temp;
}

void FeetInches::simplify()//if inchss is greater than 12 convert inches to feet
{
	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
}


int main()
{
	FeetInches Fool, Magician, Result;
	int feet, inches;
	cout << "Enter feet and inches for the Fool( x y ) "<<endl;
	cin >> feet >> inches;//input both feet and inches for fool
	Fool.setFeet(feet);
	Fool.setInches(inches);

	cout << "Enter feet and inches for the Magician ( x y )"<<endl;
	cin >> feet >> inches;//input both feet and inches for magician
	Magician.setFeet(feet);
	Magician.setInches(inches);

	Result = Fool * Magician;//return the multiple of fool and magician; print the result.
	cout << "Fool * Magician = ";
	cout << Result.getFeet()<<" feet, ";
	cout << Result.getInches() << " inches.\n";

	system("pause");
	return 0;
}