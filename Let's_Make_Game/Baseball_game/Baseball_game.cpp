#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void suffleArr(int* arr, const int& length);
bool quitGame(const int* pitching, const int& num_answer);
bool judgeAnswer(const int* pitching, const int* answer, const int& num_answer);
bool checkNumber(const int* arr);

const int num_answer = 3;
int main()
{
	bool quit = false;

	while (!quit)
	{
		int numbers[9];
		for (int i = 0; i < 9; ++i)
		{
			numbers[i] = i + 1;
		}

		suffleArr(numbers, 9);

		int answer[num_answer];
		for (int i = 0; i < num_answer; ++i)
			answer[i] = numbers[i];

		bool isWin = false;

		// Loop ends when user win
		while (!isWin)
		{
			//  pitch a ball
			int pitching[num_answer] = { 0 };
			for (int i = 0; i < num_answer; ++i)
				cin >> pitching[i];
			
			quit = quitGame(pitching, num_answer);
			if (quit) break;

			bool correctNum = checkNumber(pitching);
			if (!correctNum) continue;

			//  hit or out ? JUDGE!
			isWin = judgeAnswer(pitching, answer, num_answer);
		}
	}


	return 0;
}

void suffleArr(int* arr, const int& length)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; ++i)
	{
		int idx1 = rand() % length;
		int idx2 = rand() % length;
		int tmp = 0;

		tmp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = tmp;
	}

}

bool judgeAnswer(const int* pitching, const int* answer, const int& num_answer)
{
	int strike = 0, ball = 0;
	for (int i = 0; i < num_answer; ++i)
	{
		for (int j = 0; j < num_answer; ++j)
		{
			if ((pitching[i] == answer[j]) && (i == j))
			{
				strike++;
				//cout << "i : " << i << ", j : " << j << endl;	//	for debug
			}
			else if ((pitching[i] == answer[j]))
			{
				ball++;
				//cout << "i : " << i << ", j : " << j << endl;	//	for debug
			}
		}
	}
	if (strike == 3) { cout << "You win!! \n"; return true; }
	else if (ball > 0 || strike > 0) { cout << strike << " Strikes, " << ball << " balls\nTry again.\n"; return false; }
	else { cout << "Hit!! \nTry again.\n"; return false; }
}

bool quitGame(const int* pitching, const int& num_answer)
{
	for (int i = 0; i < num_answer; ++i)
		if (pitching[i] == 0) return true;   // true means quit this game
	return false;
}

bool checkNumber(const int* arr)
{
	if (arr[0] == arr[1] == arr[2])
	{
		cout << "You can't input SAME NUMBER " << endl;
		return false;
	}
	else if (arr[0] > 9 || arr[1] > 9 || arr[2] > 9)
	{
		cout << "Wrong nunber! " << endl;
		return false;
	}
	else
		return true;
}