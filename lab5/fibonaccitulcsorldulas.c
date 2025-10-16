/*
Írj programot, mely egy 100 elemű long long unsigned tömb első két elemét beolvassa a standard inputról, majd a Fibonacci-sorozat
Fn=Fn-1+Fn-2
rekurzív szabályát alkalmazva feltölti a tömböt. A program írja ki a standard outputra az utolsó olyan tömbelem indexét, melyben tárolt érték még nem csordult túl.

A túlcsordulás detektálása általános esetben nehéz feladat, hardvertámogatást igényel. Jelen speciális sorozat esetén a számértékek vizsgálatával megtehető, gondolj ki egy megfelelő módszert.

Ügyelj a beolvasás formátumkódjára!

Megjegyzés: A feladat megoldásához valójában szükségtelen a 100 elemű tömb feltöltése. Két elemű tömb ciklikus indexelésével is benyújthatsz megoldást.
*/ 

#define length 3

#include <stdio.h>

int main()
{
    long long unsigned int numbers[length] = {0};

    scanf("%llu%llu", &numbers[0], &numbers[1]);
    int i = 0;
    int run = 1;

    for (i = 1; i < 101; i++)
    {
        numbers[2] = numbers[1];
        numbers[1] += numbers[0];
        numbers[0] = numbers[2];

        if (numbers[2] > numbers[1])
        {
            break;
        }
    }

    printf("%d\n", i);

    return 0;
 }
