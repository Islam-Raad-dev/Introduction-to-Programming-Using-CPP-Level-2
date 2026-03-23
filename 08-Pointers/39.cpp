/*

Call By Reference Using Pointers:

*/
#include <iostream>
using namespace std;

void Swap(int *n1, int *n2)
{

    int Temp;
    Temp = *n1;
    *n1 = *n2;
    *n2 = Temp;
}

int main()
{

    int a = 1, b = 2;

    cout << "Before Swapping " << endl;
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;

    Swap(&a, &b);

    cout << "After Swapping " << endl;
    cout << "A = " << a << endl;
    cout << "B = " << b << endl;

    return 0;
}