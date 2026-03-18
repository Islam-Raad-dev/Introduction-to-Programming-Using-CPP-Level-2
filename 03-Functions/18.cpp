/*

Functions :

Functions Recursion: Then The Function Recall Him Self.

The Problem = Stack OverFlow.

 لايستحب استخدامها لانها ممكن تضرب البرنامج عند الارقام الكبيرة

*/

#include <iostream>
using namespace std;

void PrintNumbers(int N, int M)
{

    if (N <= M)
    {
        cout << M << endl;
        PrintNumbers(N, M - 1);
    }

    cout<<"\n\n";
}

void PowerNumber(int K, int Y)
{

    if (K <= Y)
    {
        cout << K << endl;
        PrintNumbers(K * Y, Y);
    }
}
int main()
{
    PrintNumbers(1, 10);
    PowerNumber(2, 100);

    return 0;
}