/*

Functions Overloading: 

Functions Overloading =  اسم واحد اعطيه لاكثر من فنكشن  وهو شكل من تعدد الاشكال
ادخل بنفس الفنكشن الي كلها تسوي نفس الوظيفة ادخل بداخلها اكثر من وظيفه
*/

#include <iostream>
using namespace std;

double MySum(double a, double b)
{
    return (a + b);
}

int MySum(int a, int b)
{
    return (a + b);
}

int MySum(int a, int b, int c)
{
    return (a + b + c);
}

int MySum(int a, int b, int c, int d)
{
    return (a + b + c + d);
}

int main()
{

    cout << MySum(10.999, 20.001) << endl;
    cout << MySum(10, 20) << endl;
    cout << MySum(10, 20, 30) << endl;
    cout << MySum(10, 20, 30, 40) << endl;

    return 0;
}
