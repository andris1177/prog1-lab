/*
A Kolakoski-sorozat 1-esekből és 2-esekből álló végtelen számsorozat, melynek első néhány eleme
1 2 2 1 1 2 1 2 2 1 2 2 1 1 ...

A sorozat érdekes tulajdonsága, hogy ha felírjuk az egymás mellett álló azonos számjegyekből álló blokkok hosszúságait, akkor magát a Kolakoski-sorozatot kapjuk vissza.

1 (2 2) (1 1) (2) (1) (2 2) (1) (2 2) (1 1) ...
1  2     2     1   1   2     1   2     2 . . .

Az általánosított Kolakoski-sorozat n különböző számjegyet tartalmaz, úgy, hogy 1-esek blokkját 2-esek blokkja, azt 3-asok blokkja, stb követi, és a fenti tulajdonságot megőrzi. n=4-re pl. az alábbi sorozatot kapjuk:

1 2 2 3 3 4 4 4 1 1 1 2 2 2 2 3 3 3 3 ...

Írj programot, mely beolvassa n értékét, melyről tudjuk, hogy 2 és 9 közé esik. A program listázza ki az általánosított Kolakoski-sorozat első 100 tagját! A számokat egyetlen szóköz válassza el!
*/

#include <stdio.h>

#define size 100

int main()
{
    int numbers[size] = {1, 2, 2};
    int n = 0;
    int referenceIndex = 2;
    int i = 3;
    int next = 3;

    scanf("%d", &n);

    while (i < size)
    {   
        if (next == n+1)
        {
            next = 1;
        }

        for (int j = 0; j < numbers[referenceIndex] && i < size; j++)
        {
            numbers[i] = next;
            i++;
        }

        next++;
        referenceIndex++;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}
