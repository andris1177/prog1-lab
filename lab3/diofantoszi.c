/*
Adott a következő diofantoszi egyenlet:

a x + b y = c

Diofantoszi egyenleteknek azokat az egyenleteket nevezzük, amelyeknek minden együtthatója és megoldása egész szám. Esetünket korlátozzuk a csak pozitív számokra. Írj standard C programot, amely beolvassa a pozitív a b c együtthatókat, majd kiírja az összes x y megoldáspárt. A különböző megoldásokat x értéke szerint növekvő sorrenben külön sorba írja, az x és y számokat egy szóköz válassza el.

Amennyiben a bemenet pl. 2 8 26, akkor a kimenet legyen

1 3
5 2
9 1
*/ 

#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);
    
    for (int i = 0; a*i <= c ; i++)
    {
        for (int j = 0; b*j <= c; j++)
        {
            if (i*a + j*b == c)
            {
                if (i == 0 || j == 0)
                {
                    continue;
                }

                printf("%d %d\n", i, j);
            }
        }
    }

    return 0;
}
