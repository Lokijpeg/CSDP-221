#include <iostream>
#include <cmath>
#include <iomanip>
#include <complex>
using namespace std;

int discriminant(double, double, double);
void quadratic(double, double, double, int);

int main()
{
	double A, B, C;
	char cont;
	do {
		cout << "Discriminate:\n 1 = Positive\n -1 = Negative\n 0 = Zero."<<endl;
		cout << "Enter value A :";
		cin >> A;
		if (A == 0)
		{
			cout << "error A can't be zero.";
			system("pause");
			return 0;
		}
		cout << "Enter value B :";
		cin >> B;
		if (B == 0)
			B = 0.0;
		cout << "Enter value C :";
		cin >> C;
		if (C == 0)
			C = 0.0;
		int n = discriminant(A, B, C);
		quadratic(A, B, C, n);
		cout << "\ndo you wish to do it again (y/n)" << endl;
		cin >> cont;
	} while (tolower(cont) != 'n');
	system("pause");
	return 0;
}

void quadratic(double a, double b, double c, int quad)
{
	int d = sqrt(pow(b, 2.0)- 4*a*c);
	double 	positive = ((-b) + d) / static_cast<double>(2.0 * a);//quadratic formula
	double negative = ((-b) - d) / static_cast<double>((2.0 * a));
	cout << "Discriminate = " << quad<<endl;
	if (quad <= 0)
	{
		d = sqrt(abs(pow(b, 2.0) - 4 * a * c));
		positive = ((-b) + d) / static_cast<double>(2.0 * a);//quadratic formula
		negative = ((-b) - d) / static_cast<double>((2.0 * a));
		cout << "A = " << a << " B = " << b << " C = " << c << " ## " << "X = " << fixed << setprecision(4) << positive << "i. X = " << fixed << setprecision(4) << negative<<"i";
	}
	else
		cout << "A = " << a << " B = " << b << " C = " << c << " ## " << "X = " << fixed << setprecision(4) << positive<< ". X = " << fixed << setprecision(4) << negative;
}
int discriminant(double a, double b, double c)
{
	int total = pow(b, 2) - 4*a*c;
	int result;
	if (total > 0)
		result = 1;
	else if (total < 0)
		result = -1;
	else if (total == 0)
		result = 0;

	return result;
}