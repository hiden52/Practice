// MakeAPiano.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

#define NUM_KEY 4

char key_list[] = { 'a', 's', 'd', 'f' };
double frequency_list[] = { 261.6256, 293.6648, 329.6276, 349.2282 };

double getFrequencyFromKey(char key)
{
	for (int i = 0; i < NUM_KEY;++i)
	{
		if (key_list[i] == key)
			return frequency_list[i]; 
	}

	std::cout << "Invaild Key!!" << std::endl;
	return 0.0;
}
void playSound(void)
{
	char ch;
	std::cin >> ch;
	Beep(getFrequencyFromKey(ch), 500);
}
int main()
{
	/*while (true)
		playSound();*/
	
	ifstream input_file("key_mapping.txt");
	string s;

	if (!input_file.is_open())
		cout << "File was not Found.\n";

	int num_keys = 0;

	input_file.seekg(0, ios::end);
	int size = input_file.tellg();

	s.resize(size);

	input_file.seekg(0, ios::beg);
	
	input_file.read(&s[0], size);
	cout << s << endl;

	return 0;
}