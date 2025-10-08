/*
Írj C-programot, mely beolvas egy nem negatív számot a bemenetről, és ennyi darab # karaktert ír ki egymás után! Amennyiben a beolvasott szám nagyobb, mint 100, akkor csak száz karaktert írjon ki a program.

Például: 4 -> ####
*/ 

#include <stdio.h>

int main()
{
    long int  length;
    
    scanf("%d", &length);

    for (long int i = 1; i <= length && i < 101; i++)
    {
        printf("%s", "#");
    }
    
    printf("\n");

    return 0;
}
