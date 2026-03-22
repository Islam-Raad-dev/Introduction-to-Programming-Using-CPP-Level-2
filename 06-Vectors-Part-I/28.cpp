/*

Vectors: Declaration VS Intiliztion

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> Numbers = {10, 20, 30, 40, 50};

    cout << "Numbers Vector = ";

    for (int &Num : Numbers)//Ranged loop
    {
        cout << Num << " ";
    }

    cout << endl;

    return 0;
}