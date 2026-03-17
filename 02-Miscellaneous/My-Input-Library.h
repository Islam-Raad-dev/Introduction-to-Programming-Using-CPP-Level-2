#include <iostream>
using namespace std;

namespace MyIn
{

    int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;
        } while (Number <= 0);

        return Number;
    }

    int ReadNegativeNumber(string Message)
    {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;
        } while (Number > 0);

        return Number;
    }

    int ReadUserAge(string Message)
    {
        int Age = 0;
        do
        {
            cout << Message << endl;
            cin >> Age;
        } while (Age > 0);

        return Age;
    }

    string ReadUserName(string Message)
    {

        string Text;

        cout << Message;
        getline(cin, Text);

        return Text;
    }

    int RandomNumber(int From, int To)
    {

        int randNumb = rand() % (To - From + 1) + From;

        return randNumb;
    }

    int ReadNumber(string Message)
    {
        int Num;

        cout << Message;
        cin >> Num;

        return Num;
    }

}