/*

Exception Handling: 

Try / Catch.

Run Time Error. 

*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> Num = {1, 2, 3, 4, 5};

    try
    {
        //Body. 
        cout << Num.at(5);
    }
    catch (...)
    {
        cout << "Out Of Bound\n";
    }

    return 0;
}
