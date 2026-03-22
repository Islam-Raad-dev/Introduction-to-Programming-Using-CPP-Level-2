/*

setw Manipulatpr:

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    cout << "----------|-----------------------------|----------|" << endl;
    cout << "   Code   |             Name            |   Mark   |" << endl;
    cout << "----------|-----------------------------|----------|" << endl;

    cout << setw(10) << "C101" << "|" << setw(29) << "Introduction To Programing 1" << "|" << setw(10) << "95" << "|" << endl;
    cout << setw(10) << "C102" << "|" << setw(29) << "Computer Hardwear" << "|" << setw(10) << "88" << "|" << endl;
    cout << setw(10) << "C10352" << "|" << setw(29) << "Network" << "|" << setw(10) << "75" << "|" << endl;
    cout << "----------|-----------------------------|----------|" << endl;

    return 0;
}