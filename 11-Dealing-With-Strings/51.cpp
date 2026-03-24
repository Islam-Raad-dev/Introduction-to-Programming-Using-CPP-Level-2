/*

CCtype Library:

*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    char x, w;

    x = toupper('a');
    w = tolower('A');

    cout << x << endl;
    cout << w << endl;

    //_____________________

    cout << "Is IT Upper " << isupper('A') << endl;
    cout << "Is IT Lower " << islower('a') << endl;

    cout << "Is IT Digit " << isdigit('9') << endl;
    cout << "Is IT Puncet " << ispunct(';') << endl;

    //_____________________

    return 0;
}