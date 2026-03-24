/*

String Object : 

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{

    string N1 = "My Name is Islam Raadm I Love Programming";

    //_____________________________________________

    // Length Of The String

    cout << N1.length() << endl;

    //_____________________________________________

    // Reutrn Letter in Position 3

    cout << N1.at(3) << endl;

    //_____________________________________________

    // Add (In C ++) To The End Of The String

    N1.append("In C ++");
    cout << N1 << endl;

    //_____________________________________________

    // Insert (Mohamed) in Position 7

    N1.insert(7, "Mohamed");
    cout << N1 << endl;

    //_____________________________________________

    // Print All The Next 8 Letter From Position 16

    cout << N1.substr(16, 8) << endl;

    //_____________________________________________

    // Remove One Charecter Form The End Of The Sring

    cout << N1 << endl; 

    //_____________________________________________

    // Add One Charecter To The End Of The Stirng

    N1.push_back('X');
    cout << N1 << endl;

    return 0;
}