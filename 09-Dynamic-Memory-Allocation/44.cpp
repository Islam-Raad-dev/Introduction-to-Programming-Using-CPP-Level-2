/*

Dynamic Arrays : New / Delete.

*/
#include <iostream>
using namespace std;

int main()
{
    int Num;
    cout << "Enter Total Number Of Student: ";
    cin >> Num;

    float *ptr;

    ptr = new float[Num];

    cout << "\nEnter Grades Of Student:\n\n";

    for (int i = 0; i < Num; i++)
    {
        cout << "Student [" << i + 1 << "] : ";
        cin >> *(ptr + i);
    }

    cout << "\nDisplay Greades Of Student :\n\n";

    for (int i = 0; i < Num; i++)
    {
        cout << "Student [" << i + 1 << "] : " << *(ptr + i) << endl;
    }

    delete[] ptr;

    return 0;
}