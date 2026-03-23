/*

Pointer And Structures:

*/
#include <iostream>
using namespace std;

struct stPointer
{
    string Name;
    float Salary;
};

int main()
{
    stPointer Employee, *ptr;

    Employee.Name = "Islam Raad";
    Employee.Salary = 5000.5;

    cout << Employee.Name << endl;
    cout << Employee.Salary << endl;

    ptr = &Employee;

    cout << "Using Pointer: \n";
    cout << ptr->Name << endl;
    cout << ptr->Salary << endl;

    return 0;
}