/*

Functions :

Call Stack / Call Hierarchy

Last Input.
First Output.

*/

#include <iostream>
using namespace std;

void Function4()
{
    cout << "Hi, My Name Is Islam Raad." << endl;
}

void Function3()
{
    Function4();
}

void Function2()
{
    Function3();
}

void Function1()
{
    Function2();
}

int main()
{
    Function1();

    return 0;
}
