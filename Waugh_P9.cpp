#include <iostream>
#include <string>
using namespace std;

class car
{
private://hide the model, brand, year, and speed of the car object
	string model, brand;
	int year;
	double speed;
public:
	car(int, string, string);//constructor argument
	//Accessor – Appropriate accessor functions to get the values stored in an object’s
	//year, Model, make, and speed member variables.
	int getYear() { return year; }//accessor of year, speed, model, and brand 
	double getSpeed() { return speed; }
	string getModel() { return model; }
	string getBrand() { return brand; }
	void setYear(int y) { year = y; }//mutator of year, speed, model, and brand
	void setSpeed(double s) { speed = s; }
	void setModel(string m) { model=m; }
	void setBrand(string b) { brand=b; }
	//accelerate – The accelerate function should add 12.5 to the speed member
	//variable each time it is called.
	double acceleration() { return speed+=12.5; }
	//brake – The brake function should subtract 11.5 from the speed member variable
	//each time it is called.
	double brake() { return speed-=11.5; }
};
car::car(int y, string m, string b)
{
	//Constructor – The constructor should accept the car’s year, model and make as
	//arguments.The values should be assigned to the object’s year, Model and make
	//	member variables.The constructor should also assign 0 to the speed member
	//	variables.
	year = y;
	model = m;
	brand = b;
	speed = 0;
}

int main()
{
	int year=0;//define year, model, and brand
	string model, brand;
	car info(year,model, brand);//define car object
		cout << "Enter your car's year" << endl;
		cout << "Year: ";
		cin >> year;//enter year
		info.setYear(year);
		cout << "\nEnter your car's model" << endl;
		cout << "Model: ";
		cin.ignore();
		getline(cin, model);//enter model
		info.setModel(model);
		cout << "\nEnter your car's brand" << endl;
		cout << "Brand: ";
		getline(cin,brand);//enter brand
		info.setBrand(brand);
		for (int i = 0; i < 5; i++)
		{
			info.acceleration();//call the objects acceleration 5 times
		}
		for (int i = 0; i < 5; i++)
		{
			info.brake();//call the object break 5 times
		}
		//print information of car and how fast it went
		cout << "Year: "<<info.getYear() << endl;
		cout << "Model: " << info.getModel() << endl;
		cout << "Brand: " << info.getBrand() << endl;
		cout << "Speed: "<<info.getSpeed() << endl;

	system("pause");
	return 0;
}