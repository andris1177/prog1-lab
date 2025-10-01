/*
Írj programot, mely egész értéket olvas a bemenetről, és ezek közül a pozitívokat fordított sorrendben kiírja! Az adatsor végjele a 0 érték, legfeljebb 100 darab érték érkezhet (a végjel előtt).

Például: 2 -1 5 -7 -1 8 -3 0 -> 8 5 2
*/ 

#include <stdio.h>

#define listSize 100

int main()
{
    int numbers[listSize] = {0}, x, i = 0;

    while (i < listSize && scanf("%d", &x) == 1 && x != 0)
    {
        if (x <= 0)
        {
            continue;
        }

        numbers[i] = x;
        i++;
    }

    for (int j = i-1; j >= 0; j--)
    {
        printf("%d ", numbers[j]);
    } 

    printf("\n");

    return 0;
}
