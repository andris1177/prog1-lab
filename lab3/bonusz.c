/*
Írj programot, mely egy dolgozó kategóriáját és éves fizetését (euróban) kapja meg, és ezek alapján kiszámolja a bónusz mértékét!

Négy kategória van, az egyes kategóriákban a bónusz számítási módja az alábbi:

    0: nincs bónusz
    1: fix 1000 EUR
    2: az évi fizetés egy tizede
    3: az évi fizetés egy tizede + 1000 EUR

Érvénytelen kategória esetén írja ki a program, hogy: INVALID, és a bónusz értéke 0. Amennyiben a bónusz értéke tört szám lenne, abban az esetben lefelé kerekítünk. A program ne használja az if kulcsszót!

Példák:
Input:
3 40000 EUR
Output:
Bonus: 5000 EUR

Input:
9 21300 EUR
Output:
INVALID
Bonus: 0 EUR

Megjegyzés: Mint látod, a bemeneten az EUR szöveg is beérkezik. Ezt a legegyszerűbb simán figyelmen kívül hagyni.
*/

#include <stdio.h>

int main()
{
    int cat;
    int sal;
    int bonus = 0;

    scanf("%d%d", &cat, &sal);

    switch (cat) 
    {
        case 0:
        break;

        case 1:
            bonus = 1000;
        break;

        case 2:
            bonus = sal * 0.1;
        break;

        case 3:
            bonus = (sal * 0.1) + 1000;
        break;

        default:
            printf("INVALID\n");
    }

    printf("Bonus: %d EUR\n", bonus); 

    return 0;
}
