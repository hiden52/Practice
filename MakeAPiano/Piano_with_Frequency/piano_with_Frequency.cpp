#include <iostream>
#pragma comment (lib, "winmm.lib")
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

//constexpr int NUM_NOTES = 10;
//
////char key_m[NUM_NOTES] = { 'a', 's', 'd','f','j','k','l',';' };
////unsigned long freq_m[NUM_NOTES] = { 261, 293, 329, 349, 391, 440, 493, 523 };
char* key_m = NULL;
string* sound_m = NULL;

string findFreq(const char key, const int num_keys);


int main()
{
	unsigned long time_check = timeGetTime();

	ifstream inf;
	inf.open("key_table.txt", ios::in);
	int key_num;	inf >> key_num;

	key_m = new char[key_num];
	sound_m = new string[key_num];

	

	for (int i = 0; i < key_num; ++i)
	{
		char key;
		string sounds;

		inf >> key >> sounds;
		cout << key << " " << sounds << "\n";

		//	initialize key, freq table
		key_m[i] = key;
		sound_m[i] = sounds;
	}
	bool quit = false;
	while (!quit)
	{
		const char key = _getch();
		cout << "You pressed " << key << " key\n";
		string ring = findFreq(key, key_num);
		if ((int)key == 27) { cout << "Exit this game. \n";	quit = true; }
		else if (ring[0] != '\0')
		{
			unsigned long current_time = timeGetTime();
			cout << "Elapsed time = " << current_time - time_check;

			time_check = current_time;
			PlaySoundA(ring.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
		}
		else					{cout << "Wrong key input!!\n";}
	}
		
	delete[] sound_m;
	delete[] key_m;

	return 0;
}

string findFreq(const char key, const int num_keys)
{
	for (int i = 0; i < num_keys; ++i)
	{
		if (key == key_m[i])
		{
			cout << sound_m[i] << endl;
			return sound_m[i];

		}
	}
	return "\0";	// not found key
}

bool findFreq(const char key, const int num_keys, int)
{
	for (int i = 0; i < num_keys; ++i)
	{
		if (key == key_m[i])
		{
			return true;

		}
	}
	return 0;	// not found key
}