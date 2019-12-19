#include <iostream>
#include <string>
using namespace std;

const int Good_score = 17;//Recommended score to search in the get order and sum of points string
bool sum_of_points(int[]);//if sum of points equals to the good score then return true; else, return false
string getorder(int[]);//return the order of the number of balls that can equal to the good score
int main()
{
	const int Num_of_boxes = 4;//number of boxes
	int box[Num_of_boxes]{ 0,0,0,0 };
	string order;
	cout << "Box 1 = 1 point.\nBox 2 = 2 points.\nBox 3 = 3 points.\nBox 4 = 4 points.\n";//display the points for each boxes
	cout << "Display: ( box 1, box 2, box 3, box 4 )." << endl;//display the format of each boxes
	order = getorder(box);//get the order of the list
	cout << order;//prints the order of the list
	system("pause");
	return 0;
}


bool sum_of_points(int box[])
{
	if ((box[0] * 1) + (box[1] * 2) + (box[2] * 3) + (box[3] * 4) == Good_score)
		return true;
	else
		return false;
}

string getorder(int boxes[])//Look at each individual order by counting down from 9 9 9 9 to 0 0 0 0 if one of the following loops have add up greater than the good score than continue the loop.
{
	int Num_of_balls = 9;
	int total = 0;
	string order;
	for (int i = Num_of_balls; i > -1; i--)
	{
		boxes[0] = i;
		if ((boxes[0] * 1) + (boxes[1] * 2) + (boxes[2] * 3) + (boxes[3] * 4) <= Good_score)
		{
			for (int j = Num_of_balls; j > -1; j--)
			{
				boxes[1] = j;
				if ((boxes[0] * 1) + (boxes[1] * 2) + (boxes[2] * 3) + (boxes[3] * 4) <= Good_score)
				{
					for (int k = Num_of_balls; k > -1; k--)
					{
						boxes[2] = k;
						if ((boxes[0] * 1) + (boxes[1] * 2) + (boxes[2] * 3) + (boxes[3] * 4) <= Good_score)
						{
							for (int l = Num_of_balls; l > -1; l--)
							{
								boxes[3] = l;
								if (sum_of_points(boxes))
								{
									total += 1;
									order += to_string(total) + ".) ( " + to_string(boxes[0]) + ", " + to_string(boxes[1]) + ", " + to_string(boxes[2]) + ", " + to_string(boxes[3]) + " )\n";
								}
								else
									continue;
							}
						}
						else
							continue;
					}
				}
				else
					continue;
			}
		}
		else
			continue;
	}
	return order;
}