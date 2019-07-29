//const int start_age = 28;
//const int end_age = 120;
//const double start_salary = 0.45;
//const double salary_increase_rate = 0.03;
//
//double annual_salary = start_salary;
//double income_sum = 0;
//double sum_salary = 0;
//
//ofstream out_file("income.txt");
//
//for (int age = start_age; age <= 54; age++, annual_salary *= (1.0 + salary_increase_rate))
//{
//	income_sum += annual_salary * 0.7;
//	sum_salary += annual_salary;
//	out_file << age << " " << annual_salary << " " << income_sum << endl;
//}
//
//annual_salary *= 0.5;
//
//for (int age = 55; age <= 60; age++)
//{
//	income_sum += annual_salary * 0.7;
//	sum_salary += annual_salary;
//	out_file << age << " " << annual_salary << " " << income_sum << endl;;
//}
//
//const double salary_average = sum_salary / (double)(60 - start_age + 1);
//for (int age = 61; age < end_age; age++)
//{
//	income_sum += salary_average;
//
//	out_file << age << " " << salary_average << " " << income_sum << endl;;
//}
//
//out_file.close();