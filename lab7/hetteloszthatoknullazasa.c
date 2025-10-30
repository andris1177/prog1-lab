/*
Írj függvényt, mely egy egészekből álló tömböt kap paraméterként, és a héttel osztható tömbelemeket kinullázza! A függvény neve seven_to_zero legyen. 
*/

void seven_to_zero(int* list, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (list[i] % 7 == 0)
        {
            list[i] = 0;
        }
    }
}

#include <stdio.h>

#define length 12

int main()
{
    int list[length] = {1, 7, 7, 2, 2, 2, 7, 2, 2, 7, 2, 7};

    seven_to_zero(list, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }

    printf("\n");
}