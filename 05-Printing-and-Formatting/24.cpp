/*

Printf

String / Char Varibales

*/
#include <iostream>
using namespace std;
int main()
{

    char Name[] = "Islam Raad";
    char Letter = 'I';

    printf("Dear %s, How Are You ? \n\n", Name);
    printf("Char = %*c\n\n", 1, Letter);


    return 0;
}