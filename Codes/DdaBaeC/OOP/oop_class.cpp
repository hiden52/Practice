#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Friend
{
public:
    string name;
    string address;
    int age;
    double height;
    double weight;

    void print()
    {
        cout << name << " " << address << " " << age << " " <<
        height << "cm " << weight << "kg" << endl;
    }

};

class Date      // access specifier는 private가 default
{
//private:
    int m_month;
    int m_day;
    int m_year;

public:
    void setDate(const int& month_in, const int& day_in, const int& year_in)
    {
        m_month = month_in;
        m_day = day_in;
        m_year = year_in;

    }

    

    const int& getDay()
    {
        return m_day;
    }
    const int& getMonth()
    {
        return m_month;
    }
    const int& getYear()
    {
        return m_year;
    }

    void copyFrom(const Date& original)
    {
        m_month = original.m_month;
        m_day = original.m_day;
        m_year = original.m_year;
    }
    
    void printDate()
    {
        cout << m_month << "." << m_day << "." << m_year << endl;
    }
};

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    // Constructor가 없으면 default constructor가 호출 ex) Fraction(){}
    Fraction(const int& num_in = 0, const int& den_in = 1)
    {
        // m_numerator = 0;
        // m_denominator = 1;
        m_numerator = num_in;
        m_denominator = den_in;

        //cout << "Fraction() constructor" << endl;
    }
    
    //  위임생성자 -> 생성자가 생성자를 가져다 쓰는 것. C++11부터 가능
    Fraction(const int& den_in)
        : Fraction(1, den_in)
    {}
    

    // Constructor member Initialization list
    class Something
    {
    private:
        int     m_i = 2;
        double  m_d = 3.2;
        char    m_c = 'v';
        int     m_arr[5] = {1,5,5,8,7};   //이니셜라이저 리스트가 우선

    public:
        Something()
            : m_i{1}
            , m_d{3.14}
            , m_c{'a'}
            , m_arr{1, 2, 3, 4, 5} 
            //Initializer list
        {
            // 이니셜라이저 리스트 적용 후 실행
            m_i *= 2;
            m_d *= 3.2;
            m_c += 3;
            // 즉 최종적으로 위의 값이 적용됨
        }
    };

    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};


int main ()
{

    Friend john { "John", "LA", 32, 175.4, 65}; //instanciation, instance

    john.print();
    cout << &john << endl;

    Date today;
    // today.month;
    // today.day;
    // today.year;
    today.setDate(12, 19, 2020);
    today.printDate();

    Date copy;
    copy.copyFrom(today);       //같은 클래스안에 정의 되어있는 멤버라면
                                //다른 instance에 있는 member도 접근 가능

    Fraction frac;      //  parameter가 없는 생성자는 ()를 생략
    frac.print();

    return 0;
}