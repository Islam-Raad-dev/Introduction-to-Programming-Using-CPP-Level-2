/*

Files Append Mode :

*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    fstream MyFile;

    MyFile.open("Islam File.txt", ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << "HI, This Is The First Line.\n";
        MyFile << "HI, This Is The Secound Line.\n";
        MyFile << "HI, This Is The Third Line.\n";

        MyFile.close();
    }

    return 0;
}