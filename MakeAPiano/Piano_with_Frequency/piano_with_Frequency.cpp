#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

//constexpr int NUM_NOTES = 10;
//
////char key_m[NUM_NOTES] = { 'a', 's', 'd','f','j','k','l',';' };
////unsigned long freq_m[NUM_NOTES] = { 261, 293, 329, 349, 391, 440, 493, 523 };
//char* key_m = NULL;
//unsigned long* freq_m = NULL;
//
//unsigned long findFreq(const char key, const int num_keys);


int main()
{
	PlaySound(TEXT("sound_files/25.wav"), NULL, SND_FILENAME | SND_SYNC | SND_NODEFAULT);
	//bool quit = false;

	//ifstream inf;
	//inf.open("key_table.txt", ios::in);
	//int key_num;	inf >> key_num;

	//key_m = new char[key_num];
	//freq_m = new unsigned long[key_num];

	//

	//for (int i = 0; i < key_num; ++i)
	//{
	//	char key;
	//	unsigned long freq;

	//	inf >> key >> freq;
	//	cout << key << " " << freq << "\n";

	//	//	initialize key, freq table
	//	key_m[i] = key;
	//	freq_m[i] = freq;
	//}

	//while (!quit)
	//{
	//	const char key = _getch();
	//	cout << "You pressed " << key << " key\n";
	//	if ((int)key == 27)	{	cout << "Exit this game. \n";	quit = true;	}
	//	else if (findFreq(key, key_num)) {Beep(findFreq(key, key_num), 500); }
	//	else					{cout << "Wrong key input!!\n";}
	//}
	//	
	//delete[] freq_m;
	//delete[] key_m;

	return 0;
}
//
//unsigned long findFreq(const char key, const int num_keys)
//{
//	for (int i = 0; i < num_keys; ++i)
//	{
//		if (key == key_m[i])	return freq_m[i];
//	}
//	return 0;	// not found key
//}