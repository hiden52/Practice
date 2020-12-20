#include <iostream>

using namespace std;

void doSomething(int &n)            //reference로 받으면 변수 자체가 넘어가는 개념
                                    //주소조차 복사하지 않으므로 퍼포먼스 상승
{
    n = 10;
    cout << "In doSomething" << n << endl;
}

void doSomething2(const int &n)     //const를 붙이면 입력 값을 변경 불가
{
    //n = 10;
    cout << "In doSomething" << n << endl;
}

int main ()
{
    int val = 3;

    int *ptr = nullptr;
    ptr = &val;

    int &ref = val; //ref와 val이 같은 메모리를 사용하는 것 처럼 작동
                    //Reference는 반드시 초기화해야 한다.
    const int y = 3;
    //int &ref = y;   //const는 const ref
    const int &ref1 = y;

    ref = 7;

    cout << val << "\t" << ref << "\t" << *ptr << endl;
    cout << &val << "\t" << &ref << "\t" << &ptr << "\t" << ptr << endl;

    return 0;


}