#include <iostream>
#include <bitset>

void printArr(int *array)
{
    std::cout << sizeof(array) << std::endl;
}

int main()
{
    using namespace std;

    //unsigned int a = 0b0110;

    //cout << (a >> 2 ) << " " << bitset<16>(a >> 2) << endl;
    // char name[] = "Duke Enlington";

    // cout << name << endl;
    // cout << *name << endl;
    // cout << sizeof(name) << endl;
    // cout << sizeof(*name) << endl;
    // cout << sizeof(name[0]) << endl;

    // int arr[] { 1, 2, 4, 6};

    // cout << sizeof(arr) << endl;
    // printArr(arr);
    // cout << *arr << "\t";
    // for(int i = 1; i < 4; ++i)
    // {
    //     cout << *arr + i << "\t";
    // }
    // cout << endl;

    // int val = 23;
    // int *iptr = &val;

    // cout << uintptr_t(iptr - 1) << endl;
    // cout << uintptr_t(iptr) << endl;
    // cout << uintptr_t(iptr + 1) << endl;

    // char *name = "Mike Shinoda";  // not allowed
    const char *name1 = "Mike Shinoda"; // C언어 스타일의 무자열 심볼릭 상수
    const char *name2 = "Mike Shinoda";

    cout << uintptr_t(name1) << endl;
    cout << uintptr_t(name2) << endl;


    char name[] = "Turing Arch";
    char *ptr = name;

    while(1)
    {
        if(*ptr == '\0')
        {
            break;
        }

        cout << *ptr++;
    }
    cout << endl;


    int array[1000]; // using stack memory - static memory allocation
    //Dynamic Memory Allocation - using heap memory
    int *ptr1 = new (std::nothrow) int;     //int var; 
                                            // (std::nothrow) is 예외처리, 메모리 할당 실패시 포인터에 nullptr 할당
    *ptr1 = 7;                              //var = 7;

    cout << ptr1 << endl;
    cout << *ptr1 << endl;

    int *ptr2 = new int {32};

    //delete는 필수!!
    delete ptr1;
    ptr1 = nullptr;
    delete ptr2;
    ptr2 = nullptr;

    if(ptr1 != nullptr)
    {
        cout << ptr1 << endl;
        cout << *ptr1 << endl;
    }

    return 0;
}