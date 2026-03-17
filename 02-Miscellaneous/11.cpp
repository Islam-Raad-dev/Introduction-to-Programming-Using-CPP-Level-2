/*

Validation Number Only:



*/

#include <iostream>
#include <limits>

using namespace std;

int ReadNumber(){

    int Number;

    cout<<"Please Enter A Number:\n";
    cin>>Number;

    while(cin.fail()){

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<"Invaild Number, Enter A Valid Number "<<endl;

    cin>>Number;

    }

    return Number;
}




int main()
{


    cout<< ReadNumber();

    return 0;
}