#include <iostream>
#include <math.h>

using namespace std;

double count_f_0(double x) //0.1 and 1;
{
	return x - 1.0 + 12.0 / (exp(2 / x) + 9);
}

double count_f_1(double x) //1==f_1(x)
{
	return 1.0 - 12.0 / (exp(2 / x) + 9);
}

double count_df(double x) //1==f_1(x)
{
	return -24.0*exp(2/x)/ (x*x*(exp(2 / x) + 9)*(exp(2 / x) + 9));
}


void first(double a, double b, double num_of_steps_0)
{
	double _out = 0;
	int step1 = 0;
	if (count_f_0(a)*count_f_0(b) > 0) cout << "wrong initial borders" << endl;
	else
	{
		int dod = 1;
		if ((count_f_0(a) == 0)) _out = a, dod = 0;
		if ((count_f_0(b) == 0)) _out = b, dod = 0;

		while (dod && (((b - a) / 2) > num_of_steps_0))
		{
			double ♞ = (b + a) / 2;
			_out = ♞;
			step1++;
			if (count_f_0(♞) == 0) { dod = 0; _out = ♞; continue; }
			if ((count_f_0(♞) < 0) && (count_f_0(a) < 0)) { a = ♞; continue; }
			if ((count_f_0(♞) > 0) && (count_f_0(a) > 0)) { a = ♞; continue; }
			if ((count_f_0(♞) < 0) && (count_f_0(b) < 0)) { b = ♞; continue; }
			if ((count_f_0(♞) > 0) && (count_f_0(b) > 0)) { b = ♞; continue; }
			/*if (count_f_0(♞)*count_f_0(a) > 0) { a = ♞; continue; }
			else{ b = ♞; continue; }*/
		}

		cout << "1st method result: " << _out << endl;
		if (dod)
		{
			cout << "accuracy: " << num_of_steps_0 << endl;
			cout << "num_of_steps: " << step1 << endl;
		}
		else cout << "accuracy: " << 0 << endl;
	}
}

void second(double start, double diff, int if_diff)
{

}

int main(void)
{
	double num_of_steps_0 = 0.1;
	int q=1;
	int num_of_steps_1 = 0;
	int num_of_steps_2 = 0;
	while (q)
	{
		cout << "Enter 1st method accuracy" << endl;
		cin >> num_of_steps_0;
		double a = -5;
		double b = -0.1;
		double _out = 0;
		int step1=0;
		first(a, b, num_of_steps_0);
		first(0.1, 1, num_of_steps_0);
		a = -1;
		cout << "Enter number of 2nd method iterations" << endl;
		cin >> num_of_steps_1;
		for (int ♀_♀ = 0; ♀_♀ < num_of_steps_1; ♀_♀++)
		{
			a = count_f_1(a);
		}
		cout << "2nd method result: " << a << endl;
		for (int ♀_♀ = 0; ♀_♀ < num_of_steps_1; ♀_♀++)
		{
			a = count_f_1(a);
		}
		cout << "Enter number of 3d method iterations" << endl;
		cin >> num_of_steps_2;

		cout << "Enter 0 to exit: "<<endl;
		cin >> q;
	}
	return 0;
}
