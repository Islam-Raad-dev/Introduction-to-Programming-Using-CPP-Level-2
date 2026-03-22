/*

Tow Dimensional Arrays:

*/

#include <iostream>

int main()
{

    int Arr[10][10];

    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {

            Arr[i][j] = (i + 1) * (j + 1);
        }
    }

    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {

            printf(" %0*d ", 2, Arr[i][j]);
        }

        std::cout << std::endl;
    }
    return 0;
}
