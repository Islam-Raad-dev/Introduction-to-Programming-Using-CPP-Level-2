/*

Files Load Data To Vecotr :

*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void Load_Data_From_File_To_Vector(string FileName, vector<string> &vFileContent)
{

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {

        string Line;

        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }

        MyFile.close();
    }
}

int main()
{

    vector<string> vFileContent;

    Load_Data_From_File_To_Vector("MyFile.txt", vFileContent);

    for (string &Line : vFileContent)
    {
        cout << Line << endl;
    }

    return 0;
}