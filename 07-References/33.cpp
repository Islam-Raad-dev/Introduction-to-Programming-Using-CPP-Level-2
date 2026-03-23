/*

Call ByRef / ByVal
 
*/
#include <iostream>
using namespace std;

void Fuction1(int a)
{
    a++;
}

int main()
{
    int a = 10;

    cout << a << endl; // Value In Memore in DEC / Call ByVal.

    cout << &a << endl; // Adrees In Memory in HEX / Call ByRef.

    return 0;
}