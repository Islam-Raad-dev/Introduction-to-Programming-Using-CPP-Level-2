/*

Functions :

Functions Recursion: Then The Function Recall Him Self.

The Problem = Stack OverFlow.

 لايستحب استخدامها لانها ممكن تضرب البرنامج عند الارقام الكبيرة

*/

#include <iostream>
using namespace std;

int PowerNumber(int Base, int Power)
{

    if (Power == 0)
    {
        return 1;
    }
    else
    {
        return (Base * PowerNumber(Base, Power - 1));
    }
}
int main()
{

    cout << PowerNumber(2, 4) << endl;

    return 0;
}