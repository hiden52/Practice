#include <iostream>

using namespace std;

int main ()
{
    const int val1 = 3;
    const int *ptr = &val1;  //int *ptr = &val  //const 변수의 포인터도 const
    // const 포인터의 의미
    // 포인터 변수에 저장된 주소값을 바꾸지 않는 다는 것이 아니라
    // 포인터 변수가 가르키는 주소에 있는 값을 바꾸지 않는 다는 뜻
    int val2 = 4;
    ptr = &val2; // it's ok.

    int val3 = 23;
    //int *const ptr2 = &val2;  //const 타입변수는 불가능
    int *const ptr2 = &val2;
    *ptr2 = 1;                  //가능
    //ptr2 = &val3;             //불가능
    //int *const pointer        //변수로써의 const, 가르키는 주소 변경 불가

    const int *const ptr3 = &val1;

    //Void pointer = generic pointer

    int i = 5;
    float f = 2.1;
    char c = 'v';

    void *v_ptr = nullptr;  //void pointer는 포인터연산 불가
    v_ptr = &i;
    v_ptr = &f;
    v_ptr = &c;

   // cout << *v_ptr << endl; 
   //void pointer는 가르키는 데이터의 타입을 모르기 때문에 디레퍼런싱 불가
   cout << *static_cast<float*>(v_ptr) << endl; //캐스팅하여 사용가능


   //이중포인터
   int *ptr_1 = nullptr;
   int **ptrptr_1 = nullptr;

    int value = 1;

    ptr_1 = &value;
    ptrptr_1 = &ptr_1;



    
    return 0;
}