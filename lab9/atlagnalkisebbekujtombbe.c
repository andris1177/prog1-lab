/*
Írj függvényt, mely egy egész számokat tartalmazó tömböt kap paraméterként és létrehoz egy 
új tömböt, mely a számok átlagánál kisebb értékeket tartalmazza! 
A függvény neve legyen filter_average, térjen vissza a létrehozott tömb kezdőcímével, 
és mivel az új tömb méretét is ismernie kell a hívónak, ezt az információt a 
paraméterlistán keresztül, utolsó paraméterként adja vissza.

Például: 3 5 11 4 -1 2 (6 elemű tömb) -> 3 -1 2 (3 elemű tömb)
*/

#include <stdio.h>
#include <stdlib.h>

int* filter_average(int list[], int n, int* m)
{
    float average = 0.0;

    for (int i = 0; i < n; i++)
    {
        average += list[i];
    }

    average /= n;

    int lowerCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (list[i] < average)
        {
            lowerCount++;
        }
    }

    int* lower = (int *)malloc(lowerCount * sizeof(int));

    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (list[i] < average)
        {
            lower[index] = list[i];
            index++;
        }
    }

    *m = lowerCount;
    return lower;
}

int main()
{
    int list[] = {1, -1, 10, 1};
    int* result = NULL;
    int length = 0;
    result = filter_average(list, 4, &length);

    if (length != 0)
    {
        for (int i = 0; i < length; i++)
        {
            printf("%d ", result[i]);
        }

        printf("\n");
    }

    free(result);

    return 0;
}