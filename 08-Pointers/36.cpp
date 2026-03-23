/*

Dereferencing Pointer:

*/
#include <iostream>
using namespace std;

int main()
{

    int a = 10;

    cout << "a Value   =  " << a << endl;
    cout << "a Address =  " << &a << endl;

    int *p = &a;

    cout << "Pointer Value  = " << p << endl;
    cout << "Pointer Key  = " << *p << endl;

    *p = 20;

    cout << a << endl;
    cout << *p << endl;

    a = 30;

    cout << a << endl;
    cout << *p << endl;

    return 0;
}