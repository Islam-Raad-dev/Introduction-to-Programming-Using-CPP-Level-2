/*

Vectors Access Element: 

*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> Num = {1, 2, 3, 4, 5};

    cout << "\nUsing .at(i)\n";
    cout << "Element at Index 0 : " << Num.at(0) << endl;
    cout << "Element at Index 2 : " << Num.at(2) << endl;
    cout << "Element at Index 4 : " << Num.at(4) << endl;

    cout << "\nUsing [i]\n";
    cout << "Element at Index 0 : " << Num[0] << endl;
    cout << "Element at Index 0 : " << Num[2] << endl;
    cout << "Element at Index 0 : " << Num[3] << endl;

    return 0;
}