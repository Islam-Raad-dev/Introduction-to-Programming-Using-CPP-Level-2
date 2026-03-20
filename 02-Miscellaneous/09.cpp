#include <iostream>
#include "My-Input-Library.h"

using namespace std; 

int main()
{


    string Result = (MyIn::ReadNumber("Please A Enter Number:") > 0) ? "Positve" : "Nagative";
    
    cout << Result << endl;


    string Result2 = ((MyIn::ReadNumber("Please A Enter Number:") == 0) ? "Zero" : (MyIn::ReadNumber("Please A Enter Number:") > 0) ? "Positve" : "Nagative");
    
    cout << Result2 << endl;
    return 0;
}
