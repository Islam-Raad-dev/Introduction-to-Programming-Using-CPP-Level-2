/*

Printf

String / Char Varibales

*/
#include <iostream>
using namespace std;
int main()
{

    char Name[] = "Islam Raad";
    char Letter1 = 'I';
    char Letter2 = 'S';
    char Letter3 = 'L';
    char Letter4 = 'A';
    char Letter5 = 'M';
    char Letter6 = 'R';
    char Letter7 = 'A';
    char Letter8 = 'A';
    char Letter9 = 'D';

    printf("Dear %s, How Are You ? \n\n", Name);
    printf("Char = %*c\n\n", 1, Letter1);
    printf("Char = %*c\n\n", 2, Letter2);
    printf("Char = %*c\n\n", 3, Letter3);
    printf("Char = %*c\n\n", 4, Letter4);
    printf("Char = %*c\n\n", 5, Letter5);
    printf("Char = %*c\n\n", 6, Letter6);
    printf("Char = %*c\n\n", 7, Letter7);
    printf("Char = %*c\n\n", 8, Letter8);        
    printf("Char = %*c\n\n", 9, Letter9);



    return 0;
}