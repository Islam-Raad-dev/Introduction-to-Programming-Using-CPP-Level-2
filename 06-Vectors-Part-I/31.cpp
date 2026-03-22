/*
  
Vector : Remove Element

push = Add Element To The Vector.
pop = Remove last Element.
size = Number Of Element Inside The Vector.
clear = Remoce All Element Inside The Vector. 

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> vNumbers;

    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);

    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();


    cout << "Vector Element : ";


    for (int &Number : vNumbers)
    {
        cout << Number << endl;
    }

    return 0;
}