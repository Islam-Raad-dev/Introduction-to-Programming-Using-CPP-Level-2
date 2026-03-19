/*

Static Varibles == هو متغير ثابت لكل البرنامج وليس له فترة حياة واحدة
 فقط اذا ان فترة حياته هي فترة حياة البرنامج كامل 


*/

#include <iostream>
using namespace std;

void MyFunc()
{

    static int Number = 1;

    cout << "Value Of Number: " << Number << "\n";

    Number++;
}
int main()
{

    MyFunc();
    MyFunc();
    MyFunc();

    return 0;
}