#include <iostream>
#include "header_Files/Calc.h"

using namespace std;

class Simple
{
private:
    int m_id;
public:
    Simple(int id)
    {
        /*this ->*/ setId(id);

        //cout << this << endl;   //  this : 자기 자신의 포인터
    }
    //~Simple();

    void setId(int id)
    {
        m_id = id;
    }
    int getId()
    {
        return m_id;
    }
};


int main ()
{
    Simple s1(1), s2(2);
    s1.setId(2);
    s2.setId(42);

    cout << &s1 << " "  << &s2 << endl;

    Calc cal(10);
    // cal.add(1);
    // cal.sub(2);
    // cal.mult(2);
    cal.add(1).sub(2).mult(2).print();  // Chaining member functions
    cal.print();


    return 0;
}