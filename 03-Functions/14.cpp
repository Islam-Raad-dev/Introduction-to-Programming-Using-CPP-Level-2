/*

Functions :

Declaration VS Definition. 

 
*/

#include <iostream>
using namespace std;

void add(int a, int b); // Function Declaration.

int main()
{

    add(10, 20);

    return 0;
}

void add(int a, int b) // Function Definition
{
    cout << (a + b) << endl;
}
