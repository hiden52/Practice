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

int main ()
{

    Friend john { "John", "LA", 32, 175.4, 65}; //instanciation, instance

    john.print();
    cout << &john << endl;

    return 0;
}