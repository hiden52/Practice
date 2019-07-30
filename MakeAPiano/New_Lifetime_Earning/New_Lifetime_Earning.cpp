#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	double annual_salary = 0.3;
	cout << "Input your firtst annual salary = ";
	cin >> annual_salary;

	int start_age = 25, retire_age = 60;;
	cout << "Input your start age and retirement age = ";
	cin >> start_age >> retire_age;
	//cout << "Input your retirement age = ";
	//cin >> retire_age;

	double annual_salary_increase = 0.03;
	cout << "Input your annual salary increase rate ( 03% -> 0.03 ) = ";
	cin >> annual_salary_increase;

	double total_income = 0;

	ofstream of("annual_salary.txt");

	for (int age = start_age; age < retire_age; ++age)
	{
		cout << "Age = " << age << ", Annual salary = " << annual_salary << endl;
		of << age << ", " << annual_salary << ", " << total_income << endl;

		total_income += annual_salary;
		if (age < 54)
			annual_salary *= (annual_salary_increase + 1.0);
	}

	cout << "Total income in your life = " << total_income;
	of << "\n " << "Total income " << total_income;

	of.close();

	return 0;
}