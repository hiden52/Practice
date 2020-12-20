#include <iostream>
#include <cmath>

using namespace std;

//Call by Value
void doSomething(int y)
{
    cout << "In func " << y << " " << &y << endl;
}

//Call by Reference
void addOne(int &y)
{
    cout << y << " " << &y << endl;
    y += 1;
}
void getSinCos(const double &degrees, double &sin_out, double &cos_out)
{
    static const double pi = 3.141592 / 180.0;
    const double radians = degrees * pi; // / 180.0;    //한번 계산 후 안바뀔 것은 const로 박제
    sin_out = std::sin(radians);
    cos_out = std::cos(radians);


}


//Call by Adress


//Function Overloading
int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)  //매개변수도 달라야 다른 함수로 인식
{
    return x + y;
}


//Recursion
int sumTo(int sumto)
{
    if(sumto <= 0)
    {
        return 0;
    }
    else if (sumto == 1)
    {
        return 1;
    }
    else
    {
        return sumto + sumTo(sumto - 1);
    }
    
}

int  fibonacci(int n)
{
    if ( n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 2) + fibonacci(n - 1);
    }
    
    
}


int main ()
{
    //Call by Value   
    int x = 9;
    cout << "In Main " << x << " " << &x << endl;
    doSomething(x);



    //Call by Reference
    int a = 1;
    cout << a << " " << &a << endl;

    addOne(a);
    cout << a << " " << &a << endl;

    double sin(0.0);
    double cos(0.0);

    getSinCos(30.0, sin, cos);

    cout << sin << " " << cos << endl;



    //Call by Adress



    //함수 오버로딩
    add(1,2);
    add(2.4, 24.3);

    //Recursion

    
    cout << sumTo(55) << endl;
   
    int f_num = 20;
    for(int i = 0; i < f_num; ++i)
    {
        cout << fibonacci(i) << '\t';
    }
    cout << endl;

    return 0;
    
}