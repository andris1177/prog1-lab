/*
Írj függvényt, mely egy karaktert kap paraméterként, és visszatér a karakterben található hexadecimális számjegy értékével! A függvény neve hexa_value. Amennyiben a paraméterként kapott karakter nem értelmezhető hexadecimális számjegyként, akkor visszatérési értéke -1.

Például: '3' -> 3, 'c' -> 12, '!' -> -1

Segítség: Ne felejtsük el, hogy a karakterekkel aritmetikai műveletek végezhetők! Mi lesz a '3' - '0' kifejezés értéke? (Ne tanuld meg az ASCII táblát, ne szerepeljenek a kódban "mágikus számok"!)
*/
#include <stdio.h>


char lower(char hex)
{
    return hex + ('a' - 'A');
}

int hexa_value(char hex)
{
    if (hex >= 'A' && hex <= 'F')
    {
        hex = lower(hex);
    }

    if (hex >= '0' && hex <= '9')
    {
        return (int)(hex - '0');
    }

    else if (hex >= 'a' && hex <= 'f')
    {
        return 10 + ((int)(hex - 'a'));
    }

    return -1;
}

int main()
{
    char hex;

    scanf("%c", &hex);

    printf("%d\n", hexa_value(hex));
}