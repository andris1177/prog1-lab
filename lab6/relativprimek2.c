/* 
Írj gcd azonosítójú függvényt (gcd: greatest common divisor), mely kiszámolja és visszaadja két pozitív egész szám legnagyobb közös osztóját. A függvény dolgozzon az euklideszi algoritmus szerint.

Írj relative_primes azonosítójú függvényt, mely visszaadja, hogy a paraméterként kapott két pozitív szám relatív prím-e. Két szám akkor relatív prím, ha legnagyobb közös osztójuk 1. A relative_primes függvény ne végezzen aritmetikai műveleteket, hanem a legnagyobb közös osztót a gcd függvény hívásával határozza meg.

Írj főprogramot (main), mely számpárokat olvas a standard inputról, amíg csak tud. A program feladata kiírni a standard outputra a relatív prím párok darabszámát. A főprogram ne végezzen a vizsgálathoz közvetlen aritmetikai műveleteket, hanem a relative_primes függvényt hívja!

Input:  3 8   2 4   5 7
Output: 2@
*/
#include <stdio.h>

#define listSize 10

int gcd(int x, int y)
{
    while (y != 0)
    {
        int c = y;
        y = x % y;
        x = c;
    }

    return x;
}

int relative_primes(int x, int y)
{
    if (gcd(x, y) == 1)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int c = 0;
    int x;
    int numbers[listSize];

    for (int i = 0; i < listSize; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < listSize; i++)
    {
        for (int j = i + 1; j < (listSize); j++)
        {
            if (relative_primes(numbers[i], numbers[j]) == 1)
            {
                c++;
            }
        } 
    }

    printf("%d\n", c);

    return 0;
}