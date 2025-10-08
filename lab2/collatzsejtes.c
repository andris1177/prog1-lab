/*
Tekintsük a következő sorozatképzési szabályt:

Ha ai páros, akkor ai+1 = ai / 2 , egyébként ai+1 = 3ai + 1.

Az a0 = 3 kezdőértékről indulva a fenti szabály az alábbi sorozatot generálja:
3 10 5 16 8 4 2 1 4 2 1 4 2 1 4 2 1 ...

A Collatz-sejtés (1937) szerint a fenti szabályt tetszőleges pozitív a0 kezdőértékre alkalmazva, előbb-utóbb eljutunk a 4 2 1 számhármas végtelen ismétlődéséhez. Ezt a sejtést még senki nem bizonyította, sőt igen nehéz matematikai problémaként tartják számon.

Írj C-programot, mely beolvassa a0 értékét, majd kiírja, hogy melyik az a legkisebb i index, melyre ai = 1. A fenti példára a helyes válasz 7. 
*/ 

#include <stdio.h>

int main()
{
    int x;
    int count = 0;

    scanf("%d", &x);

    for (; x != 1; count++)
    {        
        if (x % 2 == 0)
            x = x/2;

        else
            x = 3*x+1;
    }

    printf("%d\n", count);

    return 0;
}
