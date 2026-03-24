/*

Vectors Iterator:

*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> Num = {1, 2, 3, 4, 5};

    vector<int>::iterator iter;

    for (iter = Num.begin(); iter != Num.end(); iter++)
    {

        cout << *iter << "  ";
    }

    cout << endl;

    return 0;
}