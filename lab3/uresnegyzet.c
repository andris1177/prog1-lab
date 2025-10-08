/*
Írj programot, mely beolvas egy pozitív egész számot, és egy ekkora oldalhosszúságú, x-ekkel határolt, pontokkal kitöltött négyzetet rajzol a standard kimenetre a következő módon:


Input: 4
Output:
xxxx
x..x
x..x
xxxx
*/ 

#include <stdio.h>

int main()
{
    int sideLength;

    scanf("%d", &sideLength);
    
    for ( int row = 1; row <= sideLength; row++)
    {
        if (row == 1 || row == sideLength)
        {
            for(int column = 1; column <= sideLength; column++)
            {
                printf("x");
            }

            printf("\n");
        }

        else 
        {
            printf("x");

            for (int column = 1; column<= sideLength-2; column++)
            {
                printf(".");
            }

            printf("x\n");
        }
    }
    
    return 0;
}
