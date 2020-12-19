#include <iostream>

int main ()
{
    using namespace std;

    int length;

    cin >> length;

    int *arr = new int[length];

    arr[0] = 1;
    arr[1] = 2;

    for (int i = 0; i < length; ++i)
    {
        cout << (uintptr_t)&arr[i] << endl;
        cout << arr[i] << endl;
    }

    //resizeing

    int *arr1 = new int[3]{1, 2, 3};



    delete [] arr;
    delete [] arr1;

}
