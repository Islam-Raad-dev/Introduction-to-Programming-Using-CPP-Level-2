/*

Files Delete Record From File:

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

void Save_Vector_To_File(string FileName, vector<string> vFileContent)
{

    fstream MyFile;

    MyFile.open("MyFile.txt", ios::out);

    if (MyFile.is_open())
    {

        for (string Line : vFileContent)
        {

            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }

        MyFile.close();
    }
}

void DeleteRecordFromFile(string FileName, string Record)
{

    vector<string> vFileContent;

    Load_Data_From_File_To_Vector(FileName, vFileContent);

    for (string &Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = " ";
        }
    }
}

void PrintFile(string FileName)
{

    fstream MyFile;

    MyFile.open(FileName, ios::in);

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

    cout << "File Content Before Delete\n";
    PrintFile("MyFile.txt");

    DeleteRecordFromFile("MyFile.txt", "Islam");

    cout << "File Content After Delete\n";
    PrintFile("MyFile.txt");

    return 0;
}