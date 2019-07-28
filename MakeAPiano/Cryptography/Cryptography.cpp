// Cryptography.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#define MAX_STR 255
using namespace std;

void printString(char* in) // no '\n'
{
	for (int i = 0; i < MAX_STR; i++)
	{
		if (in[i] == '\0') return;
		cout << in[i];
	}
}
void print(char* in) //	print char array with "\n"
{
	for (int i = 0; i < MAX_STR; i++)
	{
		if (in[i] == '\0') break;
		cout << in[i];
	}

	cout << "\n";
}

void ceaserChiper(char* strings)
{
	cout << "Encrypt \""; printString(strings); cout << "\"\n";

	for (int i = 0; i < MAX_STR; ++i)
	{
		if (strings[i] == '\0') break;

		int ascii_en = (int)*(strings + i) - 3;

		if (ascii_en < 65)
			ascii_en += 26;
		else if(ascii_en > 90 && ascii_en < 97)	// when string[i] is not capital
			ascii_en += 26;
		
		strings[i] = (char)ascii_en;
	}
}

void decryptCC(char* enString)
{
	cout << "Decrypt \""; printString(enString); cout << "\"\n";

	for (int i = 0; i < MAX_STR; ++i)
	{
		if (enString[i] == '\0') break;

		int ascii_en = (int) * (enString + i) + 3;

		if (ascii_en > 122)
			ascii_en -= 26;
		else if (ascii_en < 97 && ascii_en > 90)	// when string[i] is not capital
			ascii_en -= 26;

		enString[i] = (char)ascii_en;
	}
}

int main()
{
	char input_string[MAX_STR];

	cin >> input_string;

	ceaserChiper(input_string);
	print(input_string);

	decryptCC(input_string);
	print(input_string);

	return 0;
}
