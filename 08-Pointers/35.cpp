/*

Pointer : Varibal That Store Addres Another Varibal/Fuction/Object Not Value.

*/
#include <iostream>
using namespace std;

int main()
{

    int a = 10;

    cout << "a Value   =  " << a << endl;
    cout << "a Address =  " << &a << endl;

    int *p;
    p = &a;
    
    cout << "Pointer Value  = " << p << endl;

    return 0;
}