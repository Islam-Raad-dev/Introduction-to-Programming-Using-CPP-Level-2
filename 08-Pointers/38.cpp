/*

Pointer VS References.

Pointer: هو متغير يمكن ان اغيره في اوقت داخل البرنامج
References: هو دالة فقط و لايمكن ان اغيره ادخل البرنامج فهو ثابث 
*/
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &x = a;

    cout << &a << endl;
    cout << &x << endl;

    cout << a << endl;
    cout << x << endl;

    int *p = &a;

    cout << p << endl;
    cout << *p << endl;

    int b = 20;
    p = &b;

    cout << p << endl;
    cout << *p << endl;

    return 0;
}