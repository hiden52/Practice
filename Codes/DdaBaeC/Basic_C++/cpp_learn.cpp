#include <iostream>
#include <string>
#include <cstdarg>

using namespace std;

double findAverege(int count, ...)
{
    double sum = 0;

    va_list list;

    va_start(list, count);

    for (int arg = 0; arg < count; ++arg)   
    {
        sum += va_arg(list, int);
    }
        va_end(list);

        return sum / count;
    
    

}

int main (/* int argc, char *argv[] */)
{
    // for (int count = 0; count < argc; ++count)
    // {
    //     std::string argv_single = argv[count];
    //     std::cout << argv_single << std::endl;
    // }

    cout << findAverege(2,1,2,3, "hello, world") << endl;
     cout << findAverege(3,1,2,3) << endl;
    return 0;
}