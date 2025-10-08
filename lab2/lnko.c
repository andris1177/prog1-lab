/*
Keresd meg két beolvasott szám legnagyobb közös osztóját! Alkalmazd az Euklideszi algoritmust! (https://www.youtube.com/watch?v=fwuj4yzoX1o)

Például: 12 18 -> 6
*/ 

#include <stdio.h>

int main()
{
    int a, b;

    scanf("%d%d", &a, &b);

    while (b != 0)
    {
        int c = b;
        b = a % b;
        a = c;
    }

    printf("%d\n", a);

    return 0;
}
