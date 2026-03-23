/*

Pointer And Arrays:

*/
#include <iostream>
using namespace std;

int main()
{
    int arr[4] = {10, 20, 30, 40};
    int *ptr = arr;

    cout << "Addresses Are:\n";
    cout << ptr << endl;
    cout << ptr + 1 << endl;
    cout << ptr + 2 << endl;
    cout << ptr + 3 << endl;

    cout << "Vlaues Are: \n";
    cout << *(ptr) << endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr + 2) << endl;
    cout << *(ptr + 3) << endl;

    return 0;
}