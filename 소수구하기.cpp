#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> intList;
	vector<int>::iterator itr;

	for (int i = 1; i < 51; i++)
	{
		intList.push_back(i);
		
	}
	for (int i : intList)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 1; i < intList.size(); i++)
	{
		for (int j = i + 1; j < intList.size();)
		{
			if ((intList[j] % intList[i]) == 0)
			{
				intList.erase(intList.begin() + j);
			}
			else
			{
				j++;
			}
		}
	}
	for (int i : intList)
	{
		cout << i << " ";
	}

	
}
