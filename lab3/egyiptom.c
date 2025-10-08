/*
Az ókori Egyiptomban a 0 és 1 közötti racionális számokat egységtörtek összegeként adták meg. Tehát:

m/n = 1/a + 1/b + 1/c + 1/d + ...

ahol n > m, továbbá a < b < c < d < ... különböző pozítív egész számok.

Írj programot, amely beolvassa m és n értékét, majd egy-egy szóközzel elválasztva kilistázza az a b c d ... nevezőket!

Amennyiben az input pl. 2 3, a helyes output 2 6, hiszen 2/3 = 1/2 + 1/6.

A megoldáshoz nem használhatsz lebegőpontos (float, double) típust.

Mivel a felbontás nem egyértelmű, a megoldást a következő algoritmus szerint keresd meg: Válaszd ki azt a legnagyobb egységtörtet, mely még nem haladja meg a bejövő racionális számot. Ennek nevezőjét írd ki, majd vond ki a bemenetből. A fenti lépéseket folytasd mindaddig, míg a racionális szám nullává nem válik.
*/

#include <stdio.h>

int main()
{
    int x, y, a = 1;

    scanf("%d%d", &x, &y); 

    while (x != 0)
    {
        if (x*a >= y)
        {
            x = x*a-y;
            y = y*a;
            printf("%d ", a);
        }

        a++;
    }

    printf("\n");

    return 0;
}
