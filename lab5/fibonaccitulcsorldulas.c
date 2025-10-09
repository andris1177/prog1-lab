/*
Írj programot, mely egy 100 elemű long long unsigned tömb első két elemét beolvassa a standard inputról, majd a Fibonacci-sorozat
Fn=Fn-1+Fn-2
rekurzív szabályát alkalmazva feltölti a tömböt. A program írja ki a standard outputra az utolsó olyan tömbelem indexét, melyben tárolt érték még nem csordult túl.

A túlcsordulás detektálása általános esetben nehéz feladat, hardvertámogatást igényel. Jelen speciális sorozat esetén a számértékek vizsgálatával megtehető, gondolj ki egy megfelelő módszert.

Ügyelj a beolvasás formátumkódjára!

Megjegyzés: A feladat megoldásához valójában szükségtelen a 100 elemű tömb feltöltése. Két elemű tömb ciklikus indexelésével is benyújthatsz megoldást.
*/ 

#include <stdio.h>
#include <limits.h>


int main()
{
    printf("%Lf\n", LLONG_MIN);
    return 0;
}
