/*

Files Save Vector To File :

*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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

int main()
{

    vector<string> vFileContent{"Ali", "Isslam", "Ahmad"};

    Save_Vector_To_File("MyFile.txt", vFileContent);

    return 0;
}