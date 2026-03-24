/*

Vectors Change Element:

*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> Num = {1, 2, 3, 4, 5};

    //_____________________________________________

    cout << "\nInitial Vector: ";

    for (const int &i : Num)
    {
        cout << i << "  ";
    }

    //_____________________________________________

    cout << "\nUpdate Vector: ";

    for (int &i : Num)
    {

        i = 20;
        cout << i << endl;
    }

    //_____________________________________________

    Num[1] = 40;
    Num[2] = 80;
    Num.at(3) = 90;

    //_____________________________________________
    
    cout << "\nUpdate Vector: ";

    for (const int &i : Num)
    {
        cout << i << "  ";
    }

    return 0;
}