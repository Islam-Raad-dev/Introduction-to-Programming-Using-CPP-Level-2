/*

Vector Of Structur:
 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;
};

void ReadEmployee(vector<stEmployee> &vEmployee)
{
    char ReadMore = 'Y';
    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        stEmployee tempEmployee;

        cout << "Enter First Name: ";
        cin >> tempEmployee.FirstName;

        cout << "Enter Last Name: ";
        cin >> tempEmployee.LastName;

        cout << "Enter Salary: ";
        cin >> tempEmployee.Salary;

        vEmployee.push_back(tempEmployee);

        cout << "Do You Want To Add More Employees (Y/N) ?";
        cin >> ReadMore;
    }
}

void PrintEmlpyee(const vector<stEmployee> &vEmployee)
{
    cout << "\n\nEmployee Vectors = \n\n";

    for (const stEmployee &Employee : vEmployee)
    {
        cout << " First Name : " << Employee.FirstName << endl;
        cout << " Last Name  : " << Employee.LastName << endl;
        cout << " Salary     : " << Employee.Salary << endl;
        cout << "\n--------------------\n"
             << endl;
    }
}

int main()
{
    vector<stEmployee> vEmployee;

    ReadEmployee(vEmployee);
    PrintEmlpyee(vEmployee);

    return 0;
}