/*
Írj programot, mely a bemeneten érkező egészekből álló számsorozatból addig írja a kimenetre a számokat, ameddig a sorozat szigorúan monoton (akár szigorúan monoton növekvő, akár szigorúan monoton csökkenő)!

Például: 2 4 5 8 6 5 7 4 -> 2 4 5 8

Figyelj arra, hogy a programnak működnie kell akkor is, ha a bemenet egyelemű vagy akár üres.

Például: 2 -> 2

A bemenet végét a scanf visszatérési értékével tudod figyelni.
*/ 

#include <stdio.h>

int main()
{
    int x, y, yset = 0, checked = 0, mode = 0; // mode: 1  = monoton csokken, 2 = monoton no

    while (scanf("%d", &x) == 1)
    {
        if  (x == y)
        {
            break;
        }

        if (!checked && yset)
        {
            if (x > y)
            {
                mode = 2;
                checked = 1;
            }

            else if (x < y) 
            {
                mode = 1;
                checked = 1;
            }
        } 
        
        if (mode != 0)
        {
            if (mode == 1 && x > y)
            {
                break;
            }

            else if (mode == 2 && x < y)
            {
                break;
            }
        }

        printf("%d ", x);

        y = x;
        yset = 1;
    }

    printf("\n");

    return 0;
}
