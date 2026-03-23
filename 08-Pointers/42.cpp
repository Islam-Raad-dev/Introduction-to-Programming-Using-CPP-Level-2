/*

Pointer And Void:

*/
#include <iostream>
using namespace std;

int main()
{
    void *ptr;
    int x = 50;

    float F1 = 10.5;

    ptr = &F1;

    cout << ptr << endl;

    cout << *(static_cast<float *>(ptr)) << endl;

    ptr = &x;

    cout << *(static_cast<int *>(ptr)) << endl;

    return 0;
}