/*

Mistakes With Pointer:

*/
#include <iostream>
using namespace std;

int main()
{
    int x, *p;
    p = x; //Worng;
    p = &x;//Correct;
//______________________________________________________________________

    *p = &x;//Worng;
    *p = x;//Correct;

    return 0;
}