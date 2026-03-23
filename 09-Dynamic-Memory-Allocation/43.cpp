/*

Dynamic Memory Allocation : New / Delete.

*/
#include <iostream>
using namespace std;

int main()
{

    int *ptrX;
    float *ptrY;
    //______________________________________________________

    ptrX = new int;
    ptrY = new float;

    //______________________________________________________

    *ptrX = 45;
    *ptrY = 58.35;

    //______________________________________________________

    cout << *ptrX << endl;
    cout << *ptrY << endl;

    //______________________________________________________

    delete ptrX;
    delete ptrY;

    return 0;
}