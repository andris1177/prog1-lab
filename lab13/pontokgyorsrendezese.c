/*
Írj függvényt, mely egy kétdimenziós pontokat tartalmazó tömböt az origótól való távolság alapján helyben rendez! 
A függvény neve legyen sort_points, 
a rendezés saját implementálása helyett használd az stdlib.h-ban deklarált qsort függvényt! 
A pontok az alábbi struktúrában vannak eltárolva (ezt nem szabad beküldeni az ellenőrzőnek):

typedef struct {
    double x, y;
} point;
*/

#include <stdlib.h>

typedef struct {
    double x, y;
} point;

int cmp(const void* a, const void* b)
{
    const point* p1 = (const point*)a;
    const point* p2 = (const point*)b;

    double d1 = p1->x * p1->x + p1->y * p1->y;
    double d2 = p2->x * p2->x + p2->y * p2->y;

    if (d1 > d2)
    {
        return 1;
    }

    else if (d1 < d2)
    {
        return -1;
    }

    return 0;
}

void sort_points(point list[], int n)
{
    qsort(list, n, sizeof(list[0]), cmp);
}