/*

Pointer : Varibal That Store Addres Another Varibal/Fuction/Object Not Value.

*/
#include <iostream>
using namespace std;

int main()
{

    int a = 10;

    cout << a << endl;
    cout << &a << endl;

    int *p = &a;
    cout << p << endl;

    return 0;
}