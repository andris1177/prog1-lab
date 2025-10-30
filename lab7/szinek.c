/*
Hozz létre felsorolt típust színek tárolására, melynek neve enum colour! A típus az alábbi színeket képes tárolni: WHITE, RED, YELLOW, LIME, CYAN, BLUE, MAGENTA, BLACK.

Hozd létre a struct rgb struktúrát, mely színek RGB kódját tárolja! A struktúra tagjai r, g és b, mindhárom unsigned char típusú.

Írd meg a make_rgb függvényt, mely egy színt (felsorolt típus) kap paraméterül, és visszatér a szín RGB kódját tartalmazó struktúrával. (A feladatban szereplő színek RGB kódja megtalálható ezen az oldalon: https://htmlcolorcodes.com/color-names/) 
*/

enum colour {WHITE, RED, YELLOW, LIME, CYAN, BLUE, MAGENTA, BLACK};

struct rgb
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct rgb make_rgb(enum colour c)
{
    switch (c)
    {
    case WHITE: return (struct rgb){255, 255, 255};
    case RED: return (struct rgb){255, 0, 0};
    case YELLOW: return (struct rgb){255, 255, 0};
    case LIME: return (struct rgb){0, 255, 0};
    case CYAN: return (struct rgb){0, 255, 255};
    case BLUE: return (struct rgb){0, 0, 255};
    case MAGENTA: return (struct rgb){255, 0, 255};
    case BLACK: return (struct rgb){0, 0, 0};
    }
}

#include <stdio.h>

int main()
{
    struct rgb lrgb;
    lrgb = make_rgb(MAGENTA);
    printf("%d, %d, %d\n", lrgb.r, lrgb.g, lrgb.b);
    return 0;
}