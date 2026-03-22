/*

Vectors: Add Element

*/

#include <iostream>
#include <vector>
using namespace std;

void ReadNumber(vector<int> &Numbers)
{

    char ReadMore = 'Y';
    int Number;

    while (ReadMore == 'Y' || ReadMore == 'y')
    {

        cout << "How Many Numbers Do You Want To Add: ";
        cin >> Number;

        Numbers.push_back(Number);

        cout << "Do You Want To Add More Numbers (Y/N) ?";
        cin >> ReadMore;
    }
}

void PrintVectorElement(vector<int> Numbers)
{

    for (int &Num : Numbers)
    {
        cout << Num << " ";
    }

    cout << endl;
}
int main()
{
    vector<int> Numbers;

    ReadNumber(Numbers);
    PrintVectorElement(Numbers);

    return 0;
}