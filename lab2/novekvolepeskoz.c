/*
Írj programot, mely beolvas egy alsó és egy felső határt, és kiírja a közéjük eső egész számokat növekvő lépésközzel. A bemenetet nem kell ellenőrizned, biztos lehetsz benne, hogy először a kisebb, aztán a nagyobb szám érkezik.


Input: 3 15 -> Output: 3 4 6 9 13
Input: 21 27 -> Output: 21 22 24 27
*/ 

#include <stdio.h>

int main()
{
    int low, high;

    scanf("%d%d", &low, &high);

    for (int i = 1; low <= high; i++)
    {
        printf("%d ", low);
        low += i;
    }

    printf("\n");

    return 0;   
}
