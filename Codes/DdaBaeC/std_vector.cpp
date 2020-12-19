#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void printStack(const vector<int> &stack)
{
    for(auto &e : stack)
    {
        cout << e << '\t';
    }
    cout << endl;
}


int main ()
{
    vector<int> arr;

    vector<int> arr2 { 1, 2, 3, 4, 5, 6};
    cout << arr2.size() << endl;
    for (auto &itr : arr2)
    {
        cout << itr << "\t";
    }
    cout << endl;

    cout << arr2[1] << endl;
    cout << arr2.at(1) << endl;

    arr2.resize(2);
     for (auto &itr : arr2)
    {
        cout << itr << "\t";
    }
    cout << endl;

    
    //Using vector as stack
    vector<int> v{1, 2, 3};     //vector 사용 팁 : new와 delete의 사용 최소화
    // vector.size()        사용하고 있는 크기?
    // vector.capacity()    실제 크기

    v.reserve(1024);    //메모리 미리 할당
    v.resize(2);    //메모리 반납 및 재할당x 리사이즈 한것 처럼 

    for( auto &e : v)
    {
        cout << e << "\t";
    }
    cout << endl;

    cout << v.size() << "\t" << v.capacity() << endl;

    vector<int> stack;

    stack.push_back(3);
    printStack(stack);

    stack.push_back(4);
    printStack(stack);

    stack.push_back(8);
    printStack(stack);
    
    stack.push_back(7);
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);
    
    stack.pop_back();
    printStack(stack);

    int i = 2;
    assert(i == 2);



    return 0;
}
