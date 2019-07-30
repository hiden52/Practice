#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <ctime>


double get_rand_real(const double min, const double max)
{
	return (double)rand() / RAND_MAX * (max - min) + min;
}



class Circle
{
private:
	double center_x;
	double center_y;
	double radius;

public:
	Circle(double cntr_x =1, double cntr_y = 1, double r =1)
		: center_x(cntr_x), center_y(cntr_y), radius(r)
	{}
	
	bool isInsideCircle(const double& l_x, const double& l_y)
	{
		double judge = (l_x - center_x) * (l_x - center_x) + (l_y - center_y) * (l_y - center_y) - radius * radius;
		
		return (judge <= 0) ? true : false;
	}
};
int main()
{
    //	random location(x, y) is in circle?
	srand((unsigned int)time(NULL));
	
	Circle circle1(1, 1);

	std::ofstream of("circle.txt");
	
	for (int i = 0; i < 10000; i++)
	{
		double x = get_rand_real(0, 2);
		double y = get_rand_real(0, 2);
		//bool inCircle = circle1.isInsideCircle(x, y);
		
		if (circle1.isInsideCircle(x, y))
		{
			of << x << ", " << y << "\n";
			std::cout << x << ", " << y << "\n";
		}
	}
	
	of.close();

	return 0;
	
}