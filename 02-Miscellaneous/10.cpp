/*

Ranged Loops:

for(Range Declation : Range Expression == Collaction Of Item)
{
    Code;
}

*/

#include <iostream>
#include "My-Input-Library.h"

using namespace std;

int main()
{

    int Array1[] = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int n : Array1)
    {
        cout << n << endl;
    }

    return 0;
}