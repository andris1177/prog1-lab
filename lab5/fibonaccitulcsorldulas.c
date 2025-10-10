/*
Írj programot, mely egy 100 elemű long long unsigned tömb első két elemét beolvassa a standard inputról, majd a Fibonacci-sorozat
Fn=Fn-1+Fn-2
rekurzív szabályát alkalmazva feltölti a tömböt. A program írja ki a standard outputra az utolsó olyan tömbelem indexét, melyben tárolt érték még nem csordult túl.

A túlcsordulás detektálása általános esetben nehéz feladat, hardvertámogatást igényel. Jelen speciális sorozat esetén a számértékek vizsgálatával megtehető, gondolj ki egy megfelelő módszert.

Ügyelj a beolvasás formátumkódjára!

Megjegyzés: A feladat megoldásához valójában szükségtelen a 100 elemű tömb feltöltése. Két elemű tömb ciklikus indexelésével is benyújthatsz megoldást.
*/ 

#define length 2

#include <stdio.h>

int main()
{
    unsigned long long x, y;
    unsigned long long numbers[length];
    int i;
    int run = 1;

    scanf("%llu %llu", &x, &y);
    numbers[0] = x;
    numbers[1] = y;

    for (i = 0; i < 101; i++)
    {
        unsigned long long sum = numbers[0] + numbers[1];
        numbers[1] = numbers[0];
        numbers[0] = sum;

        if (numbers[0] < numbers[1])
        {
            break;
        }
    } 

    printf("%d", i);

    return 0;
}
