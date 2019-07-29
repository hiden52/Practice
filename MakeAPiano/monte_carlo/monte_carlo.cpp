#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

double getRandomNum(const double min, const double max);

bool isInsideCircle(const double x, const double y);

double estimatePI(const double num_pts_square)
{
	int num_pts_circle = 0;

	for (int i = 0; i < num_pts_square; i++)
	{
		const double x = getRandomNum(0, 1);
		const double y = getRandomNum(0, 1);

		if (isInsideCircle(x, y) == true)
		{
			num_pts_circle++;
		}
	}

	const double pi_mc = 4 * (double)num_pts_circle / (double)num_pts_square;

	return pi_mc;
}


int main()
{
	//ofstream of("circle.txt"); 
	ofstream of("pi.txt");

	srand((unsigned int)time(NULL));

	int num_spuare = 0;
	int num_circle = 0;


	for (int num_pts_square= 10; num_pts_square < 100000000; num_pts_square *= 2)
	{
		//int num_pts_circle = 0;

		//for (int i = 0; i < num_pts_square; i++)
		//{
		//	const double x = getRandomNum(0, 1);
		//	const double y = getRandomNum(0, 1);

		//	if (isInsideCircle(x, y) == true)
		//	{
		//		num_pts_circle++;

		//		//cout << x << ", " << y << endl;
		//		of << x << ", " << y << endl;
		//	}
		//}

		//const double pi_mc = 4 * (double)num_pts_circle / (double)num_pts_square;

		//cout << num_pts_square << " " << pi_mc << endl;

		double pi_mc = estimatePI(num_pts_square);

		cout << "Estimated pi with " << num_pts_square << " randm pts is " << pi_mc << endl;
		of << pi_mc << endl;
	}

	of.close();

	return 0;
}

double getRandomNum(const double min, const double max)
{
	const double random_number = (double)rand() / (double)RAND_MAX;

	return min + (max - min) * random_number;
}

bool isInsideCircle(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x - x_c) * (x - x_c) + (y - y_c) * (y - y_c) - r * r;

	return (f < 0.0) ? true : false;
}