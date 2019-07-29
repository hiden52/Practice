#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

double getRndNum(const double min, const double max);

double estimateIncome();

double getAverageIncome(const int num_itr);

int main()
{
	srand((unsigned int)time(NULL));

	// 누적연봉 14.0천만원이 넘는 케이스 출력
	/*double est_income = 0;
	for (int i = 0; i < 10000; ++i)
	{
		est_income = estimateIncome();
		if (est_income > 14.0)
		{
			cout << est_income << endl;
			break;
		}
	}*/

	for (int i = 1; i < 100000; i *= 2)
	{
		cout << "Monte Carlo itr = " << i << ", Sum = " << getAverageIncome(i) << endl;
	}

	return 0;
}

double getRndNum(const double min, const double max)
{
	double tmp = (double)rand() / (double)RAND_MAX;
	
	tmp = min + (max - min) * tmp;

	return tmp;
}

double estimateIncome()
{
	ofstream of("annual_salary.txt");

	double annual_salary = 0.3;
	double income_sum = 0;

	for (int age = 28; age < 55; age++)
	{
		income_sum += annual_salary;

		of << annual_salary;
		//const double salary_increase = 0.03;
		const double salary_increase = getRndNum(0.0, 0.06);

		annual_salary *= (1.0 + salary_increase);

		of << " " << salary_increase << "\n";

	}

	of.close();

	return income_sum;
}

double getAverageIncome(const int num_itr)
{
	double sum = 0;
	for (int i = 0; i < num_itr; i++)
	{
		sum += estimateIncome();
	}

	return sum / (double)num_itr;
}