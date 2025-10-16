/*
Írj függvényt, mely kiszámítja az első N pozitív egész szám négyzetösszegét! A függvény neve legyen pyramid (hiszen egy N szintes, gömbökből épített piramisban éppen ennyi gömb található).

Például: 3 -> 14
*/ 

#include <stdio.h>

int pyramid(int number)
{
    int sum = 0;

    for (int i = 1; i <= number; i++)
    {
        sum += (i*i);
    }

    return sum;
}

int main()
{
    int number = 3;

    scanf("%d", &number);

    printf("%d\n", pyramid(number));

    return 0;
}
