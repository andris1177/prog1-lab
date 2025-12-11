/*
Írj függvényt, mely egy kétdimenziós pontokat tartalmazó tömböt az origótól való távolság alapján helyben rendez! 
A függvény neve legyen sort_points, a rendezéshez bármelyik tanult algoritmust használhatod. 
A pontok az alábbi struktúrában vannak eltárolva (ezt nem szabad beküldeni az ellenőrzőnek):

typedef struct {
    double x, y;
} point;
*/

typedef struct {
    double x, y;
} point;

void sort_points(point list[], int n)
{
    if (n < 0)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (((list[j].x * list[j].x) + (list[j].y * list[j].y)) > ((list[j+1].x * list[j+1].x) + (list[j+1].y * list[j+1].y)))
            {
                point tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }
    }
} 