/*

Files Read Mode :

*/
#include <iostream>
#include <fstream>
#include<string>
using namespace std;

void PrintFile(string FileName)
{

    fstream MyFile;

    MyFile.open( FileName, ios::in);

    if (MyFile.is_open())
    {

        string Line;

        while (getline(MyFile, Line))
        {
            cout << Line << endl;
        }

        MyFile.close();
    }
}

int main()
{

    PrintFile("Islam Raad.txt");

    return 0;
}