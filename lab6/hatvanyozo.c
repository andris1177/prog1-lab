/*
Lebegőpontos számok hatványozására használható a math.h-ban található pow függvény. Ezzel akár eπ is kiszámolható.

Egész számok egész kitevőjű hatványozására ugyanakkor a pow függvény nem ajánlott, mert kerekítési hibákkal terhelt lehet.

Írj ipow (integer power) azonosítójú függvényt, mely paraméterként egy pozitív alapot és egy nemnegatív kitevőt vár, és visszaadja a hatványozott értéket. A számítást ciklusban szorzással végezd.

Az ellenőrzőbe csak a függvényt másold be, de teszteléséhez természetesen készíts megfelelő main-t is.

Ha az egyszerű ciklusban szorzó megoldásod kizöldült, ismerkedj meg az Exponentiation by squaring algoritmus iteratív verziójával. 
*/
#include <stdio.h>

int ipow(int number, int power)
{
    int sum = 1;

    for (int i = 0; i < power; i++)
    {
        sum *= number; 
    }

    return sum;
}

int ipowp(int number, int power)
{
    if (power < 0)
    {
        return ipowp(1 / number, -power);
    }

    else if (power == 0)
    {
        return 1;
    }

    else if (power % 2 == 0)
    {
        ipowp(number * number, power / 2);
    }

    else if (power % 2 != 0)
    {
        return number * ipowp(number * number, (power - 1) / 2);
    }
}

int main()
{
    int number = 6;
    int power = 2;

    printf("%d\n", ipow(number, power));
    printf("%d\n", ipowp(number, power));

    return 0;
}