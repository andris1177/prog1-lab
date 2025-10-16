/*
Hozz létre felsorolt típust évszakok tárolására. A típus a SPRING, SUMMER, AUTUMN, WINTER értékek tárolására legyen képes, a típus neve legyen enum season.

Az ellenőrzőbe csak az új típust létrehozó sorokat kell bemásolnod.
*/
#include <stdio.h>

enum season
{
    SPRING, SUMMER, AUTUMN, WINTER
};

/*
Írj függvényt, mely paraméterként egy évszakot kap, és kiírja az évszak nevét csupa kis betűvel a standard outputra. A függvény neve legyen print_season.

Írj month2season azonosítójú függvényt, mely paraméterként egy hónap sorszámát kapja (1: január, 12: december), és visszatér a megfelelő évszakkal.

A megoldásban tételezd fel, hogy az enum season típus az elvárásoknak megfelelően van definiálva. A típust definiáló sorokat ne másold be az ellenőrzőbe, csak a függvényt. A megoldásban ne támaszkodj az egyes évszak-szimbólumok számszerű értékeire! 
*/

void print_season(enum season s)
{
    if (s == SPRING)
    {
        printf("spring");
    }

    else if (s == SUMMER)
    {
        printf("summer");
    }

    else if (s == AUTUMN)
    {
        printf("autumn");
    }

    else if (s == WINTER)
    {
        printf("winter");
    }
}

enum season month2season(int month)
{
    if (month >= 3 && month <= 5)
    {
        return SPRING;
    }

    else if (month >= 6 && month <= 8)
    {
        return SUMMER;
    }

    else if (month >= 9 && month <= 11)
    {
        return AUTUMN;
    }

    else if (month == 12 || (month >= 1 && month <= 2))
    {
        return WINTER;
    }
}

/*
Írj programot, mely a standard inputról hónapok sorszámait olvassa be, amíg csak tudja. A program minden egyes hónaphoz írja ki a megfelelő évszakot a standard kimenetre. Az egyes évszakokat vesszővel válassza el, az egyszerűség kedvéért az utolsót is kövesse vessző. A megoldásban tételezd fel, hogy az enum season típus, a month2season és print_season függvények megfelelően működnek, és csak a main-t másold be az ellenőrzőbe. A főprogram ne végezzen konverziós számításokat, csak a már megírt és jól működő függvényeket hívja!


Input:  3 1 12 5 6
Output: spring,winter,winter,spring,summer,
*/

int main()
{
    int month;

    while (scanf("%d", &month) == 1)
    {
        int sechuan = month2season(month);
        print_season(sechuan);
        printf(",");
    }

    printf("\n");

    return 0;
}