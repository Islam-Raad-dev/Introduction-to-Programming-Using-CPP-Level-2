/*

Functions :

Default Parameters == Optional Parameters.

Default = بالبرمجة تعني في حالة الفشل

*/

#include <iostream>
using namespace std;

int MySum(int a, int b, int c = 0, int d = 0) /*Default Parameters :
 اذا بالاستدعاء خليت له قيمة عادي واذا ما خليت فهي صفر*/
{
    return (a + b + c + d);
}

int main()
{

    cout << MySum(10, 20) << endl;
    cout << MySum(10, 20, 30) << endl;
    cout << MySum(10, 20, 30, 40) << endl;

    return 0;
}
