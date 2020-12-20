#include <iostream>

using namespace std;

int main()
{
    for( int i = 2; i <= 9; ++i)
    {
        cout << i << "단" << endl;
        for (int j = 1; j <=9; ++j)
        {
            cout << i << "\t*\t" << j << "\t=\t" << i*j <<endl;
        }
        cout << endl;
    }

    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout<< endl;

    for(int i = 5; i > 0; --i)
    {
        for(int j = 1; j <= i; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i)

    return 0;
}