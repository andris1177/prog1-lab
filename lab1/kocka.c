/*
Írj C-programot, mely a standard inputról beolvassa egy kocka oldalhosszát (egész szám), majd kiírja a standard outputra a kocka oldalhosszát, térfogatát és felszínét az alábbi példa szerinti formában:


A kocka oldalhossza 4 m
A kocka terfogata 64 m3
A kocka felszine 96 m2

Vigyázz arra, hogy a programnak nem feladata üdvözölő szöveget és információkat írnia a standard outputra. Csak azt írd ki, amit a feladat kér. 
*/ 

#include <stdio.h>

int main()
{
    int sideLenght;

    scanf("%d", &sideLenght);

    printf("A kocka oldalhossza %d m\n", sideLenght);
    printf("A kocka terfogata %d m3\n", sideLenght * sideLenght * sideLenght);
    printf("A kocka felszine %d m2\n", 6 * sideLenght * sideLenght);

    return 0;
}
